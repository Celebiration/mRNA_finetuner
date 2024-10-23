#ifndef CENTRALIZEDSLIDER_H
#define CENTRALIZEDSLIDER_H

#include <QWidget>
#include <QSlider>

namespace Ui {
class CentralizedSlider;
}

class CentralizedSlider : public QWidget
{
    Q_OBJECT

public:
    explicit CentralizedSlider(QWidget *parent = nullptr);
    ~CentralizedSlider();
    QSlider *CurrentSlider;

private:
    Ui::CentralizedSlider *ui;
};

#endif // CENTRALIZEDSLIDER_H
