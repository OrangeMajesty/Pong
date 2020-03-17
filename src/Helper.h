#ifndef HELPER_H
#define HELPER_H

#include "PObject.h"

#include <QObject>
#include <QtOpenGL>

class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr);

    static int checkCollision(PObject*,PObject*);

};

#endif // HELPER_H
