#include "supp.h"
#include "ui_supp.h"

Supp::Supp(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Supp)
{
    ui->setupUi(this);
}

Supp::~Supp()
{
    delete ui;
}

void Supp::on_add_new_employee_clicked()
{
    Employee E;
    E.setcin(ui->SCin->text().toInt());
    if (E.supprimer(E.getcin()))
    {
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been deleted successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
        hide();
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Failed"),
                    QObject::tr("The employee couldn't be deleted.\nVerify the CIN Number if it exists or not.\nReport if there is any error.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
}

void Supp::on_EXIT_clicked()
{
    hide();
}
