#ifndef LOGINDIALOG_H
#define LOGINDIALOG_H

#include <QDialog>
#include "global.h"
/******************************************************************************
 *
 * @file       logindialog.h
 * @brief      登陆窗口
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class LoginDialog;
}

class LoginDialog : public QDialog {
    Q_OBJECT

public:
    explicit LoginDialog(QWidget *parent = nullptr);
    ~LoginDialog();

private:
	void initHead();
	void initHttpHandlers();//回调函数
    Ui::LoginDialog *ui;
	bool checkUserValid();
	bool checkPwdValid();
	void AddTipErr(TipErr te, QString tips);
	void DelTipErr(TipErr te);
	QMap<TipErr, QString> _tip_errs;
	void showTip(QString str, bool b_ok);
	QMap<RegId, std::function<void(const QJsonObject&)>> _handlers;
	bool enableBtn(bool enabled);
	int _uid;
	QString _token;
signals:
    void signalSwitchRegister();
	void signalSwitchReset();
	//收到gateserver回复后发送信号通知tcpserver与chatserver进行强链接
	void sig_connect_tcp(ServerInfo);

private slots:
	void slot_forget_pwd();
	void on_login_Btn_clicked();
	void slot_login_mod_finish(RegId id, QString res, ErrorCodes err);
	void slot_tcp_con_finish(bool bsuccess);
	void slot_login_failed(int);
};

#endif // LOGINDIALOG_H
