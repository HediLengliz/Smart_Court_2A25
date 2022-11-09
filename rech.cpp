#include "rech.h"
#include "ui_rech.h"
#include "aj.h"
#include <QMessageBox>


RECH::RECH(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RECH)
{
    ui->setupUi(this);
}

RECH::~RECH()
{
    delete ui;
}


void RECH::on_rech_clicked()
{

        Aj p;
        QString choix=ui->comboBox_chercher->currentText();

        if (choix=="id")
        {
            QString id = ui->lineEdit_rech->text();

            bool test=p.rechercherid(id);
                if(test)

                  {  QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("CHERCHER successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}


                   else
                      { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                   QObject::tr("CHERCHER failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}
                ui->tableView_2->setModel(p.rechercherid(id));

        }
        if (choix=="nom")
        {
            QString nom = ui->lineEdit_rech->text();

            bool test=p.recherchernom(nom);
                if(test)

                   { QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("CHERCHER successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}


                   else
                      { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                   QObject::tr("CHERCHER failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}
                ui->tableView_2->setModel(p.recherchernom(nom));
        }
        if (choix=="age")
        {
            QString age = ui->lineEdit_rech->text();

            bool test=p.rechercherage(age);
                if(test)

                {QMessageBox::information(nullptr, QObject::tr("database is open"),
                                   QObject::tr("CHERCHER successful.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel);}


                   else
                      { QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                                   QObject::tr("CHERCHER failed.\n"
                                               "Click Cancel to exit."), QMessageBox::Cancel); }
                ui->tableView_2->setModel(p.rechercherage(age));
        }




    }


