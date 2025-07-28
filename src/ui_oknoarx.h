/********************************************************************************
** Form generated from reading UI file 'oknoarx.ui'
**
** Created by: Qt User Interface Compiler version 6.3.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOARX_H
#define UI_OKNOARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_oknoARX
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *aLineEdit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *bLineEdit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QDoubleSpinBox *zaklocenieSpinBox;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QDoubleSpinBox *opoznienieSpinBox;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *zatwierdzButton;
    QPushButton *anulujButton;

    void setupUi(QDialog *oknoARX)
    {
        if (oknoARX->objectName().isEmpty())
            oknoARX->setObjectName(QString::fromUtf8("oknoARX"));
        oknoARX->resize(248, 176);
        gridLayout = new QGridLayout(oknoARX);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(oknoARX);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        aLineEdit = new QLineEdit(oknoARX);
        aLineEdit->setObjectName(QString::fromUtf8("aLineEdit"));

        horizontalLayout->addWidget(aLineEdit);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label_2 = new QLabel(oknoARX);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_2->addWidget(label_2);

        bLineEdit = new QLineEdit(oknoARX);
        bLineEdit->setObjectName(QString::fromUtf8("bLineEdit"));

        horizontalLayout_2->addWidget(bLineEdit);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_3 = new QLabel(oknoARX);
        label_3->setObjectName(QString::fromUtf8("label_3"));

        horizontalLayout_3->addWidget(label_3);

        zaklocenieSpinBox = new QDoubleSpinBox(oknoARX);
        zaklocenieSpinBox->setObjectName(QString::fromUtf8("zaklocenieSpinBox"));

        horizontalLayout_3->addWidget(zaklocenieSpinBox);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_4 = new QLabel(oknoARX);
        label_4->setObjectName(QString::fromUtf8("label_4"));

        horizontalLayout_4->addWidget(label_4);

        opoznienieSpinBox = new QDoubleSpinBox(oknoARX);
        opoznienieSpinBox->setObjectName(QString::fromUtf8("opoznienieSpinBox"));

        horizontalLayout_4->addWidget(opoznienieSpinBox);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        zatwierdzButton = new QPushButton(oknoARX);
        zatwierdzButton->setObjectName(QString::fromUtf8("zatwierdzButton"));

        horizontalLayout_5->addWidget(zatwierdzButton);

        anulujButton = new QPushButton(oknoARX);
        anulujButton->setObjectName(QString::fromUtf8("anulujButton"));

        horizontalLayout_5->addWidget(anulujButton);


        verticalLayout->addLayout(horizontalLayout_5);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(oknoARX);

        QMetaObject::connectSlotsByName(oknoARX);
    } // setupUi

    void retranslateUi(QDialog *oknoARX)
    {
        oknoARX->setWindowTitle(QCoreApplication::translate("oknoARX", "Model ARX", nullptr));
        label->setText(QCoreApplication::translate("oknoARX", "A", nullptr));
        aLineEdit->setText(QCoreApplication::translate("oknoARX", "-0.4", nullptr));
        label_2->setText(QCoreApplication::translate("oknoARX", "B", nullptr));
        bLineEdit->setText(QCoreApplication::translate("oknoARX", "0.6", nullptr));
        label_3->setText(QCoreApplication::translate("oknoARX", "Zaklocenie", nullptr));
        label_4->setText(QCoreApplication::translate("oknoARX", "Opoznienie", nullptr));
        zatwierdzButton->setText(QCoreApplication::translate("oknoARX", "ZATWIERDZ", nullptr));
        anulujButton->setText(QCoreApplication::translate("oknoARX", "ANULUJ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class oknoARX: public Ui_oknoARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOARX_H
