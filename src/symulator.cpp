#include "symulator.h"

SymulatorUAR::SymulatorUAR(const std::vector<double> &a,
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
                           double d)
    : generator(rodzajSygnalu, amplituda, okres, czasAktywacji,skladowaStala,wypelnienie)
    , sprzezenie(a, b, opoznienie, zaklocenie, p, i, d)
{}

void SymulatorUAR::setRodzajSygnalu(RodzajSygnalu rodzajSygnalu)
{
    generator.setRodzajSygnalu(rodzajSygnalu);
}


void SymulatorUAR::setParametryPID(double p, double i, double d)
{
    sprzezenie.setPID(p,i,d);
}

void SymulatorUAR::setParametryARX(const std::vector<double>& a, const std::vector<double>& b, int opoznienie, double zaklocenie)
{
    sprzezenie.setARX(a,b,opoznienie,zaklocenie);
}

void SymulatorUAR::setWartosci(double wartzad, double okres, double czasakt,double skladowaStala,double wypelnienie)
{
    sprzezenie.setWartZad(wartzad);
    generator.setParametry(okres, czasakt,skladowaStala,wypelnienie);
}



