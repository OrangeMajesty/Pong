#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "PObject.h"
#include "PEvents.h"

class PLayer : public PEvents
{
    Q_OBJECT
public:
    explicit PLayer(QObject *parent = nullptr);

    void checkCollision();

    QVector3D getColorBackground() const;
    void setColorBackground(const QVector3D &value);

    QList<PObject *> getElements() const;
    void setElements(const QList<PObject *> &value);

    virtual void keyUpdate();
    virtual void drawTextArray(QPainter*);

    virtual void layerReset();

private:
    QList<PObject *> elements; // Элементы которые будем отрисовывать на слое
    QVector3D colorBackground;

signals:

};

#endif // PLAYER_H
