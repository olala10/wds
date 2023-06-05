#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QIODevice>
#include <QTextEdit>
#include <QDebug>
#include <QList>
#include <QIODevice>
#include <QtSerialPort/QSerialPortInfo>
#include <QDateTime>
//#include <QtCharts>
//#include <QChartView>
#include <QtCharts/QChartView>
#include <QtCharts/QLineSeries>
#include "newwindow.h"
#include "diagram.h"
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE
#ifndef DATAVECTOR_H
#define DATAVECTOR_H
/**
 * @brief The MainWindow class
 *
 * Klasa reprezentująca główne okno aplikacji.
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /**
        * @brief Konstruktor klasy MainWindow
        *
        * @param parent Wskaźnik na rodzica okna (domyślnie nullptr)
        */

    MainWindow(QWidget *parent = nullptr);


    /**
     * @brief Destruktor klasy MainWindow
     */

    ~MainWindow();

    void SetNewWindow(NewWindow *pWin) { newWindow = pWin; } // BK
signals:
    void openDevice();  /**< Sygnał otwierający komunikację z urządzeniem */
    void closeDevice();  /**< Sygnał zamykający komunikację z urządzeniem */
    void sendData(double x, double variable); /**< Sygnał do emisji danych do wykresu */
    void sendSpaceSensorData(double tSpace, double x); /**< Sygnał do emisji danych z czujnika odległości */
    void sendLightSensorData(double tSpace, double x); /**< Sygnał do emisji danych z czujnika światła */
    void sendCompasSensorData(double tSpace); /**< Sygnał do emisji danych z magnetometru */
    void sendTemperatureSensorData(double tSpace, double y); /**< Sygnał do emisji danych z czujnika temperatury */




private slots:

    /**
        * @brief Slot dla przycisku wyszukiwania
        */
    void on_pushButtonSearch_clicked();
    /**
       * @brief Slot dla przycisku połączenia
       */
    void on_pushButtonConnect_clicked();
    /**
       * @brief Slot dla odczytu z portu szeregowego
       */
    void readFromPort();
    /**
      * @brief Slot dla przycisku rozłączenia
      */
    void on_pushButtonDisconnect_clicked();
    /**
        * @brief Slot dla przycisku czyszczenia logów
        */


    void on_pushButtonClear_clicked();
    /**
         * @brief Slot dla przycisku odczytu
         */

    void on_pushButtonRead_toggled(bool Checked);



    void on_pushButton_clicked();

    void on_pushButtonClearMonitor_clicked();


    void on__pButton_Test_toggled(bool State); // BK

private:
    Ui::MainWindow *ui;/**< Wskaźnik na interfejs użytkownika (UI) */
    QChartView *QChartView;
    void setupChart(){}; // prywatna metoda do ustawienia wykresu
    void addToLogs(QString message);/**< Metoda do dodawania wiadomości do logów
                                    * @param message Wiadomość do dodania do logów
                                    */

    void addToRead(QString message);/**< Metoda do dodawania wiadomości do odczytu
                                    * @param message Wiadomość do dodania do odczytu
                                    */

    QSerialPort *device;/**< Wskaźnik na obiekt klasy QSerialPort do obsługi portu szeregowego */
    QThread* thread;/**< Wskaźnik na wątek do obsługi portu szeregowego */
    NewWindow *newWindow;/**< Wskaźnik na nowe okno */
   // Diagram *diagram;
    QVector<QString> dataVector; /** < Wskaźnik na QWektor do odczytu danych z urządzenia */
    std::vector <float> lineData; /**< Wektor do przechowywania linii odczytanych danych jako typ float */
    bool  _Start = false;
    double secTimer = 0; // do odliczania - poprawić to
    double distance =0 ;
    double light = 0;
    QString compass;
    double temperature = 0;

};
#endif // DATAVECTOR_H
#endif // MAINWINDOW_H
