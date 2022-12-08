#ifndef AJ_H
#define AJ_H
#include <QString>
#include <QSqlQueryModel>
#include <QTableView>
#include <QPdfWriter>
#include <QPainter>
#include <QCalendarWidget>
#include <QTextCharFormat>


class Aj
{
public:
    bool  userExists(int matricule) ;
    Aj();
    Aj(int,QString,QString,int,QString,int);
    int getid();
    QString getprenom();
    QString getnom();
    int getnumero();
    QString getetat();
    int getage();
    void setid(int  );
    void setnom(QString );
    void setprenom(QString );
    void setnumero(int );
    void setetat(QString );
    void setage(int);
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
     bool modifier(int,QString,QString,int,QString,int);
     bool rechid(int );
             QSqlQueryModel* rechercherid(QString );
             bool rechage(int );
                     QSqlQueryModel* rechercherage(QString );
         bool rechno(QString );
     QSqlQueryModel* recherchernom(QString );
     QSqlQueryModel * tri_agedecroissant();
          QSqlQueryModel * tri_agecroissant();
            QSqlQueryModel * tri_nomcroissant();
            QSqlQueryModel * tri_nomdecroissant();
            void  telechargerPDF();
void calendrier(QTextCharFormat f,QCalendarWidget * w);
bool chercher(int);

   QSqlQueryModel* affiche();


private:
    int id,numero,age;
    QString nom,prenom,etat;


};

#endif // AJ_H
