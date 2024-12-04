#ifndef CHATDIALOG_H
#define CHATDIALOG_H

#include <QDialog>
#include "global.h"
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
private:
    Ui::ChatDialog *ui;
    void ShowSearch(bool bsearch = false);
	ChatUIMode _mode;//side_bar模式切换
	ChatUIMode _state;//chat_user_wid状态切换
	bool _b_loading;
private slots:
    void slot_loading_chat_user();
};

#endif // CHATDIALOG_H
