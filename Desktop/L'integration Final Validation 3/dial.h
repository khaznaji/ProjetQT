#ifndef DIAL_H
#define DIAL_H
#include <QDialog>
#include <QDialog>
#include <QPushButton>
#include <QGridLayout>
#include <QMessageBox>
#include "equation.h"

QT_BEGIN_NAMESPACE
namespace Ui { class Dial; }
QT_END_NAMESPACE

class Dial : public QDialog
{
    Q_OBJECT

public:
    Dial(QWidget *parent = nullptr);
    ~Dial();

private slots:
    void on_buttonBox_accepted();
    void clear();
    void add();
    void subtract();
    void multiply();
    void divide();
    void number();
    void update();
    void addEquation();

private:
    Ui::Dial *ui;
    QList<Equation*> m_list;
    void init();
    Equation *getLast();
    void updateValue(QString data);
    void updateAction(Equation::Action value);

};
#endif // DIAL_H
