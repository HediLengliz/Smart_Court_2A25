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
private:
    int ID_OBJ,CIN;
    QString DESC,STATE,ID_ROOM;
    QDate DEADLINE;
};

#endif // OBJECTIVE_H
