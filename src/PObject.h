#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QVector3D>
#include <QtOpenGL>

class PObject : public QObject
{
    Q_OBJECT
public:
    explicit PObject(QObject *parent = nullptr);

    // control
//    QVector3D rotate(QVector3D);
//    QVector3D translate(QVector3D);

    QVector3D getPosition() const;
    void setPosition(const QVector3D &value);

    GLenum getTypePrint() const;
    void setTypePrint(const GLenum &value);

    QOpenGLVertexArrayObject *getVAO() const;
    void setVAO(QOpenGLVertexArrayObject *value);

    QVector<GLfloat> getShape() const;
    void setShape(const QVector<GLfloat> &value);

    QVector<GLint> getFragment() const;
    void setFragment(const QVector<GLint> &value);

private:
    QVector3D position;

    QVector<GLfloat> shape;
    QVector<GLint> fragment;

    GLenum typePrint;

    QOpenGLVertexArrayObject *VAO;

    //signals:

public slots:
//    void click();

};

#endif // MENU_H
