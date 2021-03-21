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
    void set_dep(QString);
    void set_dir(QString);
    void set_ser(QString);
    void set_pos(QString);
    void set_id(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_f(int,QString,QString,QString,QString);
private:
    QString dep,dir,ser,pos;
    int id;
};

#endif // FONCTION_H
