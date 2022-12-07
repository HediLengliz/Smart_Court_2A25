#include "mainwindow.h"
#include <QMessageBox>
#include <QApplication>
#include "connection.h"
#include <QMediaPlayer>

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    a.setWindowIcon(QIcon("C:/Users/Ala/Desktop/2A/Projjeeet/Atelier_Connexion/icons/Logo.ico")); //changer le chem
    MainWindow w;
    Connection c;
    bool test=c.createconnect();
    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("database is open"),
                    QObject::tr("connection successful.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        w.show();
        QMediaPlayer * media = new QMediaPlayer();
        media->setMedia(QUrl("qrc:/new/prefix1/icons/law-and-order-full-theme-high-quality.mp3"));
        media->play();
}
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                    QObject::tr("connection failed.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
