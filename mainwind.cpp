#include "mainwind.h"
#include "ui_mainwind.h"
#include<QWidget>

/*mainwind::mainwind(QWidget *parent) :
   // QDialog(parent),
    ui(new Ui::mainwind)
{
    ui->setupUi(this);
    this->setCentralWidget(ui->textEdit);
    ui->textEdit->setStyleSheet(QString::fromUtf8("background-color: rgb(50, 50, 50); color: rgb(250, 250, 250);"));

    statusLabel = new QLabel(this);
    statusLabel->setText("NotePad 1.0");
    ui->statusBar->addPermanentWidget(statusLabel, 1);
}

mainwind::~mainwind()
{
    delete ui;
}




void mainwind::on_actionNew_triggered()
{
    mFileName = "";
    ui->textEdit->setPlainText("");
}

void mainwind::on_actionOpen_triggered()
{
    QString file = QFileDialog::getOpenFileName(this, "Open a file");

    if( !file.isEmpty() )
    {
        QFile sFile(file);
        if( sFile.open(QFile::ReadOnly | QFile::Text) )
        {
            mFileName = file;
            QTextStream in(&sFile);
            QString text = in.readAll();
            sFile.close();

            ui->textEdit->setPlainText(text);
        }
    }
}

void mainwind::on_actionSave_triggered()
{
    if( !mFileName.isEmpty() )
    {
        QFile sFile(mFileName);

        if( sFile.open(QFile::WriteOnly | QFile::Text) )
        {
            QTextStream out(&sFile);

            out << ui->textEdit->toPlainText();

            sFile.flush();
            sFile.close();
            QMessageBox::information(this, "Save", "Saved Successfully!");
        }
    }
    else
    {
        on_actionSave_as_triggered();
    }
}

void mainwind::on_actionSave_as_triggered()
{
    QString file = QFileDialog::getSaveFileName(this, "Save a file");

    if( !file.isEmpty() )
    {
        mFileName = file;
        on_actionSave_triggered();
    }
}

void mainwind::on_actionCopy_triggered()
{
    ui->textEdit->copy();
}

void mainwind::on_actionCut_triggered()
{
    ui->textEdit->cut();
}

void mainwindo::on_actionPaste_triggered()
{
    ui->textEdit->paste();
}

void mainwind::on_actionUndo_triggered()
{
    ui->textEdit->undo();
}

void mainwind::on_actionRedo_triggered()
{
    ui->textEdit->redo();
}
*/
