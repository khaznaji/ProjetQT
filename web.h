#ifndef WEB_H
#define WEB_H

#include <QDialog>

namespace Ui {
class web;
}

class web : public QDialog
{
    Q_OBJECT

public:
    explicit web(QWidget *parent = nullptr);
    ~web();

private:
    Ui::web *ui;
};

#endif // WEB_H
