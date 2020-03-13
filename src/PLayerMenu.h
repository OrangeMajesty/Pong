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

public slots:
    void changeLayer();
};

#endif // PLAYERMENU_H
