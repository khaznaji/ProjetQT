#include "mainwindow.h"
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
//splashcreen
#include<QTimer>
#include<QSplashScreen>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QSplashScreen *splash=new QSplashScreen;
    splash->setPixmap(QPixmap("C:/Users/User/Desktop/back.png"));
    splash->show();
   Connexion c;
   bool test= c.ouvrirConnexion();
   MainWindow w;
   QTimer::singleShot(2500,splash,SLOT(close()));
   QTimer::singleShot(2500,&w,SLOT(show()));

              if(test)
{
                  QTimer::singleShot(2500,splash,SLOT(close()));
                  QTimer::singleShot(2500,&w,SLOT(show()));
       // w.show();


    }
          else
               QMessageBox::information(nullptr, QObject::tr("database is not open"),
                           QObject::tr("Echec de la connexion.\n""Click Cancel to exit."), QMessageBox::Cancel);



    return a.exec();
}
