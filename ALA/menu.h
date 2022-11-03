#ifndef MENU_H
#define MENU_H

#include <QDialog>
#include "mainwindow.h"

namespace Ui {
class menu;
}

class menu : public QDialog
{
    Q_OBJECT

public:
    explicit menu(QWidget *parent = nullptr);
    ~menu();

private slots:
    void on_pushButton_10_clicked();

private:
    Ui::menu *ui;
    MainWindow *w;
};

#endif // MENU_H
