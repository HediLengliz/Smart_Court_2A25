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
    void on_pushButton_clicked();

    void on_LRN_textEdited(const QString &arg1);





    void on_PDF_clicked();

    void on_radioButton_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_3_clicked();

    void on_radioButton_4_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_6_clicked();

private:
    Ui::display *ui;
    room r;
};

#endif // DISPLAY_H
