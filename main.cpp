/**
 * @file main.cpp
 * @brief Plik główny aplikacji.
 *
 * Plik zawiera funkcję main() - punkt wejścia aplikacji,
 * która tworzy i uruchamia obiekt klasy MainWindow.
 */

#include "mainwindow.h" ///< Dołączenie pliku nagłówkowego klasy MainWindow.
#include "newwindow.h"  ///< Dołączenie pliku nagłówkowego klasy NewWindow.
#include <QApplication>///< Dołączenie pliku nagłówkowego klasy QApplication.




/**
 * @brief Punkt wejścia aplikacji.
 *
 * @param argc Liczba argumentów wiersza poleceń.
 * @param argv Tablica wskaźników na argumenty wiersza poleceń.
 * @return Kod zakończenia aplikacji.
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);///< Inicjalizacja obiektu QApplication
    MainWindow mainWindow;///< Utworzenie obiektu klasy MainWindow.
    NewWindow newWindow;  ///< Utworzenie obiektu klasy NewWindow.


    Diagram diagram;
    QObject::connect(&mainWindow, SIGNAL(sendSpaceSensorData(double,double)), &newWindow, SLOT(receiveSpaceSensorData(double,double)));
    ///< Połączenie przesyłu danych dla pomiaru odległości

    QObject::connect(&mainWindow, SIGNAL(sendTemperatureSensorData(double,double)), &newWindow, SLOT(receiveTemperatureSensorData(double,double)));
     ///< Połączenie przesyłu danych dla pomiaru temperatury z mainwindow do newindow

    QObject::connect(&mainWindow, SIGNAL(sendLightSensorData(double,double)), &newWindow, SLOT(receiveLightSensorData(double,double)));
    ///< Połączenie przesyłu danych dla pomiaru natężenia światła z mainwindow do newindow

    QObject::connect(&newWindow, SIGNAL(sendTemperatureChartData(double,double)), &diagram, SLOT(receiveTemperatureChartData(double,double)));
    ///< Połączenie przesyłu danych dla pomiaru temperatury

    QObject::connect(&newWindow, SIGNAL(sendLightChartData(double,double)), &diagram, SLOT(receiveLightChartData(double,double)));
    ///< Połączenie przesyłu danych dla pomiaru natężenia światła

    QObject::connect(&mainWindow, SIGNAL(sendCompasSensorData(double,QString)), &newWindow, SLOT(receiveCompassSensorData(double,QString)));
    ///< Połączenie przesyłu danych dla pomiarów z magnetometru

    mainWindow.SetNewWindow(&newWindow); //BK
    mainWindow.show();///< Wywołanie metody show() na obiekcie MainWindow.
    newWindow.show(); //BK
    newWindow.setFixedSize(1020, 600);
    diagram.show();
    diagram.setFixedSize(1167, 500);
    return a.exec();///< Uruchomienie pętli głównej aplikacji.

}
