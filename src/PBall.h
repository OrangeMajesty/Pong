#ifndef PBALL_H
#define PBALL_H

#include "PObject.h"

class PBall : public PObject
{
    Q_OBJECT
public:
    PBall();

//    void updatePosition() override;

signals:
//    void goingAbroad(QVector3D);
};

#endif // PBALL_H
