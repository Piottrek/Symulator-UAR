#ifndef SYMULATORUAR_H
#define SYMULATORUAR_H

#include "generator.h"
#include "rodzajSygnalu.h"
#include "sprzezenieZwrotne.h"
#include "regulatorPID.h"
#include <vector>

class SymulatorUAR
{
private:

public:
    SymulatorUAR(const std::vector<double> &a,
                 const std::vector<double> &b,
                 int opoznienie,
                 double zaklocenie,
                 double amplituda,
                 double okres,
                 double czasAktywacji,
                 double wypelnienie,
                 double skladowaStala,
                 RodzajSygnalu rodzajSygnalu,
                 double p,
                 double i,
                 double d);

    void setRodzajSygnalu(RodzajSygnalu rodzajSygnalu);

    void setParametryPID(double p, double i, double d);
    void setParametryARX(const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double zaklocenie);
    void setWartosci(double wartzad, double okres, double czasakt,double skladowaStala,double wypelnienie);


    GeneratorWartosciZadanej generator;
    SprzezenieZwrotne sprzezenie;
};

#endif // SYMULATORUAR_H
