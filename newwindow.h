#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include<QMainWindow>
#include <QTableView>
#include <QTableWidget>
#include <QStandardItemModel>
#include <QGraphicsView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include <QtCore/QVector>


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

private slots:
    void on_pushButtonDiagram_clicked();

private:
  Ui::NewWindow *ui; /**< Wskaźnik na interfejs użytkownika (UI) */
  std::vector <float> floatData; /**< Wektor do przechowywania odczytanych danych typu float */

};


#endif // NEWWINDOW_H
