#include "Helper.h"
#include <ft2build.h>
#include FT_FREETYPE_H

Helper::Helper(QObject *parent) : QObject(parent)
{


}

int Helper::checkCollision(PObject *a, PObject *b)
{
    const int X = 0;
    const int Y = 1;

    if(a->getTypePrint() == GL_TRIANGLES && b->getTypePrint() == GL_TRIANGLES) {
        if(a == b) return 0; // continue

        auto vectorA = a->getShape();
        auto vectorB = b->getShape();

        auto fragmentsA = a->getFragment();
        auto fragmentsB = a->getFragment();

        auto positionA = a->getPosition();
        auto positionB = b->getPosition();

        for(int i = 0; i != vectorA.length(); i += 3) {
            vectorA[i+X] += positionA.x();
            vectorA[i+Y] += positionA.y();
        }

        for(int i = 0; i != vectorB.length(); i += 3) {
            vectorB[i+X] += positionB.x();
            vectorB[i+Y] += positionB.y();
        }

        // ----------------------------
        if((fragmentsA.length() % 3) == 0 && (vectorB.length() % 3) == 0) {
            for(int ia = 0; ia != fragmentsA.length(); ia += 3) {
                auto Xa = vectorA[(fragmentsA.at(ia+0)*3)+X], Xb = vectorA[(fragmentsA.at(ia+1)*3)+X], Xc = vectorA[(fragmentsA.at(ia+2)*3)+X];
                auto Ya = vectorA[(fragmentsA.at(ia+0)*3)+Y], Yb = vectorA[(fragmentsA.at(ia+1)*3)+Y], Yc = vectorA[(fragmentsA.at(ia+2)*3)+Y];

                for(int ib = 0; ib != vectorB.length(); ib += 3) {

                    auto X0 = vectorB[X+ib];
                    auto Y0 = vectorB[Y+ib];

                    if(
                        (Xa - X0) * (Yb - Ya) - (Xb - Xa) * (Ya - Y0) >= 0 &&
                        (Xb - X0) * (Yc - Yb) - (Xc - Xb) * (Yb - Y0) >= 0 &&
                        (Xc - X0) * (Ya - Yc) - (Xa - Xc) * (Yc - Y0) >= 0
                      ) return 1;
                    else return 0;

                }
            }


        } else qDebug() << "checkCollisionShape: Vector a !% 9";

        //--------------------------------

    }

    return -1; // unsupport type

}
