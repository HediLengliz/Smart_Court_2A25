#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <QString>
#include <QSqlQuery>
#include <QtDebug>
#include <QSqlQueryModel>
#include <QObject>
#include <QSqlRecord>
#include <QMessageBox>
#include <QtCore>
#include <QtPrintSupport/QPrinter>
#include <QtPrintSupport/qprinter.h>
#include <QPdfWriter>
#include <QPainter>
#include <QTextDocument>

struct statistic_obj
{
    int succ,fail,somme;
    float pourc;
};


class Employee
{
    public:
        Employee();
        Employee(int cin,int codepin,float salary,QString nom,QString prenom,QString email,QString city);
        Employee(int cin,QString email);
        int getcin();
        int getcodepin();
        float getsalary();
        QString getnom();
        QString getprenom();
        QString getemail();
        QString getcity();
        statistic_obj getstatisticobj();
        void setcin(int cin);
        void setcodepin(int cp);
        void setsalary(float s);
        void setnom(QString nom);
        void setprenom(QString prenom);
        void setemail(QString email);
        void setcity(QString city);
        void setstatisticobj(int numsucc,int numfail);
        bool ajouter();
        QSqlQueryModel* afficher();
        bool supprimer(int CIN);
        bool modifier(QSqlQueryModel* model);
        void afficheremail(QSqlQueryModel* model );
        QSqlQueryModel* sorting(int min,int max);
        QSqlQueryModel* sortingall();
        void ERROR();
        QSqlQueryModel* search(int state,int cin,QString email);
        QString currDate();
        void pdf();
        bool verifcin(int cin);

    private:
        int CIN,Code_Pin;
        float Salary;
        QString Nom,Prenom,E_mail,City;
        statistic_obj S_Obj;
};

#endif // EMPLOYEE_H
