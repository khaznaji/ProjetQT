#ifndef ADMIN_H
#define ADMIN_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include "mainwindow.h"
#include "ui_mainwindow.h"
class admin
{
public:
    admin();
    admin(QString , QString);
    bool chercher(QString ID, QString MDP);
private:
    QString id;
    QString mdp;
};

#endif // ADMIN_H
