#ifndef FONCTION_H
#define FONCTION_H
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>

class fonction
{
public:
    fonction();

    fonction(int,QString,QString,QString,QString);
    QString get_dep();
    QString get_dir();
    QString get_ser();
    QString get_pos();
    int get_id();
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_f(int,QString,QString,QString,QString);
private:
    QString dep,dir,ser,pos;
    int id;
};

#endif // FONCTION_H
