QT += sql
QT += charts
QT       += core gui
QT       += core gui sql
QT       += network
QT+=quickcontrols2
QT       += core gui charts
QT       += printsupport
QT       += core gui multimedia multimediawidgets
QT       +=svg
QT       += concurrent
QT       += serialport
QT += network
QT += widgets charts
QT += printsupport
greaterThan(QT_MAJOR_VERSION, 4): QT    += widgets quickwidgets


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES +=  \
    arduinodon.cpp \
    adherent.cpp \
    arduino.cpp \
    authenticator.cpp \
    beneficiaire.cpp \
    connection.cpp \
client.cpp \
    don.cpp \
    liaison.cpp \
    gestionlivraison.cpp \
    main.cpp \
    mainwindow.cpp \
    qrcode.cpp \
    peermanager.cpp \
    server.cpp \
    smtp.cpp
HEADERS += \
    arduinodon.h \
    adherent.h \
    arduino.h \
    authenticator.h \
    beneficiaire.h \
    connection.h \
client.h \
    don.h \
    liaison.h \
    gestionlivraison.h \
    mainwindow.h \
    qrcode.h \
    peermanager.h \
    server.h \
    smtp.h
FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
QT += quick

RESOURCES += \
    qml.qrc
