#ifndef MENU_H
#define MENU_H

#include <QObject>
#include <QVector3D>
#include <QtOpenGL>
#include "PConfig.h"

/**
 * @brief The PObject class.
 *      Describes the object class at the game level.
 *
 * @todo Add a rotation method around the axes.
 */
class PObject : public PConfig
{
    Q_OBJECT
public:
    /// Sets initial values
    explicit PObject(QObject *parent = nullptr);

    /// Returns the offset relative to the center of the level
    QVector3D getPosition() const;

    /// Sets the offset relative to the center of the level
    void setPosition(const QVector3D &value);

    /// Returns the rendering method
    GLenum getTypePrint() const;

    /// Sets the rendering method
    void setTypePrint(const GLenum &value);

    /// Returns VAO
    QOpenGLVertexArrayObject *getVAO() const;

    /// Sets VAO
    void setVAO(QOpenGLVertexArrayObject *value);

    /// Returns the vertices of a form
    QVector<GLfloat> getShape() const;

    /// Sets the vertices of the form
    void setShape(const QVector<GLfloat> &value);

    /// Returns fragments of an object
    QVector<GLint> getFragment() const;

    /// Sets fragments of an object
    void setFragment(const QVector<GLint> &value);

    /// Returns the current color of the object
    QColor getColor() const;

    /// Sets the current color of the object
    void setColor(const QColor &value);

    /// Returns the object selection status
    bool getSelected() const;

    /// Sets the object selection status
    void setSelected(bool value);

    /// Returns the ability to select an object
    bool getAllowSelect() const;

    /// Sets the ability to select an object
    void setAllowSelect(bool value);

    /// Returns the vertices of a form
    QVector3D getVector() const;

    /// Sets the vertices of the form
    void setVector(const QVector3D &value);

    /// Returns the current speed of an object
    float getSpeed() const;

    /// Sets the current object speed
    void setSpeed(float value);

    /// Updates position based on vector and speed
    void updatePosition();

    /// Returns the name of the object
    QString getObjectName() const;

    /// Collision probability
    bool collisionEffect;

protected:
    /// Name of the property
    QString objectName;

private:
    /// The offset of the object relative to the center of the level
    QVector3D position;

    /// Coordinates of the vertices of the form
    QVector<GLfloat> shape;

    /// Form vertex indices
    QVector<GLint> fragment;

    /// Draw method
    GLenum typePrint;

    QOpenGLVertexArrayObject *VAO;

    /// Object Direction
    QVector3D vector;

    /// Current object speed
    float speed;

    /// The current color of the object
    QColor color;

    /// Item Selection Status
    bool select;

    /// Ability to select an item
    bool allowSelect;

private slots:
    /// Collision handler
    void collisionHandler();

signals:
    /// Object click signal
    void clicked(QObject*);

    /// Level Boundary Signal
    void goingAbroad(QVector3D);

    /// Collision signal
    void collision();
};

#endif // MENU_H
