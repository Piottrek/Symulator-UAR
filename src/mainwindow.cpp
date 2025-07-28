#include "mainwindow.h"
#include <QDebug>
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , symulator(nullptr)
    , czas(0.0)
{
    ui->setupUi(this);
    ui->startButton->setEnabled(false);

    this->setFixedSize(this->size());

    ui->wartoscP->setMinimum(0.0);
    ui->wartoscI->setMinimum(0.0);
    ui->wartoscD->setMinimum(0.0);
    ui->wartoscZadana->setMinimum(0.0);

    ui->wartoscP->setMaximum(1000.0);
    ui->wartoscI->setMaximum(1000.0);
    ui->wartoscD->setMaximum(1000.0);
    ui->wartoscZadana->setMaximum(1000.0);
    ui->okres->setMaximum(1000.0);
    ui->czasAktywacji->setMaximum(1000.0);
    ui->wypelnienieSpinBox->setMaximum(1.0);

    ustawWykresy();

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::startUAR);
    connect(ui->stopButton, &QPushButton::clicked, this, &MainWindow::stopUAR);
    connect(timer, &QTimer::timeout, this, &MainWindow::wgrajDane);
    connect(ui->aktualizuj, &QPushButton::clicked, this, &MainWindow::zaktualizujDane);
    connect(ui->rodzajWykresu, &QComboBox::currentIndexChanged, this, &MainWindow::zmienSygnal);

    ui->rodzajWykresu->addItem("Sinusoida");
    ui->rodzajWykresu->addItem("Prostokątny");
    ui->rodzajWykresu->addItem("Skok jednostkowy");

    ui->wektoryALIneEdit->setStyleSheet("QLineEdit {background-color:#ffcccc; color: black; }");
    ui->wektoryBLIneEdit->setStyleSheet("QLineEdit {background-color:#ffcccc; color: black; }");
}

MainWindow::~MainWindow()
{
    delete ui;
    delete symulator;
}

void MainWindow::ustawWykresy()
{
    ui->plotUchyb->addGraph();
    ui->plotUchyb->graph(0)->setPen(QPen(Qt::red, 2));
    ui->plotUchyb->xAxis->setLabel("Czas [s]");
    ui->plotUchyb->yAxis->setLabel("Uchyb");
    ui->plotUchyb->legend->setVisible(true);
    ui->plotUchyb->graph(0)->setName("Uchyb");
    ui->plotUchyb->xAxis->setRange(0, 10);
    ui->plotUchyb->rescaleAxes();

    ui->plotPID->addGraph();
    ui->plotPID->addGraph();
    ui->plotPID->addGraph();

    ui->plotPID->graph(0)->setPen(QPen(Qt::blue, 2));
    ui->plotPID->graph(1)->setPen(QPen(Qt::green, 2));
    ui->plotPID->graph(2)->setPen(QPen(Qt::magenta, 2));

    ui->plotPID->xAxis->setLabel("Czas [s]");
    ui->plotPID->yAxis->setLabel("Składowe PID");
    ui->plotPID->legend->setVisible(true);
    ui->plotPID->graph(0)->setName("P");
    ui->plotPID->graph(1)->setName("I");
    ui->plotPID->graph(2)->setName("D");
    ui->plotPID->xAxis->setRange(0, 10);
    ui->plotPID->rescaleAxes();

    ui->plotSterowanie->addGraph();
    ui->plotSterowanie->graph(0)->setPen(QPen(Qt::darkGreen, 2));
    ui->plotSterowanie->xAxis->setLabel("Czas [s]");
    ui->plotSterowanie->yAxis->setLabel("Sterowanie");
    ui->plotSterowanie->legend->setVisible(true);
    ui->plotSterowanie->graph(0)->setName("Sterowanie");
    ui->plotSterowanie->xAxis->setRange(0, 10);
    ui->plotSterowanie->rescaleAxes();

    ui->plotWartosci->addGraph();
    ui->plotWartosci->addGraph();

    ui->plotWartosci->graph(0)->setPen(QPen(Qt::blue, 2));
    ui->plotWartosci->graph(1)->setPen(QPen(Qt::cyan, 2));

    ui->plotWartosci->xAxis->setLabel("Czas [s]");
    ui->plotWartosci->yAxis->setLabel("Wartości");
    ui->plotWartosci->legend->setVisible(true);
    ui->plotWartosci->graph(0)->setName("Wartość zadana");
    ui->plotWartosci->graph(1)->setName("Wartość regulowana");
    ui->plotWartosci->xAxis->setRange(0, 10);
    ui->plotWartosci->rescaleAxes();
}


void MainWindow::startUAR()
{
    timer->start(ui->czas_spinBox->value());
}

void MainWindow::stopUAR()
{
    timer->stop();
}
void MainWindow::wgrajDane()
{
    czas += 0.1;

    double wartoscZadana = symulator->generator.generuj(czas);
    double sterowanie = symulator->sprzezenie.getSterowanie();
    double regulowana = symulator->sprzezenie.symulacja(wartoscZadana);
    double uchyb = symulator->sprzezenie.getUchyb();

    double P = symulator->sprzezenie.regulatorPID.getP();
    double I = symulator->sprzezenie.regulatorPID.getI();
    double D = symulator->sprzezenie.regulatorPID.getD();

    qDebug() << "Czas:" << czas;
    qDebug() << "Wartość zadana:" << wartoscZadana;
    qDebug() << "Uchyb:" << uchyb;
    qDebug() << "Sterowanie:" << sterowanie;
    qDebug() << "Wartość regulowana:" << regulowana;

    ui->plotUchyb->graph(0)->addData(czas, uchyb);

    if (czas > ui->plotUchyb->xAxis->range().upper)
        ui->plotUchyb->xAxis->setRange(czas, 10, Qt::AlignRight);

    ui->plotUchyb->graph(0)->rescaleValueAxis(true);
    ui->plotUchyb->replot();

    ui->plotPID->graph(0)->addData(czas, P);
    ui->plotPID->graph(1)->addData(czas, I);
    ui->plotPID->graph(2)->addData(czas, D);

    if (czas > ui->plotPID->xAxis->range().upper)
        ui->plotPID->xAxis->setRange(czas, 10, Qt::AlignRight);

    ui->plotPID->graph(0)->rescaleValueAxis(true);
    ui->plotPID->graph(1)->rescaleValueAxis(true);
    ui->plotPID->graph(2)->rescaleValueAxis(true);

    ui->plotPID->replot();

    ui->plotSterowanie->graph(0)->addData(czas, sterowanie);

    if (czas > ui->plotSterowanie->xAxis->range().upper)
        ui->plotSterowanie->xAxis->setRange(czas, 10, Qt::AlignRight);

    ui->plotSterowanie->graph(0)->rescaleValueAxis(true);
    ui->plotSterowanie->replot();

    ui->plotWartosci->graph(0)->addData(czas, wartoscZadana);
    ui->plotWartosci->graph(1)->addData(czas, regulowana);

    if (czas > ui->plotWartosci->xAxis->range().upper)
        ui->plotWartosci->xAxis->setRange(czas, 10, Qt::AlignRight);

    ui->plotWartosci->graph(0)->rescaleValueAxis(true);
    ui->plotWartosci->graph(1)->rescaleValueAxis(true);

    ui->plotWartosci->replot();
}


bool MainWindow::sprawdzanieDanych()
{

    QStringList listaA = wartoscA.split(";");
    QStringList listaB = wartoscB.split(";");

    for (int i = 0; i < listaA.size(); ++i) {
        bool poprawne;
        listaA[i].toDouble(&poprawne);

        if (!poprawne) {
            QString informacja = QString("Nieprawidłowa wartość w wektorze A: %1").arg(listaA[i]);
            ui->statusbar->showMessage(informacja, 5000);
            return false;
        }
    }

    for (int i = 0; i < listaB.size(); ++i) {
        bool poprawne;
        listaB[i].toDouble(&poprawne);

        if (!poprawne) {
            QString informacja = QString("Nieprawidłowa wartość w wektorze B: %1").arg(listaB[i]);
            ui->statusbar->showMessage(informacja, 5000);
            return false;
        }
    }
    ui->statusbar->clearMessage();
    return true;
}

void MainWindow::zaktualizujDane()
{

    if (sprawdzanieDanych()) {
        ui->startButton->setEnabled(true);
    } else {
        ui->startButton->setEnabled(false);
        return;
    }

    timer->setInterval(ui->czas_spinBox->value());

    QStringList aList = wartoscA.split(";");
    QStringList bList = wartoscB.split(";");

    std::vector<double> a, b;

    for (int i = 0; i < aList.size(); ++i) {
        double wartosc = aList[i].toDouble();
        a.push_back(wartosc);
    }

    for (int i = 0; i < bList.size(); ++i) {
        double wartosc = bList[i].toDouble();
        b.push_back(wartosc);
    }

    int opoznienie = opoznienieOP;
    double zaklocenie = zaklocenieZA;
    double p = ui->wartoscP->value();
    double i = ui->wartoscI->value();
    double d = ui->wartoscD->value();
    double wartzad = ui->wartoscZadana->value();
    double okres = ui->okres->value();
    double czasakt = ui->czasAktywacji->value();
    double wypelnienie = ui->wypelnienieSpinBox->value();
    double skladowaStala = ui->skladowaStalaSpinBox->value();



    RodzajSygnalu rodzajSygnalu = static_cast<RodzajSygnalu>(ui->rodzajWykresu->currentIndex());

    if(!symulator)
    {
        symulator = new SymulatorUAR(
            a, b, opoznienie, zaklocenie, wartzad, okres, czasakt,wypelnienie,skladowaStala, rodzajSygnalu, p, i, d);
    }
    else
    {
        symulator->setParametryPID(p,i,d);
        symulator->setParametryARX(a,b,opoznienie,zaklocenie);
        symulator->setWartosci(wartzad,okres,czasakt,skladowaStala,wypelnienie);
        symulator->sprzezenie.regulatorPID.setTrybZSuma(ui->sumaCheckBox->isChecked());

    }
}

void MainWindow::zmienSygnal(int indeks)
{
    if (symulator) {
        symulator->setRodzajSygnalu(static_cast<RodzajSygnalu>(indeks));
    }
}

void MainWindow::on_reset_pushButton_clicked()
{
    ui->startButton->setEnabled(false);

    timer->stop();

    ui->plotUchyb->graph(0)->data()->clear();
    ui->plotUchyb->xAxis->setRange(0, 10);
    ui->plotUchyb->yAxis->setRange(-3, 3);
    ui->plotUchyb->replot();

    ui->plotPID->graph(0)->data()->clear();
    ui->plotPID->graph(1)->data()->clear();
    ui->plotPID->graph(2)->data()->clear();
    ui->plotPID->xAxis->setRange(0, 10);
    ui->plotPID->yAxis->setRange(-5, 5);
    ui->plotPID->replot();

    ui->plotSterowanie->graph(0)->data()->clear();
    ui->plotSterowanie->xAxis->setRange(0, 10);
    ui->plotSterowanie->yAxis->setRange(-3, 5);
    ui->plotSterowanie->replot();

    ui->plotWartosci->graph(0)->data()->clear();
    ui->plotWartosci->graph(1)->data()->clear();
    ui->plotWartosci->xAxis->setRange(0, 10);
    ui->plotWartosci->yAxis->setRange(-3, 5);
    ui->plotWartosci->replot();


    czas = 0.0;

    if (symulator) {
        delete symulator;
        symulator = nullptr;
    }
}


void MainWindow::on_zmienARXbutton_clicked()
{
    oknoARX okno(this);

    okno.setA(wartoscA);
    okno.setB(wartoscB);


    okno.setOpoznienie(opoznienieOP);
    okno.setZaklocenie(zaklocenieZA);

    if (okno.exec() == QDialog::Accepted)
    {
        wartoscA = okno.getA();
        wartoscB = okno.getB();

        opoznienieOP = okno.getOpoznienie();
        zaklocenieZA = okno.getZaklocenie();

        zaktualizujDane();
        ui->wektoryALIneEdit->setText(wartoscA);
        ui->wektoryBLIneEdit->setText(wartoscB);
    }
}

