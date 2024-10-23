#ifndef MYLINEEDIT_H
#define MYLINEEDIT_H

#include <QWidget>
#include <QLineEdit>
#include <QDebug>

class MyLineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit MyLineEdit(QWidget *parent = nullptr);
    void openEdit();
    void closeEdit();
    void setEditing();

signals:
    void lostFocus();

protected:
    void focusOutEvent(QFocusEvent* event) override;
private:
    bool isEditing;

signals:

};

#endif // MYLINEEDIT_H
