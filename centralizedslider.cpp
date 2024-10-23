#include "centralizedslider.h"
#include "ui_centralizedslider.h"

CentralizedSlider::CentralizedSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CentralizedSlider)
{
    ui->setupUi(this);
    void (QSpinBox:: * spSignal)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, spSignal,ui->double_slider,&DoubleSlider::setIdealValue);
    connect(ui->double_slider, &DoubleSlider::onIdealValueChange, ui->spinBox, &QSpinBox::setValue);
    ui->spinBox->setValue((int)(ui->double_slider->getIdealValue()));
    //拷贝slider并垂直翻转，表示当前属性值
//    QSlider *CurrentSlider = new QSlider(Qt::Horizontal,ui->horizontalSlider);
//    CurrentSlider->setMinimum(ui->horizontalSlider->minimum());
//    CurrentSlider->setMaximum(ui->horizontalSlider->maximum());
//    int originalRow, originalColumn, originalRowSpan, originalColumnSpan;
//    QGridLayout *gridLayout = ui->gridLayout;
//    gridLayout->getItemPosition(this->layout()->indexOf(ui->horizontalSlider), &originalRow, &originalColumn, &originalRowSpan, &originalColumnSpan);
//    gridLayout->addWidget(CurrentSlider, originalRow, originalColumn, originalRowSpan, originalColumnSpan);
//    CurrentSlider->move(ui->horizontalSlider->pos());
}

CentralizedSlider::~CentralizedSlider()
{
    delete ui;
    delete CurrentSlider;
}
