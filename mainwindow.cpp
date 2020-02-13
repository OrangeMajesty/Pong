#include "mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
{
    setSurfaceType(OpenGLSurface);

    QSurfaceFormat format;
//    format.setDepthBufferSize(24);
//    format.setMajorVersion(4);
//    format.setMinorVersion(3);
//    format.setSamples(4);
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
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

MainWindow::~MainWindow()
{
}

void MainWindow::initializeGL()
{

}

void MainWindow::resizeGL(int w, int h)
{

}

void MainWindow::paintGL()
{

    glClearColor(1.7, 0.3f, 1.2f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);

    glBegin(GL_QUADS);
    glVertex2f(-0.5f, -0.7f);
    glVertex2f(0.5f, -0.5f);
    glVertex2f(0.7f, 0.5f);
    glVertex2f(-0.5f, 0.5f);
    glEnd();

    glFlush();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{

}

void MainWindow::paintEvent(QPaintEvent *event)
{
    paintGL();
}

