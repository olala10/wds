#include "newwindow.h"
#include "ui_form.h".h"
#include "mainwindow.h"


/*!
 * \brief Konstruktor klasy NewWindow.
 * \param parent Wskaźnik na rodzica okna.
 */
NewWindow::NewWindow(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::NewWindow)
{
    ui->setupUi(this);

}

/*!
 * \brief Destruktor klasy NewWindow.
 * Zwalnia pamięć zajętą przez interfejs użytkownika.
 */

NewWindow::~NewWindow()
{
    delete ui;
}


void NewWindow::on_pushButtonDiagram_clicked()
{
//    for(const QString& str : dataVector){
//        floatData.push_back(str.toFloat());
//    }
}

