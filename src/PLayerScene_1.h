#ifndef PLAYERSCENE_1_H
#define PLAYERSCENE_1_H

#include <QObject>
#include "PLayer.h"

class PLayerScene_1 : public PLayer
{
    Q_OBJECT
public:
    PLayerScene_1(QObject *parent = nullptr);
    void keyUpdate() override;
};

#endif // PLAYERSCENE_1_H
