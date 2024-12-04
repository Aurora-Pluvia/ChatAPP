#pragma once
#include <QWidget>
#include <QGridLayout>
#include <QLabel>
#include "global.h"
class BubbleFrame;
/******************************************************************************
 *
 * @file       chatitembase.h
 * @brief      手动实现单挑聊天记录布局的基类
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ChatItemBase : public QWidget {
	Q_OBJECT
public:
	explicit ChatItemBase(ChatRole role, QWidget* parent = nullptr);
	void setUserName(const QString& name);
	void setUserIcon(const QPixmap& icon);
	void setWidget(QWidget* w);
private:
	ChatRole m_role;
	QLabel* m_pNameLabel;
	QLabel* m_pIconLabel;
	QWidget* m_pBubble;
};

