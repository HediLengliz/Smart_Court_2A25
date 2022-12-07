#include "accuse.h"
#include <QString>
#include <QSqlQuery>
#include <QDebug>
#include <QDate>
#include <QString>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlRecord>
//Test Git
Accuse::Accuse()
{
  id=0;
  name="";
  lastname="";
  gender="";
  Date_B.toString("mm/dd/yyyy");
  acc_cause="";
  Date_S.toString("mm/dd/yyyy");


}

Accuse::Accuse(int id,QString name,QString lastname,QString gender,QDate Date_B,QString acc_cause,QDate Date_S)
{

    this->id=id;
    this->name=name;
    this->lastname=lastname;
    this->gender=gender;
    this->Date_B=Date_B;
    this->acc_cause=acc_cause;
    this->Date_S=Date_S;


}


int Accuse::getid()
{

    return id;

}


QString Accuse:: getname()
{

    return name;

}


QString Accuse::getlastname()
{
    return lastname;

}


QString Accuse::getAcs()
{

    return acc_cause;
}


QString Accuse::getGnd()
{

    return gender;
}

QDate Accuse::getDate_B()
{

    return Date_B;
}

QDate Accuse::getDate_S()
{

    return Date_S;
}

void Accuse::setid(int id)
{
    this->id=id;
}


void Accuse::setname(QString name)
{

    this->name=name;
}


void Accuse::setlastname(QString lastname)
{

    this->lastname=lastname;

}


void Accuse::setAcs(QString acc_cause)
{

    this->acc_cause=acc_cause;
}

void Accuse::setDate_B(QDate Date_B)
{

    this->Date_B=Date_B;
}

void Accuse::setDate_S(QDate Date_S)
{

    this->Date_S=Date_S;
}

void Accuse::setGender(QString gender)
{

  this->gender=gender;

}


bool Accuse::Ajouter()
{


    QSqlQuery query;
    QString id_string=QString::number(id);


          query.prepare("INSERT INTO accuse (id, name, lastname, gender, Date_B, acc_cause, Date_S) "
                        "VALUES (:id, :name, :lastname, :gender, :Date_B, :acc_cause, :Date_S)");
          query.bindValue(":id", id_string);
          query.bindValue(":name", name);
          query.bindValue(":lastname", lastname);
          query.bindValue(":gender", gender);
          query.bindValue(":Date_B", Date_B);
          query.bindValue(":acc_cause", acc_cause);
          query.bindValue(":Date_S", Date_S);
         return query.exec();


}

bool Accuse::supprimer(int id)
{QSqlQuery query;

    //QString res=QString::number(id);

    query.prepare("Delete from ACCUSE where id= :ID ");
    query.bindValue(":ID",id);

    return query.exec();

}

QSqlQueryModel* Accuse::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM accuse");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lastname"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("Date Of Birth"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("Accusation Cause"));
          model->setHeaderData(5, Qt::Horizontal, QObject::tr("Gender"));
          model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Of Session"));


    return model;

}


bool Accuse::modifier( int id,QString name,QString lastname,QString gender,QDate Date_B,QString acc_cause,QDate Date_S)
{
QSqlQuery query;

QString id_string=QString::number(id);

    query.prepare(" UPDATE ACCUSE set id=:id ,name=:name ,lastname=:lastname, gender=:gender , Date_B=:Date_B, acc_cause=:acc_cause, Date_S=:Date_S  where id=:id");
    query.bindValue(":id",id_string);
    query.bindValue(":name",name);
    query.bindValue(":lastname",lastname);
    query.bindValue(":gender",gender);
    query.bindValue(":Date_B",Date_B);
    query.bindValue(":acc_cause",acc_cause);
    query.bindValue(":Date_S",Date_S);



    return query.exec();
}

QSqlQueryModel * Accuse::recherche(int id)
 {
     QSqlQuery query;
     query.prepare("select * from accuse where id=:id");
     query.bindValue(":id",id);
     query.exec();
     QSqlQueryModel *model= new QSqlQueryModel;
     model->setQuery(query);


    return model;


}


QSqlQueryModel *Accuse:: tri()
{
    QSqlQueryModel *model=new QSqlQueryModel();
    model->setQuery("select * from accuse order by id" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Name"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Lastname"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Gender"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Date Of Birth"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Accusation Cause"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Date Of Session"));
 return model;

}

bool Accuse::rech(int id){



    QSqlQuery q("select * from accuse where  id = "+QString::number(id) );
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
