#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "add.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_ADD_PUSH_2_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_23_clicked();

private:
    Ui::MainWindow *ui;
    add* Add;
};
#endif // MAINWINDOW_H
