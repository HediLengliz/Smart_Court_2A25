#include "aaaa.h"
#include "ui_aaaa.h"
#include"aj.h"
#include<QMessageBox>
#include <QIntValidator>
#include <QValidator>
aaaa::aaaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaaa)
{
    ui->setupUi(this);
    ui->le_supp->setValidator(new QIntValidator(0,99999999,this));

}

aaaa::~aaaa()
{
    delete ui;
}

void aaaa::on_pb_supp_clicked()
{
   Aj  a1;QMessageBox msgbox;
   a1.setid(ui->le_supp->text().toInt());
   if (a1.chercher(a1.getid()))
   { bool test=a1.supprimer(a1.getid());

    if (test)
        msgbox.setText("suppression avec succes");
     else
   msgbox.setText("echec de suppression");}
           else
    { msgbox.setText("id inexistant");}
   msgbox.exec();
}
