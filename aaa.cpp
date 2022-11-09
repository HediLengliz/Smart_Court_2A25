#include "aaa.h"
#include "ui_aaa.h"
#include"aj.h"
#include <QMessageBox>
#include <QDebug>
#include <QSqlQuery>
aaa::aaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaa)
{
    ui->setupUi(this);


}

aaa::~aaa()
{
    delete ui;
}


void aaa::on_aff_clicked()
{
     ui->ta->setModel(a.afficher());
}


void aaa::on_pushButton_trid_clicked()
{
    Aj P;
    QString choix=ui->comboBox_trid->currentText();
    if (choix=="age")
    {
        ui->ta->setModel(P.tri_agedecroissant());


        bool test=P.tri_agedecroissant();//tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri decroissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
             {QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri decroissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
    if (choix=="nom")
    {
        ui->ta->setModel(P.tri_nomdecroissant());
        bool test=P.tri_nomdecroissant();//tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri decroissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
         {   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri decroissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }

}

void aaa::on_pushButton_tri_clicked()
{
    Aj P;
    QString choix=ui->comboBox_tri->currentText();
    if (choix=="age")
    {
        ui->ta->setModel(P.tri_agecroissant());

        bool test=P.tri_agecroissant();// tri produit
        if (test)
        {


            QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);

        }
        else
         {    QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
    if (choix=="nom")
    {
      ui->ta-> setModel(P.tri_nomcroissant());

        bool test=P.tri_nomcroissant();//tri produit
        if (test)
        {


          { QMessageBox::information(nullptr,QObject::tr("ok"),
                                     QObject::tr("tri croissante effectué \n"
                                                 "Click Cancel to exist ."),QMessageBox::Cancel);}


        }
        else
          {   QMessageBox::critical(nullptr, QObject::tr("nonnnn"),
                          QObject::tr("tri croissante failed.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);}

    }
    }
