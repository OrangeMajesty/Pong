#include "PObject.h"

PObject::PObject(QObject *parent) : PConfig(parent)
{
    setPosition(QVector3D(0,0,0));
    setTypePrint(GL_TRIANGLES);
    setColor(QColor(255, 120, 20, 255));
    setAllowSelect(true);
    setSelect(false);

    setVector(QVector3D(0,0,0));
    setSpeed(0);

    collisionEffect = false;

    connect(this, SIGNAL(collision()), this, SLOT(collisionHandler()));
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

QVector3D PObject::getVector() const
{
    return vector;
}

void PObject::setVector(const QVector3D &value)
{
    vector = value;
}

float PObject::getSpeed() const
{
    return speed;
}

void PObject::setSpeed(float value)
{
    speed = value;
}

void PObject::updatePosition()
{
    auto pos = getPosition();
    auto speed = getSpeed();
    auto vec = getVector();


    if(vec != QVector3D(0,0,0) && speed != 0) {
        if(pos.x() >= 1.0f || pos.x() <= -1.0f) vec.setX(vec.x() * -1.0f);
        if(pos.y() >= 1.0f || pos.y() <= -1.0f) vec.setY(vec.y() * -1.0f);

        setVector(vec);
        setPosition((vec*speed)+pos);

        if(pos.x() >= 1.0f || pos.x() <= -1.0f || pos.y() >= 1.0f || pos.y() <= -1.0f)
            emit goingAbroad(pos);

    } else {
        if(pos.x() > 1.0f ) pos.setX(pos.x() - (1.0f - pos.x()) * -1);
        if(pos.x() < -1.0f ) pos.setX(pos.x() - (-1.0f - pos.x()) * -1);

        if(pos.y() > 1.0f ) pos.setY(pos.y() - (1.0f - pos.y()) * -1);
        if(pos.y() < -1.0f ) pos.setY(pos.y() - (-1.0f - pos.y()) * -1);

        setPosition(pos);
    }
}

QString PObject::getObjectName() const
{
    return objectName;
}

void PObject::collisionHandler()
{
    qDebug() << "collisionHandler";
    auto vec = getVector();

    if(vec != QVector3D(0,0,0)) {
        vec.setX(vec.x() * -1.0f);
//        vec.setY(vec.y() * -1.0f);

//        qDebug() << "collisionHandler1" << vec;
        setVector(vec);
        updatePosition();
//         qDebug()         << getVector();
    }
}
