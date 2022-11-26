#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDesktopServices>
#include <QUrl>
#include "employee.h"
#include "connection.h"
#include "objective.h"
#include "exportexcelobject.h"
#include "cihart.h"
#include "arduino.h"
#include <QDateTime>
#include <QtCharts/QtCharts>
#include <QTimer>
#include <QPieSlice>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Employee E;
    int n=0;
    Objective O;
    float fin,unfin,tod,doi;
    QString codee;

private slots:

    void update_code();

    void on_pushButton_10_clicked();

    void on_ADD_PUSH_clicked();

    void on_add_new_employee_clicked();

    void on_LIST_PUSH_clicked();

    void on_add_new_employee_2_clicked();

    void on_add_new_employee_3_clicked();

    void on_update_clicked();

    void on_add_new_employee_4_clicked();

    void on_add_new_employee_5_clicked();

    void on_MOD_PUSH_clicked();

    void on_DEL_PUSH_clicked();

    void on_EXIT_clicked();

    void on_MAX_clicked();

    void on_SCIN_clicked();

    void on_SEMAIL_clicked();

    void on_PDF_clicked();

    void on_add_new_employee_6_clicked();

    void on_SEARCH_PUSH_clicked();

    void on_SET_clicked();

    void on_SET_2_clicked();

    void on_ExportExcel_clicked();

    void on_ImportExcel_clicked();

    void on_SORT_PUSH_clicked();

    void on_EXIT_2_clicked();

    void on_ADD_clicked();

    void on_TODOLIST_clicked();

    void on_Tabobj_activated(const QModelIndex &index);

    void on_ADD_3_clicked();

    void on_MarkDone_clicked();

    void on_ADD_5_clicked();

    void on_ADD_6_clicked();

    void on_MarkDone_2_clicked();

    void on_ADD_7_clicked();

    void on_EXIT_4_clicked();

    void showtime();

    void on_EXIT_3_clicked();

    void on_ADD_11_clicked();

    void on_ADD_12_clicked();

    void on_EXIT_5_clicked();

    void on_ADD_13_clicked();

    void on_ADD_14_clicked();

    void on_pushButton_9_clicked();

    void on_DEL_PUSH_2_clicked();

    void on_DEL_PUSH_3_clicked();

private:
    Ui::MainWindow *ui;
    Cihart *cihart;
    QByteArray data;
    Arduino A;
};
#endif // MAINWINDOW_H
