#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include<QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NewWindow; }
QT_END_NAMESPACE

/**
 * @brief Klasa reprezentująca nowe okno aplikacji.
 *
 * Klasa NewWindow dziedzicząca po klasie QWidget, reprezentuje nowe okno aplikacji.
 * Zawiera deklarację interfejsu użytkownika (UI) oraz prywatne pola i metody.
 */


class NewWindow: public QWidget
{
    Q_OBJECT

public:
    /**
        * @brief Konstruktor klasy NewWindow.
        * @param parent Wskaźnik na obiekt rodzica (domyślnie nullptr)
        */
    NewWindow(QWidget *parent = nullptr);
    /**
        * @brief Destruktor klasy NewWindow.
        */
    ~NewWindow();

private:
  Ui::NewWindow *ui; /**< Wskaźnik na interfejs użytkownika (UI) */

};


#endif // NEWWINDOW_H
