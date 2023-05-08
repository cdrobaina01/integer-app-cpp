#include "MainWindow.h"
#include <QApplication>
#include <Integer.h>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    /*QApplication a(argc, argv);
    MainWindow w;
    w.show();

    return a.exec();*/


    //Prueba
    int array1[4] = {4,3,9}; // 934
    int array2[2] = {7,6};   //  67
                             //1001
    Integer num1(array1, sizeof(array1)/sizeof(int));
    Integer num2(array2, sizeof(array2)/sizeof(int));

    Integer num3(num1+num2);

    cout << "La suma de los dos numeros es:" << num3.Get() << endl;

    return 0;
}
