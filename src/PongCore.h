#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QOpenGLBuffer>
#include <QOpenGLShaderProgram>
#include <QOpenGLVertexArrayObject>
#include <QOpenGLWindow>
#include "PObject.h"
#include "PLayer.h"

/**
 * @brief The PongCore class.
 *      Main class.
 *
 * @details
 *      Configures the window, levels.
 *      Handles drawing objects and text.
 */
class PongCore : public QOpenGLWindow
{
    Q_OBJECT

public:
    /// Adjusts the window and sets the start layer.
    PongCore();

    /// Draws a list of layer objects
    void drawElements(QList<PObject*> el);

    /// Draw event
    void paintEvent(QPaintEvent *event);

    /// Layer initialization
    void initLayout(PLayer* layer);

protected:
    /// Initializing OpenGL
    virtual void initializeGL();

//    /// Изменение размера окна OpenGL
//    virtual void resizeGL(int w, int h);

    ///  OpenGL Rendering Event
    virtual void paintGL();

    /// OpenGL window resize event
    void resizeEvent(QResizeEvent *event);

    /// Key Press Event
    void keyPressEvent(QKeyEvent *);

    /// Key Release Event
    void keyReleaseEvent(QKeyEvent *);


private:
    /// Current OpenGL Context
    QOpenGLContext* context;

    /// Available OpenGL Features
    QOpenGLFunctions* openGLContext;

    /// Current shaders
    QOpenGLShaderProgram m_shaderProgram;

    /// Layer Initialization States
    bool currentLayoutInit;

    /// Current layer
    PLayer* currentLayout;

public slots:
    /// Layer Change Handler
    void changeLayout(QObject* layer);

};
#endif // MAINWINDOW_H
