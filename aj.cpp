#include "aj.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>
#include <QString>
#include<QSqlQueryModel>
#include <QSqlTableModel>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include <QSqlTableModel>
#include <QPagedPaintDevice>
#include<QPainter>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QCoreApplication>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include"QSqlRecord"
#include <QSqlError>
#ifndef QT_NO_PRINTER
#endif
    Aj::Aj()
    {id =0;
        nom=" ";
        prenom=" ";
        numero=0;
        etat=" ";
        age=0;  }
    Aj::Aj(int id ,QString nom , QString prenom ,int numero , QString etat,int age)
    { this->id=id ;  this->nom=nom ; this->prenom=prenom ; this->numero=numero ; this->etat=etat,this->age=age ;}
    int Aj::getid(){return id ;}
    QString Aj:: getprenom( ){return prenom;}
    QString Aj:: getnom(){return nom;}
    int Aj::getnumero(){return numero;}
    QString Aj::getetat(){return etat;}
    int Aj::getage(){return age;}
    void Aj::setid(int id ){this->id=id ; }
    void Aj::setnom(QString nom){ this->nom=nom ;}
    void Aj::setprenom(QString prenom){this->prenom=prenom ;}
    void Aj::setnumero(int numero){this->numero=numero ;}
    void Aj::setetat(QString etat){this->etat=etat ;}
    void Aj::setage(int age){this->age=age;}
    bool Aj::ajouter()
   {
        if(userExists(id)){return false;}

                QSqlQuery query;
                QString id_string=QString::number(id);
                  QString num_string=QString::number(numero);
                   QString age_string=QString::number(age);
         query.prepare("INSERT INTO Aj (id,nom, prenom, numero,etat,age) "
                       "VALUES (:id,:surname, :forename,:number,:state,:age )");
         query.bindValue(":id", id_string );
         query.bindValue(":surname", nom);
         query.bindValue(":forename", prenom);
         query.bindValue(":number",num_string );
         query.bindValue(":state", etat);
         query.bindValue(":age",age_string );

        return query.exec();

    }

QSqlQueryModel* Aj::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

        model->setQuery("SELECT* FROM Aj");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id "));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(3, Qt::Horizontal, QObject::tr("numero"));
       model->setHeaderData(4, Qt::Horizontal, QObject::tr("etat"));
       model->setHeaderData(6, Qt::Horizontal, QObject::tr("age"));

    return model;
}
bool Aj::supprimer(int id)
{
    QSqlQuery query;

query.prepare("delete from  Aj where id=:id");

query.bindValue(":id", id);

return query.exec();


}
bool Aj::modifier(int id,QString nom,QString prenom,int numero,QString etat,int age)
{
    QSqlQuery query;
 QString age_string=QString::number(age);
         QString id_string=QString::number(id);
       QString numero_string= QString::number(numero);
           query.prepare(" UPDATE Aj set id=:id ,nom=:nom,prenom=:prenom, numero=:numero,etat=:etat,age=:age where id=:id");
           query.bindValue(":id",id_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":numero",numero_string);
           query.bindValue(":etat",etat);
            query.bindValue(":age",age_string);
   return query.exec();
}
bool Aj::rechid(int x){
    QSqlQuery query;
    query.prepare("select * from Aj where id = :id;");
    query.bindValue(":id", x);
    return query.exec();
}
bool Aj:: userExists(int matricule)
{
    bool exists = false;

    QSqlQuery checkQuery;
    checkQuery.prepare("SELECT * FROM Aj WHERE id = (:matricule)");
    checkQuery.bindValue(":matricule", matricule);

    if (checkQuery.exec())
    {
        if (checkQuery.next())
        {
            exists = true;
        }
    }
    else
    {
        qDebug() << "User not found:" << checkQuery.lastError();
    }

    return exists;
}
QSqlQueryModel* Aj::rechercherid(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Aj where id ='"+a+"' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("age"));
        return model;

}

bool Aj::rechage(int x){
    QSqlQuery query;
    query.prepare("select * from Aj where age = :age;");
    query.bindValue(":age", x);
    return query.exec();
}
QSqlQueryModel* Aj::rechercherage(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Aj where age ='"+a+"' ");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("age"));
        return model;

}

bool Aj::rechno(QString x){
    QSqlQuery query;
    query.prepare("select * from Aj where nom = :nom;");
    query.bindValue(":nom", x);
    return query.exec();
}
QSqlQueryModel* Aj::recherchernom(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from Aj where nom ='"+a+"'");
    model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
      model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
      model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
      model->setHeaderData(6,Qt::Horizontal,QObject::tr("age"));
        return model;

}
QSqlQueryModel * Aj::tri_agecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Aj ORDER BY age ASC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

    return model;
}
QSqlQueryModel * Aj::tri_agedecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Aj ORDER BY age DESC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));
            return model;
}
QSqlQueryModel * Aj::tri_nomcroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Aj ORDER BY age ASC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));

    return model;
}
QSqlQueryModel * Aj::tri_nomdecroissant()
{
    QSqlQueryModel * model= new QSqlQueryModel();

          model->setQuery("SELECT * FROM Aj ORDER BY nom DESC ");
          model->setHeaderData(0,Qt::Horizontal,QObject::tr("id"));
          model->setHeaderData(1,Qt::Horizontal,QObject::tr("nom"));
        model->setHeaderData(2,Qt::Horizontal,QObject::tr("prenom"));
            model->setHeaderData(3,Qt::Horizontal,QObject::tr("numero"));
            model->setHeaderData(4,Qt::Horizontal,QObject::tr("etat"));
            model->setHeaderData(5,Qt::Horizontal,QObject::tr("age"));
            return model;
}

void  Aj::telechargerPDF(){


                     QPdfWriter pdf("C:/Users/HIBA/Desktop/qt pdf/exporter pdf/exporter.pdf");
                     QPainter painter(&pdf);
                    int i = 4000;
                         painter.setPen(Qt::blue);
                         painter.setFont(QFont("Arial", 30));
                         painter.drawText(1100,1200,"GESTION DU services juridiques");
                         painter.setPen(Qt::black);
                         painter.setFont(QFont("Arial",14));
                         painter.drawRect(100,100,7300,2600);
                         painter.drawRect(0,3000,9600,500);
                         painter.setFont(QFont("Arial",11));
                         painter.drawText(200,3300,"id");
                         painter.drawText(1300,3300,"NOM");
                         painter.drawText(2200,3300,"PRENOM");
                         painter.drawText(3200,3300,"numero");
                         painter.drawText(5300,3300,"etat");
                         painter.drawText(6700,3300,"age");

                         QSqlQuery query;
                        // query.prepare("select * from Aj where id='"+val+"'");
                         query.prepare("select * from Aj");
                         query.exec();
                         while (query.next())
                         {
                             painter.drawText(200,i,query.value(0).toString());
                             painter.drawText(1300,i,query.value(1).toString());
                             painter.drawText(2200,i,query.value(2).toString());
                             painter.drawText(3200,i,query.value(3).toString());
                             painter.drawText(5300,i,query.value(4).toString());
                               painter.drawText(6700,i,query.value(6).toString());

                            i = i + 500;
                         }}
void Aj::calendrier(QTextCharFormat f,QCalendarWidget * w)
{
    QDate date;
    QSqlQuery query("SELECT DATE_AUD FROM AUD");
    while (query.next())
    {
        date.setDate(query.value(2).toInt(),query.value(1).toInt(),query.value(0).toInt());
        w->setDateTextFormat(date,f);
    }
    w->setDateTextFormat(date,f);
}

bool Aj::chercher(int id){



    QSqlQuery q("select * from Aj where  id = "+QString::number(id) );
      QSqlRecord rec = q.record();

      qDebug() << "Number of columns: " << rec.count();

      int nameCol = rec.indexOf("id"); // index of the field "name"
      while (q.next()){

          qDebug() << q.value(nameCol).toString();
          QString a= q.value(nameCol).toString();
          if(a!=""){

                return true;

}
}
        return false;  }












QSqlQueryModel* Aj ::affiche()
{
    QSqlQueryModel* model=new QSqlQueryModel();
        model->setQuery("SELECT ROOM_NUMBER from ROOMS");
        model->setHeaderData(0,Qt::Horizontal,QObject::tr("ROOM_NUMBER"));
    return model;
}


