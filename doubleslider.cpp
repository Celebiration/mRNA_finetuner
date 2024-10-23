#include "doubleslider.h"
#include "ui_doubleslider.h"
#include <QGridLayout>

DoubleSlider::DoubleSlider(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DoubleSlider)
{
    ui->setupUi(this);
    //初始化idealSlider在默认位置
    ui->horizontalSlider_ideal->setValue(50);
    ui->horizontalSlider_ideal->setStyleSheet("QSlider::handle:horizontal { background-color: orange; }");
    connect(ui->horizontalSlider_ideal, &QSlider::valueChanged, this, &DoubleSlider::emitIdealValueChange);
    ui->horizontalSlider_ideal->raise();
}

void DoubleSlider::setIdealValue(float value)
{
    ui->horizontalSlider_ideal->setValue(value);
}

float DoubleSlider::getIdealValue()
{
    return (float)(ui->horizontalSlider_ideal->value());
}

float DoubleSlider::getRealValue()
{
    return (float)(ui->horizontalSlider_real->value());
}

DoubleSlider::~DoubleSlider()
{
    delete ui;
}
