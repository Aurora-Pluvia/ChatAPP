#pragma once
#include <QTextEdit>
#include "BubbleFrame.h"
#include <QHBoxLayout>

/******************************************************************************
 *
 * @file       textbubble.h
 * @brief      气泡中的文本
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class TextBubble : public BubbleFrame {
	Q_OBJECT
public:
	TextBubble(ChatRole role, const QString& text, QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* o, QEvent* e);
private:
	void adjustTextHeight();
	void setPlainText(const QString& text);
	void initStyleSheet();
private:
	QTextEdit* m_pTextEdit;
};

