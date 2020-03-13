#include "PLayerScene_1.h"
#include "PLayer.h"
#include "PPlayer.h"

#define speed 0.03

PLayerScene_1::PLayerScene_1(QObject *parent)
{
    QList<PObject*> arr;

    // Create 1 player
    PPlayer* player1 = new PPlayer();
    player1->setPosition(QVector3D(-0.95f, 0, 0));
    player1->setColor(QColor(255, 120, 20, 255));
    arr.append(player1);

    // Create 2 player
    PPlayer* player2 = new PPlayer();
    player2->setPosition(QVector3D(0.95f, 0, 0));
    player2->setColor(QColor(255, 120, 20, 255));
    arr.append(player2);

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}

void PLayerScene_1::checkEvents(QKeyEvent *e) {
    auto elements = getElements();
    for(int index = 0; index != elements.length(); index++) {
            auto el = elements.at(index);

            switch(e->key()) {
                case Qt::Key::Key_Up:{
                    auto pos = el->getPosition();
                    pos.setY(pos.y() + speed);
                    el->setPosition(pos);
                } break;
                case Qt::Key::Key_Down: {
                    auto pos = el->getPosition();
                    pos.setY(pos.y() - speed);
                    el->setPosition(pos);
                } break;
//                    case Qt::Key_Space:
//                        qDebug() << "Key_Space";
//                        emit el->clicked(new PLayerScene_1());
//                     break;
            }

        }
}
