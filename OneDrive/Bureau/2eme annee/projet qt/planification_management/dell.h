#ifndef DELL_H
#define DELL_H
#include "room.h"
#include <QDialog>

namespace Ui {
class dell;
}

class dell : public QDialog
{
    Q_OBJECT

public:
    explicit dell(QWidget *parent = nullptr);
    ~dell();

private slots:
    void on_DELL_clicked();

private:
    Ui::dell *ui;
    dell* Dell;
    room r;
};

#endif // DELL_H
