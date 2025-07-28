#ifndef REGULATOR_PID_H
#define REGULATOR_PID_H
#pragma once

class RegulatorPID
{
public:
    RegulatorPID(double k);
    RegulatorPID(double k, double Ti);
    RegulatorPID(double k, double Ti, double Td);
    double symuluj(double uchyb);

    double getPoprzedniUchyb();
    double getP();
    double getI();
    double getD();
    void setP(double p_);
    void setI(double i_);
    void setD(double d_);

    double obliczP(double uchyb);
    double obliczI(double uchyb);
    double obliczD(double uchyb);
    double obliczISuma(double uchyb);
    double symulujZSuma(double uchyb);


    bool trybZSuma = false;
    void setTrybZSuma(bool wartosc);
private:
    double k;
    double Ti;
    double Td;

    double poprzedniUchyb;
    double sumUchybow;
    double dt;

    double p;
    double i;
    double iSuma;
    double d;

    double obliczWynik(double proporcjonalna, double calkujaca, double rozniczkowa);
};

#endif // REGULATOR_PID_H
