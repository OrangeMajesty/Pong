#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWindow>

class PongCore : public QOpenGLWindow
{
    Q_OBJECT

public:
    PongCore();

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLContext;
    QOpenGLShaderProgram m_shaderProgram;

    QOpenGLVertexArrayObject* m_vao1;
};
#endif // MAINWINDOW_H
