#ifndef MAIL_H
#define MAIL_H
#include"aj.h"
#include <QDialog>
#include <QStandardItemModel>
#include <QDialog>
#include <QFileDialog>
#include <QDialog>
#include <QDesktopWidget>
#include <QSettings>
#include <QTextStream>
#include <QFile>
#include <QDataStream>
#include "smtp.h"
#include <QtWidgets/QMessageBox>
#include <QFileDialog>
namespace Ui {
class mail;
}

class mail : public QDialog
{
    Q_OBJECT

public:
    explicit mail(QWidget *parent = nullptr);
    ~mail();


private slots:
       void on_sendBtn_clicked();
       void sendMail();
          void mailSent(QString);
          void browse();
private:
    Ui::mail *ui;
    Aj k;
     QStringList files;
};

#endif // MAIL_H
