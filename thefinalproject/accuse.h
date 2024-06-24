#ifndef ACCUSE_H
#define ACCUSE_H
#include <QString>
#include <QDate>
#include <QSqlQueryModel>
#include <QSqlQuery>

//Test Git

class Accuse
{
public:
    Accuse();
    Accuse(int,QString,QString,QString,QDate,QString,QDate);
    int getid();
    QString getname();
    QString getlastname();
    QString getAcs();
    QString getGnd();
   QDate getDate_B();
   QDate getDate_S();
    void setid(int);
    void setname(QString);
    void setlastname(QString);
    void setGender(QString);
    void setAcs(QString);
    void setDate_B(QDate);
    void setDate_S(QDate);
    bool Ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
    bool modifier(int ,QString ,QString ,QString ,QDate ,QString ,QDate);
    QSqlQueryModel * recherche(int );
    QSqlQueryModel * tri();
    bool rech(int id);

private:
    int id;
    QString name,lastname,acc_cause,gender;
    QDate Date_B,Date_S;


};

#endif // ACCUSE_H
