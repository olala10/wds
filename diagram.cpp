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

}

/*!
 * \brief Definicja metody plot
 * Rysowanie wykresu
 */
void Diagram::plot()
{
    ui->plot->graph(0)->setData(qv_x, qv_y);
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

