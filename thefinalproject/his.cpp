#include "his.h"
#include "ui_his.h"
#include <QFile>
#include <QDebug>
his::his(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::his)
{
    ui->setupUi(this);
    readfile();
}

his::~his()
{
    delete ui;
}
void his::readfile(){
    QString filename="C:/thefinalproject/logs/historiques.txt";
    QFile file(filename);
    if(!file.exists()){
        qDebug() << "file dosen't exist  "<<filename;
    }else{
        qDebug() << filename<<" found...";
    }
    QString line;
    ui->history->clear();
    if (file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QTextStream stream(&file);
        while (!stream.atEnd()){
            line = stream.readLine();
            ui->history->setText(ui->history->toPlainText()+line+"\n");
            qDebug() << "linea: "<<line;
        }
    }
    file.close();
}



void his::on_pushButton_clicked()
{

}
