#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"aj.h"
#include <QtWidgets>
#include<QMainWindow>
#include<QtCharts>
#include<QHostAddress>
#include<QTcpSocket>
#include<QPieSlice >
#include<QPieSeries>
#include<QPrinter>
#include <QFileDialog>
#include<QPrintDialog>
#include<QPainter>
#include<QtCharts>
#include<QPieSlice>
#include<QPieSeries>
#include<QPrintDialog>
#include <QMessageBox>
#include <QDebug>
#include <QIntValidator>
#include <QSqlQueryModel>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include<QDesktopServices>
#include<QUrl>
#include <QTextStream>
#include <QTextDocument>
#include <QtPrintSupport/QPrintDialog>
#include <QtWidgets>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QGraphicsView>
#include<QPdfWriter>
#include<QSqlQuery>
#include<QSystemTrayIcon>
#include <QtNetwork/QAbstractSocket>
#include <QtNetwork/QSslSocket>
#include<QUrlQuery>
#include<QJsonDocument>
#include<QJsonObject>
#include<QJsonArray>
#include <QDate>
#include <QTime>
#include<QSqlTableModel>
#include<QItemSelectionModel>
#include<QTableWidgetItem>
#include <QDesktopWidget>
#include <QCoreApplication>
#include <QDateEdit>
#include <QComboBox>
#include"smtp.h"
#include <QPixmap>
#include <QMediaPlayer>
#include <QTabWidget>
#include <QObject>
#include <QDialog>
#include <QValidator>
#include <QPropertyAnimation>
#include <QEasingCurve>
#include <QSequentialAnimationGroup>
#include <QState>
#include <QStateMachine>
#include <QSignalTransition>
#include<QString>
#include<QStatusBar>
#include <QSound>
#include<QTimer>
#include<QDateTime>
#include <QApplication>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include <QHttpMultiPart>
#include <QUrl>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QEventLoop>
#include <QtWidgets>
#include"arduinoe.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_hiiii_clicked()
{
    a= new AA(this);
    a->show();
}

void MainWindow::on_hkkk_clicked()
{
    l= new aaa(this);
    l->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    m= new aaaa(this);
    m->show();
}

void MainWindow::on_mod_clicked()
{
    o= new aaaaa(this);
    o->show();
}

void MainWindow::on_rechercher_clicked()
{
    f= new RECH(this);
    f->show();
}

void MainWindow::on_pushButton_4_clicked()
{
    h= new stapd(this);
    h->show();
}

void MainWindow::on_pushButton_clicked()
{
    c= new calan(this);
    c->show();
}

void MainWindow::on_pushButton_3_clicked()
{

            QSqlQueryModel * model= new QSqlQueryModel();
                             model->setQuery("select * from Aj where age < 18 ");
                             float code=model->rowCount();
                             model->setQuery("select * from Aj where age between 18 and 30 ");
                             float codee=model->rowCount();
                             model->setQuery("select * from Aj where age >30 ");
                             float codeee=model->rowCount();
                             float total=code+codee+codeee;
                             QString a=QString("moins de 18 \t"+QString::number((code*100)/total,'f',2)+"%" );
                             QString b=QString("entre 18 et 30 \t"+QString::number((codee*100)/total,'f',2)+"%" );
                             QString c=QString("+30 \t"+QString::number((codeee*100)/total,'f',2)+"%" );
                             QPieSeries *series = new QPieSeries();
                             series->append(a,code);
                             series->append(b,codee);
                             series->append(c,codeee);
                     if (code!=0)
                     {QPieSlice *slice = series->slices().at(0);
                      slice->setLabelVisible();
                      slice->setPen(QPen());}
                     if ( codee!=0)
                     {
                              // Add label, explode and define brush for 2nd slice
                              QPieSlice *slice1 = series->slices().at(1);
                              //slice1->setExploded();
                              slice1->setLabelVisible();
                     }
                     if(codeee!=0)
                     {
                              // Add labels to rest of slices
                              QPieSlice *slice2 = series->slices().at(2);
                              //slice1->setExploded();
                              slice2->setLabelVisible();
                     }
                             // Create the chart widget
                             QChart *chart = new QChart();
                             // Add data to chart with title and hide legend
                             chart->addSeries(series);
                             chart->setTitle("Pourcentage Par age :Nombre Des Espaces "+ QString::number(total));
                             chart->legend()->hide();
                             // Used to display the chart
                             QChartView *chartView = new QChartView(chart);
                             chartView->setRenderHint(QPainter::Antialiasing);
                             chartView->resize(1000,500);
                             chartView->show();
}

void MainWindow::on_pushButton_6_clicked()
{
    maiiil mail;
    mail.setModal(true);
    mail.exec();
}


void MainWindow::on_pushButton_7_clicked()
{
    //! [0]


        selectedDate = QDate::currentDate();
        fontSize = 10;

        QWidget *centralWidget = new QWidget;
    //! [0]

    //! [1]
        QLabel *dateLabel = new QLabel(tr("Date:"));
        QComboBox *monthCombo = new QComboBox;

        for (int month = 1; month <= 12; ++month)
            monthCombo->addItem(QDate::longMonthName(month));

        QDateTimeEdit *yearEdit = new QDateTimeEdit;
        yearEdit->setDisplayFormat("yyyy");
        yearEdit->setDateRange(QDate(1753, 1, 1), QDate(8000, 1, 1));
    //! [1]

        monthCombo->setCurrentIndex(selectedDate.month() - 1);
        yearEdit->setDate(selectedDate);

    //! [2]
        QLabel *fontSizeLabel = new QLabel(tr("Font size:"));
        QSpinBox *fontSizeSpinBox = new QSpinBox;
        fontSizeSpinBox->setRange(1, 64);

        editor = new QTextBrowser;
        insertCalendar();
    //! [2]

    //! [3]
        connect(monthCombo, SIGNAL(activated(int)), this, SLOT(setMonth(int)));
        connect(yearEdit, SIGNAL(dateChanged(QDate)), this, SLOT(setYear(QDate)));
        connect(fontSizeSpinBox, SIGNAL(valueChanged(int)),
                this, SLOT(setFontSize(int)));
    //! [3]

        fontSizeSpinBox->setValue(10);

    //! [4]
        QHBoxLayout *controlsLayout = new QHBoxLayout;
        controlsLayout->addWidget(dateLabel);
        controlsLayout->addWidget(monthCombo);
        controlsLayout->addWidget(yearEdit);
        controlsLayout->addSpacing(24);
        controlsLayout->addWidget(fontSizeLabel);
        controlsLayout->addWidget(fontSizeSpinBox);
        controlsLayout->addStretch(1);

        QVBoxLayout *centralLayout = new QVBoxLayout;
        centralLayout->addLayout(controlsLayout);
        centralLayout->addWidget(editor, 1);
        centralWidget->setLayout(centralLayout);

        setCentralWidget(centralWidget);
}

void MainWindow::insertCalendar()
{
    editor->clear();
    QTextCursor cursor = editor->textCursor();
    cursor.beginEditBlock();

    QDate date(selectedDate.year(), selectedDate.month(), 1);
//! [5]

//! [6]
    QTextTableFormat tableFormat;
    tableFormat.setAlignment(Qt::AlignHCenter);
    tableFormat.setBackground(QColor("#e0e0e0"));
    tableFormat.setCellPadding(2);
    tableFormat.setCellSpacing(4);
//! [6] //! [7]
    QVector<QTextLength> constraints;
    constraints << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14)
                << QTextLength(QTextLength::PercentageLength, 14);
    tableFormat.setColumnWidthConstraints(constraints);
//! [7]

//! [8]
    QTextTable *table = cursor.insertTable(1, 7, tableFormat);
//! [8]

//! [9]
    QTextFrame *frame = cursor.currentFrame();
    QTextFrameFormat frameFormat = frame->frameFormat();
    frameFormat.setBorder(1);
    frame->setFrameFormat(frameFormat);
//! [9]

//! [10]
    QTextCharFormat format = cursor.charFormat();
    format.setFontPointSize(fontSize);

    QTextCharFormat boldFormat = format;
    boldFormat.setFontWeight(QFont::Bold);

    QTextCharFormat highlightedFormat = boldFormat;
    highlightedFormat.setBackground(Qt::yellow);
//! [10]

//! [11]
    for (int weekDay = 1; weekDay <= 7; ++weekDay) {
        QTextTableCell cell = table->cellAt(0, weekDay-1);
//! [11] //! [12]
        QTextCursor cellCursor = cell.firstCursorPosition();
        cellCursor.insertText(QString("%1").arg(QDate::longDayName(weekDay)), boldFormat);
    }
//! [12]

//! [13]
    table->insertRows(table->rows(), 1);
//! [13]

    while (date.month() == selectedDate.month()) {
        int weekDay = date.dayOfWeek();
        QTextTableCell cell = table->cellAt(table->rows()-1, weekDay-1);
        QTextCursor cellCursor = cell.firstCursorPosition();

        if (date == QDate::currentDate())
            cellCursor.insertText(QString("%1").arg(date.day()), highlightedFormat);
        else
            cellCursor.insertText(QString("%1").arg(date.day()), format);

        date = date.addDays(1);
        if (weekDay == 7 && date.month() == selectedDate.month())
            table->insertRows(table->rows(), 1);
    }

    cursor.endEditBlock();
//! [14]
    setWindowTitle(tr("Calendar for %1 %2"
        ).arg(QDate::longMonthName(selectedDate.month())
        ).arg(selectedDate.year()));
}
//! [14]

//! [15]
void MainWindow::setFontSize(int size)
{
    fontSize = size;
    insertCalendar();
}
//! [15]

//! [16]
void MainWindow::setMonth(int month)
{
    selectedDate = QDate(selectedDate.year(), month + 1, selectedDate.day());
    insertCalendar();
}
//! [16]

//! [17]
void MainWindow::setYear(QDate date)
{
    selectedDate = QDate(date.year(), selectedDate.month(), selectedDate.day());
    insertCalendar();
}
//! [17]


