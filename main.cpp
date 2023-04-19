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
    MainWindow w;///< Utworzenie obiektu klasy MainWindow.
    w.show();///< Wywołanie metody show() na obiekcie MainWindow.
    return a.exec();///< Uruchomienie pętli głównej aplikacji.
}
