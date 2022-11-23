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
    QSqlQueryModel *model;
    model = new QSqlQueryModel();
    Employee E(cin,email);
    if (E.modifier(model))
    {
        ui->TabAff->setModel(model);
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been mmodified successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be modified.\nMake sure that : \n1- CIN and E-MAIL exists \n2- E-MAIL is written like \"AA@aa.xx\"\nReport it if there is any error\n"
                                "Click Cancel to verify."), QMessageBox::Cancel);
}
