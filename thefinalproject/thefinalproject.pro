QT       += core gui sql printsupport charts serialport multimedia network

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
    aj.cpp \
    arduino.cpp \
    arduino1.cpp \
    arduinoS.cpp \
    cihart.cpp \
    connection.cpp \
    employee.cpp \
    exportexcelobject.cpp \
    his.cpp \
    incendie.cpp \
    main.cpp \
    mainwindow.cpp \
    notif.cpp \
    objective.cpp \
    room.cpp \
    smtp.cpp \
    statis.cpp \
    accuse.cpp \
    QrCode.cpp\
    statistique.cpp


HEADERS += \
    aj.h \
    arduino.h \
    arduino1.h \
    arduinoS.h \
    cihart.h \
    connection.h \
    employee.h \
    exportexcelobject.h \
    his.h \
    incendie.h \
    mainwindow.h \
    notif.h \
    objective.h \
    room.h \
    smtp.h \
    src/SmtpMime \
    src/emailaddress.h \
    src/mimebase64encoder.h \
    src/mimebase64formatter.h \
    src/mimebytearrayattachment.h \
    src/mimecontentencoder.h \
    src/mimecontentformatter.h \
    src/mimefile.h \
    src/mimehtml.h \
    src/mimeinlinefile.h \
    src/mimemessage.h \
    src/mimemultipart.h \
    src/mimepart.h \
    src/mimeqpencoder.h \
    src/mimeqpformatter.h \
    src/mimetext.h \
    src/quotedprintable.h \
    src/smtpclient.h \
    src/smtpmime_global.h \
    statis.h \
    accuse.h \
    QrCode.hpp \
    statistique.h


FORMS += \
    cihart.ui \
    his.ui \
    incendie.ui \
    mainwindow.ui \
    statis.ui \
    statistique.ui


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    icons.qrc

DISTFILES += \
    icons/checked.png \
    icons/court.png \
    icons/editing.png \
    icons/fullscreen.png \
    icons/history.png \
    icons/listR.png \
    icons/minimize (1).png \
    icons/minimize (1).png \
    icons/pdf.png \
    icons/pie-chart.png \
    icons/plus.png \
    icons/plus.png \
    icons/x-mark.png \
    icons/x-mark.png

SUBDIRS += \
    src/SMTPEmail.pro
