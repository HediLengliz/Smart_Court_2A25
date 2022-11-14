#include "display.h"
#include "ui_display.h"
#include <QMessageBox>
#include <QPlainTextEdit>
#include <QTextStream>
#include <QPainter>
#include <QTextStream>
#include <QFileDialog>
#include <QTextDocument>
#include <QtPrintSupport/QPrinter>
#include <QFileDialog>
#include <QTextDocument>
#include <strstream>
#include <QSystemTrayIcon>
#include <QRegExpValidator>
#include <QDesktopServices>
#include <QUrl>
#include <QPdfWriter>
#include <QFile>
#include <QCoreApplication>
#include <QTextStream>
#include <QSqlQuery>

display::display(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::display)
{
    ui->setupUi(this);

}

display::~display()
{
ui->tableView->setModel(r.displayroom());    delete ui;
}


void display::on_pushButton_clicked()
{
    room rs;
    QVariant id_ff = ui->tableView->model()->data(ui->tableView->selectionModel()->currentIndex(),Qt::DisplayRole);
    int idd = id_ff.toInt();
    QMessageBox::StandardButton reply;
      reply = QMessageBox::question(this, "DELETE", "Are you Sure you want to DELETE this ROOM?",
                                    QMessageBox::Yes|QMessageBox::No);
      if (reply == QMessageBox::Yes) {
          bool test=rs.deleteroom(idd);
          if(test)
          {
              ui->tableView->setModel(r.displayroom());

          }
      }
}

void display::on_LRN_textEdited(const QString &arg1)
{
    room a;
    ui->tableView->setModel(a.SEARCH(arg1));

}



void display::on_PDF_clicked()
{
    QPdfWriter pdf("C:/Users/hedi2/OneDrive/Bureau/2eme annee/projet qt/planification_management/room.pdf");

       QPainter painter(&pdf);
       int i = 4000;
              painter.setPen(Qt::darkCyan);
              painter.setFont(QFont("Time New Roman", 25));
              painter.drawText(3000,1400,"ROOMS LIST");
              painter.setPen(Qt::cyan);
              painter.setFont(QFont("Time New Roman", 15));
              painter.drawRect(100,100,9400,2500);
              painter.drawRect(100,3000,9400,500);
              painter.setFont(QFont("Time New Roman", 9));
              painter.drawText(400,3300,"ID ROOM");
              painter.drawText(1350,3300,"PINCODE");
              painter.drawText(2200,3300,"ROOM NUMBER");
              painter.drawText(3400,3300,"ROOM TYPE");
              painter.drawText(4400,3300,"CREATION DATE");
              painter.drawText(6200,3300,"ROOM STATE");
              painter.drawRect(100,3000,9400,9000);

              QSqlQuery query;
              query.prepare("select * from ROOMS");
              query.exec();
              while (query.next())
              {
                  painter.drawText(400,i,query.value(0).toString());
                  painter.drawText(1350,i,query.value(1).toString());
                  painter.drawText(2300,i,query.value(2).toString());
                  painter.drawText(3400,i,query.value(3).toString());
                  painter.drawText(4400,i,query.value(4).toString());
                  painter.drawText(6200,i,query.value(5).toString());




                 i = i + 350;
              }
              QMessageBox::information(this, QObject::tr("PDF Saved Successfuly!"),
              QObject::tr("PDF Saved Successfuly!.\n" "Click Cancel to exit."), QMessageBox::Cancel);
}

void display::on_radioButton_clicked()
{
    room r;
    ui->tableView->setModel(r.triID());
 // tazkimm ui->tableView->setModel(r.displayroom());
}

void display::on_radioButton_2_clicked()
{
    room r;
    ui->tableView->setModel(r.triPIN());
}

void display::on_radioButton_3_clicked()
{
    room r;
    ui->tableView->setModel(r.triNUM());
}

void display::on_radioButton_4_clicked()
{
    room r;
    ui->tableView->setModel(r.triTYPE());
}

void display::on_radioButton_5_clicked()
{
    room r;
    ui->tableView->setModel(r.triDATE());
}

void display::on_radioButton_6_clicked()
{
    room r;
    ui->tableView->setModel(r.triSTATE());
}
