/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QCustomPlot *plotWartosci;
    QCustomPlot *plotUchyb;
    QCustomPlot *plotPID;
    QCustomPlot *plotSterowanie;
    QFrame *frame_4;
    QLabel *labelP;
    QDoubleSpinBox *wartoscP;
    QLabel *labelI;
    QDoubleSpinBox *wartoscI;
    QLabel *labelD;
    QDoubleSpinBox *wartoscD;
    QCheckBox *sumaCheckBox;
    QFrame *frame_2;
    QLabel *labelWartZad;
    QDoubleSpinBox *wartoscZadana;
    QLabel *labelOkres;
    QDoubleSpinBox *okres;
    QLabel *labelCzasAkt;
    QDoubleSpinBox *czasAktywacji;
    QDoubleSpinBox *skladowaStalaSpinBox;
    QDoubleSpinBox *wypelnienieSpinBox;
    QSpinBox *czas_spinBox;
    QLabel *label_4;
    QLabel *label;
    QLabel *label_5;
    QFrame *frame;
    QComboBox *rodzajWykresu;
    QPushButton *aktualizuj;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *reset_pushButton;
    QPushButton *zmienARXbutton;
    QLineEdit *wektoryBLIneEdit;
    QLineEdit *wektoryALIneEdit;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1511, 808);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        plotWartosci = new QCustomPlot(centralwidget);
        plotWartosci->setObjectName(QString::fromUtf8("plotWartosci"));
        plotWartosci->setGeometry(QRect(10, 10, 1221, 380));
        plotUchyb = new QCustomPlot(centralwidget);
        plotUchyb->setObjectName(QString::fromUtf8("plotUchyb"));
        plotUchyb->setGeometry(QRect(10, 400, 381, 371));
        plotPID = new QCustomPlot(centralwidget);
        plotPID->setObjectName(QString::fromUtf8("plotPID"));
        plotPID->setGeometry(QRect(410, 400, 391, 381));
        plotSterowanie = new QCustomPlot(centralwidget);
        plotSterowanie->setObjectName(QString::fromUtf8("plotSterowanie"));
        plotSterowanie->setGeometry(QRect(820, 400, 411, 381));
        frame_4 = new QFrame(centralwidget);
        frame_4->setObjectName(QString::fromUtf8("frame_4"));
        frame_4->setGeometry(QRect(1260, 150, 231, 171));
        frame_4->setFrameShape(QFrame::Shape::Box);
        frame_4->setFrameShadow(QFrame::Shadow::Raised);
        frame_4->setLineWidth(2);
        labelP = new QLabel(frame_4);
        labelP->setObjectName(QString::fromUtf8("labelP"));
        labelP->setGeometry(QRect(30, 15, 31, 31));
        wartoscP = new QDoubleSpinBox(frame_4);
        wartoscP->setObjectName(QString::fromUtf8("wartoscP"));
        wartoscP->setGeometry(QRect(60, 10, 161, 41));
        wartoscP->setDecimals(2);
        wartoscP->setSingleStep(0.500000000000000);
        wartoscP->setValue(0.500000000000000);
        labelI = new QLabel(frame_4);
        labelI->setObjectName(QString::fromUtf8("labelI"));
        labelI->setGeometry(QRect(30, 70, 21, 16));
        wartoscI = new QDoubleSpinBox(frame_4);
        wartoscI->setObjectName(QString::fromUtf8("wartoscI"));
        wartoscI->setGeometry(QRect(60, 50, 161, 41));
        wartoscI->setSingleStep(0.500000000000000);
        wartoscI->setValue(5.000000000000000);
        labelD = new QLabel(frame_4);
        labelD->setObjectName(QString::fromUtf8("labelD"));
        labelD->setGeometry(QRect(30, 120, 21, 16));
        wartoscD = new QDoubleSpinBox(frame_4);
        wartoscD->setObjectName(QString::fromUtf8("wartoscD"));
        wartoscD->setGeometry(QRect(60, 120, 161, 41));
        wartoscD->setSingleStep(0.200000000000000);
        wartoscD->setValue(0.200000000000000);
        sumaCheckBox = new QCheckBox(frame_4);
        sumaCheckBox->setObjectName(QString::fromUtf8("sumaCheckBox"));
        sumaCheckBox->setGeometry(QRect(60, 90, 161, 31));
        frame_2 = new QFrame(centralwidget);
        frame_2->setObjectName(QString::fromUtf8("frame_2"));
        frame_2->setGeometry(QRect(1260, 330, 231, 261));
        frame_2->setFrameShape(QFrame::Shape::Box);
        frame_2->setFrameShadow(QFrame::Shadow::Raised);
        frame_2->setLineWidth(2);
        labelWartZad = new QLabel(frame_2);
        labelWartZad->setObjectName(QString::fromUtf8("labelWartZad"));
        labelWartZad->setGeometry(QRect(10, 60, 91, 20));
        wartoscZadana = new QDoubleSpinBox(frame_2);
        wartoscZadana->setObjectName(QString::fromUtf8("wartoscZadana"));
        wartoscZadana->setGeometry(QRect(100, 50, 120, 41));
        wartoscZadana->setValue(2.000000000000000);
        labelOkres = new QLabel(frame_2);
        labelOkres->setObjectName(QString::fromUtf8("labelOkres"));
        labelOkres->setGeometry(QRect(20, 90, 101, 31));
        okres = new QDoubleSpinBox(frame_2);
        okres->setObjectName(QString::fromUtf8("okres"));
        okres->setGeometry(QRect(100, 90, 120, 41));
        okres->setValue(1.000000000000000);
        labelCzasAkt = new QLabel(frame_2);
        labelCzasAkt->setObjectName(QString::fromUtf8("labelCzasAkt"));
        labelCzasAkt->setGeometry(QRect(10, 170, 91, 31));
        czasAktywacji = new QDoubleSpinBox(frame_2);
        czasAktywacji->setObjectName(QString::fromUtf8("czasAktywacji"));
        czasAktywacji->setGeometry(QRect(100, 170, 120, 41));
        czasAktywacji->setValue(1.000000000000000);
        skladowaStalaSpinBox = new QDoubleSpinBox(frame_2);
        skladowaStalaSpinBox->setObjectName(QString::fromUtf8("skladowaStalaSpinBox"));
        skladowaStalaSpinBox->setGeometry(QRect(100, 10, 121, 41));
        skladowaStalaSpinBox->setValue(2.000000000000000);
        wypelnienieSpinBox = new QDoubleSpinBox(frame_2);
        wypelnienieSpinBox->setObjectName(QString::fromUtf8("wypelnienieSpinBox"));
        wypelnienieSpinBox->setGeometry(QRect(100, 130, 121, 41));
        wypelnienieSpinBox->setMaximum(1.000000000000000);
        wypelnienieSpinBox->setSingleStep(0.100000000000000);
        wypelnienieSpinBox->setValue(0.500000000000000);
        czas_spinBox = new QSpinBox(frame_2);
        czas_spinBox->setObjectName(QString::fromUtf8("czas_spinBox"));
        czas_spinBox->setGeometry(QRect(100, 210, 121, 41));
        czas_spinBox->setMinimum(1);
        czas_spinBox->setMaximum(999999999);
        czas_spinBox->setValue(100);
        label_4 = new QLabel(frame_2);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 140, 71, 20));
        label = new QLabel(frame_2);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 220, 63, 20));
        label_5 = new QLabel(frame_2);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 20, 91, 16));
        frame = new QFrame(centralwidget);
        frame->setObjectName(QString::fromUtf8("frame"));
        frame->setGeometry(QRect(1260, 590, 231, 191));
        frame->setFrameShape(QFrame::Shape::Box);
        frame->setFrameShadow(QFrame::Shadow::Raised);
        frame->setLineWidth(2);
        rodzajWykresu = new QComboBox(frame);
        rodzajWykresu->setObjectName(QString::fromUtf8("rodzajWykresu"));
        rodzajWykresu->setGeometry(QRect(10, 10, 211, 51));
        aktualizuj = new QPushButton(frame);
        aktualizuj->setObjectName(QString::fromUtf8("aktualizuj"));
        aktualizuj->setGeometry(QRect(10, 70, 101, 51));
        startButton = new QPushButton(frame);
        startButton->setObjectName(QString::fromUtf8("startButton"));
        startButton->setGeometry(QRect(10, 130, 101, 51));
        stopButton = new QPushButton(frame);
        stopButton->setObjectName(QString::fromUtf8("stopButton"));
        stopButton->setGeometry(QRect(120, 130, 101, 51));
        reset_pushButton = new QPushButton(frame);
        reset_pushButton->setObjectName(QString::fromUtf8("reset_pushButton"));
        reset_pushButton->setGeometry(QRect(120, 70, 101, 51));
        zmienARXbutton = new QPushButton(centralwidget);
        zmienARXbutton->setObjectName(QString::fromUtf8("zmienARXbutton"));
        zmienARXbutton->setGeometry(QRect(1310, 0, 181, 61));
        wektoryBLIneEdit = new QLineEdit(centralwidget);
        wektoryBLIneEdit->setObjectName(QString::fromUtf8("wektoryBLIneEdit"));
        wektoryBLIneEdit->setEnabled(false);
        wektoryBLIneEdit->setGeometry(QRect(1310, 110, 181, 31));
        wektoryALIneEdit = new QLineEdit(centralwidget);
        wektoryALIneEdit->setObjectName(QString::fromUtf8("wektoryALIneEdit"));
        wektoryALIneEdit->setEnabled(false);
        wektoryALIneEdit->setGeometry(QRect(1310, 70, 181, 31));
        wektoryALIneEdit->setReadOnly(false);
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(1280, 80, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(1280, 110, 51, 31));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1511, 25));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Symulator UAR", nullptr));
        labelP->setText(QCoreApplication::translate("MainWindow", "P:", nullptr));
        labelI->setText(QCoreApplication::translate("MainWindow", "I:", nullptr));
        labelD->setText(QCoreApplication::translate("MainWindow", "D:", nullptr));
        sumaCheckBox->setText(QCoreApplication::translate("MainWindow", "Ti W SUMIE", nullptr));
        labelWartZad->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        labelOkres->setText(QCoreApplication::translate("MainWindow", "Okres", nullptr));
        labelCzasAkt->setText(QCoreApplication::translate("MainWindow", "Czas aktywacji", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Wypelnienie", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Sk\305\202adowa sta\305\202a", nullptr));
        aktualizuj->setText(QCoreApplication::translate("MainWindow", "Aktualizuj", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        reset_pushButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        zmienARXbutton->setText(QCoreApplication::translate("MainWindow", "Zmien parametry ARX", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "A", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "B", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
