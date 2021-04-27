#-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T08:31:47
#
#-------------------------------------------------
QT += core gui  multimedia serialport



QMAKE_CXXFLAGS+=-std=gnu++11
QT       += core gui sql
QT       +=printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Atelier_Crud_Vf
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
    arduino.cpp \
    fournisseur.cpp \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    materiel.cpp \
    smtp.cpp

HEADERS += \
    arduino.h \
    fournisseur.h \
        mainwindow.h \
    connexion.h \
    materiel.h \
    smtp.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Image.qrc

DISTFILES += \
    ../add2.png \
    ../card2.png \
    ../delete2.png \
    ../find2.png \
    ../mail2.png \
    ../menu2.png \
    ../return2.png \
    ../update2.png
