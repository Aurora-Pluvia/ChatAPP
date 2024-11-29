#ifndef RESETDIALOG_H
#define RESETDIALOG_H

#include <QDialog>
#include "global.h"

namespace Ui {
class ResetDialog;
}

class ResetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ResetDialog(QWidget *parent = nullptr);
    ~ResetDialog();

private slots:
    void on_return_Btn_clicked();

    void on_verify_Btn_clicked();

    void slot_reset_mod_finish(RegId id, QString res, ErrorCodes err);
    void on_sure_Btn_clicked();

private:
    bool checkUserValid();
    bool checkPassValid();
    void showTip(QString str,bool b_ok);
    bool checkEmailValid();
    bool checkVarifyValid();
    void AddTipErr(TipErr te,QString tips);
    void DelTipErr(TipErr te);
    void initHandlers();
    Ui::ResetDialog *ui;
    QMap<TipErr, QString> _tip_errs;
    QMap<RegId, std::function<void(const QJsonObject&)>> _handlers;
signals:
    void signalSwitchLogin();
};

#endif // RESETDIALOG_H
