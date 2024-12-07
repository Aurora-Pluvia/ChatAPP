#pragma once
#include <QListWidget>
#include <QEvent>

/******************************************************************************
 *
 * @file       applyfriendlist.h
 * @brief      好友申请列表
 *
 * @author     Carpe_Diem
 * @date       2024/12/07
 * @history
 *****************************************************************************/
class ApplyFriendList : public QListWidget {
	Q_OBJECT
public:
	ApplyFriendList(QWidget* parent = nullptr);
protected:
	bool eventFilter(QObject* watched, QEvent* event) override;

private slots:

signals:
	void sig_show_search(bool);
};

