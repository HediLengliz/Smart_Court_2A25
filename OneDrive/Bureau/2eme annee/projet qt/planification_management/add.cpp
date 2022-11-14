#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include "room.h"
#include "string"
#include <iostream>
#include "stdlib.h"
#include "stdio.h"
using namespace  std;
add::add(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::add)
{
    ui->setupUi(this);
}

add::~add()
{
    delete ui;
}

void add::on_ADD_clicked()
{
   int ID_ROOM = ui->LRI->text().toInt();
        QString pincode = ui->LCP->text();
        QString number = ui->LRN->text();
        QString room_type = ui->LRT->text();
        QString creation_date = ui->dateEdit->date().toString();
        QString room_state = ui->LRS->text();
        room r(ID_ROOM,pincode,number,room_type,creation_date,room_state);
        cout<<r.getpincode().toInt()<<endl;

        if (r.addroom())
        {
            QMessageBox::information(nullptr, QObject::tr("SUCCESS"),
                        QObject::tr("The room has been added successfully.\n"
                                    "Click OK to exit"), QMessageBox::Ok);
            hide();
        }
        else
            QMessageBox::critical(nullptr, QObject::tr("Failed"),
                        QObject::tr("The room couldn't be added."
                                    "Click Cancel to verify."), QMessageBox::Cancel);
}
