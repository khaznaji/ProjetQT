#include "dialog1.h"
#include "ui_dialog1.h"
#include<QHostAddress>

Dialog1::Dialog1(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog1)
{
    ui->setupUi(this);
}

Dialog1::~Dialog1()
{
    delete ui;
}




void Dialog1::on_btnStart_clicked()
{
    quint16 port = static_cast<quint16>(ui->sbPort->value());

    server.setMessage(ui->txtMessage->text() + "\r\n");
    if(!server.listen(QHostAddress::Any, port))
    {
        QMessageBox::critical(this,"Error",server.errorString());
        return;
    }

    ui->lblStatus->setText("Listening...");
    enableButtons();
}

void Dialog1::on_btnStop_clicked()
{
    server.close();
    ui->lblStatus->setText("Closed");
    enableButtons();
}

void Dialog1::next()
{
    int i = ui->stackedWidget->currentIndex();
    i++;
    if(i >= ui->stackedWidget->count()) i = ui->stackedWidget->count() - 1;
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog1::back()
{
    int i = ui->stackedWidget->currentIndex();
    i--;
    if(i < 0) i = 0;
    ui->stackedWidget->setCurrentIndex(i);
    enableButtons();
}

void Dialog1::changed()
{
    ui->lblStatus->setText(QString("There are %0 clients connected").arg(server.count()));
}

void Dialog1::init()
{
    btnNext = new QPushButton("Next", this);
    btnBack = new QPushButton("Back", this);

   // ui->buttonBox->addButton(btnBack, QDialogButtonBox::ButtonRole::ActionRole);
    //ui->buttonBox->addButton(btnNext, QDialogButtonBox::ButtonRole::ActionRole);

    connect(btnBack, &QPushButton::clicked,this,&Dialog1::back);
    connect(btnNext, &QPushButton::clicked,this,&Dialog1::next);
    connect(&server, &Server::changed,this,&Dialog1::changed);
    enableButtons();
}

void Dialog1::enableButtons()
{
    ui->btnStart->setEnabled(!server.isListening());
    ui->btnStop->setEnabled(server.isListening());

    //Only one page
    if(ui->stackedWidget->count() <= 1)
    {
        btnBack->setEnabled(false);
        btnNext->setEnabled(false);
        return;
    }

    //First page
    if(ui->stackedWidget->currentIndex() == 0)
    {
        btnBack->setEnabled(false);
        btnNext->setEnabled(true);
        return;
    }

    //Last page
    if(ui->stackedWidget->currentIndex() >= ui->stackedWidget->count() -1)
    {
        btnBack->setEnabled(true);
        btnNext->setEnabled(false);
        return;
    }
}












/*void Dialog1::on_buttonBox_accepted()
{
    chat= new mainwindo (this);
    chat->show();
}
*/

/*void Dialog1::on_pushButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}*/
