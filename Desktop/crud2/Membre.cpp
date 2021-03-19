#include "Membre.h"
#include <QDebug>
#include "connexion.h"
Membre::Membre()
{
id=0;
num=0;
nom="";
prenom="";
adr="";
mail="";
slr=0;
}
Membre::Membre(int id,int num, int slr,QString nom,QString prenom,QString adr, QString mail)
{
  this->id=id;
 this->slr=slr;
    this->num=num;
  this->nom=nom;
  this->prenom=prenom;
    this->adr=adr;
    this->mail=mail;
}
QString Membre::get_nom(){return  nom;}
QString Membre::get_prenom(){return prenom;}
QString Membre::get_adr(){return  adr;}
QString Membre::get_mail(){return  mail;}
int Membre::get_id(){return  id;}
int Membre::get_slr(){return  slr;}
int Membre::get_num(){return  num;}

bool Membre::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO membre (ID, NOM, SLR, PRENOM, NUM, ADR, MAIL) "
                    "VALUES (:id, :nom, :slr ,:prenom , :num, :adr, :mail)");
query.bindValue(":id", res);
query.bindValue(":slr", res);
query.bindValue(":num", res);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":adr", adr);
query.bindValue(":mail", mail);

return    query.exec();
}

QSqlQueryModel * Membre::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from membre");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prénom"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("adr"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("mail"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("num"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("slr"));
    return model;
}

bool Membre::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from membre where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Membre::modifier (int id,int num ,int slr, QString nom ,QString prenom,QString adr,QString mail)
{
    QSqlQuery query;
    query.prepare("UPDATE membre SET id= :id,num= :num,slr = :slr,nom = :nom,prenom = :prenom,adr = :adr, mail = :mail  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":num",num);
    query.bindValue(":slr",slr);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":adr",adr);
    query.bindValue(":mail",mail);
    return    query.exec();
}
