#ifndef OBJECTIVE_H
#define OBJECTIVE_H
#include <QString>
#include <QDate>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QMessageBox>

class Objective
{
public:
    Objective();
    Objective(int idobj,int cin,QString Desc,QString Idroom,QDate D);
    bool ajouter();
    QSqlQueryModel* afficher();
    void modifydone(QString id, int n);
    bool verifdate(QString id);
    bool del(QString id);
    QSqlQueryModel* objemployee(QString cin);
    bool verifemp(int cin);
    void stat(int* sum,float* fin,float* unfin,float* doi,float* tod,QString cin);
private:
    int ID_OBJ,CIN;
    QString DESC,STATE,ID_ROOM;
    QDate DEADLINE;
};

#endif // OBJECTIVE_H
