#include "PLayerScene_1.h"
#include "PLayer.h"
#include "PPlayer.h"

PLayerScene_1::PLayerScene_1()
{
    QList<PObject*> arr;

    // Create 1 player
    PPlayer* player1 = new PPlayer();
    player1->setPosition(QVector3D(-0.95f, 0, 0));
    arr.append(player1);

    // Create 2 player
    PPlayer* player2 = new PPlayer();
    player2->setPosition(QVector3D(0.95f, 0, 0));
    arr.append(player2);

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}
