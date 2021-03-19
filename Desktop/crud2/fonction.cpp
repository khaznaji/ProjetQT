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
QString fonction::get_dep(){return  dep;}
QString fonction::get_dir(){return dir;}
QString fonction::get_ser(){return  ser;}
QString fonction::get_pos(){return  pos;}
int fonction::get_id(){return  id;}


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
model->setHeaderData(1, Qt::Horizontal, QObject::tr("dep "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("dir"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("ser"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("pos"));

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



