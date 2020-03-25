#include "PObject.h"

/**
 * @brief PObject::PObject
 * @param parent - main object
 */
PObject::PObject(QObject *parent) : PConfig(parent)
{
    setPosition(QVector3D(0,0,0));
    setTypePrint(GL_TRIANGLES);
    setColor(QColor(255, 120, 20, 255));
    setAllowSelect(true);
    setSelected(false);

    setVector(QVector3D(0,0,0));
    setSpeed(0);

    collisionEffect = false;

    connect(this, SIGNAL(collision()), this, SLOT(collisionHandler()));
}

/**
 * @brief PObject::getPosition
 * @return position
 */
QVector3D PObject::getPosition() const
{
    return position;
}

/**
 * @brief PObject::setPosition
 * @param value - position
 */
void PObject::setPosition(const QVector3D &value)
{
    position = value;
}

/**
 * @brief PObject::getTypePrint
 * @return method draw
 */
GLenum PObject::getTypePrint() const
{
    return typePrint;
}

/**
 * @brief PObject::setTypePrint
 * @param value - method draw
 */
void PObject::setTypePrint(const GLenum &value)
{
    typePrint = value;
}

/**
 * @brief PObject::getVAO
 * @return VAO
 */
QOpenGLVertexArrayObject *PObject::getVAO() const
{
    return VAO;
}

/**
 * @brief PObject::setVAO
 * @param value - VAO
 */
void PObject::setVAO(QOpenGLVertexArrayObject *value)
{
    VAO = value;
}

/**
 * @brief PObject::getShape
 * @return list of form vertices
 */
QVector<GLfloat> PObject::getShape() const
{
    return shape;
}

/**
 * @brief PObject::setShape
 * @param value - list of form vertices
 */
void PObject::setShape(const QVector<GLfloat> &value)
{
    shape = value;
}

/**
 * @brief PObject::getFragment
 * @return list of Form Vertex Indices
 */
QVector<GLint> PObject::getFragment() const
{
    return fragment;
}

/**
 * @brief PObject::setFragment
 * @param value - list of Form Vertex Indices
 */
void PObject::setFragment(const QVector<GLint> &value)
{
    fragment = value;
}

/**
 * @brief PObject::getColor
 * @return color in RGB format
 */
QColor PObject::getColor() const
{
    return color;
}

/**
 * @brief PObject::setColor
 * @param value - color in RGB format
 */
void PObject::setColor(const QColor &value)
{
    color = value;
}

/**
 * @brief PObject::getSelected
 * @return true - object selected | false - not selected
 */
bool PObject::getSelected() const
{
    return select;
}

/**
 * @brief PObject::setSelected
 * @param value - selected or not selected
 */
void PObject::setSelected(bool value)
{
    select = value;
    if(value)
        setColor(QColor(255, 120, 20, 255));
    else
        setColor(QColor(150, 120, 20, 255));
}

/**
 * @brief PObject::getAllowSelect
 * @return ability to select an item
 */
bool PObject::getAllowSelect() const
{
    return allowSelect;
}

/**
 * @brief PObject::setAllowSelect
 * @param value - ability to select an item
 */
void PObject::setAllowSelect(bool value)
{
    allowSelect = value;
}

/**
 * @brief PObject::getVector
 * @return vector object
 */
QVector3D PObject::getVector() const
{
    return vector;
}

/**
 * @brief PObject::setVector
 * @param value - vector object
 */
void PObject::setVector(const QVector3D &value)
{
    vector = value;
}

/**
 * @brief PObject::getSpeed
 * @return speed
 */
float PObject::getSpeed() const
{
    return speed;
}

/**
 * @brief PObject::setSpeed
 * @param value - speed
 */
void PObject::setSpeed(float value)
{
    speed = value;
}

void PObject::updatePosition()
{
    auto pos = getPosition();
    auto speed = getSpeed();
    auto vec = getVector();


    if(vec != QVector3D(0,0,0) && speed != 0)
    {
        if(pos.x() >= 1.0f || pos.x() <= -1.0f) vec.setX(vec.x() * -1.0f);
        if(pos.y() >= 1.0f || pos.y() <= -1.0f) vec.setY(vec.y() * -1.0f);

        setVector(vec);
        setPosition((vec*speed)+pos);

        if(pos.x() >= 1.0f || pos.x() <= -1.0f || pos.y() >= 1.0f || pos.y() <= -1.0f)
            emit goingAbroad(pos);

    } else
    {
        if(pos.x() > 1.0f ) pos.setX(pos.x() - (1.0f - pos.x()) * -1);
        if(pos.x() < -1.0f ) pos.setX(pos.x() - (-1.0f - pos.x()) * -1);

        if(pos.y() > 1.0f ) pos.setY(pos.y() - (1.0f - pos.y()) * -1);
        if(pos.y() < -1.0f ) pos.setY(pos.y() - (-1.0f - pos.y()) * -1);

        setPosition(pos);
    }
}

/**
 * @brief PObject::getObjectName
 * @return object name
 */
QString PObject::getObjectName() const
{
    return objectName;
}

/**
 * @brief PObject::collisionHandler
 */
void PObject::collisionHandler()
{
    qDebug() << "collisionHandler";
    auto vec = getVector();

    if(vec != QVector3D(0,0,0))
    {
        vec.setX(vec.x() * -1.0f);

        setVector(vec);
        updatePosition();
    }
}
