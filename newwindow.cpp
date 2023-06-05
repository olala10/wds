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

    /*!
     * \brief Ustawienie pixmapy dla ikonki kompasu
     * \param pixC -- pixmapa z ikonką kompasu
     * \param labelCompass -- label, któremu przypisujemy pixmapę pixC
     */
    QPixmap pixC("C:/Users/Acer/Documents/wds/wds/kompas.png"); //BK
    ui->labelCompass->setPixmap(pixC.scaled(ui->labelCompass->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));
    /*!
     * \brief Ustawienie pixmapy dla ikonki kompasu
     * \param pixT -- pixmapa z ikonką kompasu
     * \param labelCompass -- label, któremu przypisujemy pixmapę pixT
     */

    QPixmap pixT("C:/Users/Acer/Documents/wds/wds/triangle.png");
    ui->triangleLabel->setPixmap(pixT.scaled(ui->triangleLabel->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation));

    /*!
     * \brief Ustawienie pixmapy dla stref odległości
     * \param pixmapArray - tablica przechowująca pixmapy dla każdej strefy
     * \param greenPic1 - przykładowy label, któremu przypisywana jest pixmapa
     */


    pixmapArray[0] = QPixmap ("./green1.png");/**< Ustawienie pixmapy dla zielonej strefy */ //BK
    pixmapArray[1] = QPixmap ("./green2.png"); /**< Ustawienie pixmapy dla zielonej strefy */  //BK
    pixmapArray[2] = QPixmap ("./green3.png"); /**< Ustawienie pixmapy dla zielonej strefy */  //BK

    ui->greenPic1->setPixmap(pixmapArray[0]);  /**< Przypisanie pixmapy do label */
    ui->greenPic2->setPixmap(pixmapArray[1]); /**< Przypisanie pixmapy do label */
    ui->greenPic3->setPixmap(pixmapArray[2]); /**< Przypisanie pixmapy do label */

    ui->greenPic1->setVisible(false); /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */  //BK
    ui->greenPic2->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */ //BK
    ui->greenPic3->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */ //BK

    pixmapArray[3] = QPixmap ("./yellow1.png"); /**< Ustawienie pixmapy dla żółtej strefy */
    pixmapArray[4] = QPixmap ("./yellow2.png"); /**< Ustawienie pixmapy dla żółtej strefy */
    pixmapArray[5] = QPixmap ("./yellow3.png"); /**< Ustawienie pixmapy dla żółtej strefy */

    ui->yellowPic1->setPixmap(pixmapArray[3]); /**< Przypisanie pixmapy do label */
    ui->yellowPic2->setPixmap(pixmapArray[4]); /**< Przypisanie pixmapy do label */
    ui->yellowPic3->setPixmap(pixmapArray[5]); /**< Przypisanie pixmapy do label */

    ui->yellowPic1->setVisible(false); /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */
    ui->yellowPic2->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */
    ui->yellowPic3->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */

    pixmapArray[6] = QPixmap ("./red1.png"); /**< Ustawienie pixmapy dla czerwonej strefy */
    pixmapArray[7] = QPixmap ("./red2.png"); /**< Ustawienie pixmapy dla czerwonej strefy */
    pixmapArray[8] = QPixmap ("./red3.png"); /**< Ustawienie pixmapy dla czerwonej strefy */

    ui->redPic1->setPixmap(pixmapArray[6]); /**< Przypisanie pixmapy do label */
    ui->redPic2->setPixmap(pixmapArray[7]); /**< Przypisanie pixmapy do label */
    ui->redPic3->setPixmap(pixmapArray[8]); /**< Przypisanie pixmapy do label */

    ui->redPic1->setVisible(false); /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */
    ui->redPic2->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */
    ui->redPic3->setVisible(false);  /**< Domyślne ustawienie widoczności label na false przy pierwszym wyświetleniu okna */


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

//      qDebug() << "Zegar: " << tSpace<<'\n';
//      qDebug() << " Distans: " << x<<'\n';
      if (x < 10) {

          ui->greenPic1->setVisible(false); /**< Schowanie strefy zielonej dla x<10 */
          ui->greenPic2->setVisible(false); /**< Schowanie strefy zielonej dla x<10 */
          ui->greenPic3->setVisible(false); /**< Schowanie strefy zielonej dla x<10 */
          ui->yellowPic1->setVisible(false); /**< Schowanie strefy żółtej dla x<10 */
          ui->yellowPic2->setVisible(false); /**< Schowanie strefy żółtej dla x<10 */
          ui->yellowPic3->setVisible(false); /**< Schowanie strefy żółtej dla x<10 */
          ui->redPic1->setVisible(true); /**< Wyświetlenie strefy czerwonej dla x<10 */
          ui->redPic2->setVisible(true); /**< Wyświetlenie strefy czerwonej dla x<10 */
          ui->redPic3->setVisible(true); /**< Wyświetlenie strefy czerwonej dla x<10 */

      }
      else if(x<20) {
         ui->greenPic1->setVisible(false); /**< Schowanie strefy zielonej dla x<20 */
         ui->greenPic2->setVisible(false); /**< Schowanie strefy zielonej dla x<20 */
         ui->greenPic3->setVisible(false); /**< Schowanie strefy zielonej dla x<20 */
         ui->yellowPic1->setVisible(true); /**< Wyświetlenie strefy żółtej dla x<20 */
         ui->yellowPic2->setVisible(true); /**< Wyświetlenie strefy żółtej dla x<20 */
         ui->yellowPic3->setVisible(true); /**< Wyświetlenie strefy żółtej dla x<20 */
         ui->redPic1->setVisible(true);    /**< Wyświetlenie strefy czerwonej dla x<20 */
         ui->redPic2->setVisible(true);    /**< Wyświetlenie strefy czerwonej dla x<20 */
         ui->redPic3->setVisible(true);    /**< Wyświetlenie strefy czerwonej dla x<20 */
      }
      else{
          ui->greenPic1->setVisible(true); /**< Wyświetlenie strefy zielonej dla x>20 */
          ui->greenPic2->setVisible(true); /**< Wyświetlenie strefy zielonej dla x>20 */
          ui->greenPic3->setVisible(true); /**< Wyświetlenie strefy zielonej dla x>20 */
          ui->yellowPic1->setVisible(true);/**< Wyświetlenie strefy żółtej dla x>20 */
          ui->yellowPic2->setVisible(true);/**< Wyświetlenie strefy żółtej dla x>20 */
          ui->yellowPic3->setVisible(true);/**< Wyświetlenie strefy żółtej dla x>20 */
          ui->redPic1->setVisible(true);   /**< Wyświetlenie strefy czerwonej dla x>20 */
          ui->redPic2->setVisible(true);   /**< Wyświetlenie strefy czerwonej dla x>20 */
          ui->redPic3->setVisible(true);   /**< Wyświetlenie strefy czerwonej dla x>20 */

      }


  qDebug()<<"Status: "<<distanceStatus<<'\n';
  }
}

void NewWindow::receiveLightSensorData(double tSpace, double x){
//          qDebug() << "Zegar: " << tSpace<<'\n';
//          qDebug() << " Light: " << x<<'\n';
}

void NewWindow::receiveTemperatureSensorData(double tSpace, double y)
{

//    qDebug()<<tSpace<<'\n';
//    qDebug()<<y<<'\n';
   sendx=tSpace;
   sendy=y;


}


void NewWindow::on_pushButtonTemperature_clicked()
{


}
