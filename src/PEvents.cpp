#include "PEvents.h"
#include <QKeyEvent>


PEvents::PEvents(QObject *parent) : QObject(parent)
{

}

void PEvents::checkEvents(QKeyEvent *e) {

}


void PEvents::setElements(const QList<PObject *> &value)
{
    elements = value;
}

QList<PObject *> PEvents::getElements() const
{
    return elements;
}
