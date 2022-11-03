#include "aff.h"
#include "ui_aff.h"

Aff::Aff(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Aff)
{
    ui->setupUi(this);
    ui->TabAff->setModel(E.afficher());
}

Aff::~Aff()
{
    delete ui;
}

void Aff::on_add_new_employee_clicked()
{
    hide();
}
