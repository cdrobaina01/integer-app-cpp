#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pshBtnSumar_clicked();

    void on_pshBtnRestar_clicked();

    void on_pshBtnMutiplicar_clicked();

private:
    Ui::MainWindow *ui;

    int* convertirEntero(int, int);
    int seeSize(int);
};

#endif // MAINWINDOW_H
