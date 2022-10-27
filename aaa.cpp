#include "aaa.h"
#include "ui_aaa.h"
#include"aj.h"
aaa::aaa(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::aaa)
{
    ui->setupUi(this);
   ui->ta->setModel(a.afficher());

}

aaa::~aaa()
{
    delete ui;
}

