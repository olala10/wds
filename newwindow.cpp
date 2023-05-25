#include "newwindow.h"
#include "ui_form.h".h"
#include "mainwindow.h"
#include "diagram.h"
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
    connect(parent, SIGNAL(sendSpaceSensorData(double, double)), this, SLOT(receiveSpaceSensorData(double, double)));



    int w =100, h = 100;
//    QPixmap pix1("C:/Users/Acer/Documents/wds/green1.png");
////    ui->greenPic1->setPixmap(pix1.scaled(w,h,Qt::KeepAspectRatio));
////    ui->greenPic1->setVisible(spacePicStatus);
//    QPixmap pix2("C:/Users/Acer/Documents/wds/green2.png");
//    ui->greenPic2->setPixmap(pix2.scaled(w,h,Qt::KeepAspectRatio));
//    QPixmap pix3("C:/Users/Acer/Documents/wds/green3.png");
//    ui->greenPic3->setPixmap(pix3.scaled(w,h,Qt::KeepAspectRatio));

//    w=150;
//    h=150;
//    QPixmap ypix1("C:/Users/Acer/Documents/wds/yellow1.png");
//    ui->yellowPic1->setPixmap(ypix1.scaled(w,h,Qt::KeepAspectRatio));
//    QPixmap ypix2("C:/Users/Acer/Documents/wds/yellow2.png");
//    ui->yellowPic2->setPixmap(ypix2.scaled(w,h,Qt::KeepAspectRatio));
//    QPixmap ypix3("C:/Users/Acer/Documents/wds/yellow3.png");
//    ui->yellowPic3->setPixmap(ypix3.scaled(w,h,Qt::KeepAspectRatio));

//    w=200;
//    h=200;
//    QPixmap rpix1("C:/Users/Acer/Documents/wds/red1.png");
//    ui->redPic1->setPixmap(rpix1.scaled(w,h,Qt::KeepAspectRatio));
//    QPixmap rpix2("C:/Users/Acer/Documents/wds/red2.png");
//    ui->redPic2->setPixmap(rpix2.scaled(w,h,Qt::KeepAspectRatio));
//    QPixmap rpix3("C:/Users/Acer/Documents/wds/red3.png");
//    ui->redPic3->setPixmap(rpix3.scaled(w,h,Qt::KeepAspectRatio));

    spacePicStatus = true;

    ui->greenPic1->setVisible(greenPicStatus1);
    ui->greenPic2->setVisible(spacePicStatus);
    ui->greenPic3->setVisible(spacePicStatus);
    ui->yellowPic1->setVisible(spacePicStatus);
    ui->yellowPic2->setVisible(spacePicStatus);
    ui->yellowPic3->setVisible(spacePicStatus);
    ui->redPic1->setVisible(spacePicStatus);
    ui->redPic2->setVisible(spacePicStatus);
    ui->redPic3->setVisible(spacePicStatus);
}

/*!
 * \brief Destruktor klasy NewWindow.
 * Zwalnia pamięć zajętą przez interfejs użytkownika.
 */

NewWindow::~NewWindow()
{
    delete ui;
}


void NewWindow::on_pushButtonDiagram_toggled()
{
    chartSpace = new Diagram(this);

    chartSpace->show();
}

void NewWindow::receiveSpaceSensorData(double tSpace, double x){
 //   emit sendSpaceData(tSpace, x);
    qDebug()<<tSpace<<'\n';
    greenPicStatus1 = true;
    ui->greenPic1->setVisible(greenPicStatus1);
}

