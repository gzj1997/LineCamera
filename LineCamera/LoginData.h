#pragma once

#include <QDialog.h>
#include "ui_LoginData.h"
#include <Qstring.h>
#include<Qinputdialog.h>

class LoginData : public QDialog
{
	Q_OBJECT

public:
	LoginData(QWidget *parent = Q_NULLPTR);
	~LoginData();
signals:
	void sendsignal();//��������û���������֪ͨ�رյ���Ϣ
private:
	Ui::LoginData ui;
	private slots:
	void getproductname();
	void newproduct();

};
