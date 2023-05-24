#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Integer.h"

#include <iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lNumR->setText("0");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pshBtnSumar_clicked()
{
    Integer num1(ui->tNum1->text().toInt());
    Integer num2(ui->tNum2->text().toInt());
    Integer result = num1 + num2;
    ui->lNumR->setText(QString::number(result.Get()));
}

void MainWindow::on_pshBtnRestar_clicked()
{
    Integer num1(ui->tNum1->text().toInt());
    Integer num2(ui->tNum2->text().toInt());
    Integer result = num1 - num2;
    ui->lNumR->setText(QString::number(result.Get()));
}


void MainWindow::on_pshBtnMutiplicar_clicked()
{
    Integer num1(ui->tNum1->text().toInt());
    Integer num2(ui->tNum2->text().toInt());

    Integer::SetMultiplyMethod(false);
    Integer result = num1 * num2;

    ui->lNumR->setText(QString::number(result.Get()));

    QString normal = "Método Tradicional: ";
    normal += QString::number(result.Get());
    normal += "\n";
    normal += "Tiempo invertido: ";

    Integer::SetMultiplyMethod(true);
    result = num1 * num2;

    QString karatsuba = "\nMétodo de Karatsuba: ";
    karatsuba += QString::number(result.Get());
    karatsuba += "\n";
    karatsuba += "Tiempo invertido: ";

    QString message = normal + karatsuba;
    QMessageBox::information(this, "Comparación métodos de multiplión", message);
}

int* MainWindow::convertirEntero(int n, int s)
{
    int *integer = new int[s];
    int i = 0;

    while (n != 0) {
        integer[i] = n % 10;
        n /= 10;
        i++;
    }

    return integer;
}

int MainWindow::seeSize(int n)
{
    int i;

    for (i = 0; n != 0; i++) {
        n /= 10;
    }

    return i;
}
