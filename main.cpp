#include "MainWindow.h"
#include <QApplication>
#include <Integer.h>
#include <iostream>
#include <ctime>
#include <unistd.h>

using namespace std;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setStyle("fusion");
    MainWindow w;
    w.show();

    return a.exec();
/*
    clock_t inicial, final;

    inicial = clock();

    sleep(3);
    for(long i = 0; i < 10000000; i++);

    final = clock();

    cout << "Segundos empleados: " << (double (final - inicial) / CLOCKS_PER_SEC) << endl;

    return 0;
*/
}
