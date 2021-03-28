#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Membre.h"
#include"fonction.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);


ui->tabmembre->setModel(tmpmembre.afficher());
ui->tableView->setModel(tmpfonction.afficher());
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{   int num = ui->lineEdit_3->text().toInt();
    int slr = ui->lineEdit_4->text().toInt();
    int id = ui->lineEdit_id->text().toInt();
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString adr=ui->lineEdit->text();
    QString mail=ui->lineEdit_2->text();
  Membre m(id,slr,num,nom,prenom,adr,mail);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmembre->setModel(tmpmembre.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un membre"),
                  QObject::tr("Membre ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un membre"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pb_supprimer_clicked()
{

}

void MainWindow::on_pb_supprimer_3_clicked()
{
int id = ui->lineEdit_id_2->text().toInt();
bool test=tmpmembre.supprimer(id);
if(test)
{ui->tabmembre->setModel(tmpmembre.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un membre"),
                QObject::tr("Membre supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un membre"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}


void MainWindow::on_pushButton_clicked()
{
    int id = ui->lineEdit_6->text().toInt();
    int num = ui->lineEdit_11->text().toInt();
    int slr = ui->lineEdit_12->text().toInt();
    QString nom = ui->lineEdit_7->text();
    QString prenom = ui->lineEdit_8->text();
    QString adr = ui->lineEdit_9->text();
    QString mail = ui->lineEdit_10->text();
    Membre m;
    bool test=m.modifier(id,num,slr,nom,prenom,adr,mail);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie un membre"),
                          QObject::tr("membre modifie.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tabmembre->setModel(tmpmembre.afficher());

}

void MainWindow::on_pushButton_5_clicked()
{
    int id = ui->lineEdit_15->text().toInt();
    QString dep= ui->lineEdit_16->text();
    QString dir= ui->lineEdit_17->text();
    QString ser=ui->lineEdit_18->text();
    QString pos=ui->lineEdit_13->text();
  fonction f (id,dep,dir,ser,pos);
  bool test=f.ajouter();
  if(test)
{

      ui->tableView->setModel(tmpfonction.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter une fonction"),
                  QObject::tr("fonction ajoutée.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter une fonction"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}

void MainWindow::on_pushButton_4_clicked()
{
    {
    int id = ui->lineEdit_14->text().toInt();
    bool test=tmpfonction.supprimer(id);
    if(test)
    {ui->tableView->setModel(tmpfonction.afficher());//refresh
        QMessageBox::information(nullptr, QObject::tr("Supprimer une fonction"),
                    QObject::tr("Fonction supprimée.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);

    }
    else
        QMessageBox::critical(nullptr, QObject::tr("Supprimer une fonction"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);


    }
}

void MainWindow::on_pushButton_8_clicked()
{

    int id = ui->lineEdit_24->text().toInt();

    QString dep = ui->lineEdit_20->text();
    QString dir = ui->lineEdit_25->text();
    QString pos = ui->lineEdit_27->text();
    QString ser = ui->lineEdit_26->text();
    fonction f;
    bool test=f.modifier_f (id,dep,dir,pos,ser);

    if(test)
    {
        QMessageBox::information(nullptr, QObject::tr("modifie une fonction"),
                          QObject::tr("fonctin modifiée.\n"
                                      "Click Cancel to exit."), QMessageBox::Cancel);
    }
    else
        QMessageBox::critical(nullptr, QObject::tr("non modifie"),
                    QObject::tr("Erreur !.\n"
                                "Click Cancel to exit."), QMessageBox::Cancel);
        ui->tableView->setModel(tmpfonction.afficher());

}
//recherche
void MainWindow::on_pushButton_9_clicked()
{
    QString rech =ui->lineEdit_5->text();

       ui->tabmembre->setModel(tmpmembre.rechercher(rech));
}


void MainWindow::on_comboBox_activated(int )
{ ui->tabmembre->setModel(tmpmembre.tri());

}

void MainWindow::on_pushButton_10_clicked()
{
    QString rech =ui->lineEdit_19->text();

       ui->tableView->setModel(tmpfonction.rechercher(rech));
}

void MainWindow::on_comboBox_2_activated(const QString &arg1)
{ui->tableView->setModel(tmpfonction.tri());

}
