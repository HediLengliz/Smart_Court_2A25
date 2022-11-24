QT       += core gui
QT += sql charts printsupport widgets axcontainer
QT += gui
QT += serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    accuse.cpp \
    arduino.cpp \
    connection.cpp \
    consult.cpp \
    delete.cpp \
    dialog.cpp \
    mail.cpp \
    main.cpp \
    mainwindow.cpp \
    modify.cpp \
    qrcode.cpp \
    recherche.cpp \
    results.cpp \
    statistique.cpp \
    tri.cpp

HEADERS += \
    accuse.h \
    arduino.h \
    connection.h \
    consult.h \
    delete.h \
    dialog.h \
    mail.h \
    mainwindow.h \
    modify.h \
    qrcode.h \
    recherche.h \
    results.h \
    statistique.h \
    tri.h

FORMS += \
    arduino.ui \
    consult.ui \
    delete.ui \
    dialog.ui \
    mail.ui \
    mainwindow.ui \
    modify.ui \
    qrcode.ui \
    recherche.ui \
    results.ui \
    statistique.ui \
    tri.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target