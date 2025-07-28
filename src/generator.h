#ifndef GENERATOR_H
#define GENERATOR_H
#pragma once
#include "rodzajSygnalu.h"

class GeneratorWartosciZadanej
{
private:
    RodzajSygnalu rodzajSygnalu;
    double amplituda = 0;
    double okres = 0;
    double czasAktywacji = 0;
    double skladowaStala = 0;
    double wypelnienie= 0;

    double generujSkokJednostkowy(double czas);
    double generujSinusoide(double czas);
    double generujProstokatny(double czas);

public:
    GeneratorWartosciZadanej(RodzajSygnalu rodzaj,
                             double amplituda,
                             double okres,
                             double skladowaStala,
                             double wypelnienie,
                             double czasAktywacji = 0.0);

    double generuj(double czas);
    void setRodzajSygnalu(RodzajSygnalu rodzajSygnalu);
    void setParametry(double o, double czasak,double skladowaStala,double wypelnienie);

};

#endif // GENERATOR_H
