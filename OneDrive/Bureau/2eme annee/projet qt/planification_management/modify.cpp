#include "modify.h"
#include "ui_modify.h"
#include <QMessageBox>
#include "room.h"
#include "string"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <QDateTime>
#include "QTextStream"
#include <Qfile>
#include "notif.h"
using namespace  std;
Modify::Modify(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Modify)
{
    ui->setupUi(this);
    room rs;
   ui->comboRoom->clear();
   ui->comboRoom->addItems(rs.search_id());

}

Modify::~Modify()
{
    delete ui;
}

void Modify::on_MOD_2_clicked()
{

    int ID_ROOM = ui->comboRoom->currentText().toInt();
    QString ID_ROOMss = ui->comboRoom->currentText();
    QString pincodee = ui->LCP_m->text();
    QString number = ui->LRN_m->text();
    QString room_type = ui->LRT_m->text();
   QString creation_date = ui->dateEdit_m->date().toString();
    QString room_state = ui->LRS_m->text();
    room r;
         bool test=r.modifyroom(ID_ROOM,pincodee,number,room_type,creation_date,room_state);
//         cout<<"khedmet"<<endl;
         cout<<number.toInt()<<endl;
          if(test)
          {
//              QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
//                          QObject::tr("The room has been Updated successfully!.\n"
//                                      "Click OK to exit"), QMessageBox::Ok);
              notif m("Room","Room modified !");
              m.afficher();

              foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                         le->clear();}
                                    QFile file("C:/Users/hedi2/OneDrive/Bureau/2eme annee/projet qt/planification_management/logs/historiques.txt");
                                    if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                        return;
                                    QTextStream cout(&file);
                                    QString d_info = QDateTime::currentDateTime().toString();
                                    QString message2=" ~ "+d_info+" A Room has been deleted by ID : "+ID_ROOMss+"\n";
                                    cout << message2;
              hide();
          }
          else
              QMessageBox::critical(nullptr, QObject::tr("Failed"),
                          QObject::tr("The room couldn't be Updated!."
                                      "Click Cancel to verify."), QMessageBox::Cancel);
}

void Modify::on_dateEdit_userDateChanged(const QDate &date)
{

}
