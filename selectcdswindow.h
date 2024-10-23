#ifndef SELECTCDSWINDOW_H
#define SELECTCDSWINDOW_H

#include <QMainWindow>

namespace Ui {
class SelectCDSWindow;
}

class SelectCDSWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit SelectCDSWindow(QWidget *parent = nullptr);
    ~SelectCDSWindow();

private:
    Ui::SelectCDSWindow *ui;
};

#endif // SELECTCDSWINDOW_H
