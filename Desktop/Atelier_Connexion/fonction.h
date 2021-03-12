#ifndef FONCTION_H
#define FONCTION_H
#include <QString>
#include <QSqlQueryModel>
#include <QSqlTableModel>

class Fonction
{Fonction(int,QString,QString,QString,QString);
    int getidfonction();
    QString getdep();
    QString getdir();
    QString getposte();
    QString getservice();
    void setidfonction(int);
    void setdep(QString);
    void setdir(QString);
    void setposte(QString);
    void setservice(QString);

    bool ajouterfonction();

public:
    Fonction();
    int idfonction;
    QString dir;
    QString dep;
    QString poste;
    QString service;

};

#endif // FONCTION_H
