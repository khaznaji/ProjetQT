#include "fonction.h"
#include <QDebug>
#include "connexion.h"
fonction::fonction()
{
    id=0;
    dep="";
    dir="";
    pos="";
    ser="";


}
fonction::fonction(int id,QString dep,QString dir, QString pos,QString ser)
{
  this->id=id;
 this->dep=dep;
    this->dir=dir;
  this->pos=pos;
  this->ser=ser;

}
void fonction::set_dep(QString departement){ dep=departement; }
void fonction::set_dir(QString direction){ dir=direction; }
void fonction::set_ser(QString service){ ser=service; }
void fonction::set_pos(QString poste){ pos=poste; }
void fonction::set_id(int idf){ id=idf; }



bool fonction::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO fonction (ID, DEP,DIR, SER, POS) "
                    "VALUES (:id, :dep, :dir ,:ser , :pos)");
query.bindValue(":id", res);

query.bindValue(":dep", dep);
query.bindValue(":dir", dir);
query.bindValue(":ser", ser);
query.bindValue(":pos", pos);

return    query.exec();
}

QSqlQueryModel * fonction::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from fonction");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Département "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Direction"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Service"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Poste"));

    return model;
}

bool fonction::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from fonction where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool fonction::modifier_f (int id,QString dep ,QString dir,QString pos,QString ser)
{
    QSqlQuery query;
    query.prepare("UPDATE fonction SET id= :id,dep= :dep,dir = :dir,pos = :pos,ser = :ser  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":dep",dep);
    query.bindValue(":dir",dir);
    query.bindValue(":pos",pos);
query.bindValue(":ser",ser);
    return    query.exec();
}



