// main.cpp
#include "mainWindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;  // MainWindow will be the menu
    w.show();
    return a.exec();
}
