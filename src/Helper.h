#ifndef HELPER_H
#define HELPER_H

#include "PObject.h"

#include <QObject>
#include <QtOpenGL>

/**
 * @brief The Helper class.
 * Contains helper methods not included in other classes.
 */
class Helper : public QObject
{
    Q_OBJECT
public:
    explicit Helper(QObject *parent = nullptr) {};

    /// Statistical method for checking collision of an PObject
    static int checkCollision(PObject*,PObject*);

};

#endif // HELPER_H
