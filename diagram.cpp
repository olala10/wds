#include "diagram.h"
#include "ui_diagram.h"
#include "qcustomplot.h"

/*!
 * \brief Konstruktor klasy Diagram.
 * \param parent Wskaźnik na rodzica okna.
 */
Diagram::Diagram(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Diagram)
{
    ui->setupUi(this);
    ui->plot->addGraph();
    ui->plot->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plot->xAxis->setLabel("Czas[s]");
    ui->plot->yAxis->setLabel("Pomiar");
    //connect(&QMainWindow, &MainWindow::sendData, &Diagram, &Diagram::receiveData);
//    connect(&parent, &MainWindow::sendData(double,double), &diagram, &Diagram::receiveData(double, double));
   connect(parent, SIGNAL(sendData(double,double)), this, SLOT(receiveData(double,double))); /**< Łączenie sygnału, gdzie 1 i 3
  //to obiekty okien, między którymi przesyłane są dane a 2 i 4 składowa to nazwy sygnału i slotu, które mają być połączone*/


}


/*!
 * \brief Destruktor klasy Diagram.
 * Zwalnia pamięć zajętą przez interfejs użytkownika.
 */
Diagram::~Diagram()
{
    delete ui;
}

/*!
 * \brief Definicja metody addPoint
 * Dodaje x i y
 */
void Diagram::addPoint(double x, double y)
{
    qv_x.append(x);
    qv_y.append(y);

}

/*!
 * \brief Definicja metody clearData
 *
 */
void Diagram::clearData()
{
    qv_x.clear();
    qv_y.clear();
}

/*!
 * \brief Definicja metody plot
 * Rysowanie wykresu
 */
void Diagram::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y); /**< Ustawianie danych do wykresu */
    ui->plot->graph(0)->rescaleAxes(true); /**< Automatyczne skalowanie wykresu */
    ui->plot->replot(); /**< Dorysowywanie elementów*/
    ui->plot->update(); /**< Aktualizowanie rysunku */

}

/*!
 * \brief Definicja metody on_pushButtonAdd_clicked()
 * Odpowiada zachowaniu aplikacji po wciśnięciu przycisku ,,Dodaj"
 * Dodaje wartości i wywołuje metodę rysowania wykresu.
 */

void Diagram::on_pushButtonAdd_clicked()
{
    addPoint(ui->bx_x->value(), ui->bx_y->value());
    plot();
}

/*!
 * \brief Definicja metody on_pushButtonClear_clicked()
 * Usuwa zawartość wykresu
 */

void Diagram::on_pushButtonClear_clicked()
{
    clearData();
    plot();
}

/*!
 * \brief Definicja metody receiveData, przyjmująca wartości x i var
 * metoda dodaje je do wykresu i wywołuje metodę plot
 */

void Diagram::receiveData(double x, double variable)
{
    addPoint(x, variable);
    plot();
}




