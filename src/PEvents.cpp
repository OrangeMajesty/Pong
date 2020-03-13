#include "PEvents.h"
#include <QKeyEvent>


PEvents::PEvents(QObject *parent) : QObject(parent)
{

}

void PEvents::keyUpdate() {

}

void PEvents::keyPress(QKeyEvent *e)
{
    if(e->type() == QEvent::KeyPress)
        keyPressed[e->key()] = true;
}

void PEvents::keyRelease(QKeyEvent *e)
{
    if(e->type() == QEvent::KeyRelease)
        keyPressed.remove(e->key());


}


void PEvents::setElements(const QList<PObject *> &value)
{
    elements = value;
}

QList<PObject *> PEvents::getElements() const
{
    return elements;
}

QMap<uint, bool> PEvents::getKeyPressed() const
{
    return keyPressed;
}
