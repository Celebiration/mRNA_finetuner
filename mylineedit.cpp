#include "mylineedit.h"
#include "qevent.h"
#include <QDebug>
#include <QMessageBox>

MyLineEdit::MyLineEdit(QWidget *parent)
    : QLineEdit{parent}, isEditing(true)
{
    //编辑结束后，设置为不可编辑状态
    connect(this,&MyLineEdit::editingFinished,this,&MyLineEdit::closeEdit);
    //双击后，设置为可编辑状态
}

void MyLineEdit::openEdit()
{
    if (!isEditing)
    {
        setEnabled(true);
        isEditing = true;
    }
}

void MyLineEdit::closeEdit()
{
    if (isEditing)
    {
        setEnabled(false);
        isEditing = false;
    }
}

void MyLineEdit::setEditing()
{
    setFocus();
}

void MyLineEdit::focusOutEvent(QFocusEvent* event)
{
    QLineEdit::focusOutEvent(event);

    if (event->reason() == Qt::MouseFocusReason)
    {
        // 鼠标点击导致焦点失去
        closeEdit();
    }
    else
    {
        // 其他情况导致焦点失去
        closeEdit();
    }
    //发送焦点失去信号
    emit lostFocus();
}
