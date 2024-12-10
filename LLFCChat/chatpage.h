#ifndef CHATPAGE_H
#define CHATPAGE_H

#include <QWidget>
#include "userdata.h"

/******************************************************************************
 *
 * @file       chatpage.h
 * @brief      聊天界面的页面绘制
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class ChatPage;
}

class ChatPage : public QWidget
{
    Q_OBJECT

public:
    explicit ChatPage(QWidget *parent = nullptr);
    ~ChatPage();
	void SetUserInfo(std::shared_ptr<UserInfo> user_info);
	void AppendChatMsg(std::shared_ptr<TextChatData> msg);

protected:
    void paintEvent(QPaintEvent* event);//绘制样式
private slots:
    void on_send_btn_clicked();

private:
    Ui::ChatPage *ui;
	std::shared_ptr<UserInfo> _user_info;

};

#endif // CHATPAGE_H
