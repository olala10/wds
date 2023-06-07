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


    QGroupBox* lightBox = ui->lightBox; /**< Utworzenie wskaźnika na groupbox z etykietami dotyczącymi natężenia świtała */

    for (QObject* child : lightBox->children()) {  /**< Iterowanie po wszystkich dzieciach groupboxa */
        QLabel* label = qobject_cast<QLabel*>(child); /**< Sprawdzanie, czy dziecko jest etykietą QLabel */
        if (label) {
            labelVector.push_back(label); /**< Dodanie etykiety do wektora */
        }
    }

    hel = ui->lightSpinBox->value();
    qDebug()<<"Doublebox: "<<hel<<'\n';

    QGroupBox* temperatureBox = ui->temperatureBox; /**< Utworzenie wskaźnika na groupbox z etykietami dotyczącymi temperatury */
    for (QObject* child : temperatureBox->children()) {  /**< Iterowanie po wszystkich dzieciach groupboxa */
        QLabel* label = qobject_cast<QLabel*>(child); /**< Sprawdzanie, czy dziecko jest etykietą QLabel */
        if (label) {
            tempLabelVector.push_back(label); /**< Dodanie etykiety do wektora */
        }
    }


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

//    hel = ui->lightSpinBox->value();

//    labelVector[7]->setStyleSheet("background-color: red;");
    qDebug()<<"Received lux: "<<x<<'\n';

    qDebug()<<"Doublebox: "<<hel<<'\n';
    int j = static_cast<int>(hel);
    if (x < 10) {
        labelVector[j]->setStyleSheet("background-color: #1a1a1a");
    }
    else if (x >= 10 && x < 100) {
        labelVector[j]->setStyleSheet("background-color: #3c3c3c;");
    }
    else if (x >= 100 && x < 250) {
        labelVector[j]->setStyleSheet("background-color: #616161;");
    }
    else if (x >= 250 && x < 500) {
        labelVector[j]->setStyleSheet("background-color: #787878;");
    }
    else if (x >= 500 && x < 750) {
        labelVector[j]->setStyleSheet("background-color: #b4b4b4;");
    }
    else if (x >= 750 && x < 1000) {
        labelVector[j]->setStyleSheet("background-color: #f0f0f0;");
    }
    else {
        labelVector[j]->setStyleSheet("background-color: #f9f9f9;");
    }




}


void NewWindow::on_lightButton_clicked()
{


    if(ui->lightSpinBox->value()>=25){
    QMessageBox msgBox; /**< Utworzenie okna dialogowego z informacją o wprowadzeniu wartości spoza zakresu */
          // Ustaw arkusz stylu
    msgBox.setStyleSheet("QMessageBox { background-color: rgba(255, 255, 255, 0.5); "
                               "border: 2px solid qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, "
                               "stop:0 rgba(175, 64, 255, 255), stop:0.5 rgba(91, 66, 243, 255), "
                               "stop:1 rgba(0, 221, 235, 255)); "
                               "color: black; "
                               "font-family: Phantomsans, sans-serif; "
                               "text-decoration: none; }");

          // Ustaw ikonę, tytuł i treść wiadomości
          msgBox.setIcon(QMessageBox::Critical);
          msgBox.setWindowTitle("Błąd");
          msgBox.setText("Wartość niedozwolona!");
          msgBox.exec();
    }
    hel=ui->lightSpinBox->value();


}







void NewWindow::receiveTemperatureSensorData(double tSpace, double y)
{

//    tempLabelVector[7]->setStyleSheet("background-color: red;");


    int j = static_cast<int>(hel);
    if(y<-15){
        tempLabelVector[j]->setStyleSheet("background-color: #66e0ff;");
    }
    else if(y<-5){
        tempLabelVector[j]->setStyleSheet("background-color: #ccf5ff;");
    }
    else if(y<0){
        tempLabelVector[j]->setStyleSheet("background-color: #e6ffe6;");
    }
    else if(y<5){
        tempLabelVector[j]->setStyleSheet("background-color: #aaff80;");
    }
    else if(y<10){
        tempLabelVector[j]->setStyleSheet("background-color: #77ff33;");
    }
    else if(y<15){
        tempLabelVector[j]->setStyleSheet("background-color: #ffff4d;");
    }
    else if(y<20){
        tempLabelVector[j]->setStyleSheet("background-color: #ffff00;");
    }
    else if(y<25){
        tempLabelVector[j]->setStyleSheet("background-color: #ff9933;");
    }
    else if(y<30){
        tempLabelVector[j]->setStyleSheet("background-color: #ff8000c;");
    }
    else if(y<35){
        tempLabelVector[j]->setStyleSheet("background-color: #ff471a;");
    }
    else {
        tempLabelVector[j]->setStyleSheet("background-color: #ff3300;");
    }


   sendx=tSpace;
   sendy=y;


}


void NewWindow::on_pushButtonTemperature_clicked()
{


}








