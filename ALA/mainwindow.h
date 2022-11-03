#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add.h"
#include "aff.h"
#include "supp.h"
#include "modify.h"

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
    void on_ADD_PUSH_clicked();

    void on_LIST_PUSH_clicked();

    void on_DEL_PUSH_clicked();

    void on_MOD_PUSH_clicked();

private:
    Ui::MainWindow *ui;
    Add *add;
    Aff *aff;
    Supp *supp;
    Modify *mod;
};

#endif // MAINWINDOW_H
