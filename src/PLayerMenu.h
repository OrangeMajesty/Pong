#ifndef PLAYERMENU_H
#define PLAYERMENU_H

#include <QObject>
#include "PLayer.h"

class PLayerMenu : public PLayer
{
    Q_OBJECT
public:
    PLayerMenu(QObject *parent = nullptr);

    void drawTextArray(QPainter*) override;
    void keyUpdate() override;

    void layerReset() override;
};

#endif // PLAYERMENU_H
