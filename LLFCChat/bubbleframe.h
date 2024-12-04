#pragma once
#include <QFrame>
#include "global.h"
#include <QHBoxLayout>

/******************************************************************************
 *
 * @file       bubbleframe.h
 * @brief      聊天气泡
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class BubbleFrame : public QFrame {
	Q_OBJECT
public:
	BubbleFrame(ChatRole role, QWidget* parent = nullptr);
	void setMargin(int margin);
	//inline int margin(){return margin;}
	void setWidget(QWidget* w);
protected:
	void paintEvent(QPaintEvent* e);
private:
	QHBoxLayout* m_pHLayout;
	ChatRole m_role;
	int m_margin;
};

