#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "evenement.h"
#include "participant.h"
#include <QMessageBox>
#include <iostream>
#include "publicite.h"



#include  <QDebug>

#include <QRadioButton>

#include<QtPrintSupport/QPrinter>

#include<QPdfWriter>

#include <QPainter>

#include<QFileDialog>

#include<QTextDocument>

#include <QTextEdit>

#include <QtSql/QSqlQueryModel>

#include<QtPrintSupport/QPrinter>

#include <QVector2D>

#include <QVector>

#include <QSqlQuery>

#include<QDesktopServices>

#include <QMessageBox>

#include<QUrl>

#include <QPixmap>

#include <QTabWidget>

#include <QValidator>

#include <QPrintDialog>
#include<QDate>

#include<QtSql/QSqlQuery>

#include<QVariant>
#include <QMediaPlayer>
#include <QSound>
#include<QPropertyAnimation>
#include<QSystemTrayIcon>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
mMediaPlayer=new QMediaPlayer(this);
/*connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){ui->avance->setValue(pos);});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){ui->avance->setMaximum(dur);});
*/
ui->tabevenement->setModel(tmpevenement.afficher()); //remplir le tableau via un model
ui->tabparticipant->setModel(tmpparticipant.afficher());
ui->tabpublicite->setModel(tmppub.afficher());
animation =new QPropertyAnimation(ui->label_4,"geometry");

    animation->setDuration(10000);
    animation->setStartValue(ui->label->geometry());
    animation->setEndValue(QRect(200,65,400,90));

    QEasingCurve curve;//fournit des courbes d'acceleration pour controler l'animation
    curve.setType(QEasingCurve::OutBounce);
    animation->setEasingCurve(curve);
    curve.setAmplitude(2.00);
    animation->setLoopCount(2);
    animation->start();
    animation =new QPropertyAnimation(ui->label_7,"geometry");
        animation->setDuration(10000);
        animation->setStartValue(ui->label->geometry());
        animation->setEndValue(QRect(200,65,400,90));

        QEasingCurve curver;
        curve.setType(QEasingCurve::OutBounce);
        animation->setEasingCurve(curve);
        curve.setAmplitude(2.00);
        animation->setLoopCount(2);
        animation->start();
ui->lineEdit_CIN->setValidator(new QIntValidator(0,999999,this));
ui->lineEdit_numtel->setValidator(new QIntValidator(0,999999,this));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_ajouter_clicked()
{

    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }

    QString titre= ui->lineEdit_titre->text();//recuperer la valeur saisie par l'utilisateur, ui est un pointeur (vers l'interface)
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
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
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
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QString rech =ui->lineEditrech->text();
   ui->tabevenement->setModel(tmpevenement.rechercher(rech));
}


void MainWindow::on_pb_ajouter_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail= ui->lineEdit_mail->text();
    int CIN= ui->lineEdit_CIN->text().toInt();
    int numtel= ui->lineEdit_numtel->text().toInt();
    QString datenaissance= ui->lineEdit_datenaissance->text();
    QString typeeve= ui->lineEdit_typeeve->text();


  participant p(nom,prenom,mail,CIN,numtel,datenaissance,typeeve);
  bool test=p.ajouter();
  if(test)
{

      ui->tabparticipant->setModel(tmpparticipant.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION PARTICIPANT AJOUTE ","participant ajouté",QSystemTrayIcon::Information,15000);

          QMessageBox::information(nullptr, QObject::tr("ajouter participant"),
                                QObject::tr("participant ajouté./n"
                                   "click cancel to exit."),QMessageBox::Cancel);
          }

          else
              QMessageBox::critical(nullptr, QObject::tr("ajouter participant"),
                                    QObject::tr("Erreur !./n"
                                       "click cancel to exit."),QMessageBox::Cancel);


      }

void MainWindow::on_pb_modifier_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString titre= ui->lineEdit_titre->text();
    QString type= ui->lineEdit_type->text();
    QString lieu= ui->lineEdit_lieu->text();
    QString datedebut= ui->lineEdit_datedebut->text();
    QString datefin= ui->lineEdit_datefin->text();
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
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->tabevenement->setModel(tmpevenement.tri());
}

void MainWindow::on_pb_modifier_2_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString nom= ui->lineEdit_nom->text();
    QString prenom= ui->lineEdit_prenom->text();
    QString mail= ui->lineEdit_mail->text();
    int CIN= ui->lineEdit_CIN->text().toInt();
    int numtel= ui->lineEdit_numtel->text().toInt();
    QString datenaissance= ui->lineEdit_datenaissance->text();
    QString typeeve= ui->lineEdit_typeeve->text();

    participant p;
    bool test=p.modifier(nom,prenom,mail,CIN,numtel,datenaissance,typeeve);
    if (test)
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
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
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
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
     ui->tabparticipant->setModel(tmpparticipant.tri());
}

void MainWindow::on_pb_rechercher_2_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString rech =ui->lineEditrech_2->text();
   ui->tabparticipant->setModel(tmpparticipant.rechercher(rech));
}

void MainWindow::on_pb_pdf_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    QString strStream;
                     QTextStream out(&strStream);//interface pratique pour lire et ecrire

                     const int rowCount = ui->tabevenement->model()->rowCount();
                     const int columnCount = ui->tabevenement->model()->columnCount();
                      QString TT = QDate::currentDate().toString("yyyy/MM/dd");

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"
                        "<h1 style=\"text-align: center;\"><strong> ********Liste Des événements******** "+TT+"</strong></h1>"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des evenements </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tabevenement->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tabevenement->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tabevenement->isColumnHidden(column)) {
                                 QString data = ui->tabevenement->model()->data(ui->tabevenement->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
"<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/BEST TECHNOLOGIES/Downloads/back1.png\" alt=\"picture\" width=\"40\" height=\"30\">";
                         "</html>\n";

               QString fileName = QFileDialog::getSaveFileName((QWidget* )0, "Sauvegarder en PDF", QString(), "*.pdf");
                 if (QFileInfo(fileName).suffix().isEmpty()) { fileName.append(".pdf"); }

                QPrinter printer (QPrinter::PrinterResolution);
                 printer.setOutputFormat(QPrinter::PdfFormat);
                printer.setPaperSize(QPrinter::A4);
               printer.setOutputFileName(fileName);

                QTextDocument doc;
                 doc.setHtml(strStream);
                 doc.setPageSize(printer.pageRect().size()); // This is necessary if you want to hide the page number
                 doc.print(&printer);
}


void MainWindow::on_pb_imprimer_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    //imprimer

       QPrinter printer;

       printer.setPrinterName("desiered printer name");

     QPrintDialog dialog(&printer,this);

       if(dialog.exec()== QDialog::Rejected)

           return;
}

/*void MainWindow::on_pushButton_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"ouvrir");
    if (filename.isEmpty()){return;}
    mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
  on_pushButton_2_clicked();

}

void MainWindow::on_pushButton_2_clicked()
{
     mMediaPlayer->play();
}

void MainWindow::on_pushButton_3_clicked()
{
     mMediaPlayer->pause();
}

void MainWindow::on_pushButton_4_clicked()
{
     mMediaPlayer->stop();
}*/

/*void MainWindow::on_horizontalSlider_valueChanged(int value)
{
    ui->avance->setValue(value);
}

void MainWindow::on_pushButton_5_clicked()
{
    if(ui->pushButton_5->text()=="muet"){
     mMediaPlayer->setMuted(true);
    ui->pushButton_5->setText("unmuet");}
    else{ mMediaPlayer->setMuted(false);
        ui->pushButton_5->setText("muet");}
}
*/
void MainWindow::on_event_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_8_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_pushButton_9_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_10_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_12_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(1);

}

void MainWindow::on_pushButton_11_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_menu_clicked()
{  QMediaPlayer * bulletsound = new QMediaPlayer();
    bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
   if (bulletsound->state() == QMediaPlayer::PlayingState){
        bulletsound->setPosition(0);
    }
    else if (bulletsound->state() == QMediaPlayer::StoppedState){
        bulletsound->play();
    }
    ui->stackedWidget->setCurrentIndex(0);

}

/*void MainWindow::on_pb_ajout_clicked()
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
}*/

void MainWindow::on_tabevenement_activated(const QModelIndex &index) //localiser les donnees
{
    int selected_row=ui->tabevenement->currentIndex().row();//la propriete actuelle


        QString selected_titre=ui->tabevenement->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_titres->setText(ui->tabevenement->model()->data(index.sibling(selected_row,0)).toString());// contient les textes et l'etiqutte

        ui->lineEdit_titre->setText(selected_titre);
        ui->lineEdit_type->setText(ui->tabevenement->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_lieu->setText(ui->tabevenement->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_datedebut->setText(ui->tabevenement->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_datefin->setText(ui->tabevenement->model()->data(index.sibling(selected_row,4)).toString());

}

void MainWindow::on_tabparticipant_activated(const QModelIndex &index)
{
    int selected_row=ui->tabparticipant->currentIndex().row();


        QString selected_nom=ui->tabparticipant->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_noms->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,0)).toString());

        ui->lineEdit_nom->setText(selected_nom);
        ui->lineEdit_prenom->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_mail->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_CIN->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_numtel->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,4)).toString());
        ui->lineEdit_datenaissance->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_typeeve->setText(ui->tabparticipant->model()->data(index.sibling(selected_row,4)).toString());
}

void MainWindow::on_pb_ajouter_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    int id= ui->lineEdit_id->text().toInt();
    QString titre= ui->lineEdit_titr->text();
    QString form= ui->lineEdit_form->text();
    QString description= ui->lineEdit_descr->text();
    QString dte= ui->lineEdit_date->text();


  publicite p(id,titre,form,description,dte);
  bool test=p.ajouter();
  if(test)
{

      ui->tabpublicite->setModel(tmppub.afficher());//refresh
      QSystemTrayIcon *notifyIcon = new QSystemTrayIcon;
              notifyIcon->show();
              notifyIcon->setIcon(QIcon("icone.png"));

              notifyIcon->showMessage("GESTION PUBLICITE AJOUTE ","publicite ajouté",QSystemTrayIcon::Information,15000);

          QMessageBox::information(nullptr, QObject::tr("ajouter publicite"),
                                QObject::tr("publicite ajouté./n"
                                   "click cancel to exit."),QMessageBox::Cancel);
          }

          else
              QMessageBox::critical(nullptr, QObject::tr("ajouter publicite"),
                                    QObject::tr("Erreur !./n"
                                       "click cancel to exit."),QMessageBox::Cancel);


}

void MainWindow::on_pb_modifier_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
       int id= ui->lineEdit_id->text().toInt();
       QString titre= ui->lineEdit_titr->text();
       QString form= ui->lineEdit_form->text();
       QString description= ui->lineEdit_descr->text();
       QString dte= ui->lineEdit_date->text();


        publicite p;
        bool test=p.modifier(id,titre,form,description,dte);
        if (test)
        {
              ui->tabpublicite->setModel(tmppub.afficher());
                  QMessageBox::information(nullptr, QObject::tr("Modifier une publicite"),
                              QObject::tr("publicite modifiée.\n"), QMessageBox::Cancel);

        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Modifier une publicite"),
                              QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_supprimer_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        int id= ui->lineEdit_ids->text().toInt();
       bool test=tmppub.supprimer(id);
       if(test)
       {ui->tabpublicite->setModel(tmppub.afficher());//refresh
           QMessageBox::information(nullptr, QObject::tr("Supprimer une publicite"),
                       QObject::tr("publicite supprimée.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

       }
       else
           QMessageBox::critical(nullptr, QObject::tr("Supprimer une publicite"),
                       QObject::tr("Erreur !.\n"
                                   "Click Cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_rechercher_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
       QString rech =ui->lineEditrech_3->text();
      ui->tabpublicite->setModel(tmppub.rechercher(rech));
}

void MainWindow::on_pb_tri_3_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
         ui->tabpublicite->setModel(tmppub.tri());
}

void MainWindow::on_tabpublicite_activated(const QModelIndex &index)
{
    int selected_row=ui->tabpublicite->currentIndex().row();


        QString selected_id=ui->tabpublicite->model()->data(index.sibling(selected_row,0)).toString();
        ui->lineEdit_ids->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,0)).toString());

        ui->lineEdit_id->setText(selected_id);
        ui->lineEdit_titr->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,1)).toString());

        ui->lineEdit_form->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,2)).toString());
        ui->lineEdit_descr->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,3)).toString());

        ui->lineEdit_date->setText(ui->tabpublicite->model()->data(index.sibling(selected_row,4)).toString());

}

void MainWindow::on_menu_2_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_14_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_pushButton_13_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
       bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/BEST TECHNOLOGIES/Downloads/nc.mp3"));
      if (bulletsound->state() == QMediaPlayer::PlayingState){
           bulletsound->setPosition(0);
       }
       else if (bulletsound->state() == QMediaPlayer::StoppedState){
           bulletsound->play();
       }
    ui->stackedWidget->setCurrentIndex(5);
}

