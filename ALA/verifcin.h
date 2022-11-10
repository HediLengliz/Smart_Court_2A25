#ifndef VERIFCIN_H
#define VERIFCIN_H

#include <QDialog>
#include <QMessageBox>
#include "objective.h"
#include "employee.h"
#include <QDateTime>
#include <QTimer>

namespace Ui {
class verifcin;
}

class verifcin : public QDialog
{
    Q_OBJECT

public:
    explicit verifcin(QWidget *parent = nullptr);
    ~verifcin();

private slots:
    void on_EXIT_clicked();

    void on_ADD_clicked();

    void on_TabAff_activated(const QModelIndex &index);

    void showtime();

    void on_MarkDone_clicked();

    void on_EXIT_2_clicked();

    void on_ADD_7_clicked();

private:
    Ui::verifcin *ui;
    Objective O;
    Employee E;
};

#endif // VERIFCIN_H
