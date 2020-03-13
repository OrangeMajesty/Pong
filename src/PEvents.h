#ifndef PEVENTS_H
#define PEVENTS_H

#include "PObject.h"
#include <QObject>

class PEvents : public QObject
{
    Q_OBJECT
public:
    explicit PEvents(QObject *parent = nullptr);

    virtual void keyUpdate();
    void keyPress(QKeyEvent *);
    void keyRelease(QKeyEvent *);
    QMap<uint, bool> getKeyPressed() const;

    void setElements(const QList<PObject *> &value);
    QList<PObject *> getElements() const;

private:
    QList<PObject *> elements;
    QMap<uint, bool> keyPressed;

signals:

};

#endif // PEVENTS_H
