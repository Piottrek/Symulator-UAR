#pragma once
#include <deque>
#include <vector>

class ModelARX
{
private:

    std::deque<double> buforSterowania;
    std::deque<double> buforOpoznienia;
    int opoznienie;
    double zaklocenie;
    std::vector<double> wek_a;
    std::vector<double> wek_b;
public:

    ModelARX() = delete;
    ModelARX(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak);
    double symuluj(double sygnalWejsciowy);

    void setParametry(const std::vector<double> &a, const std::vector<double> &b, int opoz, double zak);


};
