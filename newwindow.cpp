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

//     w =100, h = 100;
//     pixmapArray[0] = QPixmap ("C:/Users/Acer/Documents/wds/green1.png");
//     pixmapArray[1] = QPixmap ("C:/Users/Acer/Documents/wds/green2.png");
//     pixmapArray[2] = QPixmap ("C:/Users/Acer/Documents/wds/green3.png");
//     ui->greenPic1->setPixmap(pixmapArray[0]);
//     qDebug()<<"pixmapArray[0]: "<<pixmapArray[0]<<'\n';
//        ui->greenPic2->setPixmap(pixmapArray[1]);
//           ui->greenPic3->setPixmap(pixmapArray[2]);
//     ui->greenPic2->setText("bla");
//     ui->greenPic2->setVisible(false);




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
 * \brief Slot reagujący na otrzymanie danych czujnika przestrzeni.
 * \param tSpace Wartość czasu.
 * \param x Wartość współrzędnej x.
 */

void NewWindow::receiveSpaceSensorData(double tSpace, double x)
{
    //ui->setupUi(this);
  distanceStatus =1;
  if(distanceStatus == 1){
//  pixmapArray[0] = QPixmap ("C:/Users/Acer/Documents/wds/green1.png");
//  pixmapArray[1] = QPixmap ("C:/Users/Acer/Documents/wds/green2.png");
//  pixmapArray[2] = QPixmap ("C:/Users/Acer/Documents/wds/green3.png");
      qDebug()<<tSpace<<'\n';
      qDebug()<<x<<'\n';
      if(x >30){
          pixmapArray[0] = QPixmap ("C:/Users/Acer/Documents/wds/green1.png");
          qDebug()<<pixmapArray[0]<<'\n';
          pixmapArray[1] = QPixmap ("C:/Users/Acer/Documents/wds/green2.png");
          pixmapArray[2] = QPixmap ("C:/Users/Acer/Documents/wds/green3.png");
       ui->greenPic1->setPixmap(pixmapArray[0]);
       ui->greenPic2->setPixmap(pixmapArray[1]);
       ui->greenPic3->setPixmap(pixmapArray[2]);
        ui->greenPic1->setVisible(true);
        ui->greenPic2->setVisible(true);
        ui->greenPic3->setVisible(true);


       qDebug()<<"x>30"<<'\n';

      }


  qDebug()<<"Status: "<<distanceStatus<<'\n';
  }
}


void NewWindow::setGreen(){
    qDebug()<<"Dzialam!"<<'\n';


}

void NewWindow::receiveTemperatureSensorData(double tSpace, double y)
{

//    qDebug()<<tSpace<<'\n';
//    qDebug()<<y<<'\n';
   sendx=tSpace;
   sendy=y;


}

void NewWindow::on_pushButtonDiagram_clicked()
{

}

void NewWindow::on_pushButtonTemperature_clicked()
{


}
