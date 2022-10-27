#include "aaaa.h"
#include "ui_aaaa.h"
#include"aj.h"
#include<QMessageBox>
aaaa::aaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaaa)
{
    ui->setupUi(this);
}

aaaa::~aaaa()
{
    delete ui;
}

void aaaa::on_pb_supp_clicked()
{
   Aj  a1; a1.setid(ui->le_supp->text().toInt());
    bool test=a1.supprimer(a1.getid());
    QMessageBox msgbox;
    if (test)
        msgbox.setText("suppression avec succes");

     else
     msgbox.setText("echec de suppression");

                msgbox.exec();

}
