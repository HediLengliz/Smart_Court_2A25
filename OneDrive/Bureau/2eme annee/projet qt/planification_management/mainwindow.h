#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "add.h"
#include "dell.h"
#include "display.h"
#include "modify.h"
#include "his.h"
#include "notif.h"
//#include "mail.h"
#include <QDataStream>
#include <QSortFilterProxyModel>
#include <QMainWindow>
#include <QSortFilterProxyModel>
#include <QTextTableFormat>
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
#include "email.h"
#include "statis.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
 QSortFilterProxyModel *proxy;
private slots:

        void on_ADD_PUSH_clicked();

        void on_DELL_PUSH_clicked();

        void on_DISPLAY_PUSH_clicked();

        void on_MOD_PUSH_clicked();



        void on_EMAIL_clicked();

        void on_DISPLAY_PUSH_2_clicked();



        void on_STAT_clicked();

private:
    Ui::MainWindow *ui;
    add* Add;
    dell* Dell;
    Modify* mod;
    display* Display;
    his* His;
    email *Email;
    Statis *statis;

};

#endif // MAINWINDOW_H
