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

    pixmapCompass[0] = QPixmap ("C:/Users/Acer/Documents/wds/wds/arrowNorth.png");
    pixmapCompass[1] = QPixmap ("C:/Users/Acer/Documents/wds/wds/arrowEast.png");
    pixmapCompass[2] = QPixmap ("C:/Users/Acer/Documents/wds/wds/arrowSouth.png");
    pixmapCompass[3] = QPixmap ("C:/Users/Acer/Documents/wds/wds/arrowWest.png");
    ui->labelArrowNorth->setPixmap(pixmapCompass[0].scaled(ui->labelArrowNorth->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation ));/**< Przypisanie pixmapy do label */
    ui->labelArrowEast->setPixmap(pixmapCompass[1].scaled(ui->labelArrowEast->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation ));/**< Przypisanie pixmapy do label */
    ui->labelArrowSouth->setPixmap(pixmapCompass[2].scaled(ui->labelArrowSouth->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation ));/**< Przypisanie pixmapy do label */
    ui->labelArrowWest->setPixmap(pixmapCompass[3].scaled(ui->labelArrowWest->size(),Qt::KeepAspectRatio, Qt::SmoothTransformation ));/**< Przypisanie pixmapy do label */

    ui->labelArrowNorth->setVisible(false);
    ui->labelArrowEast->setVisible(false);
    ui->labelArrowSouth->setVisible(false);
    ui->labelArrowWest->setVisible(false);



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
  ui->tableWidgetDistance->setColumnCount(2); /** Ustawienie liczby kolumn w tabeli */
  distTitles << "czas [s]" << "Odległość [cm]"; /** Dodanie tytułów kolumn do listy */
  ui->tableWidgetDistance->setHorizontalHeaderLabels(distTitles); /** Dodanie tytułów kolumn do tabeli */
  distRow = ui->tableWidgetDistance->rowCount(); /** Pobranie numeru następnego wiersza */

      dist = QString::number(x); /** Konwersja wartości temperatury do string */

      currentDistanceTime = QTime::currentTime(); /** Pobranie czasu pomiaru */

      timeDist = currentDistanceTime.toString("hh:mm:ss.zzz"); /** Konwersja czasu pomiaru do string */
      ui->tableWidgetDistance->insertRow(row); /** Dodanie kolejnego wiersza do Tabeli */
      ui->tableWidgetDistance->setItem(row, 0, new QTableWidgetItem(timeDist)); /** Zapis wartości czasu pomiaru do tabeli */
      ui->tableWidgetDistance->setItem(row, 1, new QTableWidgetItem(dist)); /** Zapis wartości temperatury do tabeli */
}

/*!
 * \brief Slot reagujący na otrzymanie danych czujnika natężenia światła.
 * \param tSpace Wartość czasu.
 * \param x Wartość pomiarowa.
 * \param hel -- wartość wprowadzona do doubleboxa
 */

void NewWindow::receiveLightSensorData(double tSpace, double x){

//    qDebug()<<"Received lux: "<<x<<'\n';

//    qDebug()<<"Doublebox: "<<hel<<'\n';

    int j = static_cast<int>(hel); /** przypisanie zmiennej j wartości hel*/
    if (x < 10) {
        labelVector[j]->setStyleSheet("background-color: #1a1a1a"); /** Ustawienie koloru #1a1a1a okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if (x >= 10 && x < 100) {
        labelVector[j]->setStyleSheet("background-color: #3c3c3c;"); /** Ustawienie koloru #3c3c3c okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if (x >= 100 && x < 250) {
        labelVector[j]->setStyleSheet("background-color: #616161;"); /** Ustawienie koloru #616161 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if (x >= 250 && x < 500) {
        labelVector[j]->setStyleSheet("background-color: #787878;"); /** Ustawienie koloru #787878 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if (x >= 500 && x < 750) {
        labelVector[j]->setStyleSheet("background-color: #b4b4b4;"); /** Ustawienie koloru #b4b4b4 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if (x >= 750 && x < 1000) {
        labelVector[j]->setStyleSheet("background-color: #f0f0f0;"); /** Ustawienie koloru #f0f0f0 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else {
        labelVector[j]->setStyleSheet("background-color: #f9f9f9;"); /** Ustawienie koloru #f9f9f9 okna pomiarowego, zgodnie z przyjętą skalą*/
    }


emit sendLightChartData(tSpace, x); /** Przesył danych o natężeniu światła do wykresu */


    ui->tableWidgetLight->setColumnCount(2); /** Ustawienie liczby kolumn w tabeli */
    lightTitles << "czas [s]" << "Światło [lux]"; /** Dodanie tytułów kolumn do listy */
    ui->tableWidgetLight->setHorizontalHeaderLabels(lightTitles); /** Dodanie tytułów kolumn do tabeli */
    lightRow = ui->tableWidgetLight->rowCount(); /** Pobranie numeru następnego wiersza */

        light = QString::number(x); /** Konwersja wartości temperatury do string */

        currentLightTime = QTime::currentTime(); /** Pobranie czasu pomiaru */

        timeLight = currentLightTime.toString("hh:mm:ss.zzz"); /** Konwersja czasu pomiaru do string */
        ui->tableWidgetLight->insertRow(row); /** Dodanie kolejnego wiersza do Tabeli */
        ui->tableWidgetLight->setItem(row, 0, new QTableWidgetItem(timeLight)); /** Zapis wartości czasu pomiaru do tabeli */
        ui->tableWidgetLight->setItem(row, 1, new QTableWidgetItem(light)); /** Zapis wartości temperatury do tabeli */

}

/*!
 * \brief Slot reagujący na wciśnięcie przycisku lightButton.
 * Dodaje okienko pomiarowe do wizualizacji
 */


void NewWindow::on_lightButton_clicked()
{


    if(ui->lightSpinBox->value()>=25 || ui->lightSpinBox->value()<= 0){ /** Sprawdzenie czy wprowadzona wartość mieści się
                                                                        w zakresie punktów pomiarowych pomieszczenia */
    QMessageBox msgBox; /**< Utworzenie okna dialogowego z informacją o wprowadzeniu wartości spoza zakresu */
          // Ustaw arkusz stylu
    msgBox.setStyleSheet("QMessageBox { background-color: rgba(255, 255, 255, 0.5); " /** Ustawienie arkusza stylów okna dialogowego*/
                               "border: 2px solid qlineargradient(spread:pad, x1:0.5, y1:0, x2:0.5, y2:1, "
                               "stop:0 rgba(175, 64, 255, 255), stop:0.5 rgba(91, 66, 243, 255), "
                               "stop:1 rgba(0, 221, 235, 255)); "
                               "color: black; "
                               "font-family: Phantomsans, sans-serif; "
                               "text-decoration: none; }");

          // Ustaw ikonę, tytuł i treść wiadomości
          msgBox.setIcon(QMessageBox::Critical); /** Ustawienie ikony krytycznej okna dialogowego */
          msgBox.setWindowTitle("Błąd"); /** Ustawienie tytułu okna dialogowego*/
          msgBox.setText("Wartość niedozwolona!"); /** Ustawienie treści okna dialogowego*/
          msgBox.exec(); /** Wywołanie okna dialogowego */
          hel = 0; /** Nadanie zmiennej przechowującej dane użytkownika wartości zerowej */
    }
    else {
    hel=ui->lightSpinBox->value()-1;  /** Przetworzenie wartości wprowadzonej przez użytkownika*/
    }



}

/*!
 * \brief NewWindow::receiveTemperatureSensorData -- odbiera dane pomiarowe o temperaturze
 * \param tSpace -- czas pomiaru w sekundach
 * \param y -- wartość zmierzona
 */





void NewWindow::receiveTemperatureSensorData(double tSpace, double y)
{

//    tempLabelVector[7]->setStyleSheet("background-color: red;");


    int j = static_cast<int>(hel);
    if(y<-15){
        tempLabelVector[j]->setStyleSheet("background-color: #66e0ff;"); /** Ustawienie koloru #66e0ff okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<-5){
        tempLabelVector[j]->setStyleSheet("background-color: #ccf5ff;"); /** Ustawienie koloru #ccf5ff okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<0){
        tempLabelVector[j]->setStyleSheet("background-color: #e6ffe6;"); /** Ustawienie koloru #e6ffe6 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<5){
        tempLabelVector[j]->setStyleSheet("background-color: #aaff80;"); /** Ustawienie koloru #aaff80 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<10){
        tempLabelVector[j]->setStyleSheet("background-color: #77ff33;"); /** Ustawienie koloru #77ff33 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<15){
        tempLabelVector[j]->setStyleSheet("background-color: #ffff4d;"); /** Ustawienie koloru #ffff4d okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<20){
        tempLabelVector[j]->setStyleSheet("background-color: #ffff00;"); /** Ustawienie koloru #ffff00 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<25){
        tempLabelVector[j]->setStyleSheet("background-color: #ff9933;"); /** Ustawienie koloru #ff9933 okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<30){
        tempLabelVector[j]->setStyleSheet("background-color: #ff8000c;"); /** Ustawienie koloru #ff8000c okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else if(y<35){
        tempLabelVector[j]->setStyleSheet("background-color: #ff471a;"); /** Ustawienie koloru #ff471a okna pomiarowego, zgodnie z przyjętą skalą*/
    }
    else {
        tempLabelVector[j]->setStyleSheet("background-color: #ff3300;"); /** Ustawienie koloru #ff3300 okna pomiarowego, zgodnie z przyjętą skalą*/
    }

    emit sendTemperatureChartData(tSpace,y);


    ui->tableWidget->setColumnCount(2); /** Ustawienie liczby kolumn w tabeli */
    titles << "czas [s]" << "temperatura [°C]"; /** Dodanie tytułów kolumn do listy */
    ui->tableWidget->setHorizontalHeaderLabels(titles); /** Dodanie tytułów kolumn do tabeli */
    row = ui->tableWidget->rowCount(); /** Pobranie numeru następnego wiersza */

        temp = QString::number(y); /** Konwersja wartości temperatury do string */

        currentTime = QTime::currentTime(); /** Pobranie czasu pomiaru */

        timeTemp = currentTime.toString("hh:mm:ss.zzz"); /** Konwersja czasu pomiaru do string */
        ui->tableWidget->insertRow(row); /** Dodanie kolejnego wiersza do Tabeli */
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(timeTemp)); /** Zapis wartości czasu pomiaru do tabeli */
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(temp)); /** Zapis wartości temperatury do tabeli */



}

/*!
 * \brief NewWindow::receiveCompassSensorData -- odbiera dane z magnetometru
 * \param tSpace -- czas pomiaru w sekundach
 * \param x -- kierunek wskazany przez kompas
 */

void NewWindow::receiveCompassSensorData(double tSpace, QString x){
    qDebug()<<"Compass: "<<x<<'\n';
    if(x == "N"){
        ui->labelArrowNorth->setVisible(true); /**< Ustawienie widzialności strzałki odpowiadającej kierunkowi północnemu */
        ui->labelArrowEast->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
        ui->labelArrowSouth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
        ui->labelArrowWest->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    }
    else if(x == "E"){
    ui->labelArrowNorth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowEast->setVisible(true); /**< Ustawienie widzialności strzałki odpowiadającej kierunkowi wschodniemu */
    ui->labelArrowSouth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowWest->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    }
    else if(x == "S"){
    ui->labelArrowNorth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowEast->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowSouth->setVisible(true);  /**< Ustawienie widzialności strzałki odpowiadającej kierunkowi południowemu */
    ui->labelArrowWest->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    }
    else if(x == "W"){
    ui->labelArrowNorth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowEast->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowSouth->setVisible(false); /**< Zanik strzałki sprzecznej ze wskazaniem */
    ui->labelArrowWest->setVisible(true);  /**< Ustawienie widzialności strzałki odpowiadającej kierunkowi wschodniemu */
    }
    else {
    ui->labelArrowNorth->setVisible(false); /**< Zanik strzałek w przypadku braku wskazań */
    ui->labelArrowEast->setVisible(false); /**< Zanik strzałek w przypadku braku wskazań */
    ui->labelArrowSouth->setVisible(false); /**< Zanik strzałek w przypadku braku wskazań */
    ui->labelArrowWest->setVisible(false); /**< Zanik strzałek w przypadku braku wskazań */
    }
}





