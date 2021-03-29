#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "participant.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);


ui->tabevenement->setModel(tmpevenement.afficher());
ui->tabparticipant->setModel(tmpparticipant.afficher());

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    QString titre= ui->lineEdit_titre->text();
    QString type= ui->lineEdit_type->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString datedebut= ui->lineEdit_datedebut->text();
    QString datefin= ui->lineEdit_datefin->text();


  evenement e(titre,type,lieu,datedebut,datefin);
  bool test=e.ajouter();
  if(test)
{

      ui->tabevenement->setModel(tmpevenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un événement"),
                  QObject::tr("Evenement ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un événement"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
 QString titre= ui->lineEdit_titres->text();
bool test=tmpevenement.supprimer(titre);
if(test)
{ui->tabevenement->setModel(tmpevenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un événement"),
                QObject::tr("Evénement supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un événement"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_rechercher_clicked()
{
    QString rech =ui->lineEditrech->text();
   ui->tabevenement->setModel(tmpevenement.rechercher(rech));
}


void MainWindow::on_pb_ajouter_2_clicked()
{
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adresse= ui->lineEdit_adresse->text();

  participant p(nom,prenom,adresse);
  bool test=p.ajouter();
  if(test)
{

      ui->tabparticipant->setModel(tmpparticipant.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un participant"),
                  QObject::tr("Participant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un participant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    QString titre=ui->lineEdit_titre_2->text();
    QString type=ui->lineEdit_type_2->text();
    QString lieu=ui->lineEdit_lieu_2->text();
    QString datedebut=ui->lineEdit_datedebut_2->text();
    QString datefin=ui->lineEdit_datefin_2->text();
    evenement e(titre,type,lieu,datedebut,datefin);
    if(e.modifier(titre))
    {
          ui->tabevenement->setModel(tmpevenement.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un événement"),
                          QObject::tr("événement modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un événement"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


}

void MainWindow::on_pb_tri_clicked()
{
     ui->tabevenement->setModel(tmpevenement.tri());
}

void MainWindow::on_pb_modifier_2_clicked()
{
    QString nom=ui->lineEdit_nom_2->text();
    QString prenom=ui->lineEdit_prenom_2->text();
    QString adresse=ui->lineEdit_adresse_2->text();

    participant p(nom,prenom,adresse);
    if(p.modifier(nom))
    {
          ui->tabparticipant->setModel(tmpparticipant.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un participant"),
                          QObject::tr("participant modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un participant"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }
}

void MainWindow::on_pb_supprimer2_clicked()
{
    QString nom= ui->lineEdit_noms->text();
   bool test=tmpparticipant.supprimer(nom);
   if(test)
   {ui->tabparticipant->setModel(tmpparticipant.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un participant"),
                   QObject::tr("participant supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un participant"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}


void MainWindow::on_pb_tri_2_clicked()
{
     ui->tabparticipant->setModel(tmpparticipant.tri());
}

void MainWindow::on_pb_rechercher_2_clicked()
{
    QString rech =ui->lineEditrech_2->text();
   ui->tabparticipant->setModel(tmpparticipant.rechercher(rech));
}
