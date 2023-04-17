#include "newwindow.h"
#include "ui_form.h"

NewWindow::NewWindow(QWidget *parent)
    :QWidget(parent)
    ,ui(new Ui::NewWindow)
{
    ui->setupUi(this);
}

NewWindow::~NewWindow()
{
    delete ui;
}
