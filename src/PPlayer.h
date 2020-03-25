#ifndef PPLAYER_H
#define PPLAYER_H

#include <QObject>
#include "PObject.h"

/**
 * @brief The PPlayer class.
 *      Used to determine player class.
 */
class PPlayer : public PObject
{
    Q_OBJECT
public:
    /// Sets the shape and fragments of an object, as well as settings
    PPlayer();

    /// Returns Player Points
    unsigned int getScore() const;

    /// Sets player points
    void setScore(unsigned int value);

private:
    /// Player Current Points
    unsigned int score;
};

#endif // PPLAYER_H
