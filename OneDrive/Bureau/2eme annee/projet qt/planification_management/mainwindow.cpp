#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "connection.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_ADD_PUSH_clicked()
{
    Add=new add(this);
    Add->show();
}


void MainWindow::on_DELL_PUSH_clicked()
{
    Dell=new dell(this);
    Dell->show();
}

void MainWindow::on_DISPLAY_PUSH_clicked()
{
    Display=new display(this);
    Display->show();
}



void MainWindow::on_MOD_PUSH_clicked()
{
    mod=new Modify(this);
    mod->show();



}
//void  MainWindow::browse()
//{
//    files.clear();

//    QFileDialog dialog(this);
//    dialog.setDirectory(QDir::homePath());
//    dialog.setFileMode(QFileDialog::ExistingFiles);

//    if (dialog.exec())
//        files = dialog.selectedFiles();

//    QString fileListString;
//    foreach(QString file, files)
//        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

//    ui->file->setText( fileListString );

//}
//void   MainWindow::sendMail()
//{
//    mail* smtp = new mail("mohamedhedi.lengliz@esprit.tn",ui->mail_pass->text(), "mail.gmail.com");
//    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

//    if( !files.isEmpty() )
//        smtp->sendMail("mohamedhedi.lengliz@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
//    else
//        smtp->sendMail("mohamedhedi.lengliz@esprit.tn", ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
//}
//void   MainWindow::mailSent(QString status)
//{

//    if(status == "Message sent")
//        QMessageBox::warning( nullptr, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
//    ui->rcpt->clear();
//    ui->subject->clear();
//    ui->file->clear();
//    ui->msg->clear();
//    ui->mail_pass->clear();
//}
//connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
//connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));


//void MainWindow::on_EMAIL_clicked()
//{
//    Mail=new mail(this);
//    Mail->show();
//}
