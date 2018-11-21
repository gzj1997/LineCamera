/********************************************************************************
** Form generated from reading UI file 'Calgorithm.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CALGORITHM_H
#define UI_CALGORITHM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Calgorithm
{
public:
    QLabel *label;
    QTableWidget *tableWidget;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QRadioButton *radioButton;
    QRadioButton *radioButton_2;
    QPushButton *pushButton_7;
    QLabel *label_2;
    QSlider *horizontalSlider;
    QTextEdit *textEdit;

    void setupUi(QDialog *Calgorithm)
    {
        if (Calgorithm->objectName().isEmpty())
            Calgorithm->setObjectName(QStringLiteral("Calgorithm"));
        Calgorithm->resize(730, 380);
        label = new QLabel(Calgorithm);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(20, 20, 681, 141));
        tableWidget = new QTableWidget(Calgorithm);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));
        tableWidget->setGeometry(QRect(10, 180, 271, 111));
        gridLayoutWidget = new QWidget(Calgorithm);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(480, 180, 239, 161));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_2 = new QPushButton(gridLayoutWidget);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 1, 0, 1, 1);

        pushButton = new QPushButton(gridLayoutWidget);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        pushButton_3 = new QPushButton(gridLayoutWidget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(gridLayoutWidget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 0, 2, 1, 1);

        pushButton_5 = new QPushButton(gridLayoutWidget);
        pushButton_5->setObjectName(QStringLiteral("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(gridLayoutWidget);
        pushButton_6->setObjectName(QStringLiteral("pushButton_6"));

        gridLayout->addWidget(pushButton_6, 1, 2, 1, 1);

        gridLayoutWidget_2 = new QWidget(Calgorithm);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(290, 180, 181, 161));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        radioButton = new QRadioButton(gridLayoutWidget_2);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        gridLayout_2->addWidget(radioButton, 0, 0, 1, 1);

        radioButton_2 = new QRadioButton(gridLayoutWidget_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        gridLayout_2->addWidget(radioButton_2, 0, 1, 1, 1);

        pushButton_7 = new QPushButton(gridLayoutWidget_2);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));

        gridLayout_2->addWidget(pushButton_7, 2, 1, 1, 1);

        label_2 = new QLabel(gridLayoutWidget_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout_2->addWidget(label_2, 2, 0, 1, 1);

        horizontalSlider = new QSlider(gridLayoutWidget_2);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        horizontalSlider->setOrientation(Qt::Horizontal);

        gridLayout_2->addWidget(horizontalSlider, 1, 0, 1, 2);

        textEdit = new QTextEdit(Calgorithm);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setGeometry(QRect(10, 300, 271, 61));

        retranslateUi(Calgorithm);
        QObject::connect(pushButton_5, SIGNAL(clicked()), Calgorithm, SLOT(returnmain()));
        QObject::connect(pushButton_7, SIGNAL(clicked()), Calgorithm, SLOT(suanfa()));
        QObject::connect(pushButton, SIGNAL(clicked()), Calgorithm, SLOT(sinitial()));
        QObject::connect(pushButton_3, SIGNAL(clicked()), Calgorithm, SLOT(sdetect()));
        QObject::connect(pushButton_4, SIGNAL(clicked()), Calgorithm, SLOT(ssaveresult()));
        QObject::connect(pushButton_6, SIGNAL(clicked()), Calgorithm, SLOT(readimage()));
        QObject::connect(horizontalSlider, SIGNAL(valueChanged(int)), Calgorithm, SLOT(Getscrollnum()));
        QObject::connect(tableWidget, SIGNAL(itemChanged(QTableWidgetItem*)), Calgorithm, SLOT(gettab(QTableWidgetItem*)));
        QObject::connect(pushButton_2, SIGNAL(clicked()), Calgorithm, SLOT(saveimage()));

        QMetaObject::connectSlotsByName(Calgorithm);
    } // setupUi

    void retranslateUi(QDialog *Calgorithm)
    {
        Calgorithm->setWindowTitle(QApplication::translate("Calgorithm", "Calgorithm", 0));
        label->setText(QString());
        pushButton_2->setText(QApplication::translate("Calgorithm", "\344\277\235\345\255\230\345\233\276\347\211\207", 0));
        pushButton->setText(QApplication::translate("Calgorithm", "\345\210\235\345\247\213\345\214\226", 0));
        pushButton_3->setText(QApplication::translate("Calgorithm", "\346\211\271\351\207\217\346\243\200\346\265\213", 0));
        pushButton_4->setText(QApplication::translate("Calgorithm", "\346\230\276\347\244\272\347\273\223\346\236\234", 0));
        pushButton_5->setText(QApplication::translate("Calgorithm", "\344\277\235\345\255\230\351\200\200\345\207\272", 0));
        pushButton_6->setText(QApplication::translate("Calgorithm", "\350\257\273\345\217\226\345\233\276\347\211\207", 0));
        radioButton->setText(QApplication::translate("Calgorithm", "\351\273\221\350\211\262", 0));
        radioButton_2->setText(QApplication::translate("Calgorithm", "\347\231\275\350\211\262", 0));
        pushButton_7->setText(QApplication::translate("Calgorithm", "\347\256\227\346\263\225", 0));
        label_2->setText(QApplication::translate("Calgorithm", "  \345\200\274 \357\274\232", 0));
    } // retranslateUi

};

namespace Ui {
    class Calgorithm: public Ui_Calgorithm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CALGORITHM_H
