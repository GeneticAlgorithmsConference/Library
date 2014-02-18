#include "mainwindow.h"

#include <QApplication>

Parser<double> minSearchParser;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    
    return a.exec();
}
