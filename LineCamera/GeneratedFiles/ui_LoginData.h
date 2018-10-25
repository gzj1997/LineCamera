/********************************************************************************
** Form generated from reading UI file 'LoginData.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINDATA_H
#define UI_LOGINDATA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginData
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QComboBox *comboBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *LoginData)
    {
        if (LoginData->objectName().isEmpty())
            LoginData->setObjectName(QStringLiteral("LoginData"));
        LoginData->resize(400, 300);
        gridLayoutWidget = new QWidget(LoginData);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(60, 60, 261, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 2, 0, 1, 1);

        comboBox = new QComboBox(gridLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        gridLayout->addWidget(comboBox, 0, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 3, 0, 1, 1);


        retranslateUi(LoginData);
        QObject::connect(pushButton, SIGNAL(clicked()), LoginData, SLOT(getproductname()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), LoginData, SLOT(newproduct()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), LoginData, SLOT(reject()));

        QMetaObject::connectSlotsByName(LoginData);
    } // setupUi

    void retranslateUi(QDialog *LoginData)
    {
        LoginData->setWindowTitle(QApplication::translate("LoginData", "LoginData", 0));
        pushButton_2->setText(QApplication::translate("LoginData", "cancel", 0));
        pushButton->setText(QApplication::translate("LoginData", "ok", 0));
        pushButton_3->setText(QApplication::translate("LoginData", "newproduct", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginData: public Ui_LoginData {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINDATA_H
