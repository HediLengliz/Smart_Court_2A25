#include "searchpdf.h"
#include "ui_searchpdf.h"

searchpdf::searchpdf(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::searchpdf)
{
    ui->setupUi(this);
    n = 0;
}

searchpdf::~searchpdf()
{
    delete ui;
}

void searchpdf::on_MAX_clicked()
{
    n = 1;
    ui->TabAff->setModel(E.search(n,0,""));
}

void searchpdf::on_PDF_clicked()
{
    if (n!=0)
    {
        E.pdf();
        QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                    QObject::tr("The employee has been printed in a pdf file successfully.\n"
                                "Click OK to exit"), QMessageBox::Ok);
    }
    else
        QMessageBox::information(nullptr, QObject::tr("ERROR"),
                    QObject::tr("You should search for an employee to be printed in a pdf file.\n"
                                "Click OK to exit"), QMessageBox::Ok);
}

void searchpdf::on_SCIN_clicked()
{
    n = 2;
    int cin = ui->LCin->text().toInt();
    ui->TabAff->setModel(E.search(n,cin,""));
}

void searchpdf::on_SEMAIL_clicked()
{
    n = 3;
    QString email = ui->LEmail->text();
    ui->TabAff->setModel(E.search(n,0,email));
}

void searchpdf::on_add_new_employee_clicked()
{
    hide();
}
