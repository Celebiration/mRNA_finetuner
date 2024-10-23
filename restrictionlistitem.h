#ifndef RESTRICTIONLISTITEM_H
#define RESTRICTIONLISTITEM_H

#include <QWidget>

namespace Ui {
class RestrictionListItem;
}

class RestrictionListItem : public QWidget
{
    Q_OBJECT

public:
    explicit RestrictionListItem(QWidget *parent = nullptr);
    ~RestrictionListItem();
    std::array<bool, 2> isValid();
    void setIdEditing();
    void setPatternEditing();
    void closeEdits();
    void openIdEdit();
    void openPatternEdit();
    void autoSignId(int);
    void clearPattern();
    bool eventFilter(QObject*, QEvent*);
    static bool dontCheckFocus;
    QString getId();
signals:
    void lostidfocus();
private:
    Ui::RestrictionListItem *ui;
    static QRegularExpression regex;
};

#endif // RESTRICTIONLISTITEM_H
