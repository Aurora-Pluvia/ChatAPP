#pragma once

#include <QListWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
#include <QObject>
/******************************************************************************
 *
 * @file       chatuserlist.h
 * @brief      聊天用户列表
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ChatUserList : public QListWidget {
	Q_OBJECT
public:
	ChatUserList(QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;//设置滚动条
private:
	bool _load_pending;
signals:
	void sig_loading_chat_user();
};

