#ifndef REGISTERDIALOG_H
#define REGISTERDIALOG_H

#include <QDialog>
#include "global.h"
/******************************************************************************
 *
 * @file       registerdialog.h
 * @brief      注册窗口
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class RegisterDialog;
}

class RegisterDialog : public QDialog
{
    Q_OBJECT

public:
    explicit RegisterDialog(QWidget *parent = nullptr);
    ~RegisterDialog();

private slots:
    void on_get_Code_clicked();
    void slot_reg_mod_finish(RegId id, QString res, ErrorCodes err);

    void on_sure_Btn_clicked();

    void on_return_Btn_clicked();

    void on_cancel_Btn_clicked();

private:
    Ui::RegisterDialog *ui;
    void showTip(QString str, bool b_Ok);//显示提示
    void initHttpHandlers();//初始化http处理器
    //添加/删除错误提示
    void AddTipErr(TipErr te, QString tips);
    void DelTipErr(TipErr te);
    //检测输入框中内容是否合理
    bool checkUserValid();
    bool checkEmailValid();
    bool checkPassValid();
    bool checkConfirmValid();
    bool checkVarifyValid();

    void ChangeTipPage();
    QMap<RegId, std::function<void(const QJsonObject&)>> _handlers;//利用_handlers根据id执行函数
    QMap<TipErr, QString> _tip_errs;
    QTimer* _countdown_timer;
    int _countdown;
signals:
    void sigSwitchLogin();
};

#endif // REGISTERDIALOG_H
