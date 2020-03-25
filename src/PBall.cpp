#include "PBall.h"

/**
 * \brief PBall::PBall
 * The constructor builds the shape of the object and adjusts the effects.
 */
PBall::PBall()
{
    /// Setting a name to define an object
    objectName = "Ball";

    /// VAO definition for point designation
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

    /// EBO definition for VAO
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

    /// Setting a VAO
    setShape(sharpe);

    /// Setting a EBO
    setFragment(fragment);

    /// Setting the rendering method
    setTypePrint(GL_TRIANGLES);

    /// Enable collision processing for an object
    collisionEffect = true;
}
