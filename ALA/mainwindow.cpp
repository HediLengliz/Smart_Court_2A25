#include "mainwindow.h"
#include "ui_mainwindow.h"

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

void MainWindow::on_ADD_PUSH_clicked()
{
    add = new Add(this);
    add->show();
}

void MainWindow::on_LIST_PUSH_clicked()
{
    aff = new Aff(this);
    aff->show();
}

void MainWindow::on_DEL_PUSH_clicked()
{
    supp = new Supp(this);
    supp->show();
}

void MainWindow::on_MOD_PUSH_clicked()
{
    mod = new Modify(this);
    mod->show();
}

void MainWindow::on_SORT_PUSH_clicked()
{
    sorting = new Sorting(this);
    sorting->show();
}

void MainWindow::on_SEARCH_PUSH_clicked()
{
    Searchpdf = new searchpdf(this);
    Searchpdf->show();
}

void MainWindow::on_TODOLIST_clicked()
{
    Verifcin = new verifcin(this);
    Verifcin->show();
}
