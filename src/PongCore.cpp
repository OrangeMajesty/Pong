#include "PongCore.h"
#include <QtOpenGL>
#include <QGLWidget>
#include <QtOpenGL/QGLBuffer>
#include <QtOpenGL/QGLShader>
#include <GL/glu.h>
#include <QOpenGLFunctions_3_3_Core>
#include <algorithm>
#include "PLayerMenu.h"
#include "PLayerScene_1.h"

PongCore::PongCore()
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
    format.setRenderableType(QSurfaceFormat::OpenGL);
    format.setProfile(QSurfaceFormat::CoreProfile);
    format.setVersion(3,3);
    setFormat(format);
    create();

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openGLContext = QOpenGLContext::currentContext()->functions();

    this->resize(QSize(800,600));

    QList<QByteArray> extention = context->extensions().toList();
    std::sort(extention.begin(), extention.end());
    qDebug() << "Supported extensions (" << extention.count() <<")";

    foreach (const QByteArray &extension, extention) {
      qDebug() << "    " << extension;
    }

    currentLayoutInit = false;
    //currentLayout = new PLayerMenu(this);
    currentLayout = new PLayerScene_1(this);


}

void PongCore::initLayout(PLayer *layer_)
{
//    qDebug() << "typeid(*layer_).name()"<<typeid(*layer_).name();
//    qDebug() << "typeid(PLayer).name()"<<typeid(PLayer).name();

//    if(typeid(*layer_).name() != typeid(PLayer).name()) return;
    // To Do проверить возможность превидения типа
    PLayer* layer = (PLayer*)layer_;

    qDebug() << "initLayout";
    //currentLayoutInit = false;
    m_shaderProgram.bind();

    auto elements = layer->getElements();
    for(auto index = 0; index != elements.length(); index++) {
        auto m_vao1 = new QOpenGLVertexArrayObject(this);
        m_vao1->create();
        elements.at(index)->setVAO(m_vao1);

        m_vao1->bind();

        auto shape = elements.at(index)->getShape();
        auto fragment = elements.at(index)->getFragment();

//        GLfloat sharpe_[] = {
//            0.5f,  0.5f, 0.0f,  // Верхний правый угол
//                 0.5f, -0.5f, 0.0f,  // Нижний правый угол
//                -0.5f, -0.5f, 0.0f,  // Нижний левый угол
//                -0.5f,  0.5f, 0.0f   // Верхний левый угол
//        };

//        GLint fragment_[] = {
//            0, 1, 3,   // Первый треугольник
//                1, 2, 3    // Второй треугольник
//        };



        QOpenGLBuffer VBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        VBO.create();
        VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
        VBO.bind();
        VBO.allocate(shape.constData(), sizeof(GLfloat)*shape.length());
//        VBO.allocate(sharpe_, sizeof(sharpe_));


        QOpenGLBuffer EBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
        if(!fragment.isEmpty()) {
            EBO.create();
            EBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
            EBO.bind();
            EBO.allocate(fragment.constData(), sizeof(GLint)*fragment.length());
//            EBO.allocate(fragment_, sizeof(fragment_));
        }



        m_shaderProgram.enableAttributeArray(0);
        m_shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);

//        m_shaderProgram.enableAttributeArray(1);
//        m_shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);

        VBO.release();
        m_vao1->release();

    }
    currentLayoutInit = true;



//    m_shaderProgram.release();

    QVector3D background = layer->getColorBackground();

    glClearColor(background.x(), background.y(), background.z(), 1.0f);
}


void PongCore::drawElements(QList<PObject*> el)
{

    m_shaderProgram.bind();
    for(auto index = 0; index != el.length(); index++) {
        auto VAO = el.at(index)->getVAO();
        VAO->bind();

        m_shaderProgram.setUniformValue("color", el.at(index)->getColor());
        //m_shaderProgram.setUniformValue("offsetPosition", 0.4, 0, 0);
        m_shaderProgram.setUniformValue("offsetPosition", el.at(index)->getPosition());

//        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);


        if(!el.at(index)->getFragment().isEmpty()) {
            glDrawElements(el.at(index)->getTypePrint(), el.at(index)->getFragment().length(), GL_UNSIGNED_INT, 0);
        } else {
            glDrawArrays(el.at(index)->getTypePrint(), 0, el.at(index)->getShape().length()/3);
        }

        el.at(index)->updatePosition();


//        glEnableClientState(GL_VERTEX_ARRAY);
        //glVertexPointer(3, GL_FLOAT, 0, sharpe);

//        glPolygonMode(GL_FRONT_AND_BACK, GL_LINES);

        //glDrawArrays(el.at(index)->getTypePrint(), 0, el.at(index)->getShape().length());
        //glDrawArrays(el.at(index)->getTypePrint(), 0, el.at(index)->getShape().length()/3);
        //glDrawArrays(GL_TRIANGLES, 0, 3);
//        for(auto i = 0; i != 10; i++)
            //glDrawArrays(GL_LINE_LOOP, 0, 4);
//            glDisableClientState(GL_VERTEX_ARRAY);
//        glDrawElements(GL_QUADS, 24, GL_UNSIGNED_INT, 0);

        VAO->release();
    }
    m_shaderProgram.release();

    //glDrawElements(GL_L, 4, GL_UNSIGNED_INT, 0);
}


void PongCore::initializeGL()
{
    QOpenGLShader *vshader = new QOpenGLShader(QOpenGLShader::Vertex, this);
    vshader->compileSourceFile(":/V/firstShader.vert");
    m_shaderProgram.addShader(vshader);

    QOpenGLShader *fshader = new QOpenGLShader(QOpenGLShader::Fragment, this);
    fshader->compileSourceFile(":/V/frag.frag");
    m_shaderProgram.addShader(fshader);

    m_shaderProgram.link();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(updateScreen()));
    timer->start(10);
    timer->start();

}

void PongCore::resizeGL(int w, int h)
{

}

void PongCore::paintGL()
{
    if(!currentLayoutInit)
        initLayout(currentLayout);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(currentLayout && currentLayoutInit) {
        drawElements(currentLayout->getElements());
        currentLayout->drawTextArray(new QPainter(this));
        if(currentLayoutInit)
            currentLayout->keyUpdate();
    }
}

void PongCore::resizeEvent(QResizeEvent *event)
{
    resize(640, 480);
}

void PongCore::paintEvent(QPaintEvent *event)
{
    paintGL();
}

void PongCore::keyPressEvent(QKeyEvent *e)
{
    if(currentLayoutInit)
        currentLayout->keyPress(e);
}

void PongCore::keyReleaseEvent(QKeyEvent *e)
{
    if(currentLayoutInit)
        currentLayout->keyRelease(e);
}

void PongCore::changeLayout(QObject *layer)
{
    currentLayoutInit = false;
    currentLayout = (PLayer*)layer;
}

void PongCore::updateScreen()
{
    requestUpdate();
}
