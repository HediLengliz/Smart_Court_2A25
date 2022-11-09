#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aj.h"
#include<QPainter>

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





void MainWindow::on_hiiii_clicked()
{
    a= new AA(this);
    a->show();

}


void MainWindow::on_hkkk_clicked()
{
    l= new aaa(this);
    l->show();
}


void MainWindow::on_pushButton_2_clicked()
{
    m= new aaaa(this);
    m->show();
}

void MainWindow::on_mod_clicked()
{
    o= new aaaaa(this);
    o->show();
}




void MainWindow::on_rechercher_clicked()
{
    f= new RECH(this);
    f->show();
}



void MainWindow::on_pushButton_4_clicked()
{
    h= new stapd(this);
    h->show();
}

void MainWindow::on_pushButton_clicked()
{
    c= new calan(this);
    c->show();
}



void MainWindow::on_pushButton_3_clicked()
{
    n= new mail(this);
    n->show();
}
