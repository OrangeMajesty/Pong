#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "PObject.h"
#include "PEvents.h"

class PLayer : public QObject
{
    Q_OBJECT
public:
    explicit PLayer(QObject *parent = nullptr);

    QVector3D getColorBackground() const;
    void setColorBackground(const QVector3D &value);

    QList<PObject *> getElements() const;
    void setElements(const QList<PObject *> &value);

    virtual void drawTextArray(QPainter*);

    PEvents* events;

private:
    QList<PObject *> elements; // Элементы которые будем отрисовывать на слое
    QVector3D colorBackground;

signals:

};

#endif // PLAYER_H
