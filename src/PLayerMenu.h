#ifndef PLAYERMENU_H
#define PLAYERMENU_H

#include <QObject>
#include "PLayer.h"

class PLayerMenu : public PLayer
{
    Q_OBJECT
public:
    PLayerMenu();

    void drawTextArray(QPainter*);
};

#endif // PLAYERMENU_H
