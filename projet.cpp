#include "projet.h"
#include <QDebug>
#include "connexion.h"
#include <QSqlQuery>

Projet::Projet()
{   id=0;
    nom="";
    type="";
    status="";
    adresse="";
    datedebut="";
    budget=0;
}
Projet::Projet(int id,QString nom,QString type,QString status,QString adresse,QString datedebut, int budget)
{
    this->id=id;
    this->nom=nom;
    this->type=type;
    this->status=status;
    this->adresse=adresse;
    this->datedebut=datedebut;
    this->budget=budget;
}
int Projet::getid(){return id;}
QString Projet::getnom(){return  nom;}
QString Projet::gettype(){return  type;}
QString Projet::getstatus(){return  status;}
QString Projet::getadresse(){return  adresse;}
QString Projet::getdatedebut(){return  datedebut;}
int Projet::getbudget(){return budget;}

bool Projet::ajouter()
{
QSqlQuery query;
QString res= QString::number(id);
query.prepare("INSERT INTO projet (ID, NOM, TYPE, STATUS, ADRESSE, DATEDEBUT, BUDGET) "
                    "VALUES (:id, :nom, :type, :status, :adresse, :datedebut, :budget)");
query.bindValue(":id", res);
query.bindValue(":nom", nom);
query.bindValue(":type", type);
query.bindValue(":status", status);
query.bindValue(":adresse", adresse);
query.bindValue(":datedebut", datedebut);
query.bindValue(":budget", budget);

return    query.exec();
}

QSqlQueryModel * Projet::afficher()
{QSqlQueryModel * model= new QSqlQueryModel();
model->setQuery("select * from projet");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("ID"));
model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom "));
model->setHeaderData(2, Qt::Horizontal, QObject::tr("Type"));
model->setHeaderData(3, Qt::Horizontal, QObject::tr("Status"));
model->setHeaderData(4, Qt::Horizontal, QObject::tr("Adresse"));
model->setHeaderData(5, Qt::Horizontal, QObject::tr("Datedebut"));
model->setHeaderData(6, Qt::Horizontal, QObject::tr("Budget"));
    return model;
}

bool Projet::supprimer(int idd)
{
QSqlQuery query;
QString res= QString::number(idd);
query.prepare("Delete from projet where ID = :id ");
query.bindValue(":id", res);
return    query.exec();
}
/*bool Projet::modifier()
{

QSqlQuery query;
QString res= QString::number(id);

query.prepare("update projet set  nom='"+nom+"',type='"+type+"' , status='"+status+"', adresse='"+adresse+"', datedebut='"+datedebut+"', budget='"+budget+"'  where id='"+res+"'  ;");
query.bindValue(":id", res) ;
query.bindValue(":nom", nom) ;
query.bindValue(":type", type) ;
query.bindValue(":status", status) ;
query.bindValue(":adresse", adresse) ;
query.bindValue(":datedebut", datedebut) ;
query.bindValue(":budget", budget) ;
return    query.exec();
}

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
bool Projet::modifier(int id ,QString nom,QString type,QString status,QString adresse,QString datedebut,int budget)
{
    QSqlQuery query;
    query.prepare("UPDATE projet SET id= :id,nom= :nom,type = :type,status = :status,adresse = :adresse,datedebut= :datedebut,budget= :budget  WHERE id= :id ");
    query.bindValue(":id",id);
    query.bindValue(":nom",nom);
    query.bindValue(":type",type);
    query.bindValue(":status",status);
    query.bindValue(":adresse",adresse);
    query.bindValue(":datedebut",datedebut);
    query.bindValue(":budget",budget);

    return    query.exec();
}
QSqlQueryModel * Projet::rechercher(int id)
{

    QSqlQueryModel *model=new QSqlQueryModel();
    QSqlQuery query;
    query.prepare("Select * from projet where id =:id");
    query.bindValue(":id",id);
    query.exec();
    model->setQuery(query);
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

        return model;
   }
QSqlQueryModel * Projet::afficher_tri()
{
    QSqlQueryModel * model= new QSqlQueryModel();

model->setQuery("select * from projet order by ID desc ");
model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));

    return model;
}
int Projet::calculer(QString type) {
  QSqlQuery query;
  query.prepare("select * from projet where type = :type");
  query.bindValue(":type", type);

  query.exec();
  int total = 0;
  while (query.next()) {
    total++;
  }

  return total;
}
projeth::projeth()
{
nom="";
datee="";
fn="";
}
projeth::projeth(QString nom,QString datee,QString fn)
{
    this->nom=nom;
    this->datee=datee;
    this->fn=fn ;
}
QString projeth::get_datee(){return  datee;}
QString projeth::get_fn(){return  fn;}
QString projeth::get_nom(){return  nom;}
bool projeth::ajoutehis()
{
    QSqlQuery query;
    query.prepare("INSERT INTO historique (NOM, DATEE, FN) "
                  "VALUES (:nom, :datee, :fn)");
    query.bindValue(":nom", nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
bool projeth::modifierhis()
{
    QSqlQuery query;
    query.prepare("UPDATE historique SET datee='"+datee+"',fn='"+fn+"' where nom='"+nom+"'  ;");
    query.bindValue(":nom",nom);
    query.bindValue(":datee", datee);
    query.bindValue(":fn", fn);
    return    query.exec();
}
QSqlQueryModel * projeth::afficherhis()
{
    QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from historique");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("NOM"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("date "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("fonction "));
        return model;

}

