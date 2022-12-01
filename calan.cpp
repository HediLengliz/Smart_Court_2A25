#include "calan.h"
#include "ui_calan.h"
#include<QtCharts>
#include<QHostAddress>
#include<QTcpSocket>
#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include<QPainter>
#include<QtCharts>
#include<QPieSlice>
#include<QPieSeries>
#include<QPrintDialog>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include"smtp.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QEventLoop>
calan::calan(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::calan)
{
    ui->setupUi(this);
}

calan::~calan()
{
    delete ui;
}
void calan::postrequest(QString smsmsg,QString phonenumber)
{

    // create custom temporary event loop on stack
       QEventLoop eventLoop;

       // "quit()" the event-loop, when the network request "finished()"
       QNetworkAccessManager mgr;
       QObject::connect(&mgr, SIGNAL(finished(QNetworkReply*)), &eventLoop, SLOT(quit()));

       // the HTTP request
       QNetworkRequest req( QUrl( QString("https://api.orange.com/smsmessaging/v1/outbound/tel%3A%2B322804/requests") ) );

      req.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");



req.setRawHeader("Authorization", "Bearer oKP9TUD0JXp269TGnCwcOPt0CdBK");
QJsonObject msg;
msg["message"] = smsmsg;
QJsonObject obj;
obj["address"] = "tel:+216"+phonenumber;
obj["senderAddress"] = "tel:+322804";
obj["outboundSMSTextMessage"] = msg;
QJsonObject body;
body["outboundSMSMessageRequest"] = obj;
QJsonDocument doc(body);
QByteArray data = doc.toJson();
       QNetworkReply *reply = mgr.post(req,data);
       eventLoop.exec(); // blocks stack until "finished()" has been called

       if (reply->error() == QNetworkReply::NoError) {
           //success
           qDebug() << "Success" <<reply->readAll();
           delete reply;
       }
       else {
           //failure
           qDebug() << "Failure" <<reply->errorString() << reply->error();
           delete reply;
       }
}

void calan::on_pushButton_clicked()
{
    QString numtel=ui->lineEdit_numtel->text();
    QString msg=ui->textEdit->toPlainText();
    postrequest(msg,numtel);
}
