#pragma once

#include <QDialog>
#include "ui_Cconsole.h"
#include "card.h"
#include<qdir.h>
#include"datahelper.h"
#include <fstream> 
#include <iostream> 
#include <sstream>
#include<qmessagebox.h>
class Cconsole : public QDialog
{
	Q_OBJECT

public:
	Cconsole(QWidget *parent = Q_NULLPTR);
	~Cconsole();
	void initial();
	QString name;
	QString Spixel;
	QString Sgain;
	QString Sexpose;
	QString Sphotowidth;
	int Idial_1;
	int Idial_2;
	QString path;

	bool heng;
	bool zong;
	int speed_zong;
	int speed_heng;
	void saveccf(string name, double da);
signals:
	void sendsignal();//这个函数用户向主界面通知关闭的消息
private:
	Ui::Cconsole ui;
	private slots:
	void returnmain();
	void Dialnum_1();
	void Dialnum_2();
	void  horizontal_speed();
	void  vertical_speed();
	void  save_quit();
	void testqi();
};
