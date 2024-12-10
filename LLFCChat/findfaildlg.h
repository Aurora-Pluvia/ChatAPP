#ifndef FINDFAILDLG_H
#define FINDFAILDLG_H

#include <QDialog>

/******************************************************************************
 *
 * @file       findfaildlg.h
 * @brief      查找失败对话框
 *
 * @author     Carpe_Diem
 * @date       2024/12/09
 * @history
 *****************************************************************************/
namespace Ui {
class FindFailDlg;
}

class FindFailDlg : public QDialog
{
    Q_OBJECT

public:
    explicit FindFailDlg(QWidget *parent = nullptr);
    ~FindFailDlg();
private:
    Ui::FindFailDlg *ui;
private slots:
    void on_fail_sure_btn_clicked();
};

#endif // FINDFAILDLG_H
