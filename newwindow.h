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
#include <QPixmap>
#include <QGroupBox>
#include <QLabel>
#include <vector>
#include "diagram.h"



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

signals:
    void sendSpaceData(double x, double y);
    void sendTemperatureChartData(double x, double variable); /**< Sygnał do emisji danych do wykresu pomiaru temperatury */
    void sendLightChartData(double x, double variable); /**< Sygnał do emisji danych do wykresu natężenia światła*/

public slots: //BK
    void receiveSpaceSensorData(double tSpace, double x); /**< Sygnał do odbioru danych z czujnika odległości */
    void receiveLightSensorData(double tSpace, double x); /**< Sygnał do odbioru danych z czujnika światła */
    void receiveTemperatureSensorData(double tSpace, double y); /**< Sygnał do odbioru danych z czujnika temperatury */


private slots:
    void on_lightButton_clicked();


private:
  Ui::NewWindow *ui; /**< Wskaźnik na interfejs użytkownika (UI) */
  std::vector <float> floatData; /**< Wektor do przechowywania odczytanych danych typu float */
   QChartView *QChartView;
  void setupChart(){}; /**< Prywatna metoda do ustawiania wykresu */
  double hel = 0; /**< Zmienna przechowująca wartość doubleboxa, wykorzystywana to ustawienia pomiaru światła*/
  double hel1 = 0;/**< Zmienna przechowująca wartość doubleboxa, wykorzystywana to ustawienia pomiaru temperatury*/

  bool start = false;

  bool spacePicStatus = false;
  bool greenPicStatus = false;
  int distanceStatus = 0;
   bool startDiagram = false ;
  double receivedTime=0, receivedDistance=2;
  double sendx =0, sendy=0;
  int w =0 , h =0;
  QPixmap pixmapArray[9]; /** Tablica pixmap wartości pomiaru odległości*/

  QStringList titles, lightTitles, distTitles; /** Tytuły kolumn temperatury i światła*/
  int flag = 0;

  int row = 0, lightRow = 0, distRow=0; /** Początkowa ilość wierszy w tabeli */
  QString timeTemp, timeLight, timeDist; /** Do wpisania do tabeli */
  QString temp, light, dist; /** Do wpisania do tabeli */
  QTime currentTime, currentLightTime, currentDistanceTime;
  std::vector<QLabel*> labelVector; /** Wektor obiektów label w groupboxie dla pomiaru światła*/
  std::vector<QLabel*> tempLabelVector; /** Wektor obiektów label w groupboxie dla pomiaru temperatury*/



};


#endif // NEWWINDOW_H
