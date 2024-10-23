#include "selectcdsdialog.h"
#include <QDebug>
#include "ui_selectcdsdialog.h"
#include <thread>
#include <QRegularExpression>
#include <QString>

SelectCDSDialog::SelectCDSDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SelectCDSDialog)
{
    ui->setupUi(this);

}

SelectCDSDialog::~SelectCDSDialog()
{
    delete ui;
}

void SelectCDSDialog::settext(QByteArray text)
{
    ui->plainTextEdit->setPlainText(text);
    //分析文件（text）内容，选择性预先填入字段
    QRegularExpressionMatch match = regex1.match(text);
    if (match.hasMatch()) {
        QString id = match.captured(1);
        QString utr5 = match.captured(2);
        QString cds = match.captured(3);
        QString utr3 = match.captured(4);
        ui->lineEdit_id->setText(id);
        ui->lineEdit_utr5->setText(utr5);
        ui->lineEdit_cds->setText(cds);
        ui->lineEdit_utr3->setText(utr3);
    }else{
        match = regex2.match(text);
        if (match.hasMatch()) {
            QString id = match.captured(1);
            ui->lineEdit_id->setText(id);
        }
    }
}

std::array<QString, 4> SelectCDSDialog::gettext()
{
    return std::array{ui->lineEdit_id->text(),ui->lineEdit_utr5->text(),ui->lineEdit_cds->text(),ui->lineEdit_utr3->text()};
}

void SelectCDSDialog::closeEvent(QCloseEvent* event)
{
    // 在关闭对话框之前执行自定义操作
    qDebug() << "CustomDialog is closing...";
    // 调用基类的 closeEvent() 以确保对话框能够正常关闭
    QDialog::closeEvent(event);
}

void SelectCDSDialog::accept()
{
    //验证CDS


    QDialog::accept();
}
