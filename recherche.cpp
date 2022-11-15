#include "recherche.h"
#include "ui_recherche.h"
#include <QIntValidator>
#include <QValidator>
#include <QMessageBox>

Recherche::Recherche(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Recherche)
{

    //ui->Lid_rech->setValidator(new QIntValidator(0,99999999,this));
    ui->setupUi(this);
}

Recherche::~Recherche()
{
    delete ui;
}


void Recherche::on_getsrch_clicked()
{QMessageBox msgBox;

    int id=ui->Lid_rech->text().toInt();
  QSqlQueryModel *verif=A.recherche(id);
  if(A.rech(id))
    {           if (verif!=nullptr)
               {
                   ui->tablerech->setModel(verif);
               }
    }
               else
               {QMessageBox::critical(nullptr, QObject::tr("Not found ID"),
                                               QObject::tr("Not found ID \n"
                                                           "Click Cancel to exit."), QMessageBox::Cancel);}
}
