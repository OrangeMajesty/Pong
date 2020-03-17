#include "PLayer.h"
#include "PEvents.h"
#include "Helper.h"

PLayer::PLayer(QObject *parent) : PEvents(parent)
{
//    events = new PEvents(config);
    //    events = new PEvents();
}

void PLayer::checkCollision()
{
    auto els = getElements();

    const int x = 0;
    const int y = 1;

    for(auto index_1 = 0; els.length() != index_1; index_1++) {
        if(!els.at(index_1)->collisionEffect) continue;

        for(auto index_2 = 0; els.length() != index_2; index_2++) {
            if(els.at(index_2)->collisionEffect && index_1 != index_2) {

                if(Helper::checkCollision(els.at(index_1), els.at(index_2)) == 1) {
                    qDebug() << "collision!";
                    emit ((PObject*)els.at(index_1))->collision();
                    emit ((PObject*)els.at(index_2))->collision();
                }

            }


        }
    }
}

void PLayer::keyUpdate() {

}

void PLayer::setColorBackground(const QVector3D &value)
{
    colorBackground = value;
}

QVector3D PLayer::getColorBackground() const
{
    return colorBackground;
}

QList<PObject *> PLayer::getElements() const
{
    return elements;
}

void PLayer::setElements(const QList<PObject *> &value)
{
    elements = value;
//    events->setElements(value);
}

void PLayer::drawTextArray(QPainter*)
{

}

void PLayer::layerReset()
{

}
