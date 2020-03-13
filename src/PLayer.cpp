#include "PLayer.h"
#include "PEvents.h"

PLayer::PLayer(QObject *parent) : PEvents(parent)
{
//    events = new PEvents(config);
    events = new PEvents();
}

void PLayer::keyUpdate() {

}

void PLayer::setColorBackground(const QVector3D &value)
{
    colorBackground = value;
}

QVector3D PLayer::getColorBackground() const
{
    return colorBackground;
}

QList<PObject *> PLayer::getElements() const
{
    return elements;
}

void PLayer::setElements(const QList<PObject *> &value)
{
    elements = value;
    events->setElements(value);
}

void PLayer::drawTextArray(QPainter*)
{

}
