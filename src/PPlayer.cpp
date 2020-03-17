#include "PPlayer.h"
#include <QtOpenGL>

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

    setTypePrint(GL_TRIANGLES);

    collisionEffect = true;
}

unsigned int PPlayer::getScore() const
{
    return score;
}

void PPlayer::setScore(unsigned int value)
{
    score = value;
}

//void PPlayer::updatePosition()
//{

//}
