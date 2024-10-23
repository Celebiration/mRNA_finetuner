#include "ngswindow.h"
#include "ui_ngswindow.h"
#include "restrictionlistitem.h"
#include <QDebug>
#include <QFileDialog>
#include <QString>
#include <QFile>
#include <QStringListModel>
#include <QPushButton>
#include <vector>
#include <QDebug>
#include <QMessageBox>
#include "selectcdsdialog.h"


using std::vector;

NGSWindow::NGSWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::NGSWindow), addInd(false)
{
    ui->setupUi(this);
    ui->pushButton_delete_restriction_pattern->installEventFilter(this);
    //新建操作
    connect(ui->action_new,&QAction::triggered,this,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件",R"(D:\projects\QT_NGStool\NGS_analyzer)");
        if (path == ""){return;}
        ui->statusbar->showMessage(path);
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        QByteArray array = file.readAll();
        SelectCDSDialog cdsdialog;//对话框是声明在栈上的局部变量，离开lambda作用域后会自动销毁
        cdsdialog.settext(array);
        if (cdsdialog.exec() == QDialog::Accepted)
        {
            auto _tmp = cdsdialog.gettext();
            QString _tmp1 = ">" + _tmp[0] + "\n" + _tmp[1] + _tmp[2] + _tmp[3];
            ui->plainTextEdit_sequence_display->setPlainText(_tmp1);
        }

    });
    // 当用户点击"add new"按钮时，向ListWidget添加项目并设置为单独选中状态
    connect(ui->pushButton_add_restriction_pattern,&QPushButton::clicked,this,[=](){
        RestrictionListItem *_restrict = new RestrictionListItem();
        //restrictionVector.push_back(_restrict);
        QListWidgetItem *item1 = new QListWidgetItem();
        item1->setSizeHint(_restrict->sizeHint()); // 设置项目的大小
        ui->listWidget->addItem(item1);
        ui->listWidget->setItemWidget(item1, _restrict);
        //id焦点失去且为空时，自动分配id
        connect(_restrict,&RestrictionListItem::lostidfocus,this,[=](){
            if (!_restrict->isValid()[0]){
                _restrict->autoSignId(ui->listWidget->row(item1)+1);
            }
        });
        addInd=true;
        item1->setSelected(true);//check

        //若之前存在不合法的条目，则删除新加入的item
        if(!addInd)
        {
            ui->listWidget->takeItem(ui->listWidget->row(item1));
            delete item1;
        }else{
            _restrict->setIdEditing();
        }
        addInd=false;
    });
    //当一个ListWidgetItem取消选中状态时，检查其合法性：若合法，则pass，否则弹窗警告，并要求编辑该项目
    connect(ui->listWidget,&QListWidget::itemSelectionChanged,this,[=](){
        RestrictionListItem::dontCheckFocus=true;
        if (skipCheckOnce)
        {
            skipCheckOnce=false;
            RestrictionListItem::dontCheckFocus=false;
            return;
        }
        QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
        QList<QListWidgetItem*> allItems = ui->listWidget->findItems("*", Qt::MatchWildcard);
        for (QListWidgetItem *item : allItems) {
            if (!selectedItems.contains(item))
            {
                //验证是否是一个合法的RestrictionListItem
                RestrictionListItem *Ritem = qobject_cast<RestrictionListItem*>(ui->listWidget->itemWidget(item));
                Ritem->closeEdits();
                std::array<bool, 2> RitemValids = Ritem->isValid();
                if (!RitemValids[1])
                {
//                    QMessageBox::warning(this,"警告",Ritem->getId()+" pattern不合法");
                    skipCheckOnce=true;
                    item->setSelected(true);
                    Ritem->openPatternEdit();
                    Ritem->clearPattern();
//                    Ritem->setPatternEditing();
                    qDebug() << "2";
                    if (addInd){addInd=false;}
                    break;
                }else if (!(RitemValids[0]))
                {
                    Ritem->autoSignId(ui->listWidget->row(item)+1);
                    break;
                }
            }
        }
        RestrictionListItem::dontCheckFocus=false;
    });
    //当用户选中任意多个ListWidgetItem时，激活delete按钮，否则禁用
    connect(ui->pushButton_delete_restriction_pattern, &QPushButton::clicked, this, [&]() {
        //屏蔽lostfocus检查
        if (QMessageBox::question(this,"Question","是否删除条目",QMessageBox::Yes|QMessageBox::Cancel,QMessageBox::Cancel) == QMessageBox::Yes)
        {
            QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
            for (QListWidgetItem *item : selectedItems) {
                skipCheckOnce=true;//takeItem会引起一次listItem选择的改变，因此屏蔽一次check
                ui->listWidget->takeItem(ui->listWidget->row(item));
                delete item;
            }
        }
    });

    //test button
    connect(ui->pushButton_test,&QPushButton::clicked,this,[=](){
        QList<QListWidgetItem*> selectedItems = ui->listWidget->selectedItems();
        for (QListWidgetItem *item : selectedItems) {
            RestrictionListItem *Ritem = qobject_cast<RestrictionListItem*>(ui->listWidget->itemWidget(item));
            qDebug() << Ritem->isValid()[0] << Ritem->isValid()[1];
        }
    });
}

NGSWindow::~NGSWindow()
{
    delete ui;
}

bool NGSWindow::skipCheckOnce = false;

bool NGSWindow::eventFilter(QObject* obj,QEvent* e)
{
    if (obj==ui->pushButton_delete_restriction_pattern && e->type()==QEvent::MouseButtonPress){
        qDebug() << "...";
        return false;
    }
    return false;
}
