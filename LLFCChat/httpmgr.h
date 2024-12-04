#ifndef HTTPMGR_H
#define HTTPMGR_H

#include "singleton.h"
#include <QString>
#include <QUrl>
#include <QObject>
#include <QNetworkAccessManager>
#include <QJsonObject>
#include <QJsonDocument>

/******************************************************************************
 *
 * @file       httpmgr.h
 * @brief      收发http请求
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
//CRTP
class HttpMgr : public QObject, public Singleton<HttpMgr>, 
    public std::enable_shared_from_this<HttpMgr>
{
    Q_OBJECT;
public:
    ~HttpMgr();
    void postHttpReg(QUrl url, QJsonObject json, RegId reg_Id, Modules mod);//发送功能
private:
    friend class Singleton<HttpMgr>;//使父类能访问子类的构造函数
    HttpMgr();
    QNetworkAccessManager _manager;
private slots:
    void slot_http_finish(RegId id, QString res, ErrorCodes err, Modules mod);
signals:
    void sig_http_finish(RegId id, QString res, ErrorCodes err, Modules mod);//http请求信号
    void sig_reg_mod_finish(RegId id, QString res, ErrorCodes err);//注册模块http的响应结束
    void sig_reset_mod_finish(RegId id, QString res, ErrorCodes err);//重置模块http的响应结束
	void sig_login_mod_finish(RegId id, QString res, ErrorCodes err);//登录模块http的响应结束

};

#endif // HTTPMGR_H
