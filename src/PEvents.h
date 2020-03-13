#ifndef PEVENTS_H
#define PEVENTS_H

#include "PObject.h"
#include <QObject>

class PEvents : public QObject
{
    Q_OBJECT
public:
    explicit PEvents(QObject *parent = nullptr);

    virtual void checkEvents(QKeyEvent *);

    void setElements(const QList<PObject *> &value);
    QList<PObject *> getElements() const;

private:
    QList<PObject *> elements;

signals:

};

#endif // PEVENTS_H
