#ifndef CLICKEDBTN_H
#define CLICKEDBTN_H

#include <QPushButton>
/******************************************************************************
 *
 * @file       clickedbtn.h
 * @brief      自定义可点击按钮
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ClickedBtn : public QPushButton
{
    Q_OBJECT
public:
    ClickedBtn(QWidget* parent = nullptr);
    ~ClickedBtn();
    void SetState(QString normal, QString hover, QString press);

protected:
	virtual void enterEvent(QEnterEvent* event) override;
	virtual void leaveEvent(QEvent* event) override;
	virtual void mousePressEvent(QMouseEvent* event) override;
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
private:
	QString _normal;
	QString _hover;
	QString _press;
};

#endif // CLICKEDBTN_H
