/********************************************************************************
** Form generated from reading UI file 'resetdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RESETDIALOG_H
#define UI_RESETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <timerbtn.h>

QT_BEGIN_NAMESPACE

class Ui_ResetDialog
{
public:
    QVBoxLayout *verticalLayout;
    QSpacerItem *verticalSpacer;
    QLabel *err_Tip;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *user_Lb;
    QLineEdit *user_Edit;
    QWidget *widget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *email_Lb;
    QLineEdit *email_Edit;
    QWidget *widget_3;
    QHBoxLayout *horizontalLayout_3;
    QLabel *verify_Lb;
    QLineEdit *verify_Edit;
    TimerBtn *verify_Btn;
    QWidget *widget_4;
    QHBoxLayout *horizontalLayout_4;
    QLabel *pwd_Lb;
    QLineEdit *pwd_Edit;
    QSpacerItem *verticalSpacer_2;
    QWidget *widget_5;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *sure_Btn;
    QPushButton *return_Btn;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QDialog *ResetDialog)
    {
        if (ResetDialog->objectName().isEmpty())
            ResetDialog->setObjectName("ResetDialog");
        ResetDialog->resize(354, 538);
        verticalLayout = new QVBoxLayout(ResetDialog);
        verticalLayout->setObjectName("verticalLayout");
        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer);

        err_Tip = new QLabel(ResetDialog);
        err_Tip->setObjectName("err_Tip");
        err_Tip->setMinimumSize(QSize(0, 25));
        err_Tip->setMaximumSize(QSize(16777215, 25));
        err_Tip->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(err_Tip);

        widget = new QWidget(ResetDialog);
        widget->setObjectName("widget");
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName("horizontalLayout");
        user_Lb = new QLabel(widget);
        user_Lb->setObjectName("user_Lb");
        user_Lb->setMinimumSize(QSize(0, 25));
        user_Lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_Lb);

        user_Edit = new QLineEdit(widget);
        user_Edit->setObjectName("user_Edit");
        user_Edit->setMinimumSize(QSize(0, 25));
        user_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout->addWidget(user_Edit);


        verticalLayout->addWidget(widget);

        widget_2 = new QWidget(ResetDialog);
        widget_2->setObjectName("widget_2");
        horizontalLayout_2 = new QHBoxLayout(widget_2);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        email_Lb = new QLabel(widget_2);
        email_Lb->setObjectName("email_Lb");
        email_Lb->setMinimumSize(QSize(48, 25));
        email_Lb->setMaximumSize(QSize(48, 25));

        horizontalLayout_2->addWidget(email_Lb);

        email_Edit = new QLineEdit(widget_2);
        email_Edit->setObjectName("email_Edit");
        email_Edit->setMinimumSize(QSize(0, 25));
        email_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_2->addWidget(email_Edit);


        verticalLayout->addWidget(widget_2);

        widget_3 = new QWidget(ResetDialog);
        widget_3->setObjectName("widget_3");
        horizontalLayout_3 = new QHBoxLayout(widget_3);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        verify_Lb = new QLabel(widget_3);
        verify_Lb->setObjectName("verify_Lb");
        verify_Lb->setMinimumSize(QSize(0, 25));
        verify_Lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verify_Lb);

        verify_Edit = new QLineEdit(widget_3);
        verify_Edit->setObjectName("verify_Edit");
        verify_Edit->setMinimumSize(QSize(0, 25));
        verify_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verify_Edit);

        verify_Btn = new TimerBtn(widget_3);
        verify_Btn->setObjectName("verify_Btn");
        verify_Btn->setMinimumSize(QSize(0, 25));
        verify_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_3->addWidget(verify_Btn);


        verticalLayout->addWidget(widget_3);

        widget_4 = new QWidget(ResetDialog);
        widget_4->setObjectName("widget_4");
        horizontalLayout_4 = new QHBoxLayout(widget_4);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        pwd_Lb = new QLabel(widget_4);
        pwd_Lb->setObjectName("pwd_Lb");
        pwd_Lb->setMinimumSize(QSize(0, 25));
        pwd_Lb->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwd_Lb);

        pwd_Edit = new QLineEdit(widget_4);
        pwd_Edit->setObjectName("pwd_Edit");
        pwd_Edit->setMinimumSize(QSize(0, 25));
        pwd_Edit->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_4->addWidget(pwd_Edit);


        verticalLayout->addWidget(widget_4);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_2);

        widget_5 = new QWidget(ResetDialog);
        widget_5->setObjectName("widget_5");
        horizontalLayout_5 = new QHBoxLayout(widget_5);
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        sure_Btn = new QPushButton(widget_5);
        sure_Btn->setObjectName("sure_Btn");
        sure_Btn->setMinimumSize(QSize(0, 25));
        sure_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(sure_Btn);

        return_Btn = new QPushButton(widget_5);
        return_Btn->setObjectName("return_Btn");
        return_Btn->setMinimumSize(QSize(0, 25));
        return_Btn->setMaximumSize(QSize(16777215, 25));

        horizontalLayout_5->addWidget(return_Btn);


        verticalLayout->addWidget(widget_5);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout->addItem(verticalSpacer_3);


        retranslateUi(ResetDialog);

        QMetaObject::connectSlotsByName(ResetDialog);
    } // setupUi

    void retranslateUi(QDialog *ResetDialog)
    {
        ResetDialog->setWindowTitle(QCoreApplication::translate("ResetDialog", "Dialog", nullptr));
        err_Tip->setText(QString());
        user_Lb->setText(QCoreApplication::translate("ResetDialog", "\347\224\250\346\210\267\345\220\215\357\274\232", nullptr));
        email_Lb->setText(QCoreApplication::translate("ResetDialog", "\351\202\256\347\256\261\357\274\232", nullptr));
        verify_Lb->setText(QCoreApplication::translate("ResetDialog", "\351\252\214\350\257\201\347\240\201\357\274\232", nullptr));
        verify_Btn->setText(QCoreApplication::translate("ResetDialog", "\350\216\267\345\217\226", nullptr));
        pwd_Lb->setText(QCoreApplication::translate("ResetDialog", "\346\226\260\345\257\206\347\240\201\357\274\232", nullptr));
        sure_Btn->setText(QCoreApplication::translate("ResetDialog", "\347\241\256\350\256\244", nullptr));
        return_Btn->setText(QCoreApplication::translate("ResetDialog", "\350\277\224\345\233\236", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ResetDialog: public Ui_ResetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RESETDIALOG_H
