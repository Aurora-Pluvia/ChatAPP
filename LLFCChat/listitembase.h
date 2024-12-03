#pragma once
#include <QWidget>
#include "global.h"

class ListItemBase : public QWidget {
	Q_OBJECT
public:
	explicit ListItemBase(QWidget* parent = nullptr);
	void SetItemType(ListItemType itemType);
protected:
	virtual void paintEvent(QPaintEvent* event) override;
	ListItemType GetItemType();
private:
	ListItemType _itemType;
};

