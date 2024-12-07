#ifndef GROUPTIPITEM_H
#define GROUPTIPITEM_H

#include <QWidget>
#include "listitembase.h"

/******************************************************************************
 *
 * @file       grouptipitem.h
 * @brief      "新的朋友"
 *
 * @author     Carpe_Diem
 * @date       2024/12/07
 * @history
 *****************************************************************************/
namespace Ui {
class GroupTipItem;
}

class GroupTipItem : public ListItemBase
{
    Q_OBJECT

public:
    explicit GroupTipItem(QWidget *parent = nullptr);
    ~GroupTipItem();
	QSize sizeHint() const override;
	void SetGroupTip(QString str);
private:
	QString _tip;
	Ui::GroupTipItem* ui;
};

#endif // GROUPTIPITEM_H
