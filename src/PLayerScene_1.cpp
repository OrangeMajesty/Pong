#include "PLayerScene_1.h"
#include "PLayer.h"
#include "PPlayer.h"
#include "PBall.h"
#include "PObject.h"

/**
 * @brief PLayerScene_1::PLayerScene_1
 * @param parent - main object
 */
PLayerScene_1::PLayerScene_1(QObject *parent)
{
    QList<PObject*> arr;

    // Create game objects
    PObject* lineCenter = new PObject();
    lineCenter->setSelected(false);
    lineCenter->setTypePrint(GL_LINES);

    QVector<GLfloat> sharpe = {
        0.0f, 1.0f, 1.0f,
        0.0f, -1.0f, 1.0f,
    };

    lineCenter->setShape(sharpe);
    arr.append(lineCenter);

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
    ball->setVector(QVector3D(0.1, -0.243853, 0));
    connect((PObject*)ball, SIGNAL(goingAbroad(QVector3D)), this, SLOT(winLose(QVector3D)));
    arr.append(ball);

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}

/**
 * @brief PLayerScene_1::drawTextArray
 * @details Rendering text using Qt methods
 * @todo Implement text rendering using OpenGL methods
 * @param paint - Qt Object
 */
void PLayerScene_1::drawTextArray(QPainter* paint)
{
    auto els = getElements();
    paint->scale(3, 3);
    paint->setPen(Qt::white);

    QList<QPointF> posScore = {
        QPointF(190, 20),
        QPointF(15, 20)
    };

    // Score players
    for(auto index = 0, i_player = 0; index != els.length(); index++)
    {
        if(els.at(index)->getObjectName() == "Player")
        {
            if(posScore.length() >= i_player)
            {
                paint->drawText(posScore.at(i_player), QString::number(((PPlayer*)els.at(index))->getScore()));
                i_player++;
            }

        }
    }

    paint->end();
}

/**
 * @brief PLayerScene_1::keyUpdate
 */
void PLayerScene_1::keyUpdate()
{
    auto elements = getElements();
    auto keys = getKeyPressed();

    for(int index = 0; index != elements.length(); index++)
    {
        auto el = elements.at(index);

        if(typeid(*el).name() == typeid(PPlayer).name())
        {
            auto pos = el->getPosition();
            auto speed = ((PPlayer*) el)->getSpeed();

            if(keys[((PPlayer*)el)->getKeysControl()[PConfig::key::Up]])
            {
                pos.setY(pos.y() + speed);
            }
            if(keys[((PPlayer*)el)->getKeysControl()[PConfig::key::Down]])
            {
                pos.setY(pos.y() - speed);
            }

            el->setPosition(pos);
        }

    }
}

/**
 * @brief PLayerScene_1::layerReset
 */
void PLayerScene_1::layerReset()
{
    auto elements = getElements();

    for(int index = 0; index != elements.length(); index++)
    {
        auto el = elements.at(index);

        if("Ball" == el->getObjectName())
        {
            el->setPosition(QVector3D(0,0,0));

            break;
        }

    }

    setElements(elements);

}

/**
 * @brief PLayerScene_1::winLose
 * @details Player win / lose handler
 * @param a - position ball
 */
void PLayerScene_1::winLose(QVector3D a)
{
    auto elements = getElements();
    int offsetPlayer = 0;

    for(int index = 0; index != elements.length(); index++)
    {
        auto el = elements.at(index);

        if("Player" == el->getObjectName())
        {
            if(a.x() >= 1.0f && offsetPlayer == 1)
                ((PPlayer*)el)->setScore(((PPlayer*)el)->getScore() + 1);

            if(a.x() <= -1.0f && offsetPlayer == 0)
                ((PPlayer*)el)->setScore(((PPlayer*)el)->getScore() + 1);

            offsetPlayer++;
        }

    }

    if(a.x() >= 1.0f || a.x() <= -1.0f)
        layerReset();
}
