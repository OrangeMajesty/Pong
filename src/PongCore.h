#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWindow>
#include "PObject.h"
#include "PLayer.h"
#include "PLayerMenu.h"

class PongCore : public QOpenGLWindow
{
    Q_OBJECT

public:
    PongCore();
    void drawElements(QList<PObject*> el);
    void initLayout(PLayer* layer);
    void checkEventLayout(PLayer *layer);

protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent(QResizeEvent *event);
    void paintEvent(QPaintEvent *event);
    void keyPressEvent(QKeyEvent *);


private:
    QOpenGLContext* context;
    QOpenGLFunctions* openGLContext;
    QOpenGLShaderProgram m_shaderProgram;

    bool currentLayoutInit;
    PLayer* currentLayout;
};
#endif // MAINWINDOW_H
