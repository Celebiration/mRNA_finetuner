#ifndef NGSWINDOW_H
#define NGSWINDOW_H

#include <QMainWindow>
#include <vector>

using std::vector;

QT_BEGIN_NAMESPACE
namespace Ui { class NGSWindow; }
QT_END_NAMESPACE

class NGSWindow : public QMainWindow
{
    Q_OBJECT

public:
    NGSWindow(QWidget *parent = nullptr);
    ~NGSWindow();
    static bool skipCheckOnce;
    bool eventFilter(QObject*, QEvent*);

private:
    Ui::NGSWindow *ui;
    bool addInd;
    //vector<RestrictionListItem*> restrictionVector;//记录所有现存的限制位点控件的指针，当用户点击"delete"按钮时，同步释放和删除
};
#endif // NGSWINDOW_H
