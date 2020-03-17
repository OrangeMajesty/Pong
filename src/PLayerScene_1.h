#ifndef PLAYERSCENE_1_H
#define PLAYERSCENE_1_H

#include <QObject>
#include "PLayer.h"

class PLayerScene_1 : public PLayer
{
    Q_OBJECT
public:
    PLayerScene_1(QObject *parent = nullptr);

    void drawTextArray(QPainter*) override;
    void keyUpdate() override;

    void layerReset() override;

public slots:
    void resetLayer(QVector3D);
};

#endif // PLAYERSCENE_1_H
