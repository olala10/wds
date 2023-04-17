#ifndef NEWWINDOW_H
#define NEWWINDOW_H

#include<QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class NewWindow; }
QT_END_NAMESPACE

class NewWindow: public QWidget
{
    Q_OBJECT

public:
    NewWindow(QWidget *parent = nullptr);
    ~NewWindow();

private:
  Ui::NewWindow *ui;
};


#endif // NEWWINDOW_H
