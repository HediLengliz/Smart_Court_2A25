#ifndef STAPD_H
#define STAPD_H
#include "aj.h"
#include <QDialog>
#include<QPainter>

namespace Ui {
class stapd;
}

class stapd : public QDialog
{
    Q_OBJECT

public:
    explicit stapd(QWidget *parent = nullptr);
    ~stapd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::stapd *ui;
    Aj a;
};

#endif // STAPD_H
