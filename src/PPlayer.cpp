#include "PPlayer.h"
#include <QtOpenGL>

PPlayer::PPlayer()
{

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
}

//void PPlayer::updatePosition()
//{

//}
