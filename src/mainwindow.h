#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include "oknoarx.h"
#include "qcustomplot.h"
#include "symulator.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startUAR();
    void stopUAR();
    void wgrajDane();
    void zaktualizujDane();
    void zmienSygnal(int indeks);

    void on_reset_pushButton_clicked();
    void on_zmienARXbutton_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    SymulatorUAR *symulator;
    oknoARX *oknoarx;
    void ustawWykresy();
    QCustomPlot *customPlot;

    QString wartoscA, wartoscB;
    int opoznienieOP = 1;
    double zaklocenieZA= 0.0;
    bool sprawdzanieDanych();
    double czas = 0.0;
};

#endif // MAINWINDOW_H
