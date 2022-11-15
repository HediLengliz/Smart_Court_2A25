#include "delete.h"
#include "ui_delete.h"
#include "accuse.h"
#include <QLineEdit>
#include <QMessageBox>
#include "accuse.h"
#include "consult.h"
#include <QIntValidator>
//Test Git
Delete::Delete(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Delete)
{
    ui->setupUi(this);
    ui->Lsupp->setValidator(new QIntValidator(0,99999999,this));

}

Delete::~Delete()
{
    delete ui;
}

void Delete::on_supp_btn_clicked()
{
QSqlQuery query;
QMessageBox msgBox;


int id=ui->Lsupp->text().toInt();
if(A.rech(id))
{
if(A.supprimer(id))
    {

        QMessageBox::information(nullptr, QObject::tr("database is open"),
                        QObject::tr("Deleted successfully.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}


        else
           { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                        QObject::tr("Delete failed \n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);}
}
else{ QMessageBox::critical(nullptr, QObject::tr("Not found"),
                            QObject::tr("Not found \n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);}



}
