/********************************************************************************
** Form generated from reading UI file 'LineCamera.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LINECAMERA_H
#define UI_LINECAMERA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineCameraClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_3;
    QSpacerItem *horizontalSpacer;
    QLabel *label_2;
    QLineEdit *lineEdit;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LineCameraClass)
    {
        if (LineCameraClass->objectName().isEmpty())
            LineCameraClass->setObjectName(QStringLiteral("LineCameraClass"));
        LineCameraClass->resize(689, 391);
        centralWidget = new QWidget(LineCameraClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 50, 651, 131));
        gridLayoutWidget = new QWidget(centralWidget);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 220, 681, 111));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(110, 0, 501, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(horizontalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        horizontalLayout->addWidget(label_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        horizontalLayout->addWidget(label_2);

        lineEdit = new QLineEdit(centralWidget);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(520, 190, 113, 20));
        LineCameraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LineCameraClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 689, 23));
        LineCameraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LineCameraClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LineCameraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LineCameraClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LineCameraClass->setStatusBar(statusBar);

        retranslateUi(LineCameraClass);
        QObject::connect(pushButton_4, SIGNAL(clicked()), LineCameraClass, SLOT(showimage()));
        QObject::connect(pushButton, SIGNAL(clicked()), LineCameraClass, SLOT(btnopen()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), LineCameraClass, SLOT(btnstop()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), LineCameraClass, SLOT(btnclose()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), LineCameraClass, SLOT(linkdevice()));

        QMetaObject::connectSlotsByName(LineCameraClass);
    } // setupUi

    void retranslateUi(QMainWindow *LineCameraClass)
    {
        LineCameraClass->setWindowTitle(QApplication::translate("LineCameraClass", "LineCamera", 0));
        label->setText(QString());
        pushButton_5->setText(QApplication::translate("LineCameraClass", "link", 0));
        pushButton_2->setText(QApplication::translate("LineCameraClass", "stop", 0));
        pushButton_4->setText(QApplication::translate("LineCameraClass", "show", 0));
        pushButton->setText(QApplication::translate("LineCameraClass", "grap", 0));
        pushButton_3->setText(QApplication::translate("LineCameraClass", "close", 0));
        label_3->setText(QApplication::translate("LineCameraClass", "TextLabel", 0));
        label_2->setText(QApplication::translate("LineCameraClass", "TextLabel", 0));
    } // retranslateUi

};

namespace Ui {
    class LineCameraClass: public Ui_LineCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECAMERA_H
