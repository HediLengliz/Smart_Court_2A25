#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aa.h"
#include"aaa.h"
#include "aaaa.h"
#include"aaaaa.h"
#include "aj.h"
#include "rech.h"
# include "stapd.h"
#include"calan.h"
#include"mail.h"
#include<QPainter>

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

    void on_mod_clicked();

    void on_pushButton_clicked();

    void on_rechercher_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
    void   sendMail();
    void mailSent(QString);
    void browse();

private:
    Ui::MainWindow *ui;
    AA *a;
    aaa *l;
    aaaa *m;
    aaaaa *o;
    RECH *f;
stapd *h;
calan *c;
mail *n;


};

#endif // MAINWINDOW_H
