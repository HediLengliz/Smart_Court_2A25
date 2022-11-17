#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"
#include "his.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ADD_PUSH_clicked()
{
    Add=new add(this);
    Add->show();
}


void MainWindow::on_DELL_PUSH_clicked()
{
    Dell=new dell(this);
    Dell->show();
}

void MainWindow::on_DISPLAY_PUSH_clicked()
{
    Display=new display(this);
    Display->show();
}



void MainWindow::on_MOD_PUSH_clicked()
{
    mod=new Modify(this);
    mod->show();



}


void MainWindow::on_DISPLAY_PUSH_2_clicked()
{
    His=new his(this);
    His->show();
    his m;
    m.readfile();

}

void MainWindow::on_EMAIL_clicked()
{
    Email=new email(this);
    Email->show();
}




void MainWindow::on_STAT_clicked()
{
   statis=new Statis(this);
   statis->show();
}
