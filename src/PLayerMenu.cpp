#include "PLayerMenu.h"
#include "PPlayer.h"
#include <QPainter>

PLayerMenu::PLayerMenu()
{
    QList<PObject*> arr;

    QVector<GLfloat> sharpe = {
        -0.25f, -0.1f, 1.0f,
        0.25f, -0.1f, 1.0f,
        0.25f, 0.1f, 1.0f,
        -0.25f, 0.1f, 1.0f,
    };

//    QVector<GLfloat> sharpe = {
//        -0.01f, -0.2f, 1.0f,
//        0.01f, -0.2f, 1.0f,
//        0.01f, 0.2f, 1.0f,
//        -0.01f, 0.2f, 1.0f,
//    };

//    QVector<GLint> fragment = {
//        0,1,2,
//        0,2,3
//    };

    PObject* item1 = new PObject();
    item1->setShape(sharpe);
//    menu1->setFragment(fragment);
    item1->setTypePrint(GL_LINE_LOOP);
    item1->setPosition(QVector3D(0, 0.2f, 0));
//    item1->setColor(QColor(150, 120, 20, 255));
    item1->setSelect(true);
    arr.append(item1);


//    PObject* menu2 = new PObject();
//    menu2->setShape(sharpe);
//    menu2->setFragment(fragment);
//    menu2->setTypePrint(GL_LINE_LOOP);
//    menu2->setPosition(QVector3D(0, -0.05f, 0));
//    arr.append(menu2);

    PObject* item3 = new PObject();
    item3->setShape(sharpe);
//    menu3->setFragment(fragment);
    item3->setTypePrint(GL_LINE_LOOP);
    item3->setPosition(QVector3D(0, -0.3f, 0));
//    item3->setColor(QColor(255, 120, 20, 255));
    //item3->setSelect(false);
    arr.append(item3);


    setElements(arr);

    setColorBackground(QVector3D(0.2f, 0.3f, 0.3f));
}

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

//    paint->restore();
//    paint->scale(1.5, 1.5);
    paint->drawText(165, 175, "Exit");

    paint->end();
}
