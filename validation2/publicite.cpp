#include "publicite.h"
#include <QDebug>
#include "connexion.h"

publicite::publicite()
{
id=0;
titre=" ";
form=" ";
description=" ";
dte=" ";

}
publicite::publicite(int id, QString titre,QString form,QString description,QString dte)
{
  this->id=id;
  this->titre=titre;
  this->form=form;
  this->description=description;
  this->dte=dte;



}

void publicite::set_id(int idd){ id=idd; }
void publicite::set_titre(QString tit){ titre=tit; }
void publicite::set_form(QString frm){ form=frm; }
void publicite::set_description(QString descr){ description=descr; }
void publicite::set_dte(QString dt){ dte=dt; }


bool publicite::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO publicite (ID, TITRE, FORM,DESCRIPTION,DTE) "
                    "VALUES (:id, :titre, :form, :description, :dte)");
query.bindValue(":id", id);
query.bindValue(":titre", titre);
query.bindValue(":form", form);
query.bindValue(":description", description);
query.bindValue(":date", dte);



return    query.exec();
}

QSqlQueryModel * publicite::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from publicite");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("TITRE "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("FORM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("DTE"));






    return model;
}

bool publicite::supprimer(int id)
{
QSqlQuery query;

query.prepare("Delete from publicite where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}
QSqlQueryModel *publicite::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from publicite where id LIKE '"+rech+"%' or titre LIKE '"+rech+"%'");
    return model;
}
/*bool participant::modifier(QString nom)
{
    QSqlQuery query;

  query.prepare("UPDATE publicite set prenom='"+prenom+"',mail='"+mail+"',CIN='"+CIN+"',numtel='"+numtel+"',datenaissance='"+datenaissance+"',typeeve='"+typeeve+"' WHERE nom LIKE '"+nom+"' ");
   return query.exec();
    }*/
bool publicite::modifier (int id, QString titre,QString form,QString description,QString dte)
{
    QSqlQuery query;
    query.prepare("UPDATE publicite SET id= :id,titre= :titre,form = :form,description= :description,dte = :dte WHERE id= :id ");
    query.bindValue(":id", id);
    query.bindValue(":titre", titre);
    query.bindValue(":form", form);
    query.bindValue(":description", description);
    query.bindValue(":dte", dte);
 return    query.exec();
}
QSqlQueryModel * publicite::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from publicite ORDER BY id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("TITRE "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("FORM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("DESCRIPTION"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("DTE"));




        return model;
}
