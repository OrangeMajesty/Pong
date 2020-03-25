#ifndef PBALL_H
#define PBALL_H

#include "PObject.h"

/**
 * @brief The PBall class.
 *      Used to build a game ball.
 */
class PBall : public PObject
{
    Q_OBJECT

public:

    /// Sets the shape and fragments of an object, as well as settings
    PBall();

};

#endif // PBALL_H
