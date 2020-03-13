#include "PObject.h"

PObject::PObject(QObject *parent) : PConfig(parent)
{
    setPosition(QVector3D(0,0,0));
    setTypePrint(GL_TRIANGLES);
    setColor(QColor(255, 120, 20, 255));
    setAllowSelect(true);
    setSelect(false);
}

//QVector3D PObject::rotate(QVector3D)
//{

//}

//QVector3D PObject::translate(QVector3D)
//{

//}

QVector3D PObject::getPosition() const
{
    return position;
}

void PObject::setPosition(const QVector3D &value)
{
    position = value;
}

GLenum PObject::getTypePrint() const
{
    return typePrint;
}

void PObject::setTypePrint(const GLenum &value)
{
    typePrint = value;
}

QOpenGLVertexArrayObject *PObject::getVAO() const
{
    return VAO;
}

void PObject::setVAO(QOpenGLVertexArrayObject *value)
{
    VAO = value;
}

QVector<GLfloat> PObject::getShape() const
{
    return shape;
}

void PObject::setShape(const QVector<GLfloat> &value)
{
    shape = value;
}

QVector<GLint> PObject::getFragment() const
{
    return fragment;
}

void PObject::setFragment(const QVector<GLint> &value)
{
    fragment = value;
}

QColor PObject::getColor() const
{
    return color;
}

void PObject::setColor(const QColor &value)
{
    color = value;
}

bool PObject::getSelect() const
{
    return select;
}

void PObject::setSelect(bool value)
{
    select = value;
    if(value)
        setColor(QColor(255, 120, 20, 255));
    else
        setColor(QColor(150, 120, 20, 255));
//    qDebug() << "change color" << getColor() ;
}

bool PObject::getAllowSelect() const
{
    return allowSelect;
}

void PObject::setAllowSelect(bool value)
{
    allowSelect = value;
}
