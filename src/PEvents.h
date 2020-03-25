#ifndef PEVENTS_H
#define PEVENTS_H

#include "PObject.h"
#include <QObject>

/**
 * @brief The PEvents class.
 *      Used to identify events at the game level.
 */
class PEvents : public QObject
{
    Q_OBJECT
public:
    explicit PEvents(QObject *parent = nullptr) {};

    /// Unused
    virtual void keyUpdate() {};

    /// Accepts and processes key press
    void keyPress(QKeyEvent *);

    /// Accepts and processes key release
    void keyRelease(QKeyEvent *);

    /// Returns pressed keys
    QMap<uint, bool> getKeyPressed() const;

    /// Install Tracked elements
    void setElements(const QList<PObject *> &value);

    /// Return tracked elements
    QList<PObject *> getElements() const;

private:
    /// Tracked elements
    QList<PObject *> elements;

    /// Active keys
    QMap<uint, bool> keyPressed;

};

#endif // PEVENTS_H
