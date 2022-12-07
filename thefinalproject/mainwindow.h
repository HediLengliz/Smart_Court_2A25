#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include"arduino1.h"
#include"aj.h"
#include <QMainWindow>
#include <QDesktopServices>
#include <QMediaPlayer>
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
#include "room.h"
#include "notif.h"
#include "his.h"
#include "statis.h"
#include "accuse.h"
#include "arduinoS.h"

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
    notif m;
    his * His;
    Statis *statis;
    QMediaPlayer * media;

private slots:

    void update_code();

    void update_label();

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

    void on_pushButton_13_clicked();

    void on_ADD_19_clicked();

    void on_DISPLAY_PUSH_clicked();

    void on_PDF_5_clicked();



    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

    void on_pushButton_clicked();

    void on_LRN_4_textEdited(const QString &arg1);

    void on_MOD_PUSH_3_clicked();

    void on_MOD_2_clicked();

    void on_DISPLAY_PUSH_2_clicked();

    void on_STAT_clicked();


    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_ADD_PUSH_3_clicked();

    void on_DEL_PUSH_6_clicked();

    void on_DEL_PUSH_5_clicked();



    void on_legalAffairs_clicked();

    void on_PDF_ACC_clicked();

    void on_ADD_ACC_clicked();

    void on_List_ACC_clicked();

    void on_MODIFY_clicked();

    void on_DELETE_ACC_clicked();

    void on_getsrch_clicked();

    void on_Sort_clicked();

    void on_RES_clicked();

    void on_add__acc_clicked();

    void on_modify_clicked();

    void on_supp_btn_clicked();

    void on_search_clicked();

    void on_UPLOAD_clicked();






    void on_Stats_clicked();



    void on_qrcodegen_clicked();

    void on_LogOutACC_clicked();

    void on_EXIT_AACC_clicked();

    void on_EXIT_DACC_clicked();

    void on_EXIT_MACC_clicked();

    void on_EXIT_DACC_2_clicked();

    void on_EXIT_RACC_clicked();

    void on_EXIT_TACC_clicked();

    void on_EXIT_RSACC_clicked();

    void on_online_clicked();

    void on_incendie_clicked();

    void on_incendie_2_clicked();

    void on_pb_ajouter_clicked();

    void on_hiiii_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_6_clicked();

    void on_mod_clicked();

    void on_hkkk_clicked();

    void on_aff_clicked();

    void on_pushButton_tri_clicked();

    void on_pushButton_trid_clicked();

    void on_PUSH_clicked();

    void on_pb_supp_clicked();

    void on_MODIFIER_clicked();

    void on_rech_clicked();

    void on_rechercher_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_28_clicked();

    void on_EXIT_6_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_33_clicked();

    void on_Sort_2_clicked();

    void on_DEL_PUSH_10_clicked();

    void on_DEL_PUSH_9_clicked();

    void on_DEL_PUSH_8_clicked();

    void on_DEL_PUSH_7_clicked();

    void on_pushButton_22_clicked();

private:
    Ui::MainWindow *ui;
    Cihart *cihart;
    QByteArray data;
    Arduino Ar;
    room r;
    Accuse A;
    Arduino AA;
    arduinoS As;
    arduino1 d;
     Aj a;


};
#endif // MAINWINDOW_H
