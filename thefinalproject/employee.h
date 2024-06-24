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

typedef struct
{
    int succ,fail,somme;
    float pourc;
}statistic_obj;


class Employee
{
    public:
        Employee();
        Employee(int cin,int codepin,float salary,QString nom,QString prenom,QString email,QString city,int NOMBRESCEANCE,QString role,int code);
        Employee(int cin,QString email);
        int getcin();
        int getcodepin();
        int getcode();
        float getsalary();
        QString getnom();
        QString getprenom();
        QString getemail();
        QString getcity();
        statistic_obj getstatisticobj();
        void setcode(int code);
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
        QSqlQueryModel* sorting(int min,int max,int* n);
        QSqlQueryModel* sortingall(int* n);
        void ERROR();
        QSqlQueryModel* search(int state,int cin,QString email);
        QString currDate();
        void pdf();
        bool verifcin(int cin);
        bool isempty();

    private:
        int CIN,Code_Pin,ns,Abs,Code;
        float Salary;
        QString Nom,Prenom,E_mail,City,Role;
        statistic_obj S_Obj;
};

#endif // EMPLOYEE_H
