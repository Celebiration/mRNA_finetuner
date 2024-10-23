#include "restrictionlistitem.h"
#include "qregularexpression.h"
#include "ui_restrictionlistitem.h"
#include <QMessageBox>

RestrictionListItem::RestrictionListItem(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::RestrictionListItem)
{
    ui->setupUi(this);
    //给mylineedit安装事件过滤器
    ui->lineEdit_id->installEventFilter(this);
    ui->lineEdit_pattern->installEventFilter(this);
    //id失去焦点时需要检查是否合法，若不合法，则需要自动分配
    connect(ui->lineEdit_id,&MyLineEdit::lostFocus,this,&RestrictionListItem::lostidfocus);
    //pattern失去焦点时需要检查是否合法，若不合法，则需要继续编辑
    connect(ui->lineEdit_pattern,&MyLineEdit::lostFocus,this,[=](){
        if (dontCheckFocus){return;}
        if (!isValid()[1]){
            QMessageBox::warning(this,"警告",ui->lineEdit_id->text()+" pattern不合法");
            openPatternEdit();
            clearPattern();
//            setPatternEditing();
            qDebug() << "1";
        }
    });
}

RestrictionListItem::~RestrictionListItem()
{
    delete ui;
}

std::array<bool, 2> RestrictionListItem::isValid()
{
    QString id = ui->lineEdit_id->text();
    QString pattern = ui->lineEdit_pattern->text();
    bool pattern_match = regex.match(pattern).hasMatch();
    return std::array<bool, 2>{!id.isEmpty(),pattern_match};
}

QRegularExpression RestrictionListItem::regex("^[ATCGatcg]+$");

void RestrictionListItem::setIdEditing()
{
    ui->lineEdit_id->setEditing();
}

void RestrictionListItem::setPatternEditing()
{
    ui->lineEdit_pattern->setEditing();
}

void RestrictionListItem::closeEdits()
{
    ui->lineEdit_id->closeEdit();
    ui->lineEdit_pattern->closeEdit();
}

void RestrictionListItem::openIdEdit()
{
    ui->lineEdit_id->openEdit();
}

void RestrictionListItem::openPatternEdit()
{
    ui->lineEdit_pattern->openEdit();
}

void RestrictionListItem::autoSignId(int row_number)
{
    ui->lineEdit_id->setText("pattern"+QString::number(row_number));
}

void RestrictionListItem::clearPattern()
{
    ui->lineEdit_pattern->clear();
}

bool RestrictionListItem::eventFilter(QObject* obj, QEvent* e)
{
    if (obj==ui->lineEdit_id)
    {
        if (e->type()==QEvent::MouseButtonDblClick){
            ui->lineEdit_id->openEdit();
            ui->lineEdit_id->setEditing();
            return true;
        }
    }else if (obj==ui->lineEdit_pattern)
    {
        if (e->type()==QEvent::MouseButtonDblClick){
            ui->lineEdit_pattern->openEdit();
            ui->lineEdit_pattern->setEditing();
            return true;
        }
    }
    return false;
}

bool RestrictionListItem::dontCheckFocus = false;

QString RestrictionListItem::getId()
{
    return ui->lineEdit_id->text();
}
