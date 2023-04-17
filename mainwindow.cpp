#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QList>
#include <QtSerialPort/QSerialPortInfo>
#include <QThread>

#include <QDateTime>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->device = new QSerialPort(this);
    this->thread = new QThread;
}

MainWindow::~MainWindow()
{
    delete ui;
}


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

void MainWindow::addToLogs(QString message)
{
    QString currentDateTime = QDateTime::currentDateTime().toString("yyyy.MM.dd hh:mm:ss");
    ui -> textEditLogs -> append(currentDateTime+"\t"+message);
}

void MainWindow::addToRead(QString message)
{
    ui->textEditData->append(message);
}






void MainWindow::on_pushButtonConnect_clicked()
{
    if(ui->comboBoxDevices->count() == 0){
        this->addToLogs("Nie wykryto urządzeń");
        return;
    }

    QString portName = ui->comboBoxDevices->currentText().split("\t").first();
    // split - dzielenie łańcucha znakowego z comboBoxa, first - nazwa portu
    this->device->setPortName(portName);

    if(!device->isOpen()){

    //otwieranie i konfiguracja portu
    if(device->open(QSerialPort::ReadWrite)){
          this->device->setBaudRate(QSerialPort::Baud115200);
          this->device->setDataBits(QSerialPort::Data8);
          this->device->setParity(QSerialPort::NoParity);
          this->device->setStopBits(QSerialPort::OneStop);
          this->device->setFlowControl(QSerialPort::NoFlowControl);

        this->addToLogs("Port szeregowy został otwarty");
    }
    else{
        this->addToLogs("Port szeregowy nie został otwarty");
    }
  }
    else{
        this->addToLogs("Port został już otwarty");
    }
}

void MainWindow::readFromPort()
{
    while(this->device->canReadLine()){
        QString line = this->device->readLine();
       // qDebug()<<line;
        QString terminator = "\r";
        int pos = line.lastIndexOf(terminator);
       // qDebug()<<line.left(pos);

        this->addToLogs(line.left(pos));
    }
}



void MainWindow::on_pushButtonDisconnect_clicked()
{
    if(this->device->isOpen()){
        this->device->close();
        this->addToLogs("Rozłączono");
    }
    else
       {
           this->addToLogs("Port nie jest otwarty!");
           return;
       }

}




void MainWindow::on_pushButtonClear_clicked()
{
    ui->textEditLogs->clear();
}


void MainWindow::on_pushButtonRead_clicked()
{
//    QThread *thread()
    QByteArray data = this->device->readAll();
    ui->textEditData->append(QString(data));

}


