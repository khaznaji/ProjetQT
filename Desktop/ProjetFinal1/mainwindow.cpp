#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Membre.h"
#include"fonction.h"
#include <QMessageBox>
#include<QFileDialog>
#include<QMediaPlayer>
#include<QSound>
#include<QUrl>
#include<QtPrintSupport/QPrinter>
#include<QPdfWriter>
#include <QPainter>
#include<QTextDocument>
#include <QTextEdit>
#include <QtSql/QSqlQueryModel>
#include<QtPrintSupport/QPrinter>
#include <QSqlQuery>
#include <QMessageBox>
#include <QPixmap>
#include <QTabWidget>
#include <QValidator>
#include <QPrintDialog>
#include<QtSql/QSqlQuery>
#include<QVariant>
#include<QDebug>
#include<iostream>
#include<QValidator>
#include"smtp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
ui->setupUi(this);
//Music
mMediaPlayer=new QMediaPlayer(this);
connect(mMediaPlayer,&QMediaPlayer::positionChanged,[&](qint64 pos){ui->avance_3->setValue(pos);});
connect(mMediaPlayer,&QMediaPlayer::durationChanged,[&](qint64 dur){ui->avance_3->setMaximum(dur);});
//Mailing
connect(ui->sendBtn, SIGNAL(clicked()),this, SLOT(sendMail()));
connect(ui->exitBtn, SIGNAL(clicked()),this, SLOT(close()));
connect(ui->browseBtn, SIGNAL(clicked()), this, SLOT(browse()));
//CRUD
ui->tabmembre->setModel(tmpmembre.afficher());
ui->tableView->setModel(tmpfonction.afficher());
}
//Mailing
void MainWindow::browse()
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
//CRUD
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
//recherche et tri
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

//MUSIC
void MainWindow::on_pushButton_20_clicked()
{
    QString filename=QFileDialog::getOpenFileName(this,"ouvrir");
        if (filename.isEmpty()){return;}
        mMediaPlayer->setMedia(QUrl::fromLocalFile(filename));
      on_pushButton_18_clicked();
}

void MainWindow::on_pushButton_18_clicked()
{
    mMediaPlayer->play();
}

void MainWindow::on_pushButton_17_clicked()
{
    mMediaPlayer->pause();
}

void MainWindow::on_pushButton_16_clicked()
{
    mMediaPlayer->stop();
}

void MainWindow::on_avance_3_valueChanged(int value)
{
    ui->avance_3->setValue(value);

}

void MainWindow::on_pushButton_19_clicked()
{
    if(ui->pushButton_19->text()=="muet"){
      mMediaPlayer->setMuted(true);
     ui->pushButton_19->setText("unmuet");}
     else{ mMediaPlayer->setMuted(false);
         ui->pushButton_19->setText("muet");}
}




void MainWindow::on_pushButton_6_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tabmembre->model()->rowCount();
                     const int columnCount = ui->tabmembre->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des Membres </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tabmembre->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tabmembre->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tabmembre->isColumnHidden(column)) {
                                 QString data = ui->tabmembre->model()->data(ui->tabmembre->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
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

void MainWindow::on_pushButton_2_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}

void MainWindow::on_pushButton_3_clicked()
{
    QString strStream;
                     QTextStream out(&strStream);

                     const int rowCount = ui->tabmembre->model()->rowCount();
                     const int columnCount = ui->tabmembre->model()->columnCount();

                     out <<  "<html>\n"
                         "<head>\n"
                         "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                         <<  QString("<title>%1</title>\n").arg("strTitle")
                         <<  "</head>\n"
                         "<body bgcolor=#ffffff link=#5000A0>\n"

                        //     "<align='right'> " << datefich << "</align>"
                         "<center> <H1>Liste des Fonctions </H1></br></br><table border=1 cellspacing=0 cellpadding=2>\n";

                     // headers
                     out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
                     for (int column = 0; column < columnCount; column++)
                         if (!ui->tableView->isColumnHidden(column))
                             out << QString("<th>%1</th>").arg(ui->tabmembre->model()->headerData(column, Qt::Horizontal).toString());
                     out << "</tr></thead>\n";

                     // data table
                     for (int row = 0; row < rowCount; row++) {
                         out << "<tr> <td bkcolor=0>" << row+1 <<"</td>";
                         for (int column = 0; column < columnCount; column++) {
                             if (!ui->tableView->isColumnHidden(column)) {
                                 QString data = ui->tableView->model()->data(ui->tableView->model()->index(row, column)).toString().simplified();
                                 out << QString("<td bkcolor=0>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                             }
                         }
                         out << "</tr>\n";
                     }
                     out <<  "</table> </center>\n"
                         "</body>\n"
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
//Impre
void MainWindow::on_pushButton_7_clicked()
{
    QPrinter printer;

    printer.setPrinterName("desiered printer name");

  QPrintDialog dialog(&printer,this);

    if(dialog.exec()== QDialog::Rejected)

        return;
}
