#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "newwindow.h"
#include "diagram.h"
#include <QDebug>
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QChart>
#include <QChartView>
#include <QThread>
#include <QVector>
#include <QTimer>
#include <QDateTime>

/*!
 * \brief Konstruktor klasy MainWindow.
 * \param parent Wskaźnik na rodzica okna.
 */

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
    this->thread = new QThread;
    this->newWindow = new NewWindow;

    setupChart(); // wywołanie metody do ustawienia wykresu
}
/*!
 * \brief Destruktor klasy MainWindow.
 * Zwalnia pamięć zajętą przez interfejs użytkownika.
 */

MainWindow::~MainWindow()
{
    delete ui;
}

/*!
 * \brief Obsługa przycisku "Szukaj".
 * Dodaje dostępne porty szeregowe do comboboxa i loguje akcję.
 */

void MainWindow::on_pushButtonSearch_clicked()
{
    this -> addToLogs("Szukam urządzeń...");
    QList<QSerialPortInfo> devices;
    devices = QSerialPortInfo::availablePorts();

    for(int i=0; i<devices.count(); ++i){
    qDebug()<<devices.at(i).portName()<<devices.at(i).description();
    ui->comboBoxDevices->addItem(devices.at(i).portName() + "\t" + devices.at(i).description());

    }
}
/*!
 * \brief Dodaje wpis do logów.
 * \param message Wiadomość do zalogowania.
 */


void MainWindow::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui -> textEditLogs -> append(currentDateTime+"\t"+message);
}

/*!
 * \brief Dodaje odczytane dane do pola tekstowego.
 * \param message Odczytane dane do wyświetlenia.
 */

void MainWindow::addToRead(QString message)
{
    ui->textEditData->append(message);
}

/*!
 * \brief Obsługa przycisku "Połącz".
 * Otwiera port szeregowy na podstawie wybranego z comboboxa portu,
 * konfiguruje go i loguje akcję.
 */

/**
 * @brief Slot obsługujący przycisk "on_pushButtonConnect_clicked()"
 *
 * Metoda obsługująca kliknięcie przycisku "on_pushButtonConnect_clicked()" w oknie głównym aplikacji.
 * Otwiera port szeregowy na podstawie wybranej opcji w comboboxie "ui->comboBoxDevices".
 * Konfiguruje parametry transmisji, takie jak prędkość, liczba bitów danych, bit parzystości, bity stopu oraz kontrola przepływu.
 * Dodaje komunikaty do okna logów w zależności od wyniku operacji.
 */

void MainWindow::on_pushButtonConnect_clicked()
{
    if(ui->comboBoxDevices->count() == 0){
        this->addToLogs("Nie wykryto urządzeń");
        return;
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first(); /**< Pobranie nazwy portu z comboboxa */
    // split - dzielenie łańcucha znakowego z comboBoxa, first - nazwa portu
    this->device->setPortName(portName); /**< Ustawienie nazwy portu w obiekcie klasy QSerialPort */

    if(!device->isOpen()){// Sprawdzenie, czy port jest zamknięty


    //otwieranie i konfiguracja portu
    if(device->open(QSerialPort::ReadWrite)){
          this->device->setBaudRate(QSerialPort::Baud115200);/**< Ustawienie prędkości transmisji na 115200 bps dla STM*/
//          this->device->setBaudRate(QSerialPort::Baud9600);/** Ustawienie prędkości transmisji na 9600 bps dla Arduino */
          this->device->setDataBits(QSerialPort::Data8); /**< Ustawienie liczby bitów danych na 8 */
          this->device->setParity(QSerialPort::NoParity); /**< Ustawienie braku bitu parzystości */
          this->device->setStopBits(QSerialPort::OneStop); /**< Ustawienie jednego bitu stopu */
          this->device->setFlowControl(QSerialPort::NoFlowControl);

        this->addToLogs("Port szeregowy został otwarty"); /**< Dodanie komunikatu do logów informującego o otwarciu portu szeregowego */

    }
    else{
        this->addToLogs("Port szeregowy nie został otwarty"); /**< Dodanie komunikatu do logów informującego o nieudanym otwarciu portu szeregowego */
    }
  }
    else{
        this->addToLogs("Port został już otwarty");/**< Dodanie komunikatu do logów informującego o już otwartym porcie szeregowym */
    }
}

/**
 * @brief Metoda odczytująca dane z portu szeregowego
 *
 * Metoda odczytująca dane z portu szeregowego linia po linii i dodająca je do okna logów.
 */

void MainWindow::readFromPort()
{
    while(this->device->canReadLine()){/**< Odczyt danych z portu szeregowego linia po linii */
        QString line = this->device->readLine();/**< Odczyt jednej linii danych z portu */

//        QString terminator = "\r";/**< Separator linii */
        QString terminator = "\n";/**< Separator linii */
        int pos = line.lastIndexOf(terminator);/**< Znalezienie pozycji separatora */


        this->addToLogs(line.left(pos));/**< Dodanie odczytanej linii do logów */
    }
}



void MainWindow::on_pushButtonDisconnect_clicked()
{
    if(this->device->isOpen()){// Sprawdzenie, czy port jest otwarty
        this->device->close();// Zamknięcie portu
        this->addToLogs("Rozłączono");// Dodanie komunikatu do logów informującego o rozłączeniu portu
    }
    else
       {
           this->addToLogs("Port nie jest otwarty!");// Dodanie komunikatu do logów informującego o próbie rozłączenia nieotwartego portu
           return;
       }

}


void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEditLogs->clear();// Wyczyszczenie okna logów
}

//void MainWindow::sendSpaceSensorData();



QByteArray SimulateReceiver()
{
  static int Counter = 0;
  std::this_thread::sleep_for(std::chrono::milliseconds(300));
  QByteArray  ByteData;


  const char *Data[] {
            "10#30#40#50#60",
            "20#30#40#50#60",
            "30#30#40#50#60",
            "40#30#40#50#60",
            "50#30#40#50#60",
            "60#30#40#50#60",
            "70#30#40#50#60",
            "3#30#40#50#60",
            "21#30#40#50#60",
            "7#30#40#50#60",
            "40#30#40#50#60",
            nullptr
          };

  ByteData += "start#";
  ByteData += Data[Counter];

  ++Counter;
  if (Data[Counter] == nullptr) Counter = 0;

  return ByteData;
}





/**
 * @brief Slot obsługujący przycisk "on_pushButtonRead_toggled()"
 *
 * Metoda obsługująca kliknięcie przycisku "on_pushButtonRead_clicked()" w oknie głównym aplikacji.
 * Odczytuje dane z urządzenia szeregowego i dodaje je do pola tekstowego "ui->textEditData".
 */

void MainWindow::on_pushButtonRead_toggled(bool Checked)
{
    if (!Checked) { /**< Sprawdzenie warunku wciśnięcia przycisku
 */
        _Start = false;
        return;
    }

    _Start = true;
    double x = 2;

    QByteArray data;
    while (_Start) {
//        data = this->device->readAll();
        data =  SimulateReceiver();

        if (!data.isEmpty()) {
            QString strData = QString::fromUtf8(data); /**< Tworzenie zmiennej QString do odczytu danych */

            if (strData.startsWith("start")) { /**< Jeżeli linia zaczyna się od startu zwiekszamy timer i nastepuje odczyt */
                ++secTimer;

                QStringList values = strData.split('#'); /**< Ustalenie znaku podziału */

                if (values.size() >= 6) { /**< Sprawdzenie wielkości odczytu */
                    distance = values[1].toDouble(); /**< Dodanie wartości odległości do listy */
                    light = values[3].toDouble(); /**< Dodanie wartości światła do listy */
                    temperature = values[5].toDouble(); /**< Dodanie wartości temperatury do listy */

                 //   emit sendData(secTimer, distance); /**< Przesył danych do wykresu */
//                    double a = 2, b =3; // do testowania emisji
                    emit sendSpaceSensorData(secTimer, distance);
                    emit sendLightSensorData(secTimer, light);
//                    emit sendTemperatureSensorData(a,b);
                 //   qApp->processEvents();
//                    qDebug() << "Distance: " << values[1];
//                    qDebug() << "Light: " << values[3];
//                    qDebug() << "Temperature: " << values[5];
                }

                ui->textEditData->append(strData);
            }
        }

        qApp->processEvents();
    }
}



/**
 * @brief Slot obsługujący przycisk "on_pushButton_clicked()"
 *
 * Metoda obsługująca kliknięcie przycisku "on_pushButton_clicked()" w oknie głównym aplikacji.
 * Wyświetla nowe okno (newWindow).
 */

void MainWindow::on_pushButton_clicked()
{
    newWindow->show();/**< Wyświetlenie nowego okna */
//    diagram = new Diagram(this);
//    diagram->show();
}


void MainWindow::on_pushButtonClearMonitor_clicked()
{
  ui->textEditData->clear();
}

// BK
void MainWindow::on__pButton_Test_toggled(bool State)
{
  if (newWindow) {
    if (State) {
        newWindow->receiveSpaceSensorData(1,31);
    } else {
        newWindow->receiveSpaceSensorData(1,10);
    }
  }
}
