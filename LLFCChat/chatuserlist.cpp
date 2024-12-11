#include "chatuserlist.h"
#include <QTimer>
#include <QCoreApplication>
#include "usermgr.h"

ChatUserList::ChatUserList(QWidget* parent) : QListWidget(parent), _load_pending(false) {
	Q_UNUSED(parent);
	//关闭默认的横向和纵向的滚动条
	this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
	// 安装事件过滤器
	this->viewport()->installEventFilter(this);
}

bool ChatUserList::eventFilter(QObject* watched, QEvent* event) {
	//检查事件是否是鼠标悬浮进入或离开目标区域
	if (watched == this->viewport()) {
		if (event->type() == QEvent::Enter) {
			//鼠标悬浮，显示滚动条
			this->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
		} else if (event->type() == QEvent::Leave) {
			//鼠标离开，隐藏滚动条
			this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
		}
	}

	//检查事件是否是鼠标滚轮事件
	if (watched == this->viewport() && event->type() == QEvent::Wheel) {
		QWheelEvent* wheelEvent = static_cast<QWheelEvent*>(event);
		int numDegrees = wheelEvent->angleDelta().y() / 8;//设置滚动度数
		int numSteps = numDegrees / 15;//设置步数

		//设置滚动幅度
		this->verticalScrollBar()->setValue(this->verticalScrollBar()->value() - numSteps);

		//检查是否滚动到底部
		QScrollBar* scrollBar = this->verticalScrollBar();
		int maxScrollValue = scrollBar->maximum();
		int currentValue = scrollBar->value();
		int pageSize = 10;//每页加载的联系人数量

		if (maxScrollValue - currentValue <= 0) {
			auto b_loaded = UserMgr::GetInstance()->IsLoadChatFin();
			if (b_loaded) {
				return true;
			}

			if (_load_pending) {
				return true;
			}
			// 滚动到底部，加载新的联系人
			qDebug() << "load more chat user";
			_load_pending = true;

			QTimer::singleShot(100, [this]() {
				_load_pending = false;
				QCoreApplication::quit(); // 完成后退出应用程序
				});
			//发送信号通知聊天界面加载更多聊天内容
			emit sig_loading_chat_user();
		}
		return true;//停止事件传递
	}
	return QListWidget::eventFilter(watched, event);//其他事件执行基类中的默认操作
}
