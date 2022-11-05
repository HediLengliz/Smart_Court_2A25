#include "room.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
room::room()
{

}
room::room(int ID,int PIN,int NUM,QString RT,QString CD,QString RS)
{
   ID_ROOM=ID;
   pincode=PIN;
   number=NUM;
   room_type=RT;
   creation_date=CD;
   room_state=RS;


}

   void room::setID_ROOM(int n){ ID_ROOM=n;}
    void room::setpincode(int n){ pincode=n;}
     void room::setnumber(int n){ number=n;}
      void room::setroom_type(QString n){ room_type=n;}
       void room::setcreation_date(QString n){ creation_date=n;}
       void room::setroom_state(QString n){ room_state=n;}

          int room::getID_ROOM(){return ID_ROOM;}
          int room::getpincode(){return pincode;}
          int room::getnumber(){return number;}
          QString room::getroom_type(){return room_type;}
          QString room::getcreation_date(){return creation_date;}
           QString room::getroom_state(){return room_state;}

bool room::addroom()
{

    QSqlQuery query ;
    query.prepare("INSERT INTO ROOMS (ROOM_ID,PIN_CODE,ROOM_NUMBER,ROOM_TYPE,CREATION_DATE,ROOM_STATE)"  "VALUES (:ROOM_ID,:PIN_CODE ,:ROOM_NUMBER, :ROOM_TYPE , :CREATION_DATE, :ROOM_STATE)");
        query.bindValue(":ROOM_ID",ID_ROOM);
        query.bindValue(":PIN_CODE",pincode);
        query.bindValue(":ROOM_NUMBER",number);
        query.bindValue(":ROOM_TYPE",room_type);
        query.bindValue(":CREATION_DATE",creation_date);
        query.bindValue(":ROOM_STATE",room_state);

      return query.exec();
}
QSqlQueryModel* room::displayroom()
{



    QSqlQueryModel* model = new QSqlQueryModel();
              model->setQuery("SELECT * FROM ROOMS");
              model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
              model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
              model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
              model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
              model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
              model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

         return model;
}
bool room::deleteroom(QString ID_ROOM)
{



      QSqlQuery query ;
      query.prepare("Delete from ROOMS where ID_ROOM=:ID_ROOM");
                  query.bindValue(":ID_ROOM",ID_ROOM);
      if(query.exec())
      {
                  return query.exec();
      }
      else return false;







}
