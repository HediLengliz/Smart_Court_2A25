#ifndef AJ_H
#define AJ_H
#include <QString>
#include<QSqlQueryModel>
class Aj
{
public:
    Aj();
    Aj(int,QString,QString,int,QString);
    int getid();
    QString getprenom();
    QString getnom();
    int getnumero();
    QString getetat();
    void setid(int  );
    void setnom(QString );
    void setprenom(QString );
    void setnumero(int );
    void setetat(QString );
    bool ajouter();
    QSqlQueryModel* afficher();
    bool supprimer(int);
private:
    int id,numero;
    QString nom,prenom,etat;


};

#endif // AJ_H
