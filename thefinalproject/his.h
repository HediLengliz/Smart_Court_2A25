#ifndef HIS_H
#define HIS_H

#include <QDialog>

namespace Ui {
class his;
}

class his : public QDialog
{
    Q_OBJECT

public:
    explicit his(QWidget *parent = nullptr);
    ~his();
    void readfile();

private slots:
    void on_pushButton_clicked();

private:
    Ui::his *ui;
    his *His;
};

#endif // HIS_H
