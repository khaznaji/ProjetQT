#include "mainwindow.h"
#include "ui_mainwindow.h"
#include"materiel.h"
#include"fournisseur.h"
#include <QMessageBox>
#include<QFileDialog>
#include<QMediaPlayer>
#include<QSound>
#include<QUrl>
#include<QString>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "participant.h"
#include "mainwindow.h"
#include "smtp.h"
#include<QPropertyAnimation>












MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);

mMediaPlayer=new QMediaPlayer(this);
connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){ui->avance_3->setValue(pos);});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){ui->avance_3->setMaximum(dur);});
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(Browse()));


ui->tabmateriel->setModel(tmpmateriel.afficher());
ui->tabfournisseurs->setModel(tmpfournisseur.afficher());
animation =new QPropertyAnimation(ui->label_56,"geometry");

    animation->setDuration(10000);
    animation->setStartValue(ui->label_56->geometry());
    animation->setEndValue(QRect(200,65,400,90));

    QEasingCurve curve;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    animation->setLoopCount(2);
    animation->start();
    /****Animation2*********/

    animation =new QPropertyAnimation(ui->label_8,"geometry");
    animation->setDuration(10000);
    animation->setStartValue(ui->label_8->geometry());
    animation->setEndValue(QRect(200,65,400,90));

    QEasingCurve curver;
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    animation->setLoopCount(2);
    animation->start();
}

void MainWindow::Browse()
{
    files.clear();

    QFileDialog dialog(this);
    dialog.setDirectory(QDir::homePath());
    dialog.setFileMode(QFileDialog::ExistingFiles);

    if (dialog.exec())
        files = dialog.selectedFiles();

    QString fileListString;
    foreach(QString file, files)
        fileListString.append( "\"" + QFileInfo(file).fileName() + "\" " );

    ui->file->setText( fileListString );

}

void MainWindow::sendMail()
{
    Smtp* smtp = new Smtp(ui->uname->text(), ui->paswd->text(), ui->server->text(), ui->port->text().toInt());
    connect(smtp, SIGNAL(status(QString)), this, SLOT(mailSent(QString)));

    if( !files.isEmpty() )
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText(), files );
    else
        smtp->sendMail(ui->uname->text(), ui->rcpt->text() , ui->subject->text(),ui->msg->toPlainText());
}

void MainWindow::mailSent(QString status)
{
    if(status == "Message sent")
        QMessageBox::warning( 0, tr( "Qt Simple SMTP client" ), tr( "Message sent!\n\n" ) );
}





MainWindow::~MainWindow()
{
    delete ui;
}
//AJOUT MATERIEL

void MainWindow::on_pb_ajouter_clicked()
{

    QString nom= ui->nom->text();
    QString type= ui->typ->text();
    int cout= ui->cout->text().toInt();
    int duree= ui->duree->text().toInt();
    int volume= ui->vlm->text().toInt();
    int poids= ui->poids->text().toInt();
    int nbr= ui->nbr->text().toInt();


  Materiel m(nom,type,cout,duree,volume,poids,nbr);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("materiel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
//modifier materiel
void MainWindow::on_pb_modifier_clicked()
{
    QString nom= ui->nom->text();
    QString type= ui->typ->text();
    int cout= ui->cout->text().toInt();
    int duree= ui->duree->text().toInt();
    int volume= ui->vlm->text().toInt();
    int poids= ui->poids->text().toInt();
    int nbr= ui->nbr->text().toInt();



  Materiel m;
  bool test=m.modifier(nom,type,cout,duree,volume,poids,nbr);
    if(test)
    {
          ui->tabmateriel->setModel(tmpmateriel.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                          QObject::tr("événement modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


}
//SUPPRIMER MATERIEL

void MainWindow::on_pb_supprimer_clicked()
{
 QString nom= ui->nomsup->text();
bool test=tmpmateriel.supprimer(nom);
if(test)
{ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Supprimer un materiel"),
                QObject::tr("materiel supprimé.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}








//MODIFIER FOURNISSEURS
void MainWindow::on_pb_modifier_2_clicked()
{


    int id = ui->le_id->text().toInt();
        int num = ui->num->text().toInt();

        QString nom= ui->le_nom->text();
        QString prenom= ui->prenom->text();
        QString mail= ui->mail->text();
        QString niveau= ui->nv->text();
        QString controle= ui->ctrl->text();

  Fournisseur f;
  bool test=f.modifier( id, nom, prenom , mail, num, niveau , controle);
    if(test)
    {
          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("fournisseur modifié.\n"), QMessageBox::Cancel);

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }

}
//SUPPRIMER FOURNISSEUR
void MainWindow::on_pb_supprimer2_clicked()
{
    int idd= ui->ids->text().toInt();
   bool test=tmpfournisseur.supprimer(idd);
   if(test)
   {ui->tabfournisseurs->setModel(tmpfournisseur.afficher());//refresh
       QMessageBox::information(nullptr, QObject::tr("Supprimer un fournisseur"),
                   QObject::tr("fournisseur supprimé.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

   }
   else
       QMessageBox::critical(nullptr, QObject::tr("Supprimer un fournisseur"),
                   QObject::tr("Erreur !.\n"
                               "Click Cancel to exit."), QMessageBox::Cancel);

}
//TRI RECHERCHE MATERIEL
void MainWindow::on_pb_rechercher_clicked()
{
    QString rech =ui->rachma->text();
   ui->tabmateriel->setModel(tmpmateriel.rechercher(rech));
}
void MainWindow::on_pb_tri_2_clicked()
{
     ui->tabmateriel->setModel(tmpmateriel.tri());
}
//
//RECHERCHE TRI FOURNISSEURS

void MainWindow::on_pb_rechercher_2_clicked()
{
    QString rech =ui->idre->text();
   ui->tabfournisseurs->setModel(tmpfournisseur.rechercher(rech));
}
void MainWindow::on_pb_tri_clicked()
{
     ui->tabfournisseurs->setModel(tmpfournisseur.tri());
}
//AJOUT FOURNISSEURS
void MainWindow::on_pushButton_clicked()
{
    int id = ui->le_id->text().toInt();
        int num = ui->num->text().toInt();

        QString nom= ui->le_nom->text();
        QString prenom= ui->prenom->text();
        QString mail= ui->mail->text();
        QString niveau= ui->nv->text();
        QString controle= ui->ctrl->text();



      Fournisseur f( id, nom, prenom , mail, num, niveau , controle);
      bool test=f.ajouter();
      if(test)
    {

          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pushButton_2_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"ouvrir");

            if (filename.isEmpty()){return;}

            mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));

          on_pushButton_3_clicked();

}

void MainWindow::on_pushButton_3_clicked()
{
    mMediaPlayer->play();

}

void MainWindow::on_pushButton_4_clicked()
{
    mMediaPlayer->pause();

}

void MainWindow::on_pushButton_5_clicked()
{
    mMediaPlayer->stop();

}

void MainWindow::on_pushButton_6_clicked()
{
    if(ui->pushButton_6->text()=="muet"){

          mMediaPlayer->setMuted(true);

         ui->pushButton_6->setText("unmuet");}

         else{ mMediaPlayer->setMuted(false);

             ui->pushButton_6->setText("muet");}
}

void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->avance_3->setValue(value);

}

void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_17_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_toolButton_triggered(QAction *arg1)
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_15_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}
