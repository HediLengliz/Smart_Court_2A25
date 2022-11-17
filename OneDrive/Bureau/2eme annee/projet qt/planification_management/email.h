#ifndef EMAIL_H
#define EMAIL_H

#include <QDialog>
#include "smtp.h"
namespace Ui {
class email;
}

class email : public QDialog
{
    Q_OBJECT

public:
    explicit email(QWidget *parent = nullptr);
    ~email();

private slots:
    void on_email_7_clicked();

private:
    Ui::email *ui;
    email *Email;
};

#endif // EMAIL_H
