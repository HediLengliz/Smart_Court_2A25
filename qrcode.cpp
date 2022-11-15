#include "qrcode.h"
#include "ui_qrcode.h"
#include "mainwindow.h"
#include <QPixmap>
#include <QLineEdit>
#include "recherche.h"
#include <QMessageBox>

Qrcode::Qrcode(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Qrcode)
{
    ui->setupUi(this);

}



Qrcode::~Qrcode()
{
    delete ui;
}


void Qrcode::on_GetQR_clicked()
{
    int id=ui->LQR->text().toInt();
  QSqlQueryModel *verif=A.recherche(id);
               if (verif!=nullptr)
               {
                   if(id==2000)
                   {QPixmap pix2000("C:/Users/MAHOX/OneDrive/Desktop/QR/2000.png");
                     ui->tabQr->setPixmap(pix2000);}
                   else
                       if(id==2001)
                       {QPixmap pix2001("C:/Users/MAHOX/OneDrive/Desktop/QR/2001.png");
                           ui->tabQr->setPixmap(pix2001);}
                   else
                   if(id==2002)
                   {QPixmap pix2002("C:/Users/MAHOX/OneDrive/Desktop/QR/2002.png");
                       ui->tabQr->setPixmap(pix2002);}
                   else
                   if(id==2003)
                   {QPixmap pix2003("C:/Users/MAHOX/OneDrive/Desktop/QR/2003.png");
                       ui->tabQr->setPixmap(pix2003);}
                   else
                   if(id==2004)
                   {QPixmap pix2004("C:/Users/MAHOX/OneDrive/Desktop/QR/2004.png");
                       ui->tabQr->setPixmap(pix2004);}
                   else
                   if(id==2005)
                   {QPixmap pix2005("C:/Users/MAHOX/OneDrive/Desktop/QR/2005.png");
                       ui->tabQr->setPixmap(pix2005);}
                   else
                   if(id==2006)
                   {QPixmap pix2006("C:/Users/MAHOX/OneDrive/Desktop/QR/2006.png");
                       ui->tabQr->setPixmap(pix2006);}
                   else
                   if(id==2007)
                   {QPixmap pix2007("C:/Users/MAHOX/OneDrive/Desktop/QR/2007.png");
                       ui->tabQr->setPixmap(pix2007);}
                   else
                   { QMessageBox::information(this, QObject::tr("Not found Accused!"),
                                               QObject::tr("Not found Accused!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}
               }

}
