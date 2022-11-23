#include "task.h"
#include "ui_task.h"

Task::Task(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);
}

Task::~Task()
{
    delete ui;
}

void Task::on_add_new_employee_2_clicked()
{
    Verifcin = new verifcin(this);
    Verifcin->show();
}

void Task::on_add_new_employee_clicked()
{
    hide();
}

void Task::on_add_new_employee_3_clicked()
{
    todoja = new Todoja(this);
    todoja->show();
}
