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
        return query.exec();
    }
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
            break;
        case 3:
            query.prepare("UPDATE OBJECTIVE SET STATE = 'Undone' where ID_OBJ = :ID_OBJ");
            query.bindValue(":ID_OBJ",id);
            break;
        case 4:
            query.prepare("UPDATE OBJECTIVE SET STATE = 'Doing' where ID_OBJ = :ID_OBJ");
            query.bindValue(":ID_OBJ",id);
            break;
    }
    query.exec();
}

bool Objective::verifdate(QString id)
{
    QSqlQuery query;
    QDate D,d;
    query.prepare("SELECT DEADLINE from OBJECTIVE where ID_OBJ = :ID_OBJ");
    query.bindValue(":ID_OBJ",id);
    if (query.exec())
    {
        while(query.next())
            D = query.value(0).toDate();
        if (D < d.currentDate())
            return true;
        else
            return false;
    }
    else
        return false;
}

bool Objective::del(QString id)
{
        QSqlQuery query;
        query.prepare("Delete from OBJECTIVE where ID_OBJ=:ID_OBJ");
        query.bindValue(":ID_OBJ",id);
        return query.exec();
}

QSqlQueryModel* Objective::objemployee(QString cin)
{
        QSqlQuery query;
        QSqlQueryModel* model = new QSqlQueryModel();
        query.prepare("SELECT CIN, DESCR, STATE, ID_ROOM, DEADLINE FROM OBJECTIVE where CIN=:CIN");
        query.bindValue(":CIN",cin);
        if (query.exec())
        {
                model->setQuery(query);
                model->setHeaderData(0, Qt::Horizontal, QObject::tr("CIN"));
                model->setHeaderData(1, Qt::Horizontal, QObject::tr("DESCR"));
                model->setHeaderData(2, Qt::Horizontal, QObject::tr("STATE"));
                model->setHeaderData(3, Qt::Horizontal, QObject::tr("ID_ROOM"));
                model->setHeaderData(4, Qt::Horizontal, QObject::tr("DEADLINE"));
                return model;
        }
        else
            return model;
}

bool Objective::verifemp(int cin)
{
    QSqlQuery query;
    int row_count = 0;
    query.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN");
    query.bindValue(":CIN",cin);
    if (query.exec())
    {
        while(query.next() && row_count != 1)
             row_count++;
        if(row_count != 0)
            return true;
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("ERROR"),
                        QObject::tr("This employee has not tasks.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
            return false;
        }
    }
    else
        return false;
}

void Objective::stat(int* sum,float* fin,float* unfin,float* doi,float* tod,QString cin)
{
    QSqlQuery querys;
    int cf;
    querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN");
    querys.bindValue(":CIN",cin);
    querys.exec();
    *sum = 0;
    while(querys.next())
         (*sum)++;
    querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Done'");
    querys.bindValue(":CIN",cin);
    querys.exec();
    cf = 0;
    while(querys.next())
         cf++;
    *fin = (cf * 100)/(*sum);
    querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Undone'");
    querys.bindValue(":CIN",cin);
    querys.exec();
    cf = 0;
    while(querys.next())
         cf++;
    *unfin = (cf * 100)/(*sum);
    querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'Doing'");
    querys.bindValue(":CIN",cin);
    querys.exec();
    cf = 0;
    while(querys.next())
         cf++;
    *doi = (cf * 100)/(*sum);
    querys.prepare("SELECT * FROM OBJECTIVE where CIN=:CIN and STATE = 'To Do'");
    querys.bindValue(":CIN",cin);
    querys.exec();
    cf = 0;
    while(querys.next())
         cf++;
    *tod = (cf * 100)/(*sum);
}
