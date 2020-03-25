#include "PEvents.h"
#include <QKeyEvent>

/**
 * @brief PEvents::keyPress
 * @param e - QKeyEvent
 */
void PEvents::keyPress(QKeyEvent *e)
{
    if(e->type() == QEvent::KeyPress)
        keyPressed[e->key()] = true;
}

/**
 * @brief PEvents::keyRelease
 * @param e - QKeyEvent
 */
void PEvents::keyRelease(QKeyEvent *e)
{
    if(e->type() == QEvent::KeyRelease)
        keyPressed.remove(e->key());
}

/**
 * @brief PEvents::setElements
 * @param value - List elements
 */
void PEvents::setElements(const QList<PObject *> &value)
{
    elements = value;
}

/**
 * @brief PEvents::getElements
 * @return elements
 */
QList<PObject *> PEvents::getElements() const
{
    return elements;
}

/**
 * @brief PEvents::getKeyPressed
 * @details Used to handle multiple keystrokes simultaneously
 * @return pressed keys
 */
QMap<uint, bool> PEvents::getKeyPressed() const
{
    return keyPressed;
}
