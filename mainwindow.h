#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "add.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
        void on_ADDROOM_clicked();

private:
    Ui::MainWindow *ui;
    add* Add;
};
