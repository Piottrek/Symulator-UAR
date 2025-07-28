#ifndef SPRZEZENIEZWROTNE_H
#define SPRZEZENIEZWROTNE_H

#include "modelARX.h"
#include "regulatorPID.h"

class SprzezenieZwrotne
{
private:
    ModelARX modelARX;

    double uchyb;
    double poprzedniUchyb;
    double wartoscZadana;

public:
    RegulatorPID regulatorPID;
    SprzezenieZwrotne(const std::vector<double> &a,
                      const std::vector<double> &b,
                      int opoznienie,
                      double zaklocenie,
                      double p,
                      double i,
                      double d);

    double symulacja(double wartoscZadana);
    double getUchyb();
    double getPoprzedniUchyb();
    void setUchyb(double u);
    void setPoprzedniUchyb(double pu);
    void Oblicz_uchyb();
    double getSterowanie();

    void setPID(double p, double i, double d);
    void setARX(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak);
    void setWartZad(double war);
};

#endif // SPRZEZENIEZWROTNE_H
