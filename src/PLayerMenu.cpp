#include "PLayerMenu.h"
#include "PPlayer.h"

PLayerMenu::PLayerMenu()
{
    QList<PObject*> arr;
    arr.append(new PPlayer());

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
//    PObject test;

}
