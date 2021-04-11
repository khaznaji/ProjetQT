#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "projet.h"
#include "partenaire.h"

#include <QMainWindow>

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
    void on_pushButton_clicked();

    void on_button_ajouter_clicked();

    void on_pb_ajouter_clicked();

    void on_pb_supprimer_3_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton10_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pushButton_9_clicked();

    //void on_radioButton_clicked();

    void on_tabprojet_activated(const QModelIndex &index);

    void on_pushButton_8_clicked();

    void on_tabpartenaire_activated(const QModelIndex &index);

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

private:
    Ui::MainWindow *ui;
    Projet tmpprojet;
    Partenaire tmppartenaire;
};

#endif // MAINWINDOW_H
