#include "generator.h"
#include <cmath>

GeneratorWartosciZadanej::GeneratorWartosciZadanej(RodzajSygnalu rodzaj,
                                                   double amplituda,
                                                   double okres,
                                                   double czasAktywacji,
                                                   double skladowaStala,
                                                   double wypelnienie)
    : rodzajSygnalu(rodzaj)
    , amplituda(amplituda)
    , okres(okres)
    , czasAktywacji(czasAktywacji)
    , skladowaStala(skladowaStala)
    , wypelnienie(wypelnienie)
{}

void GeneratorWartosciZadanej::setRodzajSygnalu(RodzajSygnalu nowyRodzajSygnalu)
{
    rodzajSygnalu = nowyRodzajSygnalu;
}

double GeneratorWartosciZadanej::generuj(double czas)
{
    switch (rodzajSygnalu) {
    case RodzajSygnalu::Jednostkowy:
        return generujSkokJednostkowy(czas);

    case RodzajSygnalu::Sinusoida:
        return generujSinusoide(czas);

    case RodzajSygnalu::Prostokatny:
        return generujProstokatny(czas);

    default:
        return 0.0;
    }
}

double GeneratorWartosciZadanej::generujSkokJednostkowy(double czas)
{
    if (czas >= czasAktywacji) {
        return skladowaStala;
    } else {
        return 0.0;
    }
}

double GeneratorWartosciZadanej::generujSinusoide(double czas)
{
    const double epsilon = 1e-10;
    if (czas >= czasAktywacji) {
        double wynik = amplituda * sin((std::fmod(czas,okres)/okres) * 2 * 3.14) + skladowaStala;
        if (std::abs(wynik) < epsilon) {
            return 0.0;
        }
        return wynik + skladowaStala;
    }
    return 0.0;
}

double GeneratorWartosciZadanej::generujProstokatny(double czas)
{
    if (czas >= czasAktywacji) {
        double czasCyklu = std::fmod(czas, okres);
        if (czasCyklu < (wypelnienie * okres)) {
            return amplituda + skladowaStala;
        } else {
            return skladowaStala;
        }
    }
    return 0.0;
}

void GeneratorWartosciZadanej::setParametry(double o, double czasak,double skladowaStala,double wypelnienie)
{
    this->czasAktywacji = czasak;
    this->okres = o;
    this->skladowaStala = skladowaStala;
    this->wypelnienie = wypelnienie;
}
