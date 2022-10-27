#ifndef AAAA_H
#define AAAA_H

#include <QDialog>

namespace Ui {
class aaaa;
}

class aaaa : public QDialog
{
    Q_OBJECT

public:
    explicit aaaa(QWidget *parent = nullptr);
    ~aaaa();

private slots:
    void on_pb_supp_clicked();

private:
    Ui::aaaa *ui;
};

#endif // AAAA_H
