#ifndef DISPLAY_H
#define DISPLAY_H
#include "room.h"
#include <QDialog>

namespace Ui {
class display;
}

class display : public QDialog
{
    Q_OBJECT

public:
    explicit display(QWidget *parent = nullptr);
    ~display();

private slots:


private:
    Ui::display *ui;
    display* Display;
    room r;
};

#endif // DISPLAY_H
