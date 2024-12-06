#include "usermgr.h"

UserMgr::~UserMgr()
{

}


void UserMgr::SetToken(QString token)
{
    _token = token;
}

void UserMgr::SetName(QString name)
{
    _name = name;
}

void UserMgr::SetUid(int uid)
{
    _uid = uid;
}

int UserMgr::GetUid() {
    return _uid;
}

QString UserMgr::GetName() {
    return _name;
}

UserMgr::UserMgr()
{

}



