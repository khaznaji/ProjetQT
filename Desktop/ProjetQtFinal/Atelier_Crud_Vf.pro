    #-------------------------------------------------
#
# Project created by QtCreator 2018-10-31T08:31:47
#
#-------------------------------------------------
QT       +=printsupport serialport
QT       += core gui sql
QT += core gui  multimedia multimediawidgets
QT       +=multimedia
QT       += core gui charts

QMAKE_CXXFLAGS+=-std=gnu++11
RC_ICONS =logo.ico

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
    Membre.cpp \
    arduin.cpp \
    ardyuno2.cpp \
    article.cpp \
    fonction.cpp \
        main.cpp \
        mainwindow.cpp \
    connexion.cpp \
    mainwindowvideo.cpp \
    note.cpp \
    smtp.cpp \
    stat.cpp

HEADERS += \
    Membre.h \
    arduin.h \
    ardyuno2.h \
    article.h \
    fonction.h \
        mainwindow.h \
    connexion.h \
    mainwindowvideo.h \
    note.h \
    smtp.h \
    stat.h

FORMS += \
        ardyuno2.ui \
        mainwindow.ui \
        mainwindowvideo.ui \
        note.ui \
        stat.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Image.qrc

DISTFILES += \
    ../bluee.jpg \
    ../img/pdf.png \
    ../ll.jpg
