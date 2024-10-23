#include "selectcdswindow.h"
#include "ui_selectcdswindow.h"

SelectCDSWindow::SelectCDSWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SelectCDSWindow)
{
    ui->setupUi(this);
}

SelectCDSWindow::~SelectCDSWindow()
{
    delete ui;
}
