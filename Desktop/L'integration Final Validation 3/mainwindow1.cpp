#include "mainwindow1.h"
#include "ui_mainwindow1.h"

MainWindow1::MainWindow1(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    setCentralWidget(ui->listWidget);
    ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::ExtendedSelection);
    create();
}

MainWindow1::~MainWindow1()
{
    delete ui;
}


void MainWindow1::on_actionNew_triggered()
{
    checkSave();
    create();
}

void MainWindow1::on_actionOpen_triggered()
{
    checkSave();
    QString path = QFileDialog::getOpenFileName(this,"Open","","To-Do (*.td)");
    if(path.isEmpty()) return;
    open(path);
}

/*void MainWindow1::on_actionSave_triggered()
{
    if(m_filename.isEmpty())
    {
        on_actionSave_As_triggered();
        return;
    }

    save(m_filename);
}*/



void MainWindow1::on_actionExit_triggered()
{
    close();
}

void MainWindow1::on_actionAdd_triggered()
{
    createItem(Qt::CheckState::Unchecked,QString("New Item"));
    m_changed = true;
}

void MainWindow1::on_actionRemove_triggered()
{
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach(QListWidgetItem *itm, list)
    {
        delete ui->listWidget->takeItem(ui->listWidget->row(itm));
    }
    m_changed = true;
}

void MainWindow1::on_actionClear_triggered()
{
    ui->listWidget->clear();
    m_changed = true;
}



void MainWindow1::on_actionChecked_triggered()
{
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach(QListWidgetItem *itm, list)
    {
        itm->setCheckState(Qt::CheckState::Checked);
    }
    m_changed = true;
}

void MainWindow1::on_actionUnchecked_triggered()
{
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach(QListWidgetItem *itm, list)
    {
        itm->setCheckState(Qt::CheckState::Unchecked);
    }
    m_changed = true;
}

void MainWindow1::on_actionPartially_triggered()
{
    QList<QListWidgetItem*> list = ui->listWidget->selectedItems();
    foreach(QListWidgetItem *itm, list)
    {
        itm->setCheckState(Qt::CheckState::PartiallyChecked);
    }
    m_changed = true;
}

void MainWindow1::create()
{
    m_changed = false;
    m_filename.clear();
    ui->listWidget->clear();
}

void MainWindow1::open(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }

    QDataStream stream(&file);
    int count;
    stream >> count;

    for (int i = 0;i < count;i++)
    {
        int state = 0;
        QString name;
        stream >> state;
        stream >> name;
        Qt::CheckState checkstate = static_cast<Qt::CheckState>(state);
        createItem(checkstate,name);
    }
    file.close();
    m_filename = path;
    m_changed = false;
}

void MainWindow1::save(QString path)
{
    QFile file(path);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox::critical(this,"Error",file.errorString());
        return;
    }

    QDataStream stream(&file);

    stream << ui->listWidget->count();
    for(int i = 0; i < ui->listWidget->count(); i++)
    {
        QListWidgetItem *item = ui->listWidget->item(i);
        int state = static_cast<int>(item->checkState());
        stream << state;
        stream << item->text();
    }

    file.close();
    m_filename = path;
    m_changed = false;
}

void MainWindow1::checkSave()
{
    if(!m_changed) return;
    QMessageBox::StandardButton btn = QMessageBox::question(this,"Save File?","Do you want to save your changes?");
    if(btn == QMessageBox::StandardButton::Yes) save(m_filename);
}

void MainWindow1::createItem(Qt::CheckState state, QString name)
{
    QListWidgetItem *item = new QListWidgetItem(name,ui->listWidget);
    item->setCheckState(state);
    item->setFlags(Qt::ItemIsEnabled | Qt::ItemFlag::ItemIsEditable | Qt::ItemFlag::ItemIsTristate | Qt::ItemFlag::ItemIsUserCheckable | Qt::ItemIsSelectable);
    ui->listWidget->addItem(item);
}

void MainWindow1::closeEvent(QCloseEvent *event)
{
    event->accept();
}
