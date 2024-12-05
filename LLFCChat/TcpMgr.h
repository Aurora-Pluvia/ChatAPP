﻿#ifndef TCPMGR_H
#define TCPMGR_H
#include <QTcpSocket>
#include "singleton.h"
#include "global.h"
#include <functional>
#include <QObject>
#include <QJsonArray>
#include "userdata.h"
/******************************************************************************
 *
 * @file       TcpMgr.h
 * @brief      用于与chatserver建立tcp长连接
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class TcpMgr : public QObject, public Singleton<TcpMgr>, 
	public std::enable_shared_from_this<TcpMgr> {
	Q_OBJECT
public:
	~TcpMgr();
private:
	friend class Singleton<TcpMgr>;
	TcpMgr();
	void initHandlers();
	void handleMsg(RegId id, int len, QByteArray data);
	QTcpSocket _socket;
	QString _host;
	uint16_t _port;
	QByteArray _buffer;
	bool _b_recv_pending;
	quint16 _message_id;
	quint16 _message_len;
	QMap<RegId, std::function<void(RegId id, int len, QByteArray data)>> _handlers;
public slots:
	void slot_tcp_connect(ServerInfo);
    void slot_send_data(RegId reqId, QString data);
signals:
	void sig_con_success(bool bsuccess);
	void sig_send_data(RegId reqId, QByteArray data);
	void sig_swich_chatdlg();
	void sig_login_failed(int);
	void sig_user_search(std::shared_ptr<SearchInfo>);
};

#endif // TCPMGR_H
