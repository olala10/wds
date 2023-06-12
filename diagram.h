#ifndef DIAGRAM_H
#define DIAGRAM_H

#include <QDialog>
#include <QtCharts>
#include <QChartView>
#include <QLineSeries>
#include <QSerialPort>
#include <QPoint>


namespace Ui {
class Diagram;
}

/**
 * @brief Klasa reprezentująca nowe okno wykresów aplikacji.
 *
 * Klasa Diagram dziedzicząca po klasie QDialog, reprezentuje nowe okno aplikacji.
 * Zawiera deklarację interfejsu użytkownika (UI) oraz prywatne pola i metody.
 */
class Diagram : public QDialog
{
    Q_OBJECT

public:
    /**
           * @brief Konstruktor klasy Diagram.
           * @param parent Wskaźnik na obiekt rodzica (domyślnie nullptr)
           */
    explicit Diagram(QWidget *parent = nullptr);
    /**
         * @brief Destruktor klasy Diagram.
         */
    ~Diagram();

    void addPoint(double x, double y); /**< Funkcja dodająca wartości pomiaru temperatury do wektora */
    void addLightPoint(double x, double y);  /**< Funkcja dodająca wartości pomiaru światła do wektora */
    void clearData(); /**< Usuwanie wartości z diagramu */
    void plot(); /**< Rysowanie wykresu */
    void plotLight(); /** Rysowanie wykresu natężenia światła */
public slots:
     void receiveTemperatureChartData(double t, double y); /**< Slot odczytu danych o temperaturze do wykresu */
     void receiveLightChartData(double t, double y); /** Slot do odczytu danych o natężeniu światła do wykresu */

private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonClear_clicked();



private:
    Ui::Diagram *ui; /**< Wskaźnik na interfejs użytkownika (UI) */

    QVector <double> qv_x, qv_y; /** Wektor przechowujący czas i wartość pomiaru temperatury */
    QVector <double> qv_xL, qv_yL; /** Wektor przechowujący czas i wartość pomiaru światła*/
};

#endif // DIAGRAM_H
