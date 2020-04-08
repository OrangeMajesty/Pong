#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "PObject.h"
#include "PEvents.h"

/**
 * @brief The PLayer class.
 *      Used to create a player object.
 *
 * @todo Add a method to add an item to a level.
 */
class PLayer : public PEvents
{
    Q_OBJECT
public:

    /// Sets the shape and fragments of an object, as well as settings
    explicit PLayer(QObject *parent = nullptr) : PEvents(parent) {};

    /// Collision check
    void checkCollision();

    /// Returns the background color
    QVector3D getColorBackground() const;

    /// Sets the background color
    void setColorBackground(const QVector3D &value);

    /// Returns items at level
    QList<PObject *> getElements() const;

    /// Sets the number of items per level
    void setElements(const QList<PObject *> &value);

    virtual void keyUpdate() {};
    virtual void drawTextArray(QPainter*) {};
    virtual void layerReset() {};

private:
    /// List of drawable items
    QList<PObject *> elements;

    /// Current background color
    QVector3D colorBackground;

signals:

};

#endif // PLAYER_H
