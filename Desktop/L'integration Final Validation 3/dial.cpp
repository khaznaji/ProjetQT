#include "dial.h"
#include "ui_dial.h"

Dial::Dial(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dial)
{
    ui->setupUi(this);
 init();
}

Dial::~Dial()
{
     qDeleteAll(m_list);
    delete ui;

}

void Dial::on_buttonBox_accepted()
{
    //Add them
    double total = 0;
    foreach(Equation *e, m_list)
    {
        bool ok;
        double value = e->getSum().toDouble(&ok);
        if(!ok) continue;
        total = total + value;
    }

    QMessageBox::information(this,"Total","Total is: " + QString::number(total));
    //accept();
}

void Dial::clear()
{
    if(m_list.count() == 0) return;
    qDeleteAll(m_list);
    m_list.clear();
    update();
}

void Dial::add()
{
    updateAction(Equation::Action::ADD);
}

void Dial::subtract()
{
    updateAction(Equation::Action::SUBTRACT);
}

void Dial::multiply()
{
    updateAction(Equation::Action::MULTIPLY);
}

void Dial::divide()
{
    updateAction(Equation::Action::DIVIDE);
}

void Dial::number()
{
    QPushButton *btn = static_cast<QPushButton*>(sender());
    if(!btn) return;

    bool ok;
    double value = btn->text().toDouble(&ok);
    Q_UNUSED(value)

    if(!ok)
    {
        QMessageBox::critical(this,"Error","Not a number!");
        return;
    }

    updateValue(btn->text());

}

void Dial::update()
{
    if(ui->listWidget->count() != m_list.count())
    {
        //Out of sync
        ui->listWidget->clear();
        foreach (Equation *e, m_list)
        {
            ui->listWidget->addItem(e->toString());
        }
        ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
    }
    else
    {
        //Update the last one
        ui->listWidget->setCurrentRow(ui->listWidget->count() - 1);
        ui->listWidget->item(ui->listWidget->count() - 1)->setText(m_list.last()->toString());
    }
}

void Dial::addEquation()
{
    m_list.append(new Equation(this));
    update();
}

void Dial::init()
{
    int row = 0;
    int col = 2;
    for (int i = 9;i >= 0;i--)
    {
        QPushButton *btn = new QPushButton(QString::number(i), this);
        connect(btn,&QPushButton::clicked,this,&Dial::number);

        ui->gridLayout->addWidget(btn,row,col);
        col--;
        if(col < 0)
        {
            row++;
            col = 2;
            if(row == 3) col = 0;
        }
    }

    QPushButton *btnAdd = new QPushButton("+", this);
    QPushButton *btnSubtract = new QPushButton("-", this);
    QPushButton *btnMultiply = new QPushButton("*", this);
    QPushButton *btnDivide = new QPushButton("/", this);
    QPushButton *btnClear = new QPushButton("Clear", this);
    QPushButton *btnRow = new QPushButton("Add Equation", this);

    connect(btnAdd,&QPushButton::clicked,this,&Dial::add);
    connect(btnSubtract,&QPushButton::clicked,this,&Dial::subtract);
    connect(btnMultiply,&QPushButton::clicked,this,&Dial::multiply);
    connect(btnDivide,&QPushButton::clicked,this,&Dial::divide);
    connect(btnClear,&QPushButton::clicked,this,&Dial::clear);
    connect(btnRow,&QPushButton::clicked,this,&Dial::addEquation);

    ui->gridLayout->addWidget(btnAdd,0,3);
    ui->gridLayout->addWidget(btnSubtract,1,3);
    ui->gridLayout->addWidget(btnMultiply,2,3);
    ui->gridLayout->addWidget(btnDivide,3,3);

  //  ui->buttonBox->addButton(btnClear,QDialogButtonBox::ButtonRole::ActionRole);
    //ui->buttonBox->addButton(btnRow,QDialogButtonBox::ButtonRole::ActionRole);
}

Equation *Dial::getLast()
{
    if(m_list.count() == 0) m_list.append(new Equation(this));
    return m_list.last();
}

void Dial::updateValue(QString data)
{
    Equation *equation = getLast();
    if(!equation) return;

    QString value;
    if(equation->getAction() == Equation::Action::NONE)
    {
        qDebug() << "NONE";
        value = equation->getValue1();
        value.append(data);
        equation->setValue1(value);
    }
    else
    {
        qDebug() << "NOT NONE";
        value = equation->getValue2();
        value.append(data);
        equation->setValue2(value);
    }

    equation->calculate();
    update();

}

void Dial::updateAction(Equation::Action value)
{
    Equation *equation = getLast();
    if(!equation) return;
    equation->setAction(value);
    equation->calculate();
    update();
}
