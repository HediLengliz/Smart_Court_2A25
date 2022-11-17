#ifndef TODOJA_H
#define TODOJA_H

#include <QDialog>
#include "objective.h"
#include <QSqlQuery>
#include <QMessageBox>
#include <QTimer>
#include <QDateTime>

namespace Ui {
class Todoja;
}

class Todoja : public QDialog
{
    Q_OBJECT

public:
    explicit Todoja(QWidget *parent = nullptr);
    ~Todoja();
    Objective O;

private slots:
    void on_ADD_clicked();

    void on_ADD_6_clicked();

    void on_EXIT_clicked();

    void on_EXIT_2_clicked();

    void showtime();

private:
    Ui::Todoja *ui;
};

#endif // TODOJA_H
