#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include<QDate>
#include "adherant.h"
#include "activite.h"
#include <QtCore>
#include <QtGui>
#include <QDialog>
#include <QMouseEvent>
#include <QtWidgets/QMessageBox>


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
    void on_pb_ajouter_clicked();

    void on_pb_supprimer_clicked();

    void on_pb_modifier_clicked();

    void on_pb_tri_clicked();

    void on_pb_rechercher_clicked();

    void on_pb_ajouter_2_clicked();

    void on_pb_modifier_2_clicked();

    void on_pb_supprimer2_clicked();

    void on_pb_rechercher_2_clicked();

    void on_pb_tri_2_clicked();

    void on_pb_tri_4_clicked();

    void on_pb_tri_5_clicked();

    void on_tabactivite_activated(const QModelIndex &index);

    void on_pushButton_clicked();

    void makePolt();

        void on_tabWidget_currentChanged();
        void on_pushButton_2_clicked();

        void on_pb_tri_7_clicked();

private:
    Ui::MainWindow *ui;
    adherant tmpadherant;
    activite tmpactivite;
};

#endif // MAINWINDOW_H
