#ifndef ARTICLE_H
#define ARTICLE_H
#include <QString>
#include <QSqlQueryModel>

class article
{
public:
    article();
    article(int id,QString titre,QString type,QString msg, QString dt);
    QString get_titre();
    QString get_type();
    QString get_msg();
    QString get_dt();
    int get_id();
    void set_titre(QString);
    void set_type(QString);
    void set_msg(QString);
    void set_dt(QString);
    void set_id(int);
    bool ajouter();
    QSqlQueryModel * afficher();
    bool supprimer(int);
    bool modifier_a(int,QString,QString,QString,QString);
    QSqlQueryModel * rechercher(QString);
    QSqlQueryModel * tri();
private:
    QString titre,type,msg,dt;
    int id;
};

#endif // ARTICLE_H
