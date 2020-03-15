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
    unsigned int getScore() const;

private:
    unsigned int score;
};

#endif // PPLAYER_H
