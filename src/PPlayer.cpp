#include "PPlayer.h"
#include <QtOpenGL>

/**
 * @brief PPlayer::PPlayer
 */
PPlayer::PPlayer()
{
    objectName = "Player";

    QVector<GLfloat> sharpe = {
        -0.01f, -0.2f, 1.0f,
        0.01f, -0.2f, 1.0f,
        0.01f, 0.2f, 1.0f,
        -0.01f, 0.2f, 1.0f,
    };

    QVector<GLint> fragment = {
        0,1,2,
        0,2,3
    };


    setShape(sharpe);
    setFragment(fragment);

    setSpeed(0.03);

    setTypePrint(GL_TRIANGLES);

    collisionEffect = true;
}

/**
 * @brief PPlayer::getScore
 * @return player score
 */
unsigned int PPlayer::getScore() const
{
    return score;
}

/**
 * @brief PPlayer::setScore
 * @param value - player score
 */
void PPlayer::setScore(unsigned int value)
{
    score = value;
}
