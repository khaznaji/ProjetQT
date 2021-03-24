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


ui->tabetudiant->setModel(tmpevenement.afficher());
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

  evenement e(titre,type,lieu);
  bool test=e.ajouter();
  if(test)
{

      ui->tabetudiant->setModel(tmpevenement.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un événement"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{
 QString titre= ui->lineEdit_titres->text();
bool test=tmpevenement.supprimer(titre);
if(test)
{ui->tabetudiant->setModel(tmpevenement.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Etudiant supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un étudiant"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}




void MainWindow::on_pb_rechercher_clicked()
{
    QString rech =ui->lineEditrech->text();
   ui->tabetudiant->setModel(tmpevenement.rechercher(rech));
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
QMessageBox::information(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Etudiant ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un étudiant"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
}

void MainWindow::on_pb_modifier_clicked()
{
    QString titre=ui->lineEdit_titre_2->text();
    QString type=ui->lineEdit_type_2->text();
    QString lieu=ui->lineEdit_lieu_2->text();
    evenement e(titre,type,lieu);
    if(e.modifier(titre))
    {
          ui->tabetudiant->setModel(tmpevenement.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un Citoyen"),
                          QObject::tr("citoyen modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un Citoyen"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


}

void MainWindow::on_pb_tri_clicked()
{
     ui->tabetudiant->setModel(tmpevenement.tri());
}
