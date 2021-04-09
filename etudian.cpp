#include "etudian.h"

#include <QDebug>
//#include "connexion.h"
adherant::adherant()
{
id=" ";
nom=" ";
prenom=" ";
numtel=" ";
mail=" ";
type=" ";
competence=" ";

}
adherant::adherant(QString id,QString nom,QString prenom,QString numtel,QString mail,QString type,QString competence)
{
  this->id=id;
  this->nom=nom;
  this->prenom=prenom;
  this->numtel=numtel;
  this->mail=mail;
  this->type=type;
  this->competence=competence;



}
void adherant::set_id(QString idd){ id=idd; }
void adherant::set_nom(QString nomm){ nom=nomm; }
void adherant::set_prenom(QString prenomm){ prenom=prenomm; }
void adherant::set_numtel(QString num){ numtel=num; }
void adherant::set_type(QString typ){ type=typ; }
void adherant::set_mail(QString maill){ mail=maill; }
void adherant::set_competence(QString comp){ competence=comp; }


bool adherant::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO adherant (ID, NOM, PRENOM,NUMTEL, MAIL,TYPE,COMPETENCE) "
                    "VALUES (:id, :nom, :prenom, :numtel, :mail, :type, :competence)");
query.bindValue(":id", id);
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":numtel", numtel);
query.bindValue(":mail", mail);
query.bindValue(":type", type);
query.bindValue(":competence", competence);



return    query.exec();
}

QSqlQueryModel * adherant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from adherant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL "));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE "));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("COMPETENCE"));


    return model;
}

bool adherant::supprimer(QString id)
{
QSqlQuery query;

query.prepare("Delete from adherant where ID = :id ");
query.bindValue(":id", id);
return    query.exec();
}
QSqlQueryModel *adherant::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from adherant where id LIKE '"+rech+"%' or nom LIKE '"+rech+"%'");
    return model;
}
bool adherant::modifier(QString id)
{
    QSqlQuery query;

  query.prepare("UPDATE adherant set nom='"+nom+"',prenom='"+prenom+"',numtel='"+numtel+"',mail='"+mail+"',type='"+type+"',competence='"+competence+"' WHERE id LIKE '"+id+"' ");
   return query.exec();
    }
QSqlQueryModel * adherant::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from adherant ORDER BY id ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("NOM "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("PRENOM"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("NUMTEL "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("MAIL"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("TYPE "));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("COMPETENCE"));


        return model;
}
