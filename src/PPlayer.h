#ifndef PPLAYER_H
#define PPLAYER_H

#include <QObject>
#include "PObject.h"
#include "PConfig.h"

class PPlayer : public PObject
{
    Q_OBJECT
public:
    PPlayer();

//    void updatePosition() override;
};

#endif // PPLAYER_H
