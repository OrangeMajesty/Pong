#include "PBall.h"

PBall::PBall()
{

    QVector<GLfloat> sharpe = {
        0.0f, 0.0f, 1.0f, // O

        0.0f, 0.045f, 1.0f,
        -0.0335f, 0.0335f, 1.0f,
        -0.045f, 0.0f, 1.0f,
        -0.0335f, -0.0335f, 1.0f,

        0.0f, -0.045f, 1.0f,
        0.0335f, -0.0335f, 1.0f,
        0.045f, 0.0f, 1.0f,
        0.0335f, 0.0335f, 1.0f,
    };

    QVector<GLint> fragment = {
        0,1,2,
        0,2,3,
        0,3,4,
        0,4,5,

        0,5,6,
        0,6,7,
        0,7,8,
        0,8,1,
    };


    setShape(sharpe);
    setFragment(fragment);

    setTypePrint(GL_TRIANGLES);
}

//void PBall::updatePosition()
//{

//}
