#ifndef VERIFCIN_H
#define VERIFCIN_H

#include <QDialog>
#include <QMessageBox>
#include "objective.h"
#include "employee.h"
#include <QDateTime>
#include <QtCharts/QtCharts>
#include <QTimer>
#include "cihart.h"
#include <QPieSlice>

namespace Ui {
class verifcin;
}

class verifcin : public QDialog
{
    Q_OBJECT

public:
    explicit verifcin(QWidget *parent = nullptr);
    ~verifcin();
    float fin,unfin,doi,tod;
private slots:
    void on_EXIT_clicked();

    void on_ADD_clicked();

    void on_TabAff_activated(const QModelIndex &index);

    void showtime();

    void on_MarkDone_clicked();

    void on_EXIT_2_clicked();

    void on_ADD_7_clicked();

    void on_ADD_5_clicked();

    void on_MarkDone_2_clicked();

    void on_ADD_3_clicked();

    void on_ADD_6_clicked();

    void on_ADD_11_clicked();

    void on_ADD_12_clicked();

    void on_ADD_13_clicked();

    void on_ADD_14_clicked();

    void on_EXIT_3_clicked();

private:
    Ui::verifcin *ui;
    Objective O;
    Employee E;
    Cihart* cihart;
};

#endif // VERIFCIN_H
