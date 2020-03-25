#include "Helper.h"
#include <ft2build.h>
#include FT_FREETYPE_H

/**
* \param a,b - Checking collisions of fragments or shape for object B
* \return (int)
*   -1 If the rendering type is not supported
*    0 If no collision has occurred
*    1 If a conflict has occurred
*/
int Helper::checkCollision(PObject *a, PObject *b)
{
    const int X = 0;
    const int Y = 1;

    /// \todo Add support for other rendering methods
    if(a->getTypePrint() == GL_TRIANGLES && b->getTypePrint() == GL_TRIANGLES)
    {
        if(a == b) return 0; // Continue

        auto vectorA = a->getShape();
        auto vectorB = b->getShape();

        auto fragmentsA = a->getFragment();
        auto fragmentsB = a->getFragment();

        auto positionA = a->getPosition();
        auto positionB = b->getPosition();

        // Recalculation of coordinates taking into account offset for PObject a
        for(int i = 0; i != vectorA.length(); i += 3)
        {
            vectorA[i+X] += positionA.x();
            vectorA[i+Y] += positionA.y();
        }

        // Recalculation of coordinates taking into account offset for PObject b
        for(int i = 0; i != vectorB.length(); i += 3)
        {
            vectorB[i+X] += positionB.x();
            vectorB[i+Y] += positionB.y();
        }

        // Verification of the correct filling of VAO and EBO (x, y, z) for calculable objects
        if((fragmentsA.length() % 3) == 0 && (vectorB.length() % 3) == 0)
        {
            // Checking all the vertices of object B for each fragment of object A
            for(int ia = 0; ia != fragmentsA.length(); ia += 3)
            {
                auto Xa = vectorA[(fragmentsA.at(ia+0)*3)+X], Xb = vectorA[(fragmentsA.at(ia+1)*3)+X], Xc = vectorA[(fragmentsA.at(ia+2)*3)+X];
                auto Ya = vectorA[(fragmentsA.at(ia+0)*3)+Y], Yb = vectorA[(fragmentsA.at(ia+1)*3)+Y], Yc = vectorA[(fragmentsA.at(ia+2)*3)+Y];

                for(int ib = 0; ib != vectorB.length(); ib += 3)
                {

                    auto X0 = vectorB[X+ib];
                    auto Y0 = vectorB[Y+ib];

                    if(
                        (Xa - X0) * (Yb - Ya) - (Xb - Xa) * (Ya - Y0) >= 0 &&
                        (Xb - X0) * (Yc - Yb) - (Xc - Xb) * (Yb - Y0) >= 0 &&
                        (Xc - X0) * (Ya - Yc) - (Xa - Xc) * (Yc - Y0) >= 0
                      ) return 1; // Collision true
                    else return 0; // Collision false

                }
            }
        } else qDebug() << "checkCollisionShape: Vector a !% 9";
    }

    return -1; // Unsupport type
}
