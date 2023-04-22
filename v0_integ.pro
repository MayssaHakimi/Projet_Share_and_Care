QT += sql
QT += charts
QT += network
QT       += serialport
QT       += core gui  serialport
QT       += core gui sql multimedia printsupport charts network serialport
greaterThan(QT_MAJOR_VERSION, 4): QT    += widgets


# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11



# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adherent.cpp \
    authenticator.cpp \
    beneficiaire.cpp \
    client.cpp \
    connection.cpp \
    don.cpp \
    gestionadherent.cpp \
    gestionbeneficiaire.cpp \
    gestiondon.cpp \
    liaison.cpp \
    main.cpp \
    mainwindow.cpp \
    peermanager.cpp \
    qrcode.cpp \
    server.cpp \
    smtp.cpp

HEADERS += \
    adherent.h \
    authenticator.h \
    beneficiaire.h \
    client.h \
    connection.h \
    don.h \
    gestionadherent.h \
    gestionbeneficiaire.h \
    gestiondon.h \
    liaison.h \
    mainwindow.h \
    peermanager.h \
    qrcode.h \
    server.h \
    smtp.h

FORMS += \
    Gestionadherent.ui \
gestiondon.ui \
gestionbeneficiaire.ui \
    mainwindow.ui  

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
