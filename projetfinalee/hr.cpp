#include "hr.h"
#include "ui_hr.h"

HR::HR(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HR)
{
    ui->setupUi(this);
}

HR::~HR()
{
    delete ui;
}

void HR::on_ADD_PUSH_clicked()
{
    add = new Add(this);
    add->show();
}

void HR::on_LIST_PUSH_clicked()
{
    aff = new Aff(this);
    aff->show();
}

void HR::on_DEL_PUSH_clicked()
{
    supp = new Supp(this);
    supp->show();
}

void HR::on_MOD_PUSH_clicked()
{
    mod = new Modify(this);
    mod->show();
}

void HR::on_SORT_PUSH_clicked()
{
    sorting = new Sorting(this);
    sorting->show();
}

void HR::on_SEARCH_PUSH_clicked()
{
    Searchpdf = new searchpdf(this);
    Searchpdf->show();
}

void HR::on_TODOLIST_clicked()
{
    task = new Task(this);
    task->open();
}
