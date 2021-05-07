#ifndef DIALOG1_H
#define DIALOG1_H
#include "mainwindo.h"
#include <QDialog>
#include <QDialog>
#include <QPushButton>
#include <QMessageBox>
#include "server.h"


QT_BEGIN_NAMESPACE
namespace Ui { class Dialog1; }
QT_END_NAMESPACE

class Dialog1 : public QDialog
{
    Q_OBJECT

public:
    Dialog1(QWidget *parent = nullptr);
    ~Dialog1();

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
    Ui::Dialog1 *ui;
    QPushButton *btnBack;
    QPushButton *btnNext;
    Server server;
      mainwindo *chat ;

    void init();
    void enableButtons();
};



#endif // DIALOG1_H
