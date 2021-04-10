#include "sponsor.h"
#include <QDebug>
#include "connection.h"
#include <QSqlQuery>

Sponsor::Sponsor()
{   id=0;
    nom="";
    adresse="";
    mail="";
    produit="";
    convention="";
    numtel=0;
}
Sponsor::Sponsor(int id,QString nom,QString adresse,QString mail,QString produit,QString convention, int numtel)
{
    this->id=id;
    this->nom=nom;
    this->adresse=adresse;
    this->mail=mail;
    this->produit=produit;
    this->convention=convention;
    this->numtel=numtel;
}
int Sponsor::getid(){return id;}
QString Sponsor::getnom(){return  nom;}
QString Sponsor::getadresse(){return  adresse;}
QString Sponsor::getmail(){return  mail;}
QString Sponsor::getproduit(){return  produit;}
QString Sponsor::getconvention(){return  convention;}
int Sponsor::getnumtel(){return numtel;}

bool Sponsor::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO sponsor (ID, NOM, adresse, mail, produit, convention, numtel) "
                    "VALUES (:id, :nom, :adresse, :mail, :produit, :convention, :numtel)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":adresse", adresse);
query.bindValue(":mail", mail);
query.bindValue(":produit", produit);
query.bindValue(":convention", convention);
query.bindValue(":numtel", numtel);

return    query.exec();
}

QSqlQueryModel * Sponsor::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from sponsor");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Produit"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Convention"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Numtel"));
    return model;
}

bool Sponsor::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from sponsor where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
bool Sponsor::modifier(int id ,QString nom,QString adresse,QString mail,QString produit,QString convention,int numtel)
{
    QSqlQuery query;
    query.prepare("UPDATE sponsor SET id= :id,nom= :nom,adresse = :adresse,mail = :mail,produit = :produit,convention= :convention,numtel= :numtel  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":adresse",adresse);
    query.bindValue(":mail",mail);
    query.bindValue(":produit",produit);
    query.bindValue(":convention",convention);
    query.bindValue(":numtel",numtel);

    return    query.exec();
}
/*
bool Projet::modifier(int id,QString nom,QString type,QString status,QString adresse,QString datedebut,int budget)
{
    QSqlQuery query ;
    QString res_id = QString::number(id) ;

    query.prepare("update projet set (ID=:id, NOM=:nom, TYPE=:type, STATUS=:status, ADRESSE=:adresse, DATEDEBUT=:datedebut,BUDGET=:budget) where ID=:id");

    query.bindValue(":id", res_id) ;
    query.bindValue(":nom", nom) ;
    query.bindValue(":type", type) ;
    query.bindValue(":status", status) ;
    query.bindValue(":adresse", adresse) ;
    query.bindValue(":datedebut", datedebut) ;
    query.bindValue(":budget", budget) ;
    return query.exec() ;

}*/
QSqlQueryModel * Sponsor::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from sponsor where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
QSqlQueryModel * Sponsor::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from sponsor order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}

