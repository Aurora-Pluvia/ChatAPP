/********************************************************************************
** Form generated from reading UI file 'registerdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_REGISTERDIALOG_H
#define UI_REGISTERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "clickedlabel.h"
#include "timerbtn.h"

QT_BEGIN_NAMESPACE

class Ui_RegisterDialog
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_3;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QLabel *err_Tip;
    QHBoxLayout *horizontalLayout;
    QLabel *user_Label;
    QLineEdit *user_Edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_Label;
    QLineEdit *email_Edit;
    QHBoxLayout *horizontalLayout_3;
    QLabel *pass_Label;
    QLineEdit *pass_Edit;
    ClickedLabel *pass_Visible;
    QHBoxLayout *horizontalLayout_5;
    QLabel *confirm_Label;
    QLineEdit *confirm_Edit;
    ClickedLabel *confirm_Visible;
    QHBoxLayout *horizontalLayout_6;
    QLabel *verify_Label;
    QLineEdit *verify_Edit;
    TimerBtn *get_Code;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *sure_Btn;
    QPushButton *cancel_Btn;
    QSpacerItem *verticalSpacer_2;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QSpacerItem *verticalSpacer_5;
    QLabel *tip_Lb;
    QLabel *tip2_Lb;
    QSpacerItem *verticalSpacer_4;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_8;
    QSpacerItem *horizontalSpacer;
    QPushButton *return_Btn;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer_6;

    void setupUi(QDialog *RegisterDialog)
    {
        if (RegisterDialog->objectName().isEmpty())
            RegisterDialog->setObjectName("RegisterDialog");
        RegisterDialog->resize(300, 500);
        RegisterDialog->setMinimumSize(QSize(300, 500));
        RegisterDialog->setMaximumSize(QSize(300, 500));
        verticalLayout_2 = new QVBoxLayout(RegisterDialog);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        stackedWidget = new QStackedWidget(RegisterDialog);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_3 = new QVBoxLayout(page);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        widget = new QWidget(page);
        widget->setObjectName("widget");
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        err_Tip = new QLabel(widget);
        err_Tip->setObjectName("err_Tip");
        err_Tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_4->addWidget(err_Tip);


        verticalLayout_3->addWidget(widget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        user_Label = new QLabel(page);
        user_Label->setObjectName("user_Label");
        user_Label->setMinimumSize(QSize(0, 25));
        user_Label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_Label);

        user_Edit = new QLineEdit(page);
        user_Edit->setObjectName("user_Edit");
        user_Edit->setMinimumSize(QSize(0, 25));
        user_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_Edit);


        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        email_Label = new QLabel(page);
        email_Label->setObjectName("email_Label");
        email_Label->setMinimumSize(QSize(0, 25));
        email_Label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_Label);

        email_Edit = new QLineEdit(page);
        email_Edit->setObjectName("email_Edit");
        email_Edit->setMinimumSize(QSize(0, 25));
        email_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_Edit);


        verticalLayout_3->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        pass_Label = new QLabel(page);
        pass_Label->setObjectName("pass_Label");
        pass_Label->setMinimumSize(QSize(0, 25));
        pass_Label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(pass_Label);

        pass_Edit = new QLineEdit(page);
        pass_Edit->setObjectName("pass_Edit");
        pass_Edit->setMinimumSize(QSize(0, 25));
        pass_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(pass_Edit);

        pass_Visible = new ClickedLabel(page);
        pass_Visible->setObjectName("pass_Visible");
        pass_Visible->setMinimumSize(QSize(20, 20));
        pass_Visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_3->addWidget(pass_Visible);


        verticalLayout_3->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        confirm_Label = new QLabel(page);
        confirm_Label->setObjectName("confirm_Label");
        confirm_Label->setMinimumSize(QSize(0, 25));
        confirm_Label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(confirm_Label);

        confirm_Edit = new QLineEdit(page);
        confirm_Edit->setObjectName("confirm_Edit");
        confirm_Edit->setMinimumSize(QSize(0, 25));
        confirm_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(confirm_Edit);

        confirm_Visible = new ClickedLabel(page);
        confirm_Visible->setObjectName("confirm_Visible");
        confirm_Visible->setMinimumSize(QSize(20, 20));
        confirm_Visible->setMaximumSize(QSize(20, 20));

        horizontalLayout_5->addWidget(confirm_Visible);


        verticalLayout_3->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        verify_Label = new QLabel(page);
        verify_Label->setObjectName("verify_Label");
        verify_Label->setMinimumSize(QSize(0, 25));
        verify_Label->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(verify_Label);

        verify_Edit = new QLineEdit(page);
        verify_Edit->setObjectName("verify_Edit");
        verify_Edit->setMinimumSize(QSize(0, 25));
        verify_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(verify_Edit);

        get_Code = new TimerBtn(page);
        get_Code->setObjectName("get_Code");
        get_Code->setMinimumSize(QSize(0, 25));
        get_Code->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_6->addWidget(get_Code);


        verticalLayout_3->addLayout(horizontalLayout_6);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        sure_Btn = new QPushButton(page);
        sure_Btn->setObjectName("sure_Btn");
        sure_Btn->setMinimumSize(QSize(0, 25));
        sure_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(sure_Btn);

        cancel_Btn = new QPushButton(page);
        cancel_Btn->setObjectName("cancel_Btn");
        cancel_Btn->setMinimumSize(QSize(0, 25));
        cancel_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_7->addWidget(cancel_Btn);


        verticalLayout_3->addLayout(horizontalLayout_7);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_5);

        tip_Lb = new QLabel(page_2);
        tip_Lb->setObjectName("tip_Lb");
        tip_Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip_Lb);

        tip2_Lb = new QLabel(page_2);
        tip2_Lb->setObjectName("tip2_Lb");
        tip2_Lb->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_5->addWidget(tip2_Lb);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_4);

        widget_2 = new QWidget(page_2);
        widget_2->setObjectName("widget_2");
        horizontalLayout_8 = new QHBoxLayout(widget_2);
        horizontalLayout_8->setObjectName("horizontalLayout_8");
        horizontalSpacer = new QSpacerItem(73, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer);

        return_Btn = new QPushButton(widget_2);
        return_Btn->setObjectName("return_Btn");
        return_Btn->setMinimumSize(QSize(0, 25));
        return_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_8->addWidget(return_Btn);

        horizontalSpacer_2 = new QSpacerItem(73, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_8->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(widget_2);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_6);

        stackedWidget->addWidget(page_2);

        verticalLayout->addWidget(stackedWidget);


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(RegisterDialog);

        stackedWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(RegisterDialog);
    } // setupUi

    void retranslateUi(QDialog *RegisterDialog)
    {
        RegisterDialog->setWindowTitle(QCoreApplication::translate("RegisterDialog", "Dialog", nullptr));
        err_Tip->setText(QCoreApplication::translate("RegisterDialog", "\351\224\231\350\257\257\346\217\220\347\244\272", nullptr));
        user_Label->setText(QCoreApplication::translate("RegisterDialog", "\347\224\250\346\210\267\357\274\232", nullptr));
        email_Label->setText(QCoreApplication::translate("RegisterDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        pass_Label->setText(QCoreApplication::translate("RegisterDialog", "\345\257\206\347\240\201\357\274\232", nullptr));
        pass_Visible->setText(QString());
        confirm_Label->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244\357\274\232", nullptr));
        confirm_Visible->setText(QString());
        verify_Label->setText(QCoreApplication::translate("RegisterDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        get_Code->setText(QCoreApplication::translate("RegisterDialog", "\350\216\267\345\217\226\351\252\214\350\257\201\347\240\201", nullptr));
        sure_Btn->setText(QCoreApplication::translate("RegisterDialog", "\347\241\256\350\256\244", nullptr));
        cancel_Btn->setText(QCoreApplication::translate("RegisterDialog", "\345\217\226\346\266\210", nullptr));
        tip_Lb->setText(QCoreApplication::translate("RegisterDialog", "\346\263\250\345\206\214\346\210\220\345\212\237\357\274\2145\347\247\222\345\220\216\350\207\252\345\212\250\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        tip2_Lb->setText(QCoreApplication::translate("RegisterDialog", "\347\202\271\345\207\273\350\277\224\345\233\236\346\214\211\351\222\256\347\233\264\346\216\245\350\277\224\345\233\236\347\231\273\351\231\206\347\225\214\351\235\242", nullptr));
        return_Btn->setText(QCoreApplication::translate("RegisterDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class RegisterDialog: public Ui_RegisterDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_REGISTERDIALOG_H
