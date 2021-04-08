#include "materiel.h"

Materiel::Materiel()
{
    nom=" ";
    type=" ";
    cout=0;
    duree=0;
    volume=0;
    poids=0;
    nbr=0;


    }
    Materiel::Materiel(QString nom,QString type,int cout ,int duree ,int volume ,int poids ,int nbr)
    {
      this->nom=nom;
      this->type=type;
      this->cout=cout;
      this->duree=duree;
      this->volume=volume;
        this->poids=poids;
        this->nbr=nbr;




    }
    void Materiel::set_nom(QString name){ nom=name; }
    void Materiel::set_type(QString typ){ type=typ; }
    void Materiel::set_cout(int ct){ cout=ct; }
    void Materiel::set_duree(int dr){ duree=dr; }
    void Materiel::set_volume(int vlm){ volume=vlm; }
    void Materiel::set_poids(int pds){ poids=pds; }
    void Materiel::set_nbr(int nombre){ nbr=nombre; }


    bool Materiel::ajouter()
    {
    QSqlQuery query;

    query.prepare("INSERT INTO MATERIEL (NOM, TYPE, COUT, DUREE, VOLUME,POIDS,NBR) "
                        "VALUES (:nom, :type, :cout, :duree, :volume, :poids, :nbr)");
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":cout", cout);
    query.bindValue(":duree", duree);
    query.bindValue(":volume", volume);
    query.bindValue(":poids", poids);

    query.bindValue(":nbr", nbr);




    return    query.exec();
    }

    QSqlQueryModel * Materiel::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from MATERIEL");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Type "));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Cout"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Duree "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Volume"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Poids"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Nbr"));

        return model;
    }

    bool Materiel::supprimer(QString nom)
    {
    QSqlQuery query;

    query.prepare("Delete from MATERIEL where NOM = :nom ");
    query.bindValue(":nom", nom);
    return    query.exec();
    }
    QSqlQueryModel *Materiel::rechercher(QString rech)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from MATERIEL where nom LIKE '"+rech+"%' or nom LIKE '"+rech+"%'");
        return model;
    }
    bool Materiel::modifier (QString nom,QString type,int cout ,int duree ,int volume ,int poids ,int nbr)
    {
        QSqlQuery query;
        query.prepare("UPDATE MATERIEL SET nom= :nom,type= :type,cout= :cout,duree= :duree,volume= :volume,poids= :poids, nbr= :nbr  WHERE nom= :nom ");
        query.bindValue(":nom",nom);
        query.bindValue(":type",type);
        query.bindValue(":cout",cout);
        query.bindValue(":duree",duree);
        query.bindValue(":volume",volume);
        query.bindValue(":poids",poids);
        query.bindValue(":nbr",nbr);
        return    query.exec();
    }
    QSqlQueryModel * Materiel::tri()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from MATERIEL ORDER BY nom ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("type"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("cout"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("duree"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("volume"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("poids"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("nbr"));



            return model;
    }


