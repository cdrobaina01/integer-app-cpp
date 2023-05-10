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

    Integer num1(123);
    Integer num2(32);
    num1.SetMultiplyMethod(1);
    num2.SetMultiplyMethod(1);

    Integer num3(num1+num2); // Resultado esperado 28
    Integer num4(num1-num2); // Resultado esperado 20
    int num5 = num1 * num2; // Resultado esparado 3936

    cout << "La suma de los dos numeros es: " << num3.Get() << endl;
    cout << "La diferencia de los dos numeros es: " << num4.Get() << endl;
    cout << "La multiplicación de los 2 numero es: " << num5 << endl;

    return 0;
}
