#include <QMessageBox>
#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "Integer.h"


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
    int num;
    int size;

    num = ui->tNum1->text().toInt();
    size = seeSize(num);
    Integer num1(convertirEntero(num, size), size);

    num = ui->tNum2->text().toInt();
    size = seeSize(num);
    Integer num2(convertirEntero(num, size), size);

    Integer num3(num1 + num2);
    ui->lNumR->setText(QString::number(num3.Get()));
}

void MainWindow::on_pshBtnRestar_clicked()
{
    int num;
    int size;

    num = ui->tNum1->text().toInt();
    size = seeSize(num);
    Integer num1(convertirEntero(num, size), size);

    num = ui->tNum2->text().toInt();
    size = seeSize(num);
    Integer num2(convertirEntero(num, size), size);

    Integer num3(num1 - num2);
    ui->lNumR->setText(QString::number(num3.Get()));
}


void MainWindow::on_pshBtnMutiplicar_clicked()
{

    /*Integer num1(ui->tNum1->text());
    Integer num2(ui->tNum2->text());
    Integer num3(num1 * num2);
    ui->lNumR->setText(QString::number(num3.Get()));*/
    QMessageBox::information(this, "Comparación métodos de multiplicación", "Método Tradicional: %\nMétodo Karatsuba: %");

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
