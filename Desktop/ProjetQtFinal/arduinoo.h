#ifndef ARDUINOO_H
#define ARDUINOO_H

#include <QDialog>

namespace Ui {
class arduinoo;
}

class arduinoo : public QDialog
{
    Q_OBJECT

public:
    explicit arduinoo(QWidget *parent = nullptr);
    ~arduinoo();

private:
    Ui::arduinoo *ui;
};

#endif // ARDUINOO_H
