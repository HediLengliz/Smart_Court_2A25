#include "aa.h"
#include "ui_aa.h"
#include "aj.h"
#include <QMessageBox>
AA::AA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AA)
{
    ui->setupUi(this);
}

AA::~AA()
{
    delete ui;
}

void AA::on_pb_ajouter_clicked()
{
    int id=ui->le_id->text().toInt();
     QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    int numero=ui->le_numero->text().toInt();
    QString etat=ui->le_etat->text();
    Aj a(id,nom,prenom,numero,etat);
  if (a.ajouter())  QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("AJOUT successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


else
    QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("AJOUT failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);



}
