#include "RegulatorPID.h"

RegulatorPID::RegulatorPID(double k)
    : k(k)
    , Ti(0.0)
    , Td(0.0)
    , poprzedniUchyb(0.0)
    , sumUchybow(0.0)
    , dt(1.0)
    , p(0.0)
    , i(0.0)
    , d(0.0)
{}

RegulatorPID::RegulatorPID(double k, double Ti)
    : k(k)
    , Ti(Ti)
    , Td(0.0)
    , poprzedniUchyb(0.0)
    , sumUchybow(0.0)
    , dt(1.0)
    , p(0.0)
    , i(0.0)
    , d(0.0)
{}

RegulatorPID::RegulatorPID(double k, double Ti, double Td)
    : k(k)
    , Ti(Ti)
    , Td(Td)
    , poprzedniUchyb(0.0)
    , sumUchybow(0.0)
    , dt(1.0)
    , p(0.0)
    , i(0.0)
    , d(0.0)
{}



double RegulatorPID::obliczP(double uchyb)
{
    return k * uchyb;
}

double RegulatorPID::obliczI(double uchyb)
{
    if (Ti > 0) {
        sumUchybow += uchyb;
        return sumUchybow / Ti;
    } else {
        return 0.0;
    }
}

double RegulatorPID::obliczISuma(double uchyb)
{
    if (Ti > 0) {
        return sumUchybow += uchyb/Ti;
    } else {
        return 0.0;
    }
}

double RegulatorPID::obliczD(double uchyb)
{
    if (Td > 0) {
        double deltaUchyb = uchyb - poprzedniUchyb;
        return Td * deltaUchyb;
    } else {
        return 0.0;
    }
}

double RegulatorPID::symulujZSuma(double uchyb)
{

    this->p = obliczP(uchyb);
    this->iSuma = obliczI(uchyb);
    this->d = obliczD(uchyb);

    //double p = obliczP(uchyb);
    //double iSuma = obliczISuma(uchyb);
    //double d = obliczD(uchyb);

    poprzedniUchyb = uchyb;

    return obliczWynik(p, iSuma, d);
}

void RegulatorPID::setTrybZSuma(bool wartosc)
{
    trybZSuma = wartosc;
}

double RegulatorPID::symuluj(double uchyb)
{
    if (trybZSuma)
        return symulujZSuma(uchyb);

    this->p = obliczP(uchyb);
    this->i = obliczI(uchyb);
    this->d = obliczD(uchyb);

    //double p = obliczP(uchyb);
    //double i = obliczI(uchyb);
    //double d = obliczD(uchyb);

    poprzedniUchyb = uchyb;
    return obliczWynik(p, i, d);
}


double RegulatorPID::obliczWynik(double proporcjonalna, double calkujaca, double rozniczkowa)
{
    return proporcjonalna + calkujaca + rozniczkowa;
}

double RegulatorPID::getPoprzedniUchyb()
{
    return poprzedniUchyb;
}

double RegulatorPID::getP()
{
    return p;
}

double RegulatorPID::getI()
{
    if(trybZSuma)
    {
        return iSuma;
    }
    else
    {
        return i;
    }
}

double RegulatorPID::getD()
{
    return d;
}

void RegulatorPID::setP(double p_)
{
    this->k = p_;
}
void RegulatorPID::setI(double i_)
{
    this->Ti = i_;
}
void RegulatorPID::setD(double d_)
{
    this->Td = d_;
}
