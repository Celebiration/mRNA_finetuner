#include "editablelabel.h"
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

EditableLabel::EditableLabel(QWidget *parent)
    : QWidget{parent},isEditing(true)
{
    QLabel *label = new QLabel();
    QLineEdit *lineEdit = new QLineEdit();
    label->hide();

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(label);
    layout->addWidget(lineEdit);

    setLayout(layout);

//    connect(label, &QLabel::, this, &EditableLabel::startEditing);
//    connect(lineEdit, &QLineEdit::editingFinished, this, &EditableLabel::finishEditing);
}
