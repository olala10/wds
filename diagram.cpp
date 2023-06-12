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
//    ui->plot->setBackground(QBrush(QColor(255, 255, 255, 0.5)));


    ui->plot_light->addGraph();
    ui->plot_light->graph(0)->setScatterStyle(QCPScatterStyle::ssCircle);
    ui->plot_light->graph(0)->setLineStyle(QCPGraph::lsNone);
    ui->plot_light->xAxis->setLabel("Czas[s]");
    ui->plot_light->yAxis->setLabel("Pomiar");


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
 * \brief Definicja metody addPoint -- dodaje wartości pomiarowe do wektora wartości temperatury
 * \param x -- czas pomiaru
 * \param y -- wartość temperatury
 */
void Diagram::addPoint(double x, double y)
{
    qv_x.append(x); /** dodawanie do wektora czasu*/
    qv_y.append(y); /** dodawanie do wektora temperatury*/

}

/*!
 * \brief Diagram::addLightPoint -- dodaje wartości pomiarowe do wektora wartości pomiaru światła
 * \param x -- czas pomiaru
 * \param y -- wartość natężenia światła
 */

void Diagram::addLightPoint(double x, double y)
{
    qv_xL.append(x); /** dodawanie do wektora czasu*/
    qv_yL.append(y); /** dodawanie do wektora natężenia światła */
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
    ui->plot->update(); /**< Aktualizowanie wykresu */
}

void Diagram::plotLight()
{

    ui->plot_light->graph(0)->setData(qv_xL, qv_yL); /** Ustawianie danych do wykresu */
    ui->plot_light->graph(0)->rescaleAxes(true); /** Automatyczne skalowanie wykresu */
    ui->plot_light->replot(); /** Dodawanie elementów */
    ui->plot_light->update(); /** Aktualizowanie wykresu */
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
 * \brief Diagram::receiveTemperatureChartData -- odbiera dane o temperaturze
 * \param t -- czas zebrania pomiaru
 * \param y -- wartość zmierzona
 */

void Diagram::receiveTemperatureChartData(double t, double y)
{
    addPoint(t, y);
    plot();
    qDebug()<<"Chart time: "<<t<<'/n';
    qDebug()<<"Chart temperature: "<<y<<'/n';
}
/*!
 * \brief receiveLightChartData -- odbiera dane o rozkładzie natężenia światła
 * \param t -- czas zebrania pomiaru
 * \param y -- wartość zmierzona
 */

void Diagram::receiveLightChartData(double t, double y)
{
    addLightPoint(t,y);
    plotLight();
//    qDebug()<<"Chart time: "<<t<<'/n';
//    qDebug()<<"Chart light: "<<y<<'/n';
}


