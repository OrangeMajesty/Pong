#include "PLayerScene_1.h"
#include "PLayer.h"
#include "PPlayer.h"
#include "PBall.h"

#define speed 0.03

PLayerScene_1::PLayerScene_1(QObject *parent)
{
    QList<PObject*> arr;

    // Create 1 player
    PPlayer* player1 = new PPlayer();
    player1->setPosition(QVector3D(-0.95f, 0, 0));
    player1->setColor(QColor(255, 120, 20, 255));

    QMap<PConfig::key, int> keys_p1;
    keys_p1[PConfig::key::Up] = Qt::Key::Key_W;
    keys_p1[PConfig::key::Down] = Qt::Key::Key_S;

    player1->setKeysControl(keys_p1);

    arr.append(player1);

    // Create 2 player
    PPlayer* player2 = new PPlayer();
    player2->setPosition(QVector3D(0.95f, 0, 0));
    player2->setColor(QColor(255, 120, 20, 255));

    QMap<PConfig::key, int> keys_p2;
    keys_p2[PConfig::key::Up] = Qt::Key::Key_Up;
    keys_p2[PConfig::key::Down] = Qt::Key::Key_Down;
    player2->setKeysControl(keys_p2);

    arr.append(player2);

    // Create ball
    PBall* ball = new PBall();
    ball->setPosition(QVector3D(0,0,0));
    ball->setColor(QColor(255, 120, 20, 255));
    ball->setSpeed(0.06);
    //ball->setVector(QVector3D((rand() % 2 - 1)*0.1, (rand() % 2 - 1)*0.1, 0));
    ball->setVector(QVector3D(0.1, -0.243853, 0));
    arr.append(ball);

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}

void PLayerScene_1::keyUpdate() {
    auto elements = getElements();
    auto keys = getKeyPressed();

    for(int index = 0; index != elements.length(); index++) {
        auto el = elements.at(index);

        if(typeid(*el).name() == typeid(PPlayer).name()) {
            auto pos = el->getPosition();

            if(keys[((PPlayer*)el)->getKeysControl()[PConfig::key::Up]]) {
                pos.setY(pos.y() + speed);
            }
            if(keys[((PPlayer*)el)->getKeysControl()[PConfig::key::Down]]) {
                pos.setY(pos.y() - speed);
            }

            el->setPosition(pos);
        }

    }
}
