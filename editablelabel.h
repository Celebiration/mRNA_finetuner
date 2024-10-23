#ifndef EDITABLELABEL_H
#define EDITABLELABEL_H

#include <QWidget>

class EditableLabel : public QWidget
{
    Q_OBJECT
public:
    explicit EditableLabel(QWidget *parent = nullptr);

private:
    bool isEditing;

signals:

};

#endif // EDITABLELABEL_H
