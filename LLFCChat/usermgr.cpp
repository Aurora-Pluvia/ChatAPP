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

UserMgr::UserMgr()
{

}



