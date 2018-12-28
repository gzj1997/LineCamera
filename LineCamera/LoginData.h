#pragma once

#include <QDialog.h>
#include "ui_LoginData.h"
#include <Qstring.h>
#include<Qinputdialog.h>
#include"pathhelper.h"
#include<qmessagebox.h>
using namespace std;

class LoginData : public QDialog
{
	Q_OBJECT

public:
	LoginData(QWidget *parent = Q_NULLPTR);
	~LoginData();

    void addproductname();
//signals:
//	void sendsignal();//这个函数用户向主界面通知关闭的消息
private:
	Ui::LoginData ui;
	private slots:
	void getproductname();
	void newproduct();

};
