/********************************************************************************
** Form generated from reading UI file 'Cconsole.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CCONSOLE_H
#define UI_CCONSOLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDial>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Cconsole
{
public:
    QDial *dial;
    QLineEdit *lineEdit;
    QLabel *label;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLineEdit *lineEdit_4;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit_3;
    QLineEdit *lineEdit_5;
    QLabel *label_5;
    QDial *dial_2;
    QLabel *label_6;
    QLineEdit *lineEdit_6;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton;

    void setupUi(QDialog *Cconsole)
    {
        if (Cconsole->objectName().isEmpty())
            Cconsole->setObjectName(QStringLiteral("Cconsole"));
        Cconsole->resize(651, 311);
        dial = new QDial(Cconsole);
        dial->setObjectName(QStringLiteral("dial"));
        dial->setGeometry(QRect(30, 10, 171, 171));
        lineEdit = new QLineEdit(Cconsole);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(90, 190, 81, 31));
        label = new QLabel(Cconsole);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 200, 61, 20));
        gridLayoutWidget = new QWidget(Cconsole);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(430, 10, 181, 291));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        lineEdit_4 = new QLineEdit(gridLayoutWidget);
        lineEdit_4->setObjectName(QStringLiteral("lineEdit_4"));

        gridLayout->addWidget(lineEdit_4, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 0, 0, 1, 1);

        label_3 = new QLabel(gridLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        gridLayout->addWidget(label_3, 1, 0, 1, 1);

        label_4 = new QLabel(gridLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        gridLayout->addWidget(label_4, 2, 0, 1, 1);

        lineEdit_2 = new QLineEdit(gridLayoutWidget);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));

        gridLayout->addWidget(lineEdit_2, 0, 1, 1, 1);

        lineEdit_3 = new QLineEdit(gridLayoutWidget);
        lineEdit_3->setObjectName(QStringLiteral("lineEdit_3"));

        gridLayout->addWidget(lineEdit_3, 1, 1, 1, 1);

        lineEdit_5 = new QLineEdit(gridLayoutWidget);
        lineEdit_5->setObjectName(QStringLiteral("lineEdit_5"));

        gridLayout->addWidget(lineEdit_5, 3, 1, 1, 1);

        label_5 = new QLabel(gridLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        gridLayout->addWidget(label_5, 3, 0, 1, 1);

        dial_2 = new QDial(Cconsole);
        dial_2->setObjectName(QStringLiteral("dial_2"));
        dial_2->setGeometry(QRect(230, 10, 171, 171));
        label_6 = new QLabel(Cconsole);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(230, 200, 61, 20));
        lineEdit_6 = new QLineEdit(Cconsole);
        lineEdit_6->setObjectName(QStringLiteral("lineEdit_6"));
        lineEdit_6->setGeometry(QRect(300, 190, 81, 31));
        gridLayoutWidget_2 = new QWidget(Cconsole);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(40, 230, 351, 71));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_4 = new QPushButton(gridLayoutWidget_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout_2->addWidget(pushButton_4, 1, 0, 1, 1);

        pushButton_2 = new QPushButton(gridLayoutWidget_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout_2->addWidget(pushButton_2, 1, 1, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout_2->addWidget(pushButton_3, 0, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget_2);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout_2->addWidget(pushButton, 0, 1, 1, 1);

        dial->raise();
        lineEdit->raise();
        label->raise();
        gridLayoutWidget->raise();
        dial_2->raise();
        label_6->raise();
        gridLayoutWidget_2->raise();
        lineEdit_6->raise();

        retranslateUi(Cconsole);
        QObject::connect(pushButton_2, SIGNAL(clicked()), Cconsole, SLOT(returnmain()));
        QObject::connect(dial, SIGNAL(valueChanged(int)), Cconsole, SLOT(Dialnum_1()));
        QObject::connect(dial_2, SIGNAL(valueChanged(int)), Cconsole, SLOT(Dialnum_2()));
        QObject::connect(pushButton, SIGNAL(clicked()), Cconsole, SLOT(horizontal_speed()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Cconsole, SLOT(vertical_speed()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Cconsole, SLOT(testqi()));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Cconsole, SLOT(save_quit()));

        QMetaObject::connectSlotsByName(Cconsole);
    } // setupUi

    void retranslateUi(QDialog *Cconsole)
    {
        Cconsole->setWindowTitle(QApplication::translate("Cconsole", "Cconsole", 0));
        label->setText(QApplication::translate("Cconsole", "\347\272\265\345\220\221\351\200\237\345\272\246\357\274\232", 0));
        label_2->setText(QApplication::translate("Cconsole", "\346\233\235\345\205\211\357\274\232", 0));
        label_3->setText(QApplication::translate("Cconsole", "\345\242\236\347\233\212", 0));
        label_4->setText(QApplication::translate("Cconsole", "\346\257\224\344\276\213", 0));
        label_5->setText(QApplication::translate("Cconsole", "\347\272\277\345\256\275\357\274\232", 0));
        label_6->setText(QApplication::translate("Cconsole", "\346\250\252\345\220\221\351\200\237\345\272\246\357\274\232", 0));
        pushButton_4->setText(QApplication::translate("Cconsole", "\345\220\270\346\260\224", 0));
        pushButton_2->setText(QApplication::translate("Cconsole", "\344\277\235\345\255\230\345\271\266\351\200\200\345\207\272", 0));
        pushButton_3->setText(QApplication::translate("Cconsole", "\347\272\265\345\220\221\345\220\257\345\212\250", 0));
        pushButton->setText(QApplication::translate("Cconsole", "\346\250\252\345\220\221\345\220\257\345\212\250", 0));
    } // retranslateUi

};

namespace Ui {
    class Cconsole: public Ui_Cconsole {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CCONSOLE_H
