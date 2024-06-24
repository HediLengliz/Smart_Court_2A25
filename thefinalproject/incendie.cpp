#include "incendie.h"
#include "ui_incendie.h"
#include <QTimer>
#include <QSerialPort>
#include <QSerialPortInfo>
#include "ui_mainwindow.h"
#include "arduinoS.h"
#include <QMessageBox>
#include <QString>
#include <QtCore>

incendie::incendie(QDialog *parent) :
    QDialog(parent),
    ui(new Ui::incendie)
{
    ui->setupUi(this);

    int ret=As.connect_arduino();
    switch(ret)
    {
    case(0):qDebug()<<"arduino is available and connected to :"<<As.getarduino_port_name();
        break ;
    case(1):qDebug()<<"arduino is available and connected to :"<<As.getarduino_port_name();
        break ;
    case(-1):qDebug()<<"arduino is not available";
    }

    ui->label_1->setText("OFF");

}




incendie::~incendie()
{
    delete ui;
}



int incendie::lire_flamme()
{   int data1=0 ;

    As.write_to_arduino("1") ;
    do
    {
        As.serial->waitForReadyRead() ;
    }
    while(As.serial->bytesAvailable()!=2) ;
    data = As.read_from_arduino();
    QString d = data;
    if ( d == "10" )
    {
    data1 = 1 ;
    }
    else if ( d =="20")
    {data1 =0;}

   return data1 ;

}


void incendie::flamme()
{

{   int  flamme = lire_flamme();
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                                     QObject::tr("telcha successful.\n"
                                                 "Click Cancel to exit."), QMessageBox::Cancel);

   if (( flamme == 1 ) && (test==0) )
    {
       As.write_to_arduino("2") ;
       ui->label_1->setText("ON");
       QTime Time  =QTime::currentTime() ;
       Date1 = Time.toString("H:m:s a") ;
       test=1 ;

    }

   else if ((flamme == 0  ) && (test==1) )
    {
       As.write_to_arduino("3") ;
       QTime Time  =QTime::currentTime() ;
       Date2 = Time.toString("H:m:s a") ;
       ui->label_1->setText("OFF");

       ajouter() ;
       ui->tableView_date->setModel(afficher());


       test=0 ;

    }
}
}


void incendie::on_commencer_clicked()
{

    QTimer *timer = new QTimer(this) ;
    connect(timer,SIGNAL(timeout()),this,SLOT(flamme()) ) ;
    timer->start(500);


}



bool incendie::ajouter()
{

    QSqlQuery query;

    query.prepare("insert into incendie (DATE_INCENDIE, DATE_ARRET ) values (:DATE_ACTIVATION, :DATE_ARRET)" );
    query.bindValue(":DATE_ACTIVATION", Date1);
    query.bindValue(":DATE_ARRET", Date2);

    return query.exec();

};

QSqlQueryModel * incendie:: afficher()
{

    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from incendie" );
    return model;
};



bool incendie::supprimerTout()
{
    QSqlQuery query;

    query.prepare("delete from incendie ");

    return query.exec();

}




void incendie::on_supprimer_date_clicked()
{
    supprimerTout() ;
    ui->tableView_date->setModel(afficher());
}

