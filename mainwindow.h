#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "materiel.h"
#include <QMainWindow>
#include"fournisseur.h"
#include <QFileDialog>


#include<QMediaPlayer>
#include"smtp.h"
#include<QPropertyAnimation>

#include"arduino.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();



private slots:
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_comboBox_activated(const QString &arg1);

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer2_clicked();

    void on_pb_tri_2_clicked();

    void on_pb_rechercher_2_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_6_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void sendMail();
    void mailSent(QString);
    void Browse();

    void on_pushButton_8_clicked();

    void on_toolButton_clicked();

    void on_pushButton_17_clicked();

    void on_toolButton_triggered(QAction *arg1);

    void on_pushButton_7_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_21_clicked();

    void on_lcdNumber_2_overflow();

    void on_dateTimeEdit_dateChanged(const QDate &date);
    void showTime();

    void on_pushButton_22_clicked();

    void on_pushButton_46_clicked();

    void on_pushButton_23_clicked();

    void on_browseBtn_clicked();

    void on_pushButton_25_clicked();

    void on_pushButton_24_clicked();

private:
    Ui::MainWindow *ui;

    Materiel tmpmateriel ;
    Fournisseur tmpfournisseur;
    QMediaPlayer*mMediaPlayer;
    QPropertyAnimation *animation;
QStringList files;
arduino ard;
arduino tmparduino;


};

#endif // MAINWINDOW_H
