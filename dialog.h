#ifndef DIALOG_H
#define DIALOG_H
#include "mainwindo.h"
#include <QDialog>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include "server.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog; }
QT_END_NAMESPACE

class Dialog : public QDialog
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_btnStart_clicked();
    void on_btnStop_clicked();
    void next();
    void back();
    void changed();

    void on_buttonBox_accepted();

    void on_buttonBox_clicked(QAbstractButton *button);

    void on_pushButton_clicked();

private:
    Ui::Dialog *ui;
    QPushButton *btnBack;
    QPushButton *btnNext;
    Server server;
      mainwindo *chat ;

    void init();
    void enableButtons();
};
#endif // DIALOG_H
