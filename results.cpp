#include "results.h"
#include "ui_results.h"
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QMessageBox>

results::results(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::results)
{
    ui->setupUi(this);
}

results::~results()
{
    delete ui;
}

void results::on_UPLOAD_clicked()
{
    int id=ui->Lid_save->text().toInt();
    QString RS=ui->L_results->text();
    //QSqlQueryModel *verif=A.recherche(id);
                /* if (verif!=nullptr)
                 {*/
  QFile file("D:/Accuse/Results.txt");
        file.open(QIODevice::Append | QIODevice::Text);
        QTextStream out(&file);
        out << "ID:  "<<id<<"         Result Of session:  "<<RS<<endl;

        // optional, as QFile destructor will already do it:
        file.close();

        QMessageBox::information(this, QObject::tr("Results were sucessfully saved!"),
        QObject::tr("Results were sucessfully saved!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                  //}
                 /*else
                 { QMessageBox::information(this, QObject::tr("Accusé Introuvable!"),
                   QObject::tr("Accusé Introuvable!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
                 }*/
   }



