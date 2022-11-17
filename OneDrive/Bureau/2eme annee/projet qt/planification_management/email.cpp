#include "email.h"
#include "ui_email.h"

email::email(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::email)
{
    ui->setupUi(this);
}

email::~email()
{
    delete ui;
}

void email::on_email_7_clicked()
{
    /************************************SMTP******************************************************/
                        Smtp* smtp = new Smtp("lengliz01hedi@gmail.com","HIDEonBOX123", "smtp.gmail.com",465);
                        connect (smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

                        QString objet=ui->objet_2->text();
                        QString o=ui->description_2->text();
                        QString email=ui->email_4->text();
                        smtp->sendMail("lengliz01hedi@gmail.com", email , objet,o);
        /***********************************************************************************************/
}
