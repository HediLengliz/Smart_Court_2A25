#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aa.h"
#include"aaa.h"
#include "aaaa.h"
#include "aj.h"
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
   // void on_Qframe_clicked();

    //void on_push_clicked();

    void on_hiiii_clicked();

    void on_hkkk_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainWindow *ui;
    AA *a;
    aaa *l;
    aaaa *m;

};

#endif // MAINWINDOW_H
