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
#include<QPrinter>
#include<QTimer>
#include<QDateTime>
#include<QDesktopServices>
#include<QUrl>


//arduino
#include<QtSerialPort/QSerialPort>
#include<QtSerialPort/QSerialPortInfo>
#include"arduino.h"














MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
ard.connnect_arduino();
mMediaPlayer=new QMediaPlayer(this);
connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){ui->avance_3->setValue(pos);});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){ui->avance_3->setMaximum(dur);});
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(Browse()));


ui->tabmateriel->setModel(tmpmateriel.afficher());
ui->tabfournisseurs->setModel(tmpfournisseur.afficher());



QRegExp rx("[a-zA-Z]+");
 QValidator *validator = new QRegExpValidator(rx, this);

//fournisseur
 ui->le_nom->setValidator(validator);
 ui->prenom->setValidator(validator);
 ui->nv->setValidator(validator);
 ui->ctrl->setValidator(validator);

ui->le_id->setValidator(new QIntValidator(0,999,this));
ui->num->setValidator(new QIntValidator(0,99999999,this));
//materiel
ui->nom->setValidator(validator);
ui->typ->setValidator(validator);
ui->cout->setValidator(new QIntValidator(0,99999,this));
ui->duree->setValidator(new QIntValidator(0,999,this));
ui->vlm->setValidator(new QIntValidator(0,999,this));
ui->poids->setValidator(new QIntValidator(0,999,this));
ui->nbr->setValidator(new QIntValidator(0,999,this));


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
    QTimer *timer=new QTimer(this);
    connect(timer ,SIGNAL(timeout()),this,SLOT(showTime()));
    timer->start();

    QDateTime dateTime=QDateTime::currentDateTime();
    QString datetimetext=dateTime.toString("dddd . dd . MMMM . yyyy");
    ui->DateTime_->setText(datetimetext);


}
void MainWindow::showTime(){

    QTime time=QTime::currentTime();

    QString time_text=time.toString("hh : mm : ss");
    if ((time.second() % 2) == 0)
    {
       time_text[3] = ' ';
       time_text[8] = ' ';




    }
    ui->Digital_clock->setText(time_text);



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

    //controle de saisie
       if ((nom.isEmpty()||type.isEmpty())) {
                ui->label_16->setText("Ce Champ est obligatoire");
                ui->label_17->setText("Ce Champ est obligatoire");}
       else{






  Materiel m(nom,type,cout,duree,volume,poids,nbr);
  bool test=m.ajouter();
  if(test)
{

      ui->tabmateriel->setModel(tmpmateriel.afficher());//refresh
QMessageBox::information(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("materiel ajouté.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);
ui->label_16->setText("");
ui->label_17->setText("");

}
  else
      QMessageBox::critical(nullptr, QObject::tr("Ajouter un materiel"),
                  QObject::tr("Erreur !.\n"
                              "Click Cancel to exit."), QMessageBox::Cancel);


}
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

    //controle de saisie
    if ((nom.isEmpty()||type.isEmpty())) {
                ui->label_16->setText("Ce Champ est obligatoire");
                ui->label_17->setText("Ce Champ est obligatoire");}
    else{


  Materiel m;
  bool test=m.modifier(nom,type,cout,duree,volume,poids,nbr);
    if(test)
    {
          ui->tabmateriel->setModel(tmpmateriel.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un materiel"),
                          QObject::tr("événement modifié.\n"), QMessageBox::Cancel);
              ui->label_16->setText("");
              ui->label_17->setText("");

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un materiel"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }


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
else{
    QMessageBox::critical(nullptr, QObject::tr("Supprimer un materiel"),
                QObject::tr("Erreur !.\n"
                            "Click Cancel to exit."), QMessageBox::Cancel);


}
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
        QString alt="@";
            QString pt=".";

        //controle de saisie
        if ((nom.isEmpty()||prenom.isEmpty()||niveau.isEmpty()||controle.isEmpty())) {
                    ui->label_2->setText("Ce Champ est obligatoire");
                    ui->label_3->setText("Ce Champ est obligatoire");
                    ui->label_6->setText("Ce Champ est obligatoire");
                    ui->label_7->setText("Ce Champ est obligatoire");
        }
        else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
         {ui->label_4->setText("Verifier le mail");}
        else{
  Fournisseur f;
  bool test=f.modifier( id, nom, prenom , mail, num, niveau , controle);
    if(test)
    {
          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());
              QMessageBox::information(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("fournisseur modifié.\n"), QMessageBox::Cancel);
              ui->label_2->setText("");
              ui->label_3->setText("");
              ui->label_4->setText("");
              ui->label_6->setText("");
              ui->label_7->setText("");

    }
    else
    {
        QMessageBox::critical(nullptr, QObject::tr("Modifier un fournisseur"),
                          QObject::tr("Erreur !!!!!!!!\n"), QMessageBox::Cancel);
    }

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
        QString alt="@";
            QString pt=".";


        //controle de saisie
        if ((nom.isEmpty()||prenom.isEmpty()||niveau.isEmpty()||controle.isEmpty())) {
                    ui->label_2->setText("Ce Champ est obligatoire");
                    ui->label_3->setText("Ce Champ est obligatoire");
                    ui->label_6->setText("Ce Champ est obligatoire");
                    ui->label_7->setText("Ce Champ est obligatoire");}
        else if(mail.indexOf(alt)<1 || mail.indexOf(pt)<mail.indexOf(alt)+2)
         {ui->label_4->setText("Verifier le mail");}
        else{

      Fournisseur f( id, nom, prenom , mail, num, niveau , controle);
      bool test=f.ajouter();
      if(test)
    {

          ui->tabfournisseurs->setModel(tmpfournisseur.afficher());//refresh
    QMessageBox::information(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("fournisseur ajouté.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->label_6->setText("");
    ui->label_7->setText("");



    }
      else
          QMessageBox::critical(nullptr, QObject::tr("Ajouter un fournisseur"),
                      QObject::tr("Erreur !.\n"
                                  "Click Cancel to exit."), QMessageBox::Cancel);

}
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
    //gestion mteei
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_pushButton_17_clicked()
{
    //menu
    ui->stackedWidget->setCurrentIndex(2);

}
void MainWindow::on_pushButton_21_clicked()
{
    //menu
      ui->stackedWidget->setCurrentIndex(2);
}


void MainWindow::on_toolButton_triggered(QAction *arg1)
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainWindow::on_pushButton_7_clicked()
{
    //gestion materiel
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_pushButton_14_clicked()
{
    //gestion fournisseurs
    ui->stackedWidget->setCurrentIndex(0);

}

void MainWindow::on_pushButton_15_clicked()
{
    //retour aux entitees
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_16_clicked()
{
    //retour aux entitees
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_pushButton_18_clicked()
{  //arduino
    int x=0;
    ui->stackedWidget->setCurrentIndex(1);
    QString read=ard.read_from_arduino();


    int ln=read.length();
    QString id=read.right(ln-1);//élimination du premier espace
    id=id.left(ln-3);//élimination des 3 derniers espaces (serial.println)
    QSqlQuery query;
        query.prepare("select presence from arduino where id='"+id+"'");

        if(query.exec()){

        query.first();

        int presence=query.value(0).toInt();
        if(presence==0){presence=1;ui->lcdNumber->display(x++);}
        else{presence=0;ui->lcdNumber->display(x--);}
        QString xpresence=QString::number(presence);
        query.prepare("update arduino set presence='"+xpresence+"' where id='"+id+"'");
        query.exec();}

        else{
            ard.write_to_arduino("1");
        }

        QSqlQueryModel * model= new QSqlQueryModel();
            model->setQuery("select nom,prenom from arduino where presence=1");

            model->setHeaderData(1, Qt::Horizontal, QObject::tr("prenom"));
            model->setHeaderData(2, Qt::Horizontal, QObject::tr("nom"));

ui->tableView->setModel(model);
}

//pdf
void MainWindow::on_pushButton_19_clicked()
{
    QMediaPlayer * bulletsound = new QMediaPlayer();
        bulletsound->setMedia(QUrl::fromLocalFile("C:/Users/User/Downloads/nc.mp3"));
       if (bulletsound->state() == QMediaPlayer::PlayingState){
            bulletsound->setPosition(0);
        }
        else if (bulletsound->state() == QMediaPlayer::StoppedState){
            bulletsound->play();
        }
        QString strStream;
                         QTextStream out(&strStream);

                         const int rowCount = ui->tabmateriel->model()->rowCount();
                         const int columnCount = ui->tabmateriel->model()->columnCount();
                         QString TT = QDateTime::currentDateTime().toString("yyyy/MM/dd hh:mm:ss");
                         out <<  "<html>\n"
                             "<head>\n"
                             "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                             <<  QString("<title>%1</title>\n").arg("strTitle")
                             <<  "</head>\n"
                             "<body bgcolor=#E7E7E7 link=#5000A1>\n"

                                "<h1 style=\"text-align: center;\"><strong> ********Liste Des Materiels******** "+TT+"</strong></h1>"
                            //     "<align='right'> " << datefich << "</align>"
                             "<center></br><table border=3 cellspacing=1 cellpadding=2>\n";

                         // headers
                         out << "<thead><tr bgcolor=#FFF9F6> <th>Numero</th>";
                         for (int column = 0; column < columnCount; column++)
                             if (!ui->tabmateriel->isColumnHidden(column))
                                 out << QString("<th>%1</th>").arg(ui->tabmateriel->model()->headerData(column, Qt::Horizontal).toString());
                         out << "</tr></thead>\n";

                         // data table
                         for (int row = 0; row < rowCount; row++) {
                             out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                             for (int column = 0; column < columnCount; column++) {
                                 if (!ui->tabmateriel->isColumnHidden(column)) {
                                     QString data = ui->tabmateriel->model()->data(ui->tabmateriel->model()->index(row, column)).toString().simplified();
                                     out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                                 }
                             }
                             out << "</tr>\n";
                         }
                         out <<  "</table> </center>\n"

                             "</body>\n"
                                 "<img style=\"  grid-column: 5 / 6 grid-row: 2 / 3;\" src=\"C:/Users/User/Desktop/back.png\" alt=\"picture\" width=\"40\" height=\"30\">";

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
// excel
void MainWindow::on_pushButton_20_clicked()
{
    QTableView *table;
                       table = ui->tabfournisseurs;
                       QString filters("CSV files (*.csv);;All files (*.*)");
                       QString defaultFilter("CSV files (*.csv)");
                       QString fileName = QFileDialog::getSaveFileName(0, "Save file", QCoreApplication::applicationDirPath(),
                                          filters, &defaultFilter);
                       QFile file(fileName);
                       QAbstractItemModel *model =  table->model();
                       if (file.open(QFile::WriteOnly | QFile::Truncate)) {
                           QTextStream data(&file);
                           QStringList strList;
                           for (int i = 0; i < model->columnCount(); i++) {
                               if (model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString().length() > 0)
                                   strList.append("\"" + model->headerData(i, Qt::Horizontal, Qt::DisplayRole).toString() + "\"");
                               else
                                   strList.append("");
                           }
                           data << strList.join(";") << "\n";
                           for (int i = 0; i < model->rowCount(); i++) {
                               strList.clear();
                               for (int j = 0; j < model->columnCount(); j++) {
                                   if (model->data(model->index(i, j)).toString().length() > 0)
                                       strList.append("\"" + model->data(model->index(i, j)).toString() + "\"");
                                   else
                                       strList.append("");
                               }
                               data << strList.join(";") + "\n";
                           }
                           file.close();
                           //QMessageBox::information(this,"Exporter To Excel","Exporter En Excel Avec Succées ");


                       }
}


void MainWindow::on_pushButton_22_clicked()
{
    //open web page
    QString link="http://www.google.com";
    QDesktopServices::openUrl(QUrl(link));


}



void MainWindow::on_pushButton_23_clicked()
{
    //to open the picture file

    QString fileName = QFileDialog::getOpenFileName(this,
              tr("Choose"), "", tr("Image Files (*.png *.jpg *.bmp)"));

    //to select and show the pic
    if (QString::compare(fileName, QString()) !=0)
    {
        QImage image;
        bool valid = image.load(fileName);
        if (valid)
        {

          image = image.scaledToHeight(ui->label_pic->height(), Qt::SmoothTransformation);
          image = image.scaledToWidth(ui->label_pic->width(), Qt::SmoothTransformation);



          ui->label_pic->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            //error
        }

    }


}



void MainWindow::on_pushButton_25_clicked()
{
    //open file name
      QString filename=QFileDialog::getOpenFileName(this
                                                    ,tr("Open File"),
                                                    "C://", "All files (*.*);;Text File(*.txt);;Music file(*.mp3)" );
      QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
     // QMessageBox::information(this,tr("File Name"),filename);
}

void MainWindow::on_pushButton_24_clicked()
{
    //open file name
      QString filename=QFileDialog::getOpenFileName(this
                                                    ,tr("Open File"),
                                                    "C://", "All files (*.*);;Text File(*.txt);;Music file(*.mp3)" );
      QDesktopServices::openUrl(QUrl("file:///"+filename,QUrl::TolerantMode));
     // QMessageBox::information(this,tr("File Name"),filename);
}
