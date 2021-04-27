#include "article.h"
#include<QSqlQuery>
article::article()
{
    id=0;
    titre="";
    type="";
    msg="";
    dt="";

}
article::article(int id,QString titre,QString type, QString msg,QString dt)
{
  this->id=id;
 this->titre=titre;
    this->type=type;
  this->msg=msg;
  this->dt=dt;

}
void article::set_titre(QString title){ titre=title; }
void article::set_type(QString tp){ type=tp; }
void article::set_msg(QString message){ msg=message; }
void article::set_dt(QString dte){ dt=dte; }
void article::set_id(int ida){ id=ida; }



bool article::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO article (ID, titre,type, msg, dt) "
                    "VALUES (:id,:titre ,:type , :msg ,:dt)");
query.bindValue(":id", res);

query.bindValue(":titre", titre);
query.bindValue(":type", type);
query.bindValue(":msg", msg);
query.bindValue(":dt", dt);

return    query.exec();
}

QSqlQueryModel * article::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from article");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("msg"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("dt"));

    return model;
}

bool article::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from article where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool article::modifier_a (int id,QString titre ,QString type,QString msg,QString dt)
{
    QSqlQuery query;
    query.prepare("UPDATE article SET id= :id,titre= :titre,type = :type,msg = :msg,dt = :dt  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":titre",titre);
    query.bindValue(":type",type);
    query.bindValue(":msg",msg);
    query.bindValue(":dt",dt);

    return    query.exec();
}
QSqlQueryModel *article::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from article where id LIKE '"+rech+"%' or id LIKE '"+rech+"%'");
    return model;
}
//tri
QSqlQueryModel * article::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from article ORDER BY id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("titre "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("type"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("msg"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("dt"));

        return model;
}


