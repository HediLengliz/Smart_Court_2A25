#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "aa.h"
#include"aaa.h"
#include "aaaa.h"
#include"aaaaa.h"
#include "aj.h"
#include "rech.h"
# include "stapd.h"
#include"calan.h"
#include "maiiil.h"
#include"sms.h"

#include <QSqlQuery>
#include<QtCharts>

#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include<QPainter>
#include <QMainWindow>
#include <QStackedWidget>
#include <QtGui>
#include <QMainWindow>

#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include <QPixmap>
#include <QFile>
#include <QDialog>
#include <QFileDialog>

#include <QMainWindow>
#include <string>
#include <cstring>
#include <cctype>
#include <QMessageBox>
#include <iostream>
#include <bitset>
#include <sstream>
#include <algorithm>
#include <QUrl>
#include <QSystemTrayIcon>

#include<QPropertyAnimation>
#include <QRegularExpression>
#include <QTranslator>
#include <QPixmap>
#include <QDate>
#include <QMainWindow>

QT_BEGIN_NAMESPACE
class QTextBrowser;
QT_END_NAMESPACE

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
   // void on_Qframe_clicked();

    //void on_push_clicked();

    void on_hiiii_clicked();

    void on_hkkk_clicked();

    void on_pushButton_2_clicked();

    void on_mod_clicked();

    void on_pushButton_clicked();

    void on_rechercher_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_3_clicked();
   // void   sendMail();
   // void mailSent(QString);
   // void browse();
  //  void on_pb_envoyer_clicked();

    void on_pushButton_6_clicked();
   // void postrequest(QString smsmsg,QString phonenumber);
    void on_pushButton_7_clicked();
    void setFontSize(int size);
    void setMonth(int month);
    void setYear(QDate date);



private:
    Ui::MainWindow *ui;
    AA *a;
    aaa *l;
    aaaa *m;
    aaaaa *o;
    RECH *f;
stapd *h;
calan *c;
maiiil *n;
void insertCalendar();
int fontSize;
QDate selectedDate;
QTextBrowser *editor;



};

#endif // MAINWINDOW_H
