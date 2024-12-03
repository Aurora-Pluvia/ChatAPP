#pragma once

#include <QListWidget>
#include <QWheelEvent>
#include <QEvent>
#include <QScrollBar>
#include <QDebug>
#include <QObject>

class ChatUserList : public QListWidget {
	Q_OBJECT
public:
	ChatUserList(QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;//ÉèÖÃ¹ö¶¯Ìõ
private:
	bool _load_pending;
signals:
	void sig_loading_chat_user();
};

