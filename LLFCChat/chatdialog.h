#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "global.h"
#include "statewidget.h"
#include "userdata.h"
#include <QListWidgetItem>

/******************************************************************************
 *
 * @file       chatdialog.h
 * @brief      聊天窗口
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class ChatDialog;
}

class ChatDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ChatDialog(QWidget *parent = nullptr);
    ~ChatDialog();
    void addChatUserList();
    void ClearLabelState(StateWidget* lb);
protected:
    bool eventFilter(QObject* watched, QEvent* event) override;
    void handleGlobalMousePress(QMouseEvent* event);
private:
    Ui::ChatDialog *ui;
    void ShowSearch(bool bsearch = false);
    void AddLBGroup(StateWidget* lb);//加入按钮组
	ChatUIMode _mode;//side_bar模式切换
	ChatUIMode _state;//chat_user_wid状态切换
	bool _b_loading;
    QList<StateWidget*> _lb_list;
	QMap<int, QListWidgetItem*> _chat_items_added;
	void SetSelectChatItem(int uid = 0);
	void SetSelectChatPage(int uid = 0);
    int _cur_chat_uid;
public slots:
    void slot_loading_chat_user();
    void slot_side_chat();
    void slot_side_contact();
    void slot_text_changed(const QString& str);
	void slot_apply_friend(std::shared_ptr<AddFriendApply> apply);
	void slot_add_auth_friend(std::shared_ptr<AuthInfo> auth_info);
	void slot_auth_rsp(std::shared_ptr<AuthRsp> auth_rsp);
	void slot_jump_chat_item(std::shared_ptr<SearchInfo> si);

};

#endif // CHATDIALOG_H
