#ifndef OKNOARX_H
#define OKNOARX_H

#include <QDialog>

namespace Ui {
class oknoARX;
}

class oknoARX : public QDialog
{
    Q_OBJECT

public:
    explicit oknoARX(QWidget *parent = nullptr);
    ~oknoARX();

    QString getA();
    QString getB();

    void setA(QString wartosc);
    void setB(QString wartosc);

    int getOpoznienie();
    double getZaklocenie();

    void setZaklocenie(double WartoscZaklocenie);
    void setOpoznienie(int WartoscOpoznienie);
private:
    Ui::oknoARX *ui;
};

#endif // OKNOARX_H
