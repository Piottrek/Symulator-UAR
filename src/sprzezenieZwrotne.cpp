#include "sprzezenieZwrotne.h"
#include "QDebug"
SprzezenieZwrotne::SprzezenieZwrotne(const std::vector<double> &a,
                                     const std::vector<double> &b,
                                     int opoznienie,
                                     double zaklocenie,
                                     double p,
                                     double i,
                                     double d)
    : modelARX(a, b, opoznienie, zaklocenie)
    , uchyb(0)
    , poprzedniUchyb(0)
    , regulatorPID(p, i, d)
{}

double SprzezenieZwrotne::symulacja(double sygwe)
{
    setUchyb(sygwe - getPoprzedniUchyb());

    double wyjscieModelu = modelARX.symuluj(regulatorPID.symuluj(getUchyb()));

    setPoprzedniUchyb(wyjscieModelu);

    qDebug() << "Wyjście modelu ARX:" << wyjscieModelu;
    qDebug() << "Uchyb:" << uchyb;

    return wyjscieModelu;
}

double SprzezenieZwrotne::getSterowanie()
{
    return regulatorPID.symuluj(getUchyb());
}

double SprzezenieZwrotne::getUchyb()
{
    return uchyb;
}

void SprzezenieZwrotne::setUchyb(double u)
{
    uchyb = u;
}

double SprzezenieZwrotne::getPoprzedniUchyb()
{
    return poprzedniUchyb;
}

void SprzezenieZwrotne::setPoprzedniUchyb(double pu)
{
    poprzedniUchyb = pu;
}


void SprzezenieZwrotne::setPID(double p, double i, double d)
{
    regulatorPID.setP(p);
    regulatorPID.setI(i);
    regulatorPID.setD(d);
}

void SprzezenieZwrotne::setARX(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak)
{
    modelARX.setParametry(a,b,opoz,zak);
}

void SprzezenieZwrotne::setWartZad(double war)
{
    this->wartoscZadana = war;
}
