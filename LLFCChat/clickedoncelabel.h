#pragma once
#include <QLabel>
#include <QMouseEvent>

/******************************************************************************
 *
 * @file       clickedoncelabel.h
 * @brief      点击一次后直接跳转的label
 *
 * @author     Carpe_Diem
 * @date       2024/12/06
 * @history
 *****************************************************************************/
class ClickedOnceLabel : public QLabel {
	Q_OBJECT
public:
	ClickedOnceLabel(QWidget* parent = nullptr);
	virtual void mouseReleaseEvent(QMouseEvent* ev) override;
signals:
	void clicked(QString);
};

