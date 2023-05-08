#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pshBtnTest_clicked()
{
    Integer integer1(2);
    Integer integer2(1);
    int result = integer1 * integer2;
    ui->lblTest->setText(QString::number(result));
}
