#pragma once
#include <QString>
#include <memory>
#include <QJsonArray>
#include <vector>
#include <QJsonObject>

/******************************************************************************
 *
 * @file       userdata.h
 * @brief      用户数据
 *
 * @author     Carpe_Diem
 * @date       2024/12/05
 * @history
 *****************************************************************************/
class SearchInfo {
public:
	SearchInfo(int uid, QString name, QString nick, QString desc, int sex);
	int _uid;
	QString _name;
	QString _nick;
	QString _desc;
	int _sex;
};
