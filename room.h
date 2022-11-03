#ifndef ROOM_H
#define ROOM_H
#include <QString>
#include <QSqlQueryModel>

class room
{
public:
    room();
    room(int,int,int,QString,QString,QString);

       void setID_ROOM(int n);
        void setpincode(int n);
         void setnumber(int n);
          void setroom_type(QString n);
           void setcreation_date(QString n);
           void setroom_state(QString n);

              int getID_ROOM();
              int getpincode();
              int getnumber();
              QString getroom_type();
              QString getcreation_date();
               QString getroom_state();

                            bool addroom();
                            QSqlQueryModel* displayroom();
                            bool deleteroom(QString ID_ROOM);
                            bool modifyroom();


private:
        int ID_ROOM,pincode,number;
        QString room_type,creation_date,room_state;
};

#endif // ROOM_H

