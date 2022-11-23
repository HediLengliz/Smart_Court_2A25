#include "add.h"
#include "ui_add.h"
#include"employee.h"
Add::Add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Add)
{
    ui->setupUi(this);
    ui->LCin->setValidator(new QIntValidator(100,99999999, this));
}

Add::~Add()
{
    delete ui;
}


void Add::on_add_new_employee_clicked()
{
    int cin = ui->LCin->text().toInt();
    int codepin = ui->LCodePin->text().toInt();
    float salary = ui->LSalary->text().toFloat();
    QString nom = ui->LName->text();
    QString prenom = ui->LSurname->text();
    QString email = ui->LEmail->text();
    QString city = ui->LCity->text();
    int ns = ui->LNS->text().toInt();
    Employee E(cin,codepin,salary,nom,prenom,email,city,ns);
    if (E.ajouter())
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
