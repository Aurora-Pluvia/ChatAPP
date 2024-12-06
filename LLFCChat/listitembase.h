#pragma once
#include <QWidget>
#include "global.h"
/******************************************************************************
 *
 * @file       listitembase.h
 * @brief      列表中各个item的基类
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
class ListItemBase : public QWidget {
	Q_OBJECT
public:
	explicit ListItemBase(QWidget* parent = nullptr);
	void SetItemType(ListItemType itemType);
	ListItemType GetItemType();
protected:
	virtual void paintEvent(QPaintEvent* event) override;
private:
	ListItemType _itemType;
};

