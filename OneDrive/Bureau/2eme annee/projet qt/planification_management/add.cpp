#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include "room.h"
#include "string"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
#include <QFile>
#include "stdio.h"
#include "notif.h"
#include "QTextStream"
#include <QValidator>
#include <QIntValidator>
using namespace  std;
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
    ui->LRI->setValidator(new QIntValidator(0,99999999,this));
       // ui->LCP->setInputMask("aaaaaaaaaaaaaaaaaaa");
           // ui->LRN->setCursorPosition(0);
            ui->LRT->setInputMask("aaaaaaaaaaaaaaaaaaa");
            ui->LRS->setInputMask("aaaaaaaaaaaaaaaaaaa");


}

add::~add()
{
    delete ui;
}

void add::on_ADD_clicked()
{
    int ID_ROOM = ui->LRI->text().toInt();
    QString ID_ROOMs = ui->LRI->text();
        QString pincode = ui->LCP->text();
        QString number = ui->LRN->text();
        QString room_type = ui->LRT->text();
        QString creation_date = ui->dateEdit->date().toString();
        QString room_state = ui->LRS->text();
        room r(ID_ROOM,pincode,number,room_type,creation_date,room_state);
        cout<<r.getpincode().toInt()<<endl;

        if (r.addroom())
        {
//            QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
//                        QObject::tr("The room has been added successfully.\n"
//                                    "Click OK to exit"), QMessageBox::Ok);
            notif m("Room","Room Added !");
            m.afficher();


            foreach(QLineEdit* le, findChildren<QLineEdit*>()) {
                                       le->clear();}
                                  QFile file("C:/Users/hedi2/OneDrive/Bureau/2eme annee/projet qt/planification_management/logs/historiques.txt");
                                  if(!file.open(QIODevice::WriteOnly | QIODevice::Append | QIODevice::Text))
                                      return;
                                  QTextStream cout(&file);
                                  QString d_info = QDateTime::currentDateTime().toString();
                                  QString message2=" + "+d_info+" A Room has been added by ID : "+ID_ROOMs+"\n";
                                  cout << message2;
            hide();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Failed"),
                        QObject::tr("The room couldn't be added."
                                    "Click Cancel to verify."), QMessageBox::Cancel);
}
