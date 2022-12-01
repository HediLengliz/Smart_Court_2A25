#ifndef CALAN_H
#define CALAN_H
#include"aj.h"
#include <QDialog>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QTimer>
#include <QEventLoop>
namespace Ui {
class calan;
}

class calan : public QDialog
{
    Q_OBJECT

public:
    explicit calan(QWidget *parent = nullptr);
    ~calan();
    void postrequest(QString smsmsg,QString phonenumber);

private slots:
    void on_pushButton_clicked();

private:
    Ui::calan *ui;
    Aj a;
};

#endif // CALAN_H
