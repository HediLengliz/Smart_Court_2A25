#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "add.h"
#include "aff.h"
#include "supp.h"
#include "modify.h"
#include "sorting.h"
#include "searchpdf.h"
#include "verifcin.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    int cin;

private slots:
    void on_ADD_PUSH_clicked();

    void on_LIST_PUSH_clicked();

    void on_DEL_PUSH_clicked();

    void on_MOD_PUSH_clicked();

    void on_SORT_PUSH_clicked();

    void on_SEARCH_PUSH_clicked();

    void on_TODOLIST_clicked();

private:
    Ui::MainWindow *ui;
    Add *add;
    Aff *aff;
    Supp *supp;
    Modify *mod;
    Sorting *sorting;
    searchpdf *Searchpdf;
    verifcin *Verifcin;
};

#endif // MAINWINDOW_H
