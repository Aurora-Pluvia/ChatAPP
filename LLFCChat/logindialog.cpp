#include "logindialog.h"
#include "ui_logindialog.h"
#include <QDebug>
#include <QPainter>
#include <QPainterPath>
#include "httpmgr.h"
#include "TcpMgr.h"

LoginDialog::LoginDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::LoginDialog)
{
    ui->setupUi(this);
    
    //连接注册按钮，点击注册按钮则发出switchRegister信号切换到注册界面
    connect(ui->reg_Btn, &QPushButton::clicked, this, &LoginDialog::signalSwitchRegister);

	ui->forget_Label->SetState("normal", "hover", "", "selected", "selected_hover", "");
	
    //连接忘记密码槽函数，发出切换到重置界面信号
	connect(ui->forget_Label, &ClickedLabel::clicked, this, &LoginDialog::slot_forget_pwd);

    initHead();
    initHttpHandlers();
	//连接登录回包信号
	connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_login_mod_finish, this,
		&LoginDialog::slot_login_mod_finish);

	//连接tcp连接请求的信号和槽函数
	connect(this, &LoginDialog::sig_connect_tcp, TcpMgr::GetInstance().get(), &TcpMgr::slot_tcp_connect);
	//连接tcp管理者发出的连接成功信号
	connect(TcpMgr::GetInstance().get(), &TcpMgr::sig_con_success, this, &LoginDialog::slot_tcp_con_finish);
	//连接tcp管理者发出的登陆失败信号
	connect(TcpMgr::GetInstance().get(), &TcpMgr::sig_login_failed, this, &LoginDialog::slot_login_failed);

}

LoginDialog::~LoginDialog()
{
    qDebug() << "destruct LoginDialog";
    delete ui;
}

void LoginDialog::initHead() {
    //加载图片
    QPixmap originalPixmap(":/res/head_1.jpg");
    //设置图片自动缩放
    qDebug() << originalPixmap.size() << ui->head_Label->size();
    originalPixmap = originalPixmap.scaled(ui->head_Label->size(), 
        Qt::KeepAspectRatio, Qt::SmoothTransformation);//按照head_Label的大小等比例缩放且平滑转换
    //创建一个和原始图片相同大小的QPixmap，用于绘制圆角图片
    QPixmap roundedPixmap(originalPixmap.size());
    roundedPixmap.fill(Qt::transparent);//透明

    QPainter painter(&roundedPixmap);
    painter.setRenderHint(QPainter::Antialiasing);//设置抗锯齿
    painter.setRenderHint(QPainter::SmoothPixmapTransform);

    //使用QPainterPath设置圆角
    QPainterPath path;
    path.addRoundedRect(0, 0, originalPixmap.width(), originalPixmap.height(), 10, 10);
    painter.setClipPath(path);

    //将原始图片绘制到roundedPixmap上
    painter.drawPixmap(0, 0, originalPixmap);

    //设置绘制好的圆角图片到QLabel上
    ui->head_Label->setPixmap(roundedPixmap);
}

void LoginDialog::initHttpHandlers() {
    //注册获取登录回包逻辑
    _handlers.insert(RegId::ID_LOGIN_USER, [this](QJsonObject jsonObj) {
        int error = jsonObj["error"].toInt();
        if (error != ErrorCodes::SUCCESS) {
            showTip(tr("参数错误"), false);
            enableBtn(true);
            return;
        }
        auto email = jsonObj["email"].toString();

        //发送信号通知tcpmgr发送长链接
        ServerInfo si;
		si.Uid = jsonObj["uid"].toInt();
		si.Host = jsonObj["host"].toString();
		si.Port = jsonObj["port"].toString();
		si.Token = jsonObj["token"].toString();

        //缓存
        _uid = si.Uid;
        _token = si.Token;
		qDebug() << "email is " << email << " uid is " << si.Uid << " host is "
			<< si.Host << " Port is " << si.Port << " Token is " << si.Token;
		emit sig_connect_tcp(si);
        });
}

bool LoginDialog::checkUserValid() {
	auto user = ui->email_Edit->text();
	if (user.isEmpty()) {
		qDebug() << "User empty ";
        AddTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱不能为空"));
		return false;
	}
	DelTipErr(TipErr::TIP_EMAIL_ERR);
	return true;
}

bool LoginDialog::checkPwdValid() {
	auto pwd = ui->pass_Edit->text();
	if (pwd.length() < 6 || pwd.length() > 15) {
		qDebug() << "Pass length invalid";
		//提示长度不准确
		AddTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
		return false;
	}

	// 创建一个正则表达式对象，按照上述密码要求
	// 这个正则表达式解释：
    // ^[a-zA-Z0-9!@#$%^&*.]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
	QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*.]{6,15}$");
	bool match = regExp.match(pwd).hasMatch();
	if (!match) {
		//提示字符非法
		AddTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符且长度为(6~15)"));
		return false;;
	}

	DelTipErr(TipErr::TIP_PWD_ERR);

	return true;
}

void LoginDialog::AddTipErr(TipErr te, QString tips) {
    _tip_errs[te] = tips;
    showTip(tips, false);
}

void LoginDialog::DelTipErr(TipErr te) {
    _tip_errs.remove(te);
    if (_tip_errs.empty()) {
        ui->err_Tip->clear();
        return;
    }
	showTip(_tip_errs.first(), false);
}

void LoginDialog::showTip(QString str, bool b_ok) {
	if (b_ok) {
		ui->err_Tip->setProperty("state", "normal");
	} else {
		ui->err_Tip->setProperty("state", "err");
	}

	ui->err_Tip->setText(str);

	repolish(ui->err_Tip);
}

bool LoginDialog::enableBtn(bool enabled) {
	ui->login_Btn->setEnabled(enabled);
	ui->reg_Btn->setEnabled(enabled);
	return true;
}

void LoginDialog::slot_forget_pwd() {
	qDebug() << "slot forget pwd";
	emit signalSwitchReset();
}

void LoginDialog::on_login_Btn_clicked() {
    qDebug() << "login btn clicked";
    //检查输入是否有效
    if (checkUserValid() == false) {
        return;
	}
	if (checkPwdValid() == false) {
		return;
	}
    enableBtn(false);
    auto email = ui->email_Edit->text();
    auto pwd = ui->pass_Edit->text();

    //发送http请求登录
    QJsonObject json_obj;
    json_obj["email"] = email;
    json_obj["passwd"] = xorString(pwd);
    HttpMgr::GetInstance()->postHttpReg(QUrl(gate_url_prefix + "/user_login"),
        json_obj, RegId::ID_LOGIN_USER, Modules::LOGINMOD);
}

void LoginDialog::slot_login_mod_finish(RegId id, QString res, ErrorCodes err) {
	if (err != ErrorCodes::SUCCESS) {
		showTip(tr("json解析错误1"), false);
		return;
	}

	// 解析 JSON 字符串,res需转化为QByteArray
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
	//json解析错误
	if (jsonDoc.isNull()) {
		showTip(tr("json解析错误2"), false);
		return;
	}

	//json解析错误
	if (!jsonDoc.isObject()) {
		showTip(tr("json解析错误3"), false);
		return;
	}


	//调用对应的逻辑,根据id回调。
	_handlers[id](jsonDoc.object());

	return;
}

void LoginDialog::slot_tcp_con_finish(bool bsuccess) {
	if (bsuccess) {
		showTip(tr("聊天服务连接成功，正在登录..."), true);
		QJsonObject jsonObj;
		jsonObj["uid"] = _uid;
		jsonObj["token"] = _token;

		QJsonDocument doc(jsonObj);
		QByteArray jsonData = doc.toJson(QJsonDocument::Indented);

		//发送tcp请求给chat server
		emit TcpMgr::GetInstance()->sig_send_data(RegId::ID_CHAT_LOGIN, jsonData);

	} else {
		showTip(tr("网络异常"), false);
		enableBtn(true);
	}
}

void LoginDialog::slot_login_failed(int err) {
	QString result = QString("登录失败, err is %1").arg(err);
	showTip(result, false);
	enableBtn(true);
}
