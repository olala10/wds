#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSerialPort>
#include <QThread>
#include <QIODevice>
#include <QTextEdit>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:


    void on_pushButtonSearch_clicked();

    void on_pushButtonConnect_clicked();

    void readFromPort();
    void on_pushButtonDisconnect_clicked();



    void on_pushButtonClear_clicked();

    void on_pushButtonRead_clicked();

private:
    Ui::MainWindow *ui;
    void addToLogs(QString message);
    void addToRead(QString message);

    QSerialPort *device;
    QThread* thread;
//    DataReader* dataReader;

};
#endif // MAINWINDOW_H
