#include "activite.h"
#include <QDebug>
#include<QDate>
/*activite::activite()
{
nom=" ";
type=" ";
duree=" ";
nbr=" ";
date=" ";

}*/
activite::activite(QString nom,QString type,QString duree,QString nbr,QDate date)
{
  this->nom=nom;
  this->type=type;
  this->duree=duree;
  this->nbr=nbr;
    this->date=date;



}
QString activite::get_nom(){return  nom;}
QString activite::get_type(){return type;}
QString activite::get_duree(){return duree;}
QString activite::get_nbr(){return nbr;}
QDate activite::get_date(){return date;}



bool activite::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO activite (NOM, TYPE, DUREE, NBR ,DATEACT) "
                    "VALUES (:nom, :type, :duree, :nbr , :date)");
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":duree", duree);
query.bindValue(":nbr", nbr);
query.bindValue(":date", date);



return    query.exec();
}

QSqlQueryModel * activite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from activite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEACT"));


    return model;
}

bool activite::supprimer(QString nom)
{
QSqlQuery query;

query.prepare("Delete from activite where NOM = :nom ");
query.bindValue(":nom", nom);
return    query.exec();
}
QSqlQueryModel *activite::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from activite where nom LIKE '"+rech+"%' or type LIKE '"+rech+"%'");
    return model;
}
bool activite::modifier(QString nom)
{
    QSqlQuery query;

  query.prepare("UPDATE activite set type='"+type+"',duree='"+duree+"',nbr='"+nbr+"' WHERE nom LIKE '"+nom+"' ");
   return query.exec();
    }
QSqlQueryModel * activite::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from activite ORDER BY nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("DUREE"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NBR"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DATEACT"));





        return model;
}
