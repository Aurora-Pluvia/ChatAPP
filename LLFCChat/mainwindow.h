#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "logindialog.h"
#include "registerdialog.h"
#include "resetdialog.h"


/******************************************************************************
 *
 * @file       mainwindow.h
 * @brief      主窗口
 *
 * @author     Carpe_Diem
 * @date       2024/10/11
 * @history
 *****************************************************************************/


QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

public slots:
    void slotSwitchReg();//切换注册界面槽函数
    void slotSwitchLogin();//从注册界面转到登陆界面
    void slotSwitchReset();
    void slotSwitchLogin2();//从重置密码界面转到登陆界面
private:
    Ui::MainWindow *ui;
    LoginDialog *_login_dia;
    RegisterDialog * _reg_dia;
    ResetDialog* _reset_dia;
};
#endif // MAINWINDOW_H
