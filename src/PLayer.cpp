#include "PLayer.h"
#include "PEvents.h"
#include "Helper.h"

/**
 * @brief PLayer::checkCollision
 */
void PLayer::checkCollision()
{
    auto els = getElements();

    for(auto index_1 = 0; els.length() != index_1; index_1++)
    {
        if(!els.at(index_1)->collisionEffect) continue;

        for(auto index_2 = 0; els.length() != index_2; index_2++)
        {
            if(els.at(index_2)->collisionEffect && index_1 != index_2)
            {

                if(Helper::checkCollision(els.at(index_1), els.at(index_2)) == 1)
                {
                    qDebug() << "collision!";
                    emit ((PObject*)els.at(index_1))->collision();
                    emit ((PObject*)els.at(index_2))->collision();
                }

            }


        }
    }
}

/**
 * @brief PLayer::setColorBackground
 * @param value - RGB color format
 */
void PLayer::setColorBackground(const QVector3D &value)
{
    colorBackground = value;
}

/**
 * @brief PLayer::getColorBackground
 * @return current color (format RGB)
 */
QVector3D PLayer::getColorBackground() const
{
    return colorBackground;
}

/**
 * @brief PLayer::getElements
 * @return Objects on the layer
 */
QList<PObject *> PLayer::getElements() const
{
    return elements;
}

/**
 * @brief PLayer::setElements
 * @param value - List of objects
 */
void PLayer::setElements(const QList<PObject *> &value)
{
    elements = value;
}
