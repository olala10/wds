/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewWindow
{
public:
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGroupBox *groupBoxDistance;
    QPushButton *pushButtonDiagram;
    QGroupBox *groupBox_2;
    QGroupBox *groupBox_4;
    QGridLayout *gridLayout;

    void setupUi(QWidget *NewWindow)
    {
        if (NewWindow->objectName().isEmpty())
            NewWindow->setObjectName("NewWindow");
        NewWindow->resize(1028, 577);
        gridLayout_2 = new QGridLayout(NewWindow);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(NewWindow);
        groupBox->setObjectName("groupBox");

        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        groupBoxDistance = new QGroupBox(NewWindow);
        groupBoxDistance->setObjectName("groupBoxDistance");
        pushButtonDiagram = new QPushButton(groupBoxDistance);
        pushButtonDiagram->setObjectName("pushButtonDiagram");
        pushButtonDiagram->setGeometry(QRect(0, 230, 93, 29));

        gridLayout_2->addWidget(groupBoxDistance, 0, 1, 1, 1);

        groupBox_2 = new QGroupBox(NewWindow);
        groupBox_2->setObjectName("groupBox_2");

        gridLayout_2->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(NewWindow);
        groupBox_4->setObjectName("groupBox_4");
        gridLayout = new QGridLayout(groupBox_4);
        gridLayout->setObjectName("gridLayout");

        gridLayout_2->addWidget(groupBox_4, 1, 1, 1, 1);


        retranslateUi(NewWindow);

        QMetaObject::connectSlotsByName(NewWindow);
    } // setupUi

    void retranslateUi(QWidget *NewWindow)
    {
        NewWindow->setWindowTitle(QCoreApplication::translate("NewWindow", "Form", nullptr));
        groupBox->setTitle(QCoreApplication::translate("NewWindow", "Odczyty z magnetometru", nullptr));
        groupBoxDistance->setTitle(QCoreApplication::translate("NewWindow", "Pomiar odleg\305\202o\305\233ci", nullptr));
        pushButtonDiagram->setText(QCoreApplication::translate("NewWindow", "Wykres", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("NewWindow", "Nat\304\231\305\274enie \305\233wiat\305\202a", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("NewWindow", "Pomiar temperatury", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewWindow: public Ui_NewWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
