#include "PEvents.h"
#include <QKeyEvent>

PEvents::PEvents(QObject *parent) : QObject(parent)
{

}

// check event for key handle
void PEvents::check(QKeyEvent *e)
{
    for(int index = 0; index != elements.length(); index++) {
        auto el = elements.at(index);
//        auto sharpe = elements.at(index)->getShape();

//        if(!sharpe.isEmpty()) {

//        }
            if(el->getAllowSelect() && el->getSelect()) {
            switch(e->key()) {
            case Qt::Key::Key_Up:
                qDebug() << "event = " << e->key();
                qDebug() << "index = " << index;
                qDebug() << "el->getSelect() = " << el->getSelect();

                el->setSelect(false);

                PObject* selectElement;
//                for(int selectIndex = index; ;selectIndex++) {
//                    if(elements.length() >= selectIndex+1)
//                        selectElement = elements.at(selectIndex+1);
//                    else
//                        selectElement = elements.first();
//                }

                if(elements.last() == el)
                    selectElement = elements.first();
                else
                    selectElement = elements.at(index+1);

//                selectElement->setSelect(true);
                break;
            }
        }
    }
}

void PEvents::setElements(const QList<PObject *> &value)
{
    elements = value;
}
