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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LineCameraClass
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_9;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_3;
    QPushButton *pushButton_10;
    QLabel *label_4;
    QLineEdit *lineEdit_4;
    QLabel *label_5;
    QLineEdit *lineEdit_3;
    QLabel *label_6;
    QLineEdit *lineEdit_2;
    QRadioButton *radioButton;
    QLabel *label_7;
    QLineEdit *lineEdit;
    QGridLayout *gridLayout;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_9;
    QPushButton *pushButton;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *LineCameraClass)
    {
        if (LineCameraClass->objectName().isEmpty())
            LineCameraClass->setObjectName(QStringLiteral("LineCameraClass"));
        LineCameraClass->resize(1330, 752);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/LineCamera/Resources/\345\205\254\345\217\270LOG.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        LineCameraClass->setWindowIcon(icon);
        centralWidget = new QWidget(LineCameraClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QFont font;
        font.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font.setPointSize(14);
        font.setBold(true);
        font.setItalic(false);
        font.setWeight(75);
        centralWidget->setFont(font);
        verticalLayoutWidget_2 = new QWidget(centralWidget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(10, 470, 1311, 231));
        verticalLayout_5 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setContentsMargins(11, 11, 11, 11);
        verticalLayout_5->setObjectName(QStringLiteral("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        horizontalLayout_2->setContentsMargins(0, -1, -1, -1);
        label_9 = new QLabel(verticalLayoutWidget_2);
        label_9->setObjectName(QStringLiteral("label_9"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("\346\245\267\344\275\223"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        label_9->setFont(font1);

        horizontalLayout_2->addWidget(label_9);

        comboBox = new QComboBox(verticalLayoutWidget_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setFont(font1);

        horizontalLayout_2->addWidget(comboBox);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_3);

        pushButton_10 = new QPushButton(verticalLayoutWidget_2);
        pushButton_10->setObjectName(QStringLiteral("pushButton_10"));

        horizontalLayout_2->addWidget(pushButton_10);

        label_4 = new QLabel(verticalLayoutWidget_2);
        label_4->setObjectName(QStringLiteral("label_4"));

        horizontalLayout_2->addWidget(label_4);

        lineEdit_4 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        horizontalLayout_2->addWidget(lineEdit_4);

        label_5 = new QLabel(verticalLayoutWidget_2);
        label_5->setObjectName(QStringLiteral("label_5"));

        horizontalLayout_2->addWidget(label_5);

        lineEdit_3 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        horizontalLayout_2->addWidget(lineEdit_3);

        label_6 = new QLabel(verticalLayoutWidget_2);
        label_6->setObjectName(QStringLiteral("label_6"));

        horizontalLayout_2->addWidget(label_6);

        lineEdit_2 = new QLineEdit(verticalLayoutWidget_2);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        horizontalLayout_2->addWidget(lineEdit_2);

        radioButton = new QRadioButton(verticalLayoutWidget_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));
        radioButton->setAutoExclusive(false);

        horizontalLayout_2->addWidget(radioButton);

        label_7 = new QLabel(verticalLayoutWidget_2);
        label_7->setObjectName(QStringLiteral("label_7"));

        horizontalLayout_2->addWidget(label_7);

        lineEdit = new QLineEdit(verticalLayoutWidget_2);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));

        horizontalLayout_2->addWidget(lineEdit);


        verticalLayout_5->addLayout(horizontalLayout_2);

        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, -1, -1, -1);
        pushButton_4 = new QPushButton(verticalLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_3 = new QPushButton(verticalLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(verticalLayoutWidget_2);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_2 = new QPushButton(verticalLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_6 = new QPushButton(verticalLayoutWidget_2);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 2, 0, 1, 1);

        pushButton_7 = new QPushButton(verticalLayoutWidget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout->addWidget(pushButton_7, 2, 1, 1, 1);

        pushButton_8 = new QPushButton(verticalLayoutWidget_2);
        pushButton_8->setObjectName(QStringLiteral("pushButton_8"));

        gridLayout->addWidget(pushButton_8, 1, 2, 1, 1);

        pushButton_9 = new QPushButton(verticalLayoutWidget_2);
        pushButton_9->setObjectName(QStringLiteral("pushButton_9"));

        gridLayout->addWidget(pushButton_9, 2, 2, 1, 1);

        pushButton = new QPushButton(verticalLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);


        verticalLayout_5->addLayout(gridLayout);

        horizontalLayoutWidget = new QWidget(centralWidget);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 10, 1311, 101));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(16);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label_10 = new QLabel(horizontalLayoutWidget);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setFont(font1);

        horizontalLayout->addWidget(label_10);

        label_11 = new QLabel(horizontalLayoutWidget);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setFont(font1);

        horizontalLayout->addWidget(label_11);

        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 120, 1301, 331));
        LineCameraClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(LineCameraClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1330, 23));
        LineCameraClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(LineCameraClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        LineCameraClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(LineCameraClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        LineCameraClass->setStatusBar(statusBar);
        QWidget::setTabOrder(lineEdit_4, lineEdit_3);
        QWidget::setTabOrder(lineEdit_3, lineEdit_2);
        QWidget::setTabOrder(lineEdit_2, lineEdit);
        QWidget::setTabOrder(lineEdit, pushButton);
        QWidget::setTabOrder(pushButton, pushButton_2);
        QWidget::setTabOrder(pushButton_2, pushButton_3);
        QWidget::setTabOrder(pushButton_3, pushButton_4);
        QWidget::setTabOrder(pushButton_4, pushButton_5);
        QWidget::setTabOrder(pushButton_5, pushButton_8);
        QWidget::setTabOrder(pushButton_8, pushButton_6);
        QWidget::setTabOrder(pushButton_6, pushButton_7);
        QWidget::setTabOrder(pushButton_7, pushButton_9);

        retranslateUi(LineCameraClass);
        QObject::connect(pushButton_4, SIGNAL(clicked()), LineCameraClass, SLOT(showimage()));
        QObject::connect(pushButton, SIGNAL(clicked()), LineCameraClass, SLOT(btnopen()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), LineCameraClass, SLOT(btnstop()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), LineCameraClass, SLOT(btnclose()));
        QObject::connect(pushButton_5, SIGNAL(clicked()), LineCameraClass, SLOT(linkdevice()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), LineCameraClass, SLOT(setAlgorithm()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), LineCameraClass, SLOT(setconsole()));
        QObject::connect(pushButton_8, SIGNAL(clicked()), LineCameraClass, SLOT(getproduct()));
        QObject::connect(pushButton_9, SIGNAL(clicked()), LineCameraClass, SLOT(test()));
        QObject::connect(lineEdit_4, SIGNAL(editingFinished()), LineCameraClass, SLOT(geta()));
        QObject::connect(lineEdit_3, SIGNAL(editingFinished()), LineCameraClass, SLOT(getb()));
        QObject::connect(comboBox, SIGNAL(currentIndexChanged(int)), LineCameraClass, SLOT(getmodel(int)));
        QObject::connect(pushButton_10, SIGNAL(clicked()), LineCameraClass, SLOT(forceGo()));
        QObject::connect(radioButton, SIGNAL(clicked()), LineCameraClass, SLOT(issaveimage()));

        QMetaObject::connectSlotsByName(LineCameraClass);
    } // setupUi

    void retranslateUi(QMainWindow *LineCameraClass)
    {
        LineCameraClass->setWindowTitle(QApplication::translate("LineCameraClass", "LineCamera", 0));
        label_9->setText(QApplication::translate("LineCameraClass", "   \346\250\241\345\274\217", 0));
        pushButton_10->setText(QApplication::translate("LineCameraClass", "\350\277\207", 0));
        label_4->setText(QApplication::translate("LineCameraClass", "<html><head/><body><p><span style=\" font-size:11pt;\">\344\270\212\351\231\220x\357\274\232</span></p></body></html>", 0));
        label_5->setText(QApplication::translate("LineCameraClass", "<html><head/><body><p><span style=\" font-size:11pt;\">\344\270\213\351\231\220y:</span></p></body></html>", 0));
        label_6->setText(QApplication::translate("LineCameraClass", "<html><head/><body><p><span style=\" font-size:11pt; font-weight:600;\">\346\265\213\351\207\217\345\200\274\357\274\232</span></p></body></html>", 0));
        radioButton->setText(QApplication::translate("LineCameraClass", "\347\233\270\346\234\272\345\255\230\345\233\276", 0));
        label_7->setText(QApplication::translate("LineCameraClass", "device", 0));
        pushButton_4->setText(QApplication::translate("LineCameraClass", "show", 0));
        pushButton_3->setText(QApplication::translate("LineCameraClass", "\345\201\234\346\255\242\346\243\200\346\265\213", 0));
        pushButton_5->setText(QApplication::translate("LineCameraClass", "link", 0));
        pushButton_2->setText(QApplication::translate("LineCameraClass", "\346\232\202\345\201\234", 0));
        pushButton_6->setText(QApplication::translate("LineCameraClass", "\347\256\227\346\263\225\350\256\276\345\256\232", 0));
        pushButton_7->setText(QApplication::translate("LineCameraClass", "\350\277\220\345\212\250\350\256\276\345\256\232", 0));
        pushButton_8->setText(QApplication::translate("LineCameraClass", "Login", 0));
        pushButton_9->setText(QApplication::translate("LineCameraClass", "\350\256\276\345\244\207\346\243\200\346\265\213", 0));
        pushButton->setText(QApplication::translate("LineCameraClass", "\345\220\257\345\212\250\346\243\200\346\265\213", 0));
        label_10->setText(QApplication::translate("LineCameraClass", "  \351\242\227\347\262\222\347\211\251\346\235\202\350\264\250\345\205\211\345\255\246\346\243\200\346\237\245\346\234\272", 0));
        label_11->setText(QApplication::translate("LineCameraClass", "                      \344\270\212\346\265\267\350\277\210\350\277\205\345\250\201\350\247\206\350\247\211\347\247\221\346\212\200\346\234\211\351\231\220\345\205\254\345\217\270", 0));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class LineCameraClass: public Ui_LineCameraClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LINECAMERA_H
