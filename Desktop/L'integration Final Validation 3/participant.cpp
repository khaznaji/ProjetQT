#include "participant.h"
#include <QDebug>
#include "connexion.h"

participant::participant()
{
nom=" ";
prenom=" ";
mail=" ";
CIN=0;
numtel=0;
datenaissance=" ";
typeeve=" ";

}
participant::participant(QString nom,QString prenom,QString mail,int CIN,int numtel, QString datenaissance,QString typeeve)
{
  this->nom=nom;
  this->prenom=prenom;
  this->mail=mail;
  this->CIN=CIN;
  this->numtel=numtel;
  this->datenaissance=datenaissance;
  this->typeeve=typeeve;



}

void participant::set_nom(QString name){ nom=name; }
void participant::set_prenom(QString pren){ prenom=pren; }
void participant::set_mail(QString adrm){ mail=adrm; }
void participant::set_CIN(int cdi){ CIN=cdi; }
void participant::set_numtel(int ntel){ ntel=numtel; }
void participant::set_datenaissance(QString date){ datenaissance=date; }
void participant::set_typeeve(QString type){ typeeve=type; }


bool participant::ajouter()
{
QSqlQuery query;

query.prepare("INSERT INTO participant (NOM, PRENOM, MAIL,CIN,NUMTEL,DATENAISSANCE,TYPEEVE) "
                    "VALUES (:nom, :prenom, :mail, :CIN, :numtel, :datenaissance, :typeeve)");
query.bindValue(":nom", nom);
query.bindValue(":prenom", prenom);
query.bindValue(":mail", mail);
query.bindValue(":CIN", CIN);
query.bindValue(":numtel", numtel);
query.bindValue(":datenaissance", datenaissance);
query.bindValue(":typeeve", typeeve);



return    query.exec();
}

QSqlQueryModel * participant::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from participant");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("PRENOM "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("MAIL"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("NUMTEL "));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("DATENAISSANCE"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("TYPEEVE"));






    return model;
}

bool participant::supprimer(QString nom)
{
QSqlQuery query;

query.prepare("Delete from participant where NOM = :nom ");
query.bindValue(":nom", nom);
return    query.exec();
}
QSqlQueryModel *participant::rechercher(QString rech)
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from participant where nom LIKE '"+rech+"%' or prenom LIKE '"+rech+"%'");
    return model;
}
/*bool participant::modifier(QString nom)
{
    QSqlQuery query;

  query.prepare("UPDATE participant set prenom='"+prenom+"',mail='"+mail+"',CIN='"+CIN+"',numtel='"+numtel+"',datenaissance='"+datenaissance+"',typeeve='"+typeeve+"' WHERE nom LIKE '"+nom+"' ");
   return query.exec();
    }*/
bool participant::modifier (QString nom,QString prenom ,QString mail, int CIN ,int numtel ,QString datenaissance,QString typeeve)
{
    QSqlQuery query;
    query.prepare("UPDATE participant SET nom= :nom,prenom= :prenom,mail = :mail,CIN= :CIN,numtel = :numtel,datenaissance = :datenaissance, typeeve = :typeeve  WHERE nom= :nom ");
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":mail",mail);
    query.bindValue(":CIN",CIN);
    query.bindValue(":numtel",numtel);
    query.bindValue(":datenaissance",datenaissance);
    query.bindValue(":typeeve",typeeve);
 return    query.exec();
}
QSqlQueryModel * participant::tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

    model->setQuery("select * from participant ORDER BY nom ");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("typeeve"));





        return model;
}
QSqlQueryModel * participant::rechercheDynamic(QString SearchName)
{

    QSqlQueryModel *model = new QSqlQueryModel;
    model->setQuery("SELECT * from participant where nom LIKE '"+SearchName+"%'OR prenom like '"+SearchName+"%'");

    model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("mail"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("CIN"));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("numtel "));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("datenaissance"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("typeeve"));



    return  model;
}


QSqlQueryModel * participant::affecter_evenement()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select titre from evenement");

        return model;
}
