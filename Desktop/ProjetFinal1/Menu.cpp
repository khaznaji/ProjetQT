#include "Menu.h"
#include "ui_Menu.h"
#include"mainwindow.h"
Menu::Menu(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Menu)
{
    ui->setupUi(this);
}

Menu::~Menu()
{
    delete ui;
}

void Menu::on_pushButton_clicked()
{
    MainWindow mainWindow;
    mainWindow.setModal(true);
    mainWindow.exec();

}
