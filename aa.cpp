#include "aa.h"
#include "ui_aa.h"
#include "aj.h"
#include <QMessageBox>
#include <QIntValidator>
#include <QValidator>
#include <QSqlQuery>
#include "arduino1.h"
AA::AA(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AA)
{
    ui->setupUi(this);

ui->le_id1->setValidator(new QIntValidator(0,99999999,this));
ui->le_nom1->setInputMask("aaaaaaaaaaaaaaaaaaa");
        ui->le_nom1->setCursorPosition(0);
        ui->le_prenom1->setInputMask("aaaaaaaaaaaaaaaaaaa");
                ui->le_prenom1->setCursorPosition(0);
                ui->le_etat1->setInputMask("aaaaaaaaaaaaaaaaaaa");
                        ui->le_etat1->setCursorPosition(0);
                        ui->le_numero1->setValidator(new QIntValidator(0,99999999,this));
                        ui->le_age1->setValidator(new QIntValidator(0,99999999,this));
                        int ret=d.connect_arduino(); // lancer la connexion à arduino

                        switch(ret){
                        case(0):qDebug()<< "arduino is available and connected to : "<< d.getarduino_port_name();
                            break;
                        case(1):qDebug() << "arduino is available but not connected to :" <<d.getarduino_port_name();
                           break;
                        case(-1):qDebug() << "arduino is not available";
                        }

}

AA::~AA()
{
    delete ui;
}

void AA::on_pb_ajouter_clicked()
{
    int id=ui->le_id1->text().toInt();

     QString nom=ui->le_nom1->text();
    QString prenom=ui->le_prenom1->text();
    int numero=ui->le_numero1->text().toInt();
    QString etat=ui->le_etat1->text();
     int age=ui->le_age1->text().toInt();
    Aj a(id,nom,prenom,numero,etat,age);
     QSqlQuery query;
    QByteArray b;
    QString s ;
  if (a.ajouter())
  {
      stat();
      s="welcome " ;
      query.prepare("select NOM from Aj where ID= :ID ") ;
      query.bindValue(":ID",id);
      query.exec() ;
      query.next() ;
      s+=query.value(0).toString() ;
      b= s.toUtf8() ;
      d.write_to_arduino(b);



      QMessageBox::information(nullptr, QObject::tr("database is open"),
                QObject::tr("AJOUT successful.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}



else
  {
      s="deja " ;
      query.prepare("select NOM from Aj where ID= :ID ") ;
      query.bindValue(":ID",id);
      query.exec() ;
      query.next() ;
       s+=query.value(0).toString() ;
      b= s.toUtf8() ;
      d.write_to_arduino(b);

      QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                QObject::tr("AJOUT failed.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);}



}
