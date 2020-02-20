#include "PongCore.h"
#include <QtOpenGL>
#include <QGLWidget>
#include <QtOpenGL/QGLBuffer>
#include <QtOpenGL/QGLShader>
#include <GL/glu.h>
#include <QOpenGLFunctions_3_3_Core>
#include <algorithm>

PongCore::PongCore()
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
      format.setRenderableType(QSurfaceFormat::OpenGL);
      format.setProfile(QSurfaceFormat::CoreProfile);
      format.setVersion(3,3);
      //format.setSamples(3);
    //format.setVersion(2,1);
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
    m_shaderProgram.bind();

    GLfloat positionData[] = {
        -0.5f, -0.5f, 0.0f,
         0.5f, -0.5f, 0.0f,
         0.0f,  0.5f, 0.0f
    };

    QOpenGLBuffer m_positionBuffer = QOpenGLBuffer();
    m_positionBuffer.create();
    m_positionBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
    m_positionBuffer.bind();
    m_positionBuffer.allocate(positionData, sizeof(positionData) * 3 * sizeof(float));

    m_shaderProgram.enableAttributeArray(0);
    m_shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);

//    QOpenGLBuffer m_colorBuffer = QOpenGLBuffer();
//    m_colorBuffer.create();
//    m_colorBuffer.setUsagePattern(QOpenGLBuffer::StaticDraw);
//    m_colorBuffer.bind();
//    m_colorBuffer.allocate(positionData, sizeof(positionData) * 3 * sizeof(float));

//    m_shaderProgram.enableAttributeArray("vertexColor");
//    m_shaderProgram.setAttributeBuffer("vertexColor", GL_FLOAT, 0, 3);

    m_vao1 = new QOpenGLVertexArrayObject(this);
    m_vao1->create();
    m_vao1->bind();



    m_vao1->release();
    m_positionBuffer.release();
    m_shaderProgram.release();



}

void PongCore::resizeGL(int w, int h)
{

}

void PongCore::paintGL()
{

    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_shaderProgram.bind();

    m_vao1->bind();
    //openGLContext->glDrawElements(GL_TRIANGLES, 0, 3, (GLvoid*)0);
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //m_vao1->release();

}

void PongCore::resizeEvent(QResizeEvent *event)
{

}

void PongCore::paintEvent(QPaintEvent *event)
{
    paintGL();
}
