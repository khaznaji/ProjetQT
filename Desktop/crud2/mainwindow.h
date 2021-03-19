#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "Membre.h"
#include <QMainWindow>
#include"fonction.h"
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

    void on_pb_supprimer_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Membre tmpmembre;
    fonction tmpfonction;
};

#endif // MAINWINDOW_H
