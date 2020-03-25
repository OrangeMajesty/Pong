#include "PongCore.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    PongCore w;
    w.setTitle("Pong game");
    w.resize(640, 480);
    w.show();
    return a.exec();
}
