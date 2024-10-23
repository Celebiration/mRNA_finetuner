#ifndef SELECTCDSDIALOG_H
#define SELECTCDSDIALOG_H

#include <QDialog>
#include <QRegularExpression>

namespace Ui {
class SelectCDSDialog;
}

class SelectCDSDialog : public QDialog
{
    Q_OBJECT

public:
    explicit SelectCDSDialog(QWidget *parent = nullptr);
    ~SelectCDSDialog();
    void settext(QByteArray);
    std::array<QString, 4> gettext();

protected:
    void closeEvent(QCloseEvent* event) override;
    void accept() override;

private:
    Ui::SelectCDSDialog *ui;
    QRegularExpression regex1{"^>(.*)\n([ATCGatcg]*)[^ATCGatcg]+([ATCGatcg]+)[^ATCGatcg]+([ATCGatcg]*)$"};
    QRegularExpression regex2{"^>(.*)\n"};
};

#endif // SELECTCDSDIALOG_H
