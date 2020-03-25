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

/**
 * @brief PongCore::PongCore
 */
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

//    QList<QByteArray> extention = context->extensions().toList();
//    std::sort(extention.begin(), extention.end());
//    qDebug() << "Supported extensions (" << extention.count() <<")";

//    foreach (const QByteArray &extension, extention) {
//      qDebug() << "    " << extension;
//    }

    currentLayoutInit = false;
    currentLayout = new PLayerMenu(this);
//    currentLayout = new PLayerScene_1(this);
}

/**
 * @brief PongCore::initLayout
 * @param layer_ - layer as PLayer
 */
void PongCore::initLayout(PLayer *layer_)
{

//    if(typeid(*layer_).name() != typeid(PLayer).name()) return;
    // To Do проверить возможность превидения типа
    PLayer* layer = (PLayer*)layer_;

    qDebug() << "initLayout";
    m_shaderProgram.bind();

    auto elements = layer->getElements();
    for(auto index = 0; index != elements.length(); index++)
    {
        auto m_vao1 = new QOpenGLVertexArrayObject(this);
        m_vao1->create();
        elements.at(index)->setVAO(m_vao1);

        m_vao1->bind();

        auto shape = elements.at(index)->getShape();
        auto fragment = elements.at(index)->getFragment();

        QOpenGLBuffer VBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
        VBO.create();
        VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
        VBO.bind();
        VBO.allocate(shape.constData(), sizeof(GLfloat)*shape.length());

        QOpenGLBuffer EBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
        if(!fragment.isEmpty()) {
            EBO.create();
            EBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
            EBO.bind();
            EBO.allocate(fragment.constData(), sizeof(GLint)*fragment.length());
        }

        m_shaderProgram.enableAttributeArray(0);
        m_shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);

        VBO.release();
        m_vao1->release();
    }

    currentLayoutInit = true;

    QVector3D background = layer->getColorBackground();
    glClearColor(background.x(), background.y(), background.z(), 1.0f);
}

/**
 * @brief PongCore::drawElements
 * @param el - elements for rendering
 */
void PongCore::drawElements(QList<PObject*> el)
{
    m_shaderProgram.bind();
    for(auto index = 0; index != el.length(); index++)
    {
        auto VAO = el.at(index)->getVAO();
        VAO->bind();

        m_shaderProgram.setUniformValue("color", el.at(index)->getColor());
        m_shaderProgram.setUniformValue("offsetPosition", el.at(index)->getPosition());

        if(!el.at(index)->getFragment().isEmpty())
        {
            glDrawElements(el.at(index)->getTypePrint(), el.at(index)->getFragment().length(), GL_UNSIGNED_INT, 0);
        } else
        {
            glDrawArrays(el.at(index)->getTypePrint(), 0, el.at(index)->getShape().length()/3);
        }

        el.at(index)->updatePosition();


        VAO->release();
    }
    m_shaderProgram.release();

}

/**
 * @brief PongCore::initializeGL
 */
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
    connect(timer, SIGNAL(timeout()), this, SLOT(requestUpdate()));
    timer->start(10);
    timer->start();

}

/**
 * @brief PongCore::paintGL
 */
void PongCore::paintGL()
{
    if(!currentLayoutInit)
        initLayout(currentLayout);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(currentLayout && currentLayoutInit)
    {
        currentLayout->checkCollision();
        drawElements(currentLayout->getElements());
        currentLayout->drawTextArray(new QPainter(this));
        if(currentLayoutInit)
            currentLayout->keyUpdate();
    }
}

/**
 * @brief PongCore::resizeEvent
 */
void PongCore::resizeEvent(QResizeEvent *)
{
    resize(640, 480);
}

/**
 * @brief PongCore::paintEvent
 */
void PongCore::paintEvent(QPaintEvent *)
{
    paintGL();
}

/**
 * @brief PongCore::keyPressEvent
 * @param e - key event
 */
void PongCore::keyPressEvent(QKeyEvent *e)
{
    if(currentLayoutInit)
        currentLayout->keyPress(e);
}

/**
 * @brief PongCore::keyReleaseEvent
 * @param e - key event
 */
void PongCore::keyReleaseEvent(QKeyEvent *e)
{
    if(currentLayoutInit)
        currentLayout->keyRelease(e);
}

/**
 * @brief PongCore::changeLayout
 * @param layer - layer as PLayer
 */
void PongCore::changeLayout(QObject *layer)
{
    currentLayoutInit = false;
    currentLayout = (PLayer*)layer;
}

