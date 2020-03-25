#include "PLayerMenu.h"
#include "PPlayer.h"
#include <QPainter>
#include "PLayerScene_1.h"

/**
 * @brief PLayerMenu::PLayerMenu
 * @param parent - main object
 */
PLayerMenu::PLayerMenu(QObject *parent)
{
    QList<PObject*> arr;

    QVector<GLfloat> sharpe = {
        -0.25f, -0.1f, 1.0f,
        0.25f, -0.1f, 1.0f,
        0.25f, 0.1f, 1.0f,
        -0.25f, 0.1f, 1.0f,
    };


    PObject* item1 = new PObject();
    item1->setShape(sharpe);
    item1->setTypePrint(GL_LINE_LOOP);
    item1->setPosition(QVector3D(0, 0.2f, 0));
    item1->setSelected(true);
    arr.append(item1);
    connect(item1, SIGNAL(clicked(QObject*)), parent, SLOT(changeLayout(QObject *)));

//    PObject* menu2 = new PObject();
//    menu2->setShape(sharpe);
//    menu2->setFragment(fragment);
//    menu2->setTypePrint(GL_LINE_LOOP);
//    menu2->setPosition(QVector3D(0, -0.05f, 0));
//    arr.append(menu2);

    PObject* item3 = new PObject();
    item3->setShape(sharpe);
    item3->setTypePrint(GL_LINE_LOOP);
    item3->setPosition(QVector3D(0, -0.3f, 0));
    arr.append(item3);

    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}

/**
 * @brief PLayerMenu::drawTextArray
 * @details Rendering text using Qt methods
 * @todo Implement text rendering using OpenGL methods
 * @param paint - Qt Object
 */
void PLayerMenu::drawTextArray(QPainter* paint)
{
    paint->setPen(Qt::white);

    // print Game name
    paint->scale(3, 3);
    paint->drawText(85, 20, "Ping Pong");

    // powered
    paint->restore();
    paint->scale(0.4, 0.4);
    paint->drawText(5, 395, "powered by OrangeMajesty");

    // mwnu elements
    paint->restore();
    paint->scale(1.5, 1.5);
    paint->drawText(165, 110, "Start");

    paint->drawText(165, 175, "Exit");

    paint->end();
}

/**
 * @brief PLayerMenu::keyUpdate
 */
void PLayerMenu::keyUpdate()
{
    auto elements = getElements();
    auto keys = getKeyPressed();

    for(int index = 0; index != elements.length(); index++)
    {
        auto el = elements.at(index);
        if(el->getAllowSelect() && el->getSelected())
        {

            if(keys[Qt::Key::Key_Up])
            {
                el->setSelected(false);
                PObject* selectElement = el;

                if(0 <= index-1)
                    selectElement = elements.at(index-1);

                selectElement->setSelected(true);
            } else if(keys[Qt::Key::Key_Down])
            {
                el->setSelected(false);
                PObject* selectElement = el;

                if(elements.length() > index+1)
                    selectElement = elements.at(index+1);

                selectElement->setSelected(true);
            } else if(keys[Qt::Key::Key_Space])
            {
                emit el->clicked(new PLayerScene_1());
            }

        }
    }
}

