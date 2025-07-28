#include "ModelARX.h"
#include <QDebug>
#include <numeric>
#include <random>

ModelARX::ModelARX(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak)
    : wek_a(a)
    , wek_b(b)
    , opoznienie(opoz)
    , zaklocenie(zak)
{
    buforSterowania = std::deque<double>(wek_b.size() + opoznienie, 0.0);
    buforOpoznienia = std::deque<double>(wek_a.size(), 0.0);
}

void ModelARX::setParametry(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak)
{
    //qDebug() << "Wartosci przed:";
    //qDebug() << "Rozmiar wektora a: " << wek_a.size()
    //          << "Rozmiar wektora b: " << wek_b.size()
    //          << "Rozmiar buforu sterowania: " << buforSterowania.size()
    //          << "Rozmiar buforu opoznienia: " << buforOpoznienia.size();
    wek_a.resize(a.size());
    wek_b.resize(b.size());
    buforSterowania.resize(b.size() + opoz);
    buforOpoznienia.resize(a.size());

    this->wek_a = a;
    wek_b = b;
    opoznienie = opoz;
    zaklocenie = zak;
    // qDebug() << "Wartosci po:";
    // qDebug() << "Rozmiar wektora a: " << wek_a.size()
    //          << "Rozmiar wektora b: " << wek_b.size()
    //          << "Rozmiar buforu sterowania: " << buforSterowania.size()
    //         << "Rozmiar buforu opoznienia: " << buforOpoznienia.size();
}


double ModelARX::symuluj(double sygnalWejsciowy)
{
    buforSterowania.push_front(sygnalWejsciowy);
    buforSterowania.pop_back();

    double iloczyn_wek_B = std::inner_product(wek_b.begin(),
                                              wek_b.end(),
                                              buforSterowania.begin() + opoznienie,
                                              0.0);

    double iloczyn_wek_A = std::inner_product(wek_a.begin(),
                                              wek_a.end(),
                                              buforOpoznienia.begin(),
                                              0.0);

    double wartosc_zaklocenia = 0.0;

    if (zaklocenie != 0.0) {
        std::random_device srng;
        std::mt19937 rng;
        rng.seed(srng());
        std::normal_distribution<double> rozkladnormalny(0.0, this->zaklocenie);

        wartosc_zaklocenia = rozkladnormalny(rng);
        qDebug() << "Zakłócenie: " << zaklocenie;
        qDebug() << "Wartość zakłócenia:" << wartosc_zaklocenia;
    }

    double wyjscie = iloczyn_wek_B - iloczyn_wek_A + wartosc_zaklocenia;

    buforOpoznienia.push_front(wyjscie);

    buforOpoznienia.pop_back();
    return wyjscie;
}
