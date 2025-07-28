#include "oknoarx.h"
#include "ui_oknoarx.h"
#include "modelARX.h"

oknoARX::oknoARX(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::oknoARX)
{
    ui->setupUi(this);

    connect(ui->anulujButton,&QPushButton::clicked,this,&oknoARX::reject);
    connect(ui->zatwierdzButton,&QPushButton::clicked,this,&oknoARX::accept);
    ui->zaklocenieSpinBox->setMinimum(0.0);
    ui->opoznienieSpinBox->setMinimum(1.0);
    ui->opoznienieSpinBox->setMaximum(1000.0);
    ui->zaklocenieSpinBox->setMaximum(1000.0);
}

oknoARX::~oknoARX()
{
    delete ui;
}

QString oknoARX::getA()
{
    return ui->aLineEdit->text();
}

QString oknoARX::getB()
{
    return ui->bLineEdit->text();
}

void oknoARX::setA(QString wartosc)
{
    ui->aLineEdit->setText(wartosc);
}

void oknoARX::setB(QString wartosc)
{
    ui->bLineEdit->setText(wartosc);
}

int oknoARX::getOpoznienie()
{
    return ui->opoznienieSpinBox->value();
}

double oknoARX::getZaklocenie()
{
    return ui->zaklocenieSpinBox->value();
}

void oknoARX::setZaklocenie(double WartoscZaklocenie)
{
    ui->zaklocenieSpinBox->setValue(WartoscZaklocenie);
}

void oknoARX::setOpoznienie(int WartoscOpoznienie)
{
    ui->opoznienieSpinBox->setValue(WartoscOpoznienie);
}
