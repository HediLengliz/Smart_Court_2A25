#include "modify.h"
#include "ui_modify.h"

Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_update_clicked()
{
    int cin = ui->MCin ->text().toInt();
    QString email = ui-> MEMAIL ->text();
    Employee E(cin,email);
    if (E.modifier())
    {
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been added successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be added.\nMake sure that : \n1- CIN and E-MAIL hasn't been used before\n2- E-MAIL is written like \"AA@aa.xx\"\nReport it if there is any error\n"
                                "Click Cancel to verify."), QMessageBox::Cancel);
}
