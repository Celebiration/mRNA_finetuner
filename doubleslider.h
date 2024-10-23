#ifndef DOUBLESLIDER_H
#define DOUBLESLIDER_H

#include <QWidget>

namespace Ui {
class DoubleSlider;
}

class DoubleSlider : public QWidget
{
    Q_OBJECT

signals:
    void onIdealValueChange(float);

public:
    explicit DoubleSlider(QWidget *parent = nullptr);
    ~DoubleSlider();
    float getIdealValue();
    float getRealValue();
    void setIdealValue(float);

public slots:
    void emitIdealValueChange(float value)
    {
        emit onIdealValueChange(value);
    }

private:
    Ui::DoubleSlider *ui;
};

#endif // DOUBLESLIDER_H
