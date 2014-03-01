#include <QApplication>

#include "mainmenu.h"

int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    QApplication::setStyle(QStyleFactory::create("Fusion"));
    MainMenu window;
    window.show();
    return app.exec();
}
