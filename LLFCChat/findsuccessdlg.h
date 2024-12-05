#ifndef FINDSUCCESSDLG_H
#define FINDSUCCESSDLG_H

#include <QDialog>

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

private:
    Ui::FindSuccessDlg *ui;
};

#endif // FINDSUCCESSDLG_H
