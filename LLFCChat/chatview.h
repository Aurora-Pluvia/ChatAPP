#pragma once

#include <QScrollArea>
#include <QVBoxLayout>
#include <QTimer>
#include <QStyleOption>
#include <QPainter>
/******************************************************************************
 *
 * @file       chatview.h
 * @brief      手写聊天窗口中的聊天界面
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ChatView : public QWidget {
	Q_OBJECT
public:
	ChatView(QWidget* parent = Q_NULLPTR);
	void appendChatItem(QWidget* item);//尾插消息气泡item
	void prependChatItem(QWidget* item);//头插消息气泡item
	void insertChatItem(QWidget* before, QWidget* item);//中间插消息气泡item
	void removeAllItem();
protected:
	bool eventFilter(QObject* o, QEvent* e) override;
	void paintEvent(QPaintEvent* event) override;
private slots:
	void onVScrollBarMoved(int min, int max);
private:
	void initStyleSheet();
	//QWidget *m_pCenterWidget;
	QVBoxLayout* m_pVl;//垂直布局
	QScrollArea* m_pScrollArea;//滚动区域
	bool isAppended;//控制加载聊天记录的时间间隔

};

