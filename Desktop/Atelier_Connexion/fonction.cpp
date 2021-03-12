#include "fonction.h"
#include <QSqlQuery>
#include <QtDebug>

Fonction::Fonction()
{
idfonction=0; dep=" ";  dir=" ";  poste=" ";  service=" ";
}
Fonction::Fonction(int idfonction,QString dep,QString dir ,QString poste ,QString service)
{this->idfonction=idfonction; this->dep=dep; this->dir=dir;this->poste=poste;this->service=service;}
int Fonction::getidfonction(){return idfonction;}
QString Fonction::getdir(){return  dir;}
QString Fonction::getdep(){return  dep;}
QString Fonction::getposte(){return  poste;}
QString Fonction::getservice(){return  service;}
void Fonction::setidfonction(int idfonction){this->idfonction=idfonction;}
void Fonction::setdep(QString dep){this->dep=dep;}
void Fonction::setdir(QString dir){this->dir=dir;}
void Fonction::setposte(QString poste){this->poste=poste;}
void Fonction::setservice(QString service){this->service=service;}

bool Fonction::ajouterfonction()
{


    QSqlQuery query;
  QString id_string= QString::number(idfonction);

         query.prepare("INSERT INTO FONCTION(id, dep, dir, poste, service) "
                       "VALUES (:id, :dep, :dir, :poste, :service)");
         query.bindValue(":idfonction",id_string);
         query.bindValue(":dep", dep);
query.bindValue(":dir", dir);
query.bindValue(":poste", poste);
query.bindValue(":service", service);
        return query.exec();

}
