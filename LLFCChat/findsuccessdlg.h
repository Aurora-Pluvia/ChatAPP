#ifndef FINDSUCCESSDLG_H
#define FINDSUCCESSDLG_H

#include <QDialog>
#include <memory>
#include "userdata.h"

/******************************************************************************
 *
 * @file       findsuccessdlg.h
 * @brief      成功找到目标用户的提示框
 *
 * @author     Carpe_Diem
 * @date       2024/12/05
 * @history
 *****************************************************************************/
namespace Ui {
class FindSuccessDlg;
}

class FindSuccessDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FindSuccessDlg(QWidget *parent = nullptr);
    ~FindSuccessDlg();
	void SetSearchInfo(std::shared_ptr<SearchInfo> si);

private:
	Ui::FindSuccessDlg* ui;
	QWidget* _parent;
	std::shared_ptr<SearchInfo> _si;

private slots:
	void on_add_friend_btn_clicked();
};

#endif // FINDSUCCESSDLG_H
