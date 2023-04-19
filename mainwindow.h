#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QIODevice>
#include <QTextEdit>
#include "newwindow.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

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

    void on_pushButtonRead_clicked();



    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;/**< Wskaźnik na interfejs użytkownika (UI) */
    void addToLogs(QString message);/**< Metoda do dodawania wiadomości do logów
 * @param message Wiadomość do dodania do logów
                                    */

    void addToRead(QString message);/**< Metoda do dodawania wiadomości do odczytu
                                    * @param message Wiadomość do dodania do odczytu
                                    */

    QSerialPort *device;/**< Wskaźnik na obiekt klasy QSerialPort do obsługi portu szeregowego */
    QThread* thread;/**< Wskaźnik na wątek do obsługi portu szeregowego */
    NewWindow *newWindow;/**< Wskaźnik na nowe okno */

//    DataReader* dataReader;

};
#endif // MAINWINDOW_H
