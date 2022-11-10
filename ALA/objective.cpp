#include "objective.h"

Objective::Objective()
{

}

Objective::Objective(int idobj,int cin,QString Desc,QString Idroom,QDate D)
{
    ID_OBJ = idobj;
    CIN = cin;
    DESC = Desc;
    STATE = "To Do";
    ID_ROOM = Idroom;
    DEADLINE = D;
}

bool Objective::ajouter()
{
    QSqlQuery query;
    QString cin_string = QString::number(CIN);
    QString idobj_string = QString::number(ID_OBJ);
    QDate D;
    if (DEADLINE >= D.currentDate())
    {    query.prepare("INSERT INTO OBJECTIVE (ID_OBJ ,CIN , DESCR, STATE, ID_ROOM, DEADLINE)"  "VALUES ( :ID_OBJ, :CIN, :DESCR ,:STATE, :ID_ROOM, :DEADLINE)"   );
        query.bindValue(":ID_OBJ",ID_OBJ);
        query.bindValue(":CIN",CIN);
        query.bindValue(":DESCR",DESC);
        query.bindValue(":STATE",STATE);
        query.bindValue(":ID_ROOM",ID_ROOM);
        query.bindValue(":DEADLINE",DEADLINE);
        return query.exec();    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                    QObject::tr("Out Of Date.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        return false;
    }
}

QSqlQueryModel* Objective::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();
          model->setQuery("SELECT ID_OBJ,CIN,DESCR,STATE,DEADLINE FROM OBJECTIVE");
          model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_OBJ"));
          model->setHeaderData(1, Qt::Horizontal, QObject::tr("CIN"));
          model->setHeaderData(2, Qt::Horizontal, QObject::tr("DESCR"));
          model->setHeaderData(3, Qt::Horizontal, QObject::tr("STATE"));
          model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEADLINE"));

    return model;
};

void Objective::modifydone(QString id,int n)
{
    QSqlQuery query;
    switch(n)
    {
        case 1:
            query.prepare("UPDATE OBJECTIVE SET STATE = 'Done' where ID_OBJ = :ID_OBJ");
            query.bindValue(":ID_OBJ",id);
            break;
        case 2:
            query.prepare("UPDATE OBJECTIVE SET STATE = 'To Do' where ID_OBJ = :ID_OBJ");
            query.bindValue(":ID_OBJ",id);
    }
    query.exec();
}
