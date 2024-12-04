#ifndef LOADINGDLG_H
#define LOADINGDLG_H

#include <QDialog>
/******************************************************************************
 *
 * @file       loadingdlg.h
 * @brief      加载框
 *
 * @author     Carpe_Diem
 * @date       2024/12/04
 * @history
 *****************************************************************************/
namespace Ui {
class LoadingDlg;
}

class LoadingDlg : public QDialog
{
    Q_OBJECT

public:
    explicit LoadingDlg(QWidget *parent = nullptr);
    ~LoadingDlg();

private:
    Ui::LoadingDlg *ui;
};

#endif // LOADINGDLG_H
