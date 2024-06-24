#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QSqlQueryModel>

class room
{
public:
    room();
    room(int,QString,QString,QString,QString,QString);
    room(int);

       void setID_ROOM(int n);
        void setpincode(QString n);
         void setnumber(QString n);
          void setroom_type(QString n);
           void setcreation_date(QString n);
           void setroom_state(QString n);

              int getID_ROOM();
              QString getpincode();
              QString getnumber();
              QString getroom_type();
              QString getcreation_date();
               QString getroom_state();

                            bool addroom();
                            QSqlQueryModel* displayroom();
                            bool deleteroom(int ID_ROOM);
                            bool modifyroom(int ID_ROOM,QString pincode,QString number,QString room_type,QString creation_date,QString room_state);
                            QStringList search_id();
                            QSqlQueryModel * SEARCH(QString);
                            QSqlQueryModel * triID();
                            QSqlQueryModel * triPIN();
                            QSqlQueryModel * triNUM();
                            QSqlQueryModel * triTYPE();
                            QSqlQueryModel * triDATE();
                            QSqlQueryModel * triSTATE();




private:
        int ID_ROOM;
        QString pincode,number,room_type,creation_date,room_state;

};

#endif // ROOM_H
