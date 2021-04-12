#include "fournisseur.h"

Fournisseur::Fournisseur()
{ id=0;
    nom=" ";
    prenom="";
    mail="";
     num=0;
    niveau="";
    controle="";



    }
    Fournisseur::Fournisseur(int id,QString nom,QString prenom ,QString mail,int num,QString niveau ,QString controle)
    {      this->id=id;

      this->nom=nom;
      this->prenom=prenom;
      this->mail=mail;
      this->num=num;
      this->niveau=niveau;
        this->controle=controle;





    }
    void Fournisseur::set_id(int idf){ id=idf; }
    void Fournisseur::set_nom(QString name){ nom=name; }
    void Fournisseur::set_prenom(QString last){ prenom=last; }
    void Fournisseur::set_mail(QString email){ mail=email; }

    void Fournisseur::set_num(int n){ num=n; }
    void Fournisseur::set_niveau(QString nv){ niveau=nv; }

    void Fournisseur::set_controle(QString ctrl){ controle=ctrl; }




    bool Fournisseur::ajouter()
    {
    QSqlQuery query;

    query.prepare("INSERT INTO FOURNISSEURS (ID, NOM, PRENOM, MAIL, NUM,NIVEAU,CONTROLE) "
                        "VALUES (:id, :nom, :prenom, :mail, :num, :niveau, :controle)");
    query.bindValue(":id", id);
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":mail", mail);
    query.bindValue(":num", num);
    query.bindValue(":niveau", niveau);

    query.bindValue(":controle", controle);




    return    query.exec();
    }

    QSqlQueryModel * Fournisseur::afficher()
    {QSqlQueryModel * model= new QSqlQueryModel();
    model->setQuery("select * from FOURNISSEURS");
    model->setHeaderData(0, Qt::Horizontal, QObject::tr("Id"));
    model->setHeaderData(1, Qt::Horizontal, QObject::tr("Nom"));
    model->setHeaderData(2, Qt::Horizontal, QObject::tr("Prenom"));
    model->setHeaderData(3, Qt::Horizontal, QObject::tr("Mail "));
    model->setHeaderData(4, Qt::Horizontal, QObject::tr("Num"));
    model->setHeaderData(5, Qt::Horizontal, QObject::tr("Niveau"));
    model->setHeaderData(6, Qt::Horizontal, QObject::tr("Controle"));

        return model;
    }

    bool Fournisseur::supprimer(int idd)
    {
    QSqlQuery query;
QString res= QString::number(idd);
    query.prepare("Delete from FOURNISSEURS where id = :id ");
    query.bindValue(":id", res);
    return    query.exec();
    }
    QSqlQueryModel *Fournisseur::rechercher(QString rech)
    {
        QSqlQueryModel * model= new QSqlQueryModel();
        model->setQuery("select * from FOURNISSEURS where id LIKE '"+rech+"%' or id LIKE '"+rech+"%'");
        return model;
    }
    bool Fournisseur::modifier (int id,QString nom,QString prenom ,QString mail,int num,QString niveau ,QString controle)
    {
        QSqlQuery query;
        query.prepare("UPDATE FOURNISSEURS SET id= :id,nom= :nom,prenom = :nom,mail = :mail,num = :num,niveau = :niveau, controle = :controle  WHERE id= :id ");
        query.bindValue(":id",id);

        query.bindValue(":nom",nom);
        query.bindValue(":prenom",prenom);
        query.bindValue(":mail",mail);
        query.bindValue(":num",num);
        query.bindValue(":niveau",niveau);
        query.bindValue(":controle",controle);
        return    query.exec();
    }
    QSqlQueryModel * Fournisseur::tri()
    {
        QSqlQueryModel * model= new QSqlQueryModel();

        model->setQuery("select * from FOURNISSEURS ORDER BY id ");
        model->setHeaderData(0, Qt::Horizontal, QObject::tr("id"));
        model->setHeaderData(1, Qt::Horizontal, QObject::tr("nom"));
        model->setHeaderData(2, Qt::Horizontal, QObject::tr("prenom"));
        model->setHeaderData(3, Qt::Horizontal, QObject::tr("mail"));
        model->setHeaderData(4, Qt::Horizontal, QObject::tr("num"));
        model->setHeaderData(5, Qt::Horizontal, QObject::tr("niveau"));
        model->setHeaderData(6, Qt::Horizontal, QObject::tr("controle"));



            return model;
    }
