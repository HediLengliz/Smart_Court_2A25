#include "aaaaa.h"
#include "ui_aaaaa.h"
#include"aj.h"
#include <QIntValidator>
#include <QValidator>
#include <QMessageBox>

aaaaa::aaaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaaaa)
{
    ui->setupUi(this);
    ui->le_id->setValidator(new QIntValidator(0,99999999,this));
    ui->le_nom->setInputMask("aaaaaaaaaaaaaaaaaaa");
            ui->le_nom->setCursorPosition(0);
            ui->le_prenom->setInputMask("aaaaaaaaaaaaaaaaaaa");
                    ui->le_prenom->setCursorPosition(0);
                    ui->le_etat->setInputMask("aaaaaaaaaaaaaaaaaaa");
                            ui->le_etat->setCursorPosition(0);
                            ui->le_num->setValidator(new QIntValidator(0,99999999,this));
                            ui->le_age->setValidator(new QIntValidator(0,99999999,this));
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
     int age=ui->le_age->text().toInt();

        Aj C(id,nom,prenom,numero,etat,age);
        bool test=C.modifier(id,nom,prenom,numero,etat,age);
            if(test)

                QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("MODIFIER successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


               else
                   QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                               QObject::tr("MODIFIER failed.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);


}
