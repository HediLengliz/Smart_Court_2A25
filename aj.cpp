#include "aj.h"
#include <QSqlQuery>
#include <QDebug>
#include<QObject>
    Aj::Aj()
    {id =0;
        nom=" ";
        prenom=" ";
        numero=0;
        etat=" ";
    }
    Aj::Aj(int id ,QString nom , QString prenom ,int numero , QString etat)
    { this->id=id ;  this->nom=nom ; this->prenom=prenom ; this->numero=numero ; this->etat=etat ;}
    int Aj::getid(){return id ;}
    QString Aj:: getprenom( ){return prenom;}
    QString Aj:: getnom(){return nom;}
    int Aj::getnumero(){return numero;}
    QString Aj::getetat(){return etat;}
    void Aj::setid(int id ){this->id=id ; }
    void Aj::setnom(QString nom){ this->nom=nom ;}
    void Aj::setprenom(QString prenom){this->prenom=prenom ;}
    void Aj::setnumero(int numero){this->numero=numero ;}
    void Aj::setetat(QString etat){this->etat=etat ;}
    bool Aj::ajouter()
   {
                QSqlQuery query;
                QString id_string=QString::number(id);
                  QString num_string=QString::number(numero);
         query.prepare("INSERT INTO Aj (id,nom, prenom, numero,etat) "
                       "VALUES (:id,:surname, :forename,:number,:state )");
         query.bindValue(":id", id_string );
         query.bindValue(":surname", nom);
         query.bindValue(":forename", prenom);
         query.bindValue(":number",num_string );
         query.bindValue(":state", etat);
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

    return model;
}
bool Aj::supprimer(int id)
{
    QSqlQuery query;

query.prepare("delete from  Aj where id=:id");

query.bindValue(":id", id);

return query.exec();


}
bool Aj::modifier(int id,QString nom,QString prenom,int numero,QString etat)
{
    QSqlQuery query;

         QString id_string=QString::number(id);
       QString numero_string= QString::number(numero);
           query.prepare(" UPDATE Aj set id=:id ,nom=:nom,prenom=:prenom, numero=:numero,etat=:etat where id=:id");
           query.bindValue(":id",id_string);
           query.bindValue(":nom",nom);
           query.bindValue(":prenom",prenom);
           query.bindValue(":numero",numero_string);
           query.bindValue(":etat",etat);
   return query.exec();
}
