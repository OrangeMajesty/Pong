#include "PongCore.h"

PongCore::PongCore(QWidget* parent)
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
      format.setRenderableType(QSurfaceFormat::OpenGL);
      format.setProfile(QSurfaceFormat::CoreProfile);
      //format.setVersion(3,3);
    format.setVersion(2,1);
    setFormat(format);
    create();

    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);

    openGLContext = QOpenGLContext::currentContext()->functions();
    //func->initializeOpenGLFunctions();
}

bool PongCore::test()
{
    return true;
}

void PongCore::initializeGL()
{

}

void PongCore::resizeGL(int w, int h)
{

}

void PongCore::paintGL()
{

    glClearColor(1.0, 0.3f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.7f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}

void PongCore::resizeEvent(QResizeEvent *event)
{

}

void PongCore::paintEvent(QPaintEvent *event)
{
    paintGL();
}
