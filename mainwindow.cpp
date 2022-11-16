#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <dialog.h>
#include "accuse.h"
#include <QIntValidator>
#include <QMessageBox>
#include "consult.h"
#include "modify.h"
#include "qrcode.h"
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
//#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include "statistique.h"

//Test Git

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ADD_ACC_clicked()
{


        d=new Dialog(this);
        d->show();
       // hide();
}


void MainWindow::on_DELETE_ACC_clicked()
{
    dl=new Delete(this);
    dl->show();

   // hide();
}

void MainWindow::on_List_ACC_clicked()
{
    cl=new Consult(this);
    cl->show();

  //  hide();
}


void MainWindow::on_MODIFY_clicked()
{
    mf=new Modify(this);
    mf->show();

    // hide();
}

void MainWindow::on_QrCode_clicked()
{
    qr=new Qrcode(this);
    qr->show();
}


void MainWindow::on_search_clicked()
{
    rch=new Recherche(this);
    rch->show();
}

void MainWindow::on_Sort_clicked()
{
    tr1= new tri(this);
    tr1->show();
}

void MainWindow::on_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/MAHOX/OneDrive/Desktop/Qt Projet/Accuse/Accuse.pdf");

   QPainter painter(&pdf);
   int i = 4000;
          painter.setPen(Qt::blue);
          painter.setFont(QFont("Time New Roman", 25));
          painter.drawText(3000,1400,"Liste Des Accusés");
          painter.setPen(Qt::black);
          painter.setFont(QFont("Time New Roman", 15));
          painter.drawRect(100,100,9400,2500);
          painter.drawRect(100,3000,9400,500);
          painter.setFont(QFont("Time New Roman", 9));
          painter.drawText(400,3300,"ID");
          painter.drawText(1350,3300,"Name");
          painter.drawText(2200,3300,"Last Name");
          painter.drawText(3400,3300,"Gender");
          painter.drawText(4400,3300,"Date of Birth");
          painter.drawText(6200,3300,"Accusation Cause");
          painter.drawText(7600,3300,"Date of Session");
          painter.drawRect(100,3000,9400,9000);

          QSqlQuery query;
          query.prepare("select * from accuse");
          query.exec();
          while (query.next())
          {
              painter.drawText(400,i,query.value(0).toString());
              painter.drawText(1350,i,query.value(1).toString());
              painter.drawText(2300,i,query.value(2).toString());
              painter.drawText(3400,i,query.value(3).toString());
              painter.drawText(4400,i,query.value(4).toString());
              painter.drawText(6200,i,query.value(5).toString());
              painter.drawText(7600,i,query.value(6).toString());



             i = i + 350;
          }
          QMessageBox::information(this, QObject::tr("PDF Enregistré!"),
          QObject::tr("PDF Enregistré!.\n" "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_RES_clicked()
{
    rs=new results(this);
    rs->show();

}

void MainWindow::on_MAIL_clicked()
{
    ml=new Mail(this);
    ml->show();
}


void MainWindow::on_Stats_clicked()
{
    st=new statistique(this);
    st->show();
    st->exec();
}
