#ifndef AAAAA_H
#define AAAAA_H

#include <QDialog>

namespace Ui {
class aaaaa;
}

class aaaaa : public QDialog
{
    Q_OBJECT

public:
    explicit aaaaa(QWidget *parent = nullptr);
    ~aaaaa();

private slots:

    void on_MODIFIER_clicked();

private:
    Ui::aaaaa *ui;
};

#endif // AAAAA_H
