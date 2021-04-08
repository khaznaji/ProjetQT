#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "materiel.h"
#include <QMainWindow>
#include"fournisseur.h"
#include<QMediaPlayer>
#include"smtp.h"
#include<QPropertyAnimation>
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

private:
    Ui::MainWindow *ui;
    Materiel tmpmateriel ;
    Fournisseur tmpfournisseur;
    QMediaPlayer*mMediaPlayer;
    QPropertyAnimation *animation;
QStringList files;
};

#endif // MAINWINDOW_H
