#include "newwindow.h"
#include "ui_form.h".h"
#include "mainwindow.h"

#include <iostream>


using namespace std;

/*!
 * \brief Konstruktor klasy NewWindow.
 * \param parent Wskaźnik na rodzica okna.
 */
NewWindow::NewWindow(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::NewWindow)
{
    ui->setupUi(this);



    setupChart(); // wywołanie metody do ustawienia wykresu
    int w =350, h = 350;


     QPixmap pixC("C:/Users/Acer/Documents/wds/wds/kompas.png");
     ui->labelCompass->setPixmap(pixC.scaled(ui->labelCompass->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
     ui->labelCompass->setScaledContents(true);
     ui->labelCompass->setVisible(true);


     w= 100, h =100;
    ui->greenPic1->setVisible(greenPicStatus);
    ui->greenPic2->setVisible(false);
    ui->greenPic3->setVisible(false);
    ui->yellowPic1->setVisible(true);
    ui->yellowPic2->setVisible(true);
    ui->yellowPic3->setVisible(true);
    ui->redPic1->setVisible(true);
    ui->redPic2->setVisible(true);
    ui->redPic3->setVisible(true);


}

/*!
 * \brief Destruktor klasy NewWindow.
 * Zwalnia pamięć zajętą przez interfejs użytkownika.
 */

NewWindow::~NewWindow()
{
    delete ui;
}

/*!
\brief Slot reagujący na wciśnięcie przycisku "pushButtonDiagram".
* Tworzy i wyświetla nowy diagram.
*/

void NewWindow::on_pushButtonDiagram_toggled()
{

}

void NewWindow::setGreen(){
    ui->greenPic1->show();
    ui->greenPic1->setVisible(true);
    ui->greenPic2->setVisible(true);
    ui->greenPic3->setVisible(true);
//    qDebug()<<"Dzialam!"<<'\n';


}

/*!
 * \brief Slot reagujący na otrzymanie danych czujnika przestrzeni.
 * \param tSpace Wartość czasu.
 * \param x Wartość współrzędnej x.
 */

void NewWindow::receiveSpaceSensorData(double tSpace, double x)
{

//    qDebug()<<tSpace<<'\n';
    setGreen();


}

void NewWindow::receiveTemperatureSensorData(double tSpace, double y)
{

//    qDebug()<<tSpace<<'\n';
//    qDebug()<<y<<'\n';
   sendx=tSpace;
   sendy=y;


}



void NewWindow::on_pushButtonTemperature_toggled(bool startDiagram)
{
    if (!startDiagram) { /**< Sprawdzenie warunku wciśnięcia przycisku
 */
        startDiagram = false;
        return;
    }

    startDiagram = true;

   diagram = new Diagram(this);

    diagram->show();
    connect(this, SIGNAL(sendTemperatureChartData(double, double)), diagram, SLOT(receiveTemperatureChartData(double, double)));
     while (startDiagram){
    emit sendTemperatureChartData(sendx, sendy);
     }

}

