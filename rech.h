#ifndef RECH_H
#define RECH_H

#include <QDialog>

namespace Ui {
class RECH;
}

class RECH : public QDialog
{
    Q_OBJECT

public:
    explicit RECH(QWidget *parent = nullptr);
    ~RECH();

private slots:


    void on_rech_clicked();

private:
    Ui::RECH *ui;
};

#endif // RECH_H
