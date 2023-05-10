#include "MainWindow.h"
#include <QApplication>
#include <Integer.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.show();

    return a.exec();
}
