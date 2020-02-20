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

    GLfloat vertices[] = {
         0.5f,  0.5f, 0.0f,  // Верхний правый угол
         0.5f, -0.5f, 0.0f,  // Нижний правый угол
        -0.5f, -0.5f, 0.0f,  // Нижний левый угол
        -0.5f,  0.5f, 0.0f   // Верхний левый угол
    };
    GLuint indices[] = {  // Помните, что мы начинаем с 0!
        0, 1, 3,   // Первый треугольник
        1, 2, 3    // Второй треугольник
    };

    m_vao1 = new QOpenGLVertexArrayObject(this);
    m_vao1->create();
    m_vao1->bind();

    QOpenGLBuffer VBO = QOpenGLBuffer(QOpenGLBuffer::VertexBuffer);
    VBO.create();
    VBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    VBO.bind();
    VBO.allocate(vertices, sizeof(vertices));

    QOpenGLBuffer EBO = QOpenGLBuffer(QOpenGLBuffer::IndexBuffer);
    EBO.create();
    EBO.setUsagePattern(QOpenGLBuffer::StaticDraw);
    EBO.bind();
    EBO.allocate(indices, sizeof(indices));

    m_shaderProgram.enableAttributeArray(0);
    m_shaderProgram.setAttributeBuffer(0, GL_FLOAT, 0, 3);

    VBO.release();
    m_vao1->release();
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

    m_shaderProgram.setUniformValue("color", QColor(255, 120, 20, 255));
    glDrawArrays(GL_TRIANGLES, 1, 3);

    m_shaderProgram.setUniformValue("color", QColor(255, 0, 20, 255));
    glDrawArrays(GL_TRIANGLES, 0, 3);
    //glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

    m_vao1->release();
}

void PongCore::resizeEvent(QResizeEvent *event)
{

}

void PongCore::paintEvent(QPaintEvent *event)
{
    paintGL();
}
