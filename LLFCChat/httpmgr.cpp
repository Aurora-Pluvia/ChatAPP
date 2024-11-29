#include "httpmgr.h"

HttpMgr::~HttpMgr()
{

}

HttpMgr::HttpMgr() {
    connect(this, &HttpMgr::sig_http_finish, this, &HttpMgr::slot_http_finish);
}

void HttpMgr::postHttpReg(QUrl url, QJsonObject json, RegId reg_Id, Modules mod)
{
    QByteArray data = QJsonDocument(json).toJson();
    QNetworkRequest request(url);
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");
    //设置长度
    request.setHeader(QNetworkRequest::ContentLengthHeader, QByteArray::number(data.length()));
    auto self = shared_from_this();
    QNetworkReply* reply = _manager.post(request, data);//发送请求
    //reply发出finished信号，捕获self保证HttpMgr不会被释放
    connect(reply, &QNetworkReply::finished, [self, reply, reg_Id, mod]() {
        //处理错误情况
        if (reply->error() != QNetworkReply::NoError) {
            qDebug() << reply->errorString();
            //发送信号通知完成
            emit self->sig_http_finish(reg_Id, "", ErrorCodes::ERR_NETWORK, mod);
            reply->deleteLater();//稍后回收，防止还在调用
            return;
        }
        //无错误
        QString res = reply->readAll();
        //发送信号通知完成
        emit self->sig_http_finish(reg_Id, res, ErrorCodes::SUCCESS, mod);
		reply->deleteLater();
        return;
        });
}

void HttpMgr::slot_http_finish(RegId id, QString res, ErrorCodes err, Modules mod) {
    if (mod == Modules::REGISTERMOD) {
        //发送信号通知注册模块http的响应结束了
        emit sig_reg_mod_finish(id, res, err);
    }
    if (mod == Modules::RESETMOD) {
        //发送信号通知重置模块http响应结束
        emit sig_reset_mod_finish(id, res, err);
    }
    if(mod == Modules::LOGINMOD){
        //发送信号通知登录模块http响应结束
        emit sig_login_mod_finish(id, res, err);
    }
}
