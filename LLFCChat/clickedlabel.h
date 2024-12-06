#ifndef CLICKEDLABEL_H
#define CLICKEDLABEL_H

#include <QLabel>
#include "global.h"
/******************************************************************************
 *
 * @file       clickedlabel.h
 * @brief      自定义可点击图标
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ClickedLabel : public QLabel
{
    Q_OBJECT
public:
    ClickedLabel(QWidget* parent);
	//重写鼠标事件
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	virtual void enterEvent(QEnterEvent* event) override;
	virtual void leaveEvent(QEvent* event) override;
	void SetState(QString normal = "", QString hover = "", QString press = "",
		QString select = "", QString select_hover = "", QString select_press = "");
	ClickLbState GetCurState();
	bool SetCurState(ClickLbState state);//设置当前状态
	void ResetNormalState();//重置正常状态
private:
	QString _normal;
	QString _normal_hover;
	QString _normal_press;

	QString _selected;
	QString _selected_hover;
	QString _selected_press;
	ClickLbState _curstate;
signals:
    void clicked(QString, ClickLbState);
};

#endif // CLICKEDLABEL_H
