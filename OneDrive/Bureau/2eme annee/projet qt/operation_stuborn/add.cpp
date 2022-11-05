#include "add.h"
#include "ui_add.h"
#include <QMessageBox>
#include "room.h"

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
        int pincode = ui->LCP->text().toInt();
        int number = ui->LRN->text().toInt();
        QString room_type = ui->LRT->text();
        QString creation_date = ui->LCD->text();
        QString room_state = ui->LRS->text();
        room r(ID_ROOM,pincode,number,room_type,creation_date,room_state);
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


