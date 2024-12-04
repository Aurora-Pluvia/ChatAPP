#ifndef TIMERBTN_H
#define TIMERBTN_H

#include <QPushButton>
#include <QTimer>
/******************************************************************************
 *
 * @file       timerbtn.h
 * @brief      按钮点击后进入不可用状态并倒计时
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class TimerBtn : public QPushButton {
public:
	TimerBtn(QWidget* parent = nullptr);
	~TimerBtn();
	// 重写mouseReleaseEvent
	virtual void mouseReleaseEvent(QMouseEvent* e) override;
private:
	QTimer* _timer;
	int _counter;
};

#endif // TIMERBTN_H
