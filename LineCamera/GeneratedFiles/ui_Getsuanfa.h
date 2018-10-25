/********************************************************************************
** Form generated from reading UI file 'Getsuanfa.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GETSUANFA_H
#define UI_GETSUANFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Getsuanfa
{
public:
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;

    void setupUi(QDialog *Getsuanfa)
    {
        if (Getsuanfa->objectName().isEmpty())
            Getsuanfa->setObjectName(QStringLiteral("Getsuanfa"));
        Getsuanfa->resize(400, 300);
        gridLayoutWidget = new QWidget(Getsuanfa);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(30, 60, 321, 181));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 1, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 2, 0, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 1, 1, 1);


        retranslateUi(Getsuanfa);
        QObject::connect(pushButton, SIGNAL(clicked()), Getsuanfa, SLOT(suanfa1()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), Getsuanfa, SLOT(accept()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), Getsuanfa, SLOT(reject()));

        QMetaObject::connectSlotsByName(Getsuanfa);
    } // setupUi

    void retranslateUi(QDialog *Getsuanfa)
    {
        Getsuanfa->setWindowTitle(QApplication::translate("Getsuanfa", "Getsuanfa", 0));
        pushButton->setText(QApplication::translate("Getsuanfa", "suanfa1", 0));
        pushButton_2->setText(QApplication::translate("Getsuanfa", "PushButton", 0));
        pushButton_3->setText(QApplication::translate("Getsuanfa", "PushButton", 0));
        pushButton_4->setText(QApplication::translate("Getsuanfa", "PushButton", 0));
        pushButton_5->setText(QApplication::translate("Getsuanfa", "ok", 0));
        pushButton_6->setText(QApplication::translate("Getsuanfa", "reject", 0));
    } // retranslateUi

};

namespace Ui {
    class Getsuanfa: public Ui_Getsuanfa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GETSUANFA_H
