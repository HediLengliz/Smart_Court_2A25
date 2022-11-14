#include "room.h"
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
room::room()
{

}
room::room(int ID_ROOM,QString pincode,QString number,QString room_type,QString creation_date,QString room_state)
{
   this->ID_ROOM=ID_ROOM;
   this->pincode=pincode;
   this->number=number;
   this->room_type=room_type;
   this->creation_date=creation_date;
   this->room_state=room_state;


}

   void room::setID_ROOM(int n){ ID_ROOM=n;}
    void room::setpincode(QString n){ pincode=n;}
     void room::setnumber(QString n){ number=n;}
      void room::setroom_type(QString n){ room_type=n;}
       void room::setcreation_date(QString n){ creation_date=n;}
       void room::setroom_state(QString n){ room_state=n;}

          int room::getID_ROOM(){return ID_ROOM;}
          QString room::getpincode(){return pincode;}
          QString room::getnumber(){return number;}
          QString room::getroom_type(){return room_type;}
          QString room::getcreation_date(){return creation_date;}
           QString room::getroom_state(){return room_state;}

bool room::addroom()
{

    QSqlQuery query ;
    query.prepare("INSERT INTO ROOMS (ID_ROOM,PIN_CODE,ROOM_NUMBER,ROOM_TYPE,CREATION_DATE,ROOM_STATE)"  "VALUES (:ID_ROOM,:PIN_CODE ,:ROOM_NUMBER, :ROOM_TYPE , :CREATION_DATE, :ROOM_STATE)");
        query.bindValue(":ID_ROOM",ID_ROOM);
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
bool room::deleteroom(int ID_ROOM)
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
bool room::modifyroom(int ID_ROOM,QString pincode,QString number,QString room_type,QString creation_date,QString room_state)
{

    QSqlQuery query;
    query.prepare("UPDATE ROOMS SET PIN_CODE= :pincode,ROOM_NUMBER = :number,ROOM_TYPE= :room_type,CREATION_DATE = :creation_date,ROOM_STATE = :room_state WHERE ID_ROOM= :ID_ROOM ");
    query.bindValue(":ID_ROOM",ID_ROOM);
    query.bindValue(":pincode",pincode);
    query.bindValue(":number",number);
    query.bindValue(":room_type",room_type);
    query.bindValue(":creation_date",creation_date);
    query.bindValue(":room_state",room_state);
    return    query.exec();


}
QStringList room::search_id(){
    QSqlQuery query;
    query.prepare("select * from ROOMS");
    query.exec();
    QStringList list;
    while(query.next()){
        list.append(query.value(0).toString());
    }

    return list;

}
QSqlQueryModel * room::SEARCH(QString a)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("SELECT * FROM ROOMS WHERE ID_ROOM like '%"+a+"%' ||'%' OR PIN_CODE like '%"+a+"%' ||'%' OR ROOM_NUMBER like '%"+a+"%' ||'%' OR ROOM_TYPE like '%"+a+"%' OR CREATION_DATE like '%"+a+"%' OR ROOM_STATE like '"+a+"' ||'%' ");
    query.bindValue(":id",a);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("CREATION DATE"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("ROOM STATE"));
    return model;
}
QSqlQueryModel * room:: triID()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by ID_ROOM" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}
QSqlQueryModel * room::triPIN()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by PIN_CODE" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}
QSqlQueryModel * room:: triNUM()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by ROOM_NUMBER" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}


QSqlQueryModel * room ::triTYPE()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by ROOM_TYPE" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}




QSqlQueryModel * room::triDATE()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by CREATION_DATE" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}





QSqlQueryModel * room::triSTATE()
{
    QSqlQueryModel * model=new QSqlQueryModel();
 model->setQuery("select * from ROOMS order by ROOM_STATE" );
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID_ROOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("PIN_CODE"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("ROOM_NUMBER"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("ROOM_TYPE"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("creation_date"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("room_state"));

    return model;
}
//connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
//connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));

