#-------------------------------------------------
#
# Project created by QtCreator 2018-10-26T21:45:23
#
#-------------------------------------------------

QT       += core gui sql printsupport charts

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Connexion
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
    add.cpp \
    aff.cpp \
    cihart.cpp \
    employee.cpp \
    exportexcelobject.cpp \
        main.cpp \
        mainwindow.cpp \
    connection.cpp \
    menu.cpp \
    modify.cpp \
    objective.cpp \
    searchpdf.cpp \
    sorting.cpp \
    supp.cpp \
    task.cpp \
    todoja.cpp \
    verifcin.cpp

HEADERS += \
    add.h \
    aff.h \
    cihart.h \
    employee.h \
    exportexcelobject.h \
        mainwindow.h \
    connection.h \
    menu.h \
    modify.h \
    objective.h \
    searchpdf.h \
    sorting.h \
    supp.h \
    task.h \
    todoja.h \
    verifcin.h

FORMS += \
        add.ui \
        aff.ui \
        cihart.ui \
        mainwindow.ui \
        menu.ui \
        modify.ui \
        searchpdf.ui \
        sorting.ui \
        supp.ui \
        task.ui \
        todoja.ui \
        verifcin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    recourse.qrc
