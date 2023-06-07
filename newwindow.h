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
    void sendTemperatureChartData(double x, double variable); /**< Sygnał do emisji danych do wykresu */

public slots: //BK
    void receiveSpaceSensorData(double tSpace, double x); /**< Sygnał do odbioru danych z czujnika odległości */
    void receiveLightSensorData(double tSpace, double x); /**< Sygnał do odbioru danych z czujnika światła */
    void receiveTemperatureSensorData(double tSpace, double y); /**< Sygnał do odbioru danych z czujnika temperatury */


private slots:

//    void setGreen();


    void on_pushButtonTemperature_clicked();



    void on_lightButton_clicked();

private:
  Ui::NewWindow *ui; /**< Wskaźnik na interfejs użytkownika (UI) */
  std::vector <float> floatData; /**< Wektor do przechowywania odczytanych danych typu float */
   Diagram *diagram;

  void setupChart(){}; // prywatna metoda do ustawienia wykresu
  void updatePixmap();
  double hel = 0;
  double hel1 = 0;



  bool spacePicStatus = false;
  bool greenPicStatus = false;
  int distanceStatus = 0;
   bool startDiagram = false ;
  double receivedTime=0, receivedDistance=2;
  double sendx =0, sendy=0;
  int w =0 , h =0;
  QPixmap pixmapArray[9];

  int flag = 0;
  std::vector<QLabel*> labelVector;
  std::vector<QLabel*> tempLabelVector;



};


#endif // NEWWINDOW_H
