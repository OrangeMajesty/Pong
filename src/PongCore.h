#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLWindow>

class PongCore : public QOpenGLWindow
{
    Q_OBJECT

public:
    PongCore(QWidget* parent = nullptr);
    static bool test();


protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);

private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLContext;
};
#endif // MAINWINDOW_H
