/********************************************************************************
** Form generated from reading UI file 'diagram.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIAGRAM_H
#define UI_DIAGRAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_Diagram
{
public:
    QCustomPlot *plot;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonClear;
    QLabel *labelX;
    QLabel *labelY;
    QDoubleSpinBox *bx_x;
    QDoubleSpinBox *bx_y;
    QPushButton *pushButtonReceive;

    void setupUi(QDialog *Diagram)
    {
        if (Diagram->objectName().isEmpty())
            Diagram->setObjectName("Diagram");
        Diagram->resize(1265, 592);
        plot = new QCustomPlot(Diagram);
        plot->setObjectName("plot");
        plot->setGeometry(QRect(10, 20, 481, 291));
        pushButtonAdd = new QPushButton(Diagram);
        pushButtonAdd->setObjectName("pushButtonAdd");
        pushButtonAdd->setGeometry(QRect(300, 330, 93, 29));
        pushButtonClear = new QPushButton(Diagram);
        pushButtonClear->setObjectName("pushButtonClear");
        pushButtonClear->setGeometry(QRect(410, 330, 91, 31));
        labelX = new QLabel(Diagram);
        labelX->setObjectName("labelX");
        labelX->setGeometry(QRect(20, 330, 21, 20));
        labelY = new QLabel(Diagram);
        labelY->setObjectName("labelY");
        labelY->setGeometry(QRect(140, 330, 31, 20));
        bx_x = new QDoubleSpinBox(Diagram);
        bx_x->setObjectName("bx_x");
        bx_x->setGeometry(QRect(50, 330, 62, 25));
        bx_y = new QDoubleSpinBox(Diagram);
        bx_y->setObjectName("bx_y");
        bx_y->setGeometry(QRect(180, 330, 62, 25));
        pushButtonReceive = new QPushButton(Diagram);
        pushButtonReceive->setObjectName("pushButtonReceive");
        pushButtonReceive->setGeometry(QRect(90, 360, 93, 29));

        retranslateUi(Diagram);

        QMetaObject::connectSlotsByName(Diagram);
    } // setupUi

    void retranslateUi(QDialog *Diagram)
    {
        Diagram->setWindowTitle(QCoreApplication::translate("Diagram", "Dialog", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("Diagram", "Dodaj", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("Diagram", "Wyczy\305\233\304\207", nullptr));
        labelX->setText(QCoreApplication::translate("Diagram", " X", nullptr));
        labelY->setText(QCoreApplication::translate("Diagram", "   Y", nullptr));
        pushButtonReceive->setText(QCoreApplication::translate("Diagram", "odbieraj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Diagram: public Ui_Diagram {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIAGRAM_H
