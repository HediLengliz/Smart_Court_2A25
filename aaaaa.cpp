#include "aaaaa.h"
#include "ui_aaaaa.h"
#include"aj.h"

#include <QMessageBox>

aaaaa::aaaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaaaa)
{
    ui->setupUi(this);
}

aaaaa::~aaaaa()
{
    delete ui;
}



void aaaaa::on_MODIFIER_clicked()
{

    int id=ui->le_id->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numero=ui->le_num->text().toInt();
    QString etat=ui->le_etat->text();

        Aj C(id,nom,prenom,numero,etat);
        bool test=C.modifier(id,nom,prenom,numero,etat);
            if(test)

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("MODIFIER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("MODIFIER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


}
