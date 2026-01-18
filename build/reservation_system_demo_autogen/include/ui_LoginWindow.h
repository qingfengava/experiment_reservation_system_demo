/********************************************************************************
** Form generated from reading UI file 'LoginWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QLabel *labelTitle;
    QFormLayout *formLayout;
    QLabel *labelUserId;
    QLineEdit *lineEditUserId;
    QLabel *labelPassword;
    QLineEdit *lineEditPassword;
    QLabel *labelRole;
    QComboBox *comboRole;
    QPushButton *btnLogin;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QString::fromUtf8("LoginWindow"));
        LoginWindow->resize(420, 280);
        centralwidget = new QWidget(LoginWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        labelTitle = new QLabel(centralwidget);
        labelTitle->setObjectName(QString::fromUtf8("labelTitle"));
        labelTitle->setAlignment(Qt::AlignCenter);
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        labelTitle->setFont(font);

        verticalLayout->addWidget(labelTitle);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        labelUserId = new QLabel(centralwidget);
        labelUserId->setObjectName(QString::fromUtf8("labelUserId"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelUserId);

        lineEditUserId = new QLineEdit(centralwidget);
        lineEditUserId->setObjectName(QString::fromUtf8("lineEditUserId"));

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditUserId);

        labelPassword = new QLabel(centralwidget);
        labelPassword->setObjectName(QString::fromUtf8("labelPassword"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPassword);

        lineEditPassword = new QLineEdit(centralwidget);
        lineEditPassword->setObjectName(QString::fromUtf8("lineEditPassword"));
        lineEditPassword->setEchoMode(QLineEdit::Password);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPassword);

        labelRole = new QLabel(centralwidget);
        labelRole->setObjectName(QString::fromUtf8("labelRole"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelRole);

        comboRole = new QComboBox(centralwidget);
        comboRole->setObjectName(QString::fromUtf8("comboRole"));

        formLayout->setWidget(2, QFormLayout::FieldRole, comboRole);


        verticalLayout->addLayout(formLayout);

        btnLogin = new QPushButton(centralwidget);
        btnLogin->setObjectName(QString::fromUtf8("btnLogin"));
        btnLogin->setMinimumHeight(36);

        verticalLayout->addWidget(btnLogin);

        LoginWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(LoginWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        LoginWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(LoginWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        LoginWindow->setStatusBar(statusbar);

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QMainWindow *LoginWindow)
    {
        LoginWindow->setWindowTitle(QCoreApplication::translate("LoginWindow", "\345\256\236\351\252\214\351\242\204\347\272\246\347\263\273\347\273\237 - \347\231\273\345\275\225", nullptr));
        labelTitle->setText(QCoreApplication::translate("LoginWindow", "\345\256\236\351\252\214\351\242\204\347\272\246\347\263\273\347\273\237", nullptr));
        labelUserId->setText(QCoreApplication::translate("LoginWindow", "\350\264\246\345\217\267\357\274\232", nullptr));
        labelPassword->setText(QCoreApplication::translate("LoginWindow", "\345\257\206\347\240\201\357\274\232", nullptr));
        labelRole->setText(QCoreApplication::translate("LoginWindow", "\350\272\253\344\273\275\357\274\232", nullptr));
        btnLogin->setText(QCoreApplication::translate("LoginWindow", "\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H
