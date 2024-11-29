#include "registerdialog.h"
#include "ui_registerdialog.h"
#include "httpmgr.h"

RegisterDialog::RegisterDialog(QWidget *parent)
    : QDialog(parent) , ui(new Ui::RegisterDialog), _countdown(5)
{
    ui->setupUi(this);
    //设置输入密码和确认密码时隐藏密码
    ui->pass_Edit->setEchoMode(QLineEdit::Password);
    ui->confirm_Edit->setEchoMode(QLineEdit::Password);
    ui->err_Tip->setProperty("state", "normal");//设置错误提示初始状态
    repolish(ui->err_Tip);//刷新错误提示状态
    connect(HttpMgr::GetInstance().get(), &HttpMgr::sig_reg_mod_finish,
        this, &RegisterDialog::slot_reg_mod_finish);
    initHttpHandlers();

	//设定输入框输入后清空错误提示字符串
	ui->err_Tip->clear();

	//各输入框输入完成后发送输入完成信号并触发验证输入内容是否有效槽函数
    connect(ui->user_Edit, &QLineEdit::editingFinished, this, [this]() {
		checkUserValid();
		});
    connect(ui->email_Edit, &QLineEdit::editingFinished, this, [this]() {
		checkEmailValid();
		});
    connect(ui->pass_Edit, &QLineEdit::editingFinished, this, [this]() {
		checkPassValid();
		});
    connect(ui->confirm_Edit, &QLineEdit::editingFinished, this, [this]() {
		checkConfirmValid();
		});
    connect(ui->verify_Edit, &QLineEdit::editingFinished, this, [this]() {
		checkVarifyValid();
		});

	//鼠标移动到label上时改变鼠标指针为可点击样式
	ui->pass_Visible->setCursor(Qt::PointingHandCursor);
	ui->confirm_Visible->setCursor(Qt::PointingHandCursor);

    //设置显示密码按钮的状态
	ui->pass_Visible->SetState("unvisible", "unvisible_hover", "", "visible",
		"visible_hover", "");
	ui->confirm_Visible->SetState("unvisible", "unvisible_hover", "", "visible",
        "visible_hover", "");

    //连接点击事件
    connect(ui->pass_Visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->pass_Visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->pass_Edit->setEchoMode(QLineEdit::Password);
        }else{
                ui->pass_Edit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });
    connect(ui->confirm_Visible, &ClickedLabel::clicked, this, [this]() {
        auto state = ui->confirm_Visible->GetCurState();
        if(state == ClickLbState::Normal){
            ui->confirm_Edit->setEchoMode(QLineEdit::Password);
        }else{
                ui->confirm_Edit->setEchoMode(QLineEdit::Normal);
        }
        qDebug() << "Label was clicked!";
    });

	// 创建定时器
	_countdown_timer = new QTimer(this);
	// 连接信号和槽
	connect(_countdown_timer, &QTimer::timeout, [this]() {
		if (_countdown == 0) {
			_countdown_timer->stop();
			emit sigSwitchLogin();
			return;
		}
		_countdown--;
		auto str = QString("注册成功，%1 s后返回登录").arg(_countdown);
		ui->tip_Lb->setText(str);
		});
}

RegisterDialog::~RegisterDialog()
{
    qDebug() << "destruct RegisterDialog";
    delete ui;
}

void RegisterDialog::slot_reg_mod_finish(RegId id, QString res, ErrorCodes err) {
	if (err != ErrorCodes::SUCCESS) {
		showTip("网络请求错误", false);
		return;
	}
	//解析JSON字符串，res转化为QByteArray
	QJsonDocument jsonDoc = QJsonDocument::fromJson(res.toUtf8());
	if (jsonDoc.isNull()) {
		showTip("json解析失败", false);
		return;
	}
	//json解析错误
	if (!jsonDoc.isObject()) {
		showTip("json解析错误", false);
		return;
	}
	//成功，转成json对象，调用回调函数
	_handlers[id](jsonDoc.object());
	return;

}

//点击获取验证码
void RegisterDialog::on_get_Code_clicked()
{
    auto email = ui->email_Edit->text();
    QRegularExpression regex(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");//邮箱的正则表达式
    bool match = regex.match(email).hasMatch();//检查邮箱
    if(match){
        //发送验证码
        QJsonObject json_obj;
        json_obj["email"] = email;
        HttpMgr::GetInstance()->postHttpReg(QUrl(gate_url_prefix + "/get_verifycode"),
            json_obj, RegId::ID_GET_VERIFY_CODE, Modules::REGISTERMOD);
    }else{
        showTip("邮箱地址不正确", false);
    }
}

void RegisterDialog::showTip(QString str, bool b_Ok)
{
    if(b_Ok){
        ui->err_Tip->setProperty("state", "state");
    }else{
        ui->err_Tip->setProperty("state", "err");
    }
    ui->err_Tip->setText(str);
    repolish(ui->err_Tip);
}

void RegisterDialog::initHttpHandlers() {
    //注册获取验证码回包的逻辑
    _handlers.insert(RegId::ID_GET_VERIFY_CODE, [this](const QJsonObject& jsonObj) {
        int error = jsonObj["error"].toInt();
        if (error != ErrorCodes::SUCCESS) {
            showTip("参数错误", false);
            return;
        }
        auto email = jsonObj["email"].toString();
        showTip("验证码已发送至邮箱，注意查收", true);
        qDebug() << "email is " << email;
        });

	//注册注册用户回包逻辑
	_handlers.insert(RegId::ID_REG_USER, [this](QJsonObject jsonObj) {
		int error = jsonObj["error"].toInt();
		if (error != ErrorCodes::SUCCESS) {
			showTip(tr("参数错误"), false);
			return;
		}
		auto email = jsonObj["email"].toString();
		showTip(tr("用户注册成功"), true);
        qDebug() << "user uid is " << jsonObj["uid"].toString();
		qDebug() << "email is " << email;
		ChangeTipPage();
		});
}

void RegisterDialog::AddTipErr(TipErr te, QString tips) {
	_tip_errs[te] = tips;
	showTip(tips, false);
}
void RegisterDialog::DelTipErr(TipErr te) {
	_tip_errs.remove(te);
	if (_tip_errs.empty()) {
		ui->err_Tip->clear();
		return;
	}
	showTip(_tip_errs.first(), false);
}

bool RegisterDialog::checkUserValid() {
	if (ui->user_Edit->text() == "") {
		AddTipErr(TipErr::TIP_USER_ERR, tr("用户名不能为空"));
		return false;
	}
	DelTipErr(TipErr::TIP_USER_ERR);
	return true;
}

bool RegisterDialog::checkEmailValid() {
	//验证邮箱的地址正则表达式
	auto email = ui->email_Edit->text();
	// 邮箱地址的正则表达式
	QRegularExpression regex(R"(^[a-zA-Z0-9_.+-]+@[a-zA-Z0-9-]+\.[a-zA-Z0-9-.]+$)");
	bool match = regex.match(email).hasMatch(); // 执行正则表达式匹配
	if (!match) {
		//提示邮箱不正确
		AddTipErr(TipErr::TIP_EMAIL_ERR, tr("邮箱地址不正确"));
		return false;
	}
	DelTipErr(TipErr::TIP_EMAIL_ERR);
	return true;
}

bool RegisterDialog::checkPassValid() {
	auto pass = ui->pass_Edit->text();
	auto confirm = ui->confirm_Edit->text();

	if (pass.length() < 6 || pass.length() > 15) {
		//提示长度不准确
		AddTipErr(TipErr::TIP_PWD_ERR, tr("密码长度应为6~15"));
		return false;
	}
	// 创建一个正则表达式对象，按照上述密码要求
	// 这个正则表达式解释：
	// ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
	QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
	bool match = regExp.match(pass).hasMatch();
	if (!match) {
		//提示字符非法
		AddTipErr(TipErr::TIP_PWD_ERR, tr("不能包含非法字符"));
		return false;;
	}
	DelTipErr(TipErr::TIP_PWD_ERR);

	if (pass != confirm) {
		//显示密码不匹配
		AddTipErr(TipErr::TIP_PWD_CONFIRM, tr("两次输入的密码不匹配"));
		return false;
	} else {
		DelTipErr(TipErr::TIP_PWD_CONFIRM);
	}

	return true;
}

bool RegisterDialog::checkConfirmValid() {
	auto pass = ui->pass_Edit->text();
	auto confirm = ui->confirm_Edit->text();

	if (confirm.length() < 6 || confirm.length() > 15) {
		//提示长度不准确
		AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("密码长度应为6~15"));
		return false;
	}
	// 创建一个正则表达式对象，按照上述密码要求
	// 这个正则表达式解释：
	// ^[a-zA-Z0-9!@#$%^&*]{6,15}$ 密码长度至少6，可以是字母、数字和特定的特殊字符
	QRegularExpression regExp("^[a-zA-Z0-9!@#$%^&*]{6,15}$");
	bool match = regExp.match(confirm).hasMatch();
	if (!match) {
		//提示字符非法
		AddTipErr(TipErr::TIP_CONFIRM_ERR, tr("不能包含非法字符"));
		return false;;
	}
	DelTipErr(TipErr::TIP_CONFIRM_ERR);

	if (pass != confirm) {
		//显示密码不匹配
		AddTipErr(TipErr::TIP_PWD_CONFIRM, tr("两次输入的密码不匹配"));
		return false;
	} else {
		DelTipErr(TipErr::TIP_PWD_CONFIRM);
	}

	return true;
}

bool RegisterDialog::checkVarifyValid() {
	auto pass = ui->verify_Edit->text();
	if (pass.length() != 4) {
		AddTipErr(TipErr::TIP_VARIFY_ERR, tr("请输入四位验证码"));
		return false;
	}
	DelTipErr(TipErr::TIP_VARIFY_ERR);
	return true;
}

void RegisterDialog::ChangeTipPage() {
	_countdown_timer->stop();
	ui->stackedWidget->setCurrentWidget(ui->page_2);
	// 启动定时器，设置间隔为1000毫秒（1秒）
	_countdown_timer->start(1000);
}


void RegisterDialog::on_sure_Btn_clicked() {
	if (ui->user_Edit->text() == "") {
		showTip(tr("用户名不能为空"), false);
		return;
	}
	if (ui->email_Edit->text() == "") {
		showTip(tr("邮箱不能为空"), false);
		return;
	}
	if (ui->pass_Edit->text() == "") {
		showTip(tr("密码不能为空"), false);
		return;
	}
	if (ui->confirm_Edit->text() == "") {
		showTip(tr("确认密码不能为空"), false);
		return;
	}
	if (ui->confirm_Edit->text() != ui->pass_Edit->text()) {
		showTip(tr("密码和确认密码不匹配"), false);
		return;
	}
	if (ui->verify_Edit->text() == "") {
		showTip(tr("验证码不能为空"), false);
		return;
	}
	//发送http请求注册用户
	QJsonObject json_obj;
	json_obj["user"] = ui->user_Edit->text();
	json_obj["email"] = ui->email_Edit->text();
	json_obj["passwd"] = xorString(ui->pass_Edit->text());
	json_obj["confirm"] = xorString(ui->confirm_Edit->text());
	json_obj["verifycode"] = ui->verify_Edit->text();
	HttpMgr::GetInstance()->postHttpReg(QUrl(gate_url_prefix + "/user_register"),
		json_obj, RegId::ID_REG_USER, Modules::REGISTERMOD);
}




void RegisterDialog::on_return_Btn_clicked()
{
    _countdown_timer->stop();
    emit sigSwitchLogin();
}


void RegisterDialog::on_cancel_Btn_clicked()
{
	_countdown_timer->stop();
	emit sigSwitchLogin();
}

