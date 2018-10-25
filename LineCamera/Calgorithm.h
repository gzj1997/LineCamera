#pragma once

#include <QDialog>
#include "ui_Calgorithm.h"
#include"HalconCpp.h"
#include<qdir.h>
#include<qfiledialog.h>
#include<qdebug.h>
#include<string.h>
#include<qtableview.h>
#include<qtablewidget.h>
#include<QStandardItemModel.h>
#include"qcombobox.h"
#include"Getsuanfa.h"
#include<qwindow.h>
class Calgorithm : public QDialog
{
	Q_OBJECT

public:
	Calgorithm(QWidget *parent = Q_NULLPTR);
	Calgorithm(QWidget *parent , HalconCpp::HObject image);
	~Calgorithm();
	HalconCpp::HObject himage;
	int scrollnum;
	HalconCpp::HTuple aaa;
	Hlong MainWndID;
	// Local control variables 
	HalconCpp::HTuple  hv_Width, hv_Height;
	HalconCpp::HTuple  hv_WindowID;
	void initial();
	void suanfa1();
signals:
	void sendsignal();//这个函数用户向主界面通知关闭的消息
private:
	Ui::Calgorithm ui;
	private slots:
	void Getscrollnum();
	void returnmain();
	void suanfa();
	void sinitial();
	void sdetect();
	void ssaveresult();
	void readimage();
	void getcell(int x, int y);
	void gettab(QTableWidgetItem * kkk);
	//void getblack();
};
