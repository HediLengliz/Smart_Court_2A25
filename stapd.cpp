#include "stapd.h"
#include "ui_stapd.h"
#include "QMessageBox"
#include "aj.h"
#include<QPainter>
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
#include <QCoreApplication>
#include <QTextStream>
#include <QtPrintSupport/QPrinter>
stapd::stapd(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::stapd)
{
    ui->setupUi(this);
}

stapd::~stapd()
{
    delete ui;
}

void stapd::on_pushButton_clicked()
{


      a.telechargerPDF();

               { QMessageBox::information(nullptr, QObject::tr("database is open"),
                               QObject::tr("telcha successful.\n"
                                           "Click Cancel to exit."), QMessageBox::Cancel);}




}


