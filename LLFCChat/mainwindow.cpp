#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "resetdialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //创建登陆界面对象
    _login_dia = new LoginDialog(this);
    _login_dia->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dia);
    //_login_dia->show();

    //创建注册界面对象
    connect(_login_dia, &LoginDialog::signalSwitchRegister, this, &MainWindow::slotSwitchReg);

	//连接登录界面忘记密码信号
	connect(_login_dia, &LoginDialog::signalSwitchReset, this, &MainWindow::slotSwitchReset);
}

MainWindow::~MainWindow()
{
    delete ui;
    // if(_login_dia){
    //     delete _login_dia;
    //     _login_dia = nullptr;
    // }
    // if(_reg_dia){
    //     delete _reg_dia;
    //     _reg_dia = nullptr;
    // }
}

//切换注册界面槽函数
void MainWindow::slotSwitchReg()
{
    _reg_dia = new RegisterDialog(this);
    _reg_dia->hide();

    //设置窗口，使其能嵌入主窗口，CustomizeWindowHint: 自定义窗口标记，FramelessWindowHint: 取消边框
    _reg_dia->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);

    //连接注册界面返回登录信号
    connect(_reg_dia, &RegisterDialog::sigSwitchLogin, this, &MainWindow::slotSwitchLogin);


    setCentralWidget(_reg_dia);
    _login_dia->hide();
    _reg_dia->show();
}

//从注册界面返回登录界面
void MainWindow::slotSwitchLogin()
{
    //创建一个CentralWidget, 并将其设置为MainWindow的中心部件
    _login_dia = new LoginDialog(this);
    _login_dia->setWindowFlags(Qt::CustomizeWindowHint|Qt::FramelessWindowHint);
    setCentralWidget(_login_dia);
    _reg_dia->hide();
    _login_dia->show();
    //连接登录界面注册信号
    connect(_login_dia, &LoginDialog::signalSwitchRegister, this, &MainWindow::slotSwitchReg);
    //连接登录界面忘记密码信号
    connect(_login_dia, &LoginDialog::signalSwitchReset, this, &MainWindow::slotSwitchReset);
}

void MainWindow::slotSwitchReset() {
	//创建一个CentralWidget, 并将其设置为MainWindow的中心部件
	_reset_dia = new ResetDialog(this);
	_reset_dia->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_reset_dia);
	_login_dia->hide();
	_reset_dia->show();
	//注册返回登录信号和槽函数
	connect(_reset_dia, &ResetDialog::signalSwitchLogin, this, &MainWindow::slotSwitchLogin2);
}

void MainWindow::slotSwitchLogin2() {
	//创建一个CentralWidget, 并将其设置为MainWindow的中心部件
	_login_dia = new LoginDialog(this);
    _login_dia->setWindowFlags(Qt::CustomizeWindowHint | Qt::FramelessWindowHint);
	setCentralWidget(_login_dia);
	_reset_dia->hide();
    _login_dia->show();
	//连接登录界面忘记密码信号
	connect(_login_dia, &LoginDialog::signalSwitchReset, this, &MainWindow::slotSwitchReset);
	//连接登录界面注册信号
	connect(_login_dia, &LoginDialog::signalSwitchRegister, this, &MainWindow::slotSwitchReg);
}
