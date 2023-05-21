/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_3;
    QPushButton *pushButtonSearch;
    QComboBox *comboBoxDevices;
    QPushButton *pushButtonConnect;
    QPushButton *pushButtonDisconnect;
    QPushButton *pushButtonRead;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *horizontalSpacer;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout;
    QPushButton *pushButtonClear;
    QTextEdit *textEditLogs;
    QSpacerItem *verticalSpacer;
    QGroupBox *groupBox_3;
    QFormLayout *formLayout;
    QTextEdit *textEditData;
    QPushButton *pushButton;
    QPushButton *pushButtonClearMonitor;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(682, 574);
        MainWindow->setStyleSheet(QString::fromUtf8(""));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        centralwidget->setStyleSheet(QString::fromUtf8(""));
        gridLayout_2 = new QGridLayout(centralwidget);
        gridLayout_2->setObjectName("gridLayout_2");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setAcceptDrops(true);
        groupBox->setAutoFillBackground(false);
        groupBox->setStyleSheet(QString::fromUtf8(""));
        gridLayout_3 = new QGridLayout(groupBox);
        gridLayout_3->setObjectName("gridLayout_3");
        pushButtonSearch = new QPushButton(groupBox);
        pushButtonSearch->setObjectName("pushButtonSearch");

        gridLayout_3->addWidget(pushButtonSearch, 0, 0, 1, 1);

        comboBoxDevices = new QComboBox(groupBox);
        comboBoxDevices->setObjectName("comboBoxDevices");

        gridLayout_3->addWidget(comboBoxDevices, 0, 1, 1, 2);

        pushButtonConnect = new QPushButton(groupBox);
        pushButtonConnect->setObjectName("pushButtonConnect");

        gridLayout_3->addWidget(pushButtonConnect, 1, 0, 1, 1);

        pushButtonDisconnect = new QPushButton(groupBox);
        pushButtonDisconnect->setObjectName("pushButtonDisconnect");

        gridLayout_3->addWidget(pushButtonDisconnect, 1, 1, 1, 1);

        pushButtonRead = new QPushButton(groupBox);
        pushButtonRead->setObjectName("pushButtonRead");
        pushButtonRead->setCheckable(true);

        gridLayout_3->addWidget(pushButtonRead, 1, 2, 1, 1);


        gridLayout_2->addWidget(groupBox, 0, 0, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(252, 106, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer_2, 0, 2, 1, 1);

        horizontalSpacer = new QSpacerItem(566, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout_2->addItem(horizontalSpacer, 1, 0, 1, 3);

        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        gridLayout = new QGridLayout(groupBox_2);
        gridLayout->setObjectName("gridLayout");
        pushButtonClear = new QPushButton(groupBox_2);
        pushButtonClear->setObjectName("pushButtonClear");

        gridLayout->addWidget(pushButtonClear, 0, 0, 1, 1);

        textEditLogs = new QTextEdit(groupBox_2);
        textEditLogs->setObjectName("textEditLogs");

        gridLayout->addWidget(textEditLogs, 1, 0, 1, 1);


        gridLayout_2->addWidget(groupBox_2, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 399, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 2, 1, 1, 1);

        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        formLayout = new QFormLayout(groupBox_3);
        formLayout->setObjectName("formLayout");
        textEditData = new QTextEdit(groupBox_3);
        textEditData->setObjectName("textEditData");

        formLayout->setWidget(0, QFormLayout::SpanningRole, textEditData);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName("pushButton");

        formLayout->setWidget(1, QFormLayout::LabelRole, pushButton);

        pushButtonClearMonitor = new QPushButton(groupBox_3);
        pushButtonClearMonitor->setObjectName("pushButtonClearMonitor");

        formLayout->setWidget(1, QFormLayout::FieldRole, pushButtonClearMonitor);


        gridLayout_2->addWidget(groupBox_3, 2, 2, 1, 1);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "MENU NAWIGACYJNE", nullptr));
        pushButtonSearch->setText(QCoreApplication::translate("MainWindow", "Szukaj", nullptr));
        pushButtonConnect->setText(QCoreApplication::translate("MainWindow", "Po\305\202\304\205cz", nullptr));
        pushButtonDisconnect->setText(QCoreApplication::translate("MainWindow", "Roz\305\202\304\205cz", nullptr));
        pushButtonRead->setText(QCoreApplication::translate("MainWindow", "Odczytaj", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "MONITOR PORTU SZEREGOWEGO", nullptr));
        pushButtonClear->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "ODCZYTANE DANE", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Wizualizuj w nowym oknie", nullptr));
        pushButtonClearMonitor->setText(QCoreApplication::translate("MainWindow", "Wyczy\305\233\304\207", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
