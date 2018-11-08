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
#include<qdom.h>
#include<iostream>
#include<qxmlstream.h>
using namespace std;

class Para
{
public:
	int  thr;
	int  dth;
	int area_min,area_max;
	int width_min,width_max;
private:

};

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
	string allpath;
	Para *para;
	void initial();
	void suanfa1();
	void getpara();
	void readpara();
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
	void saveimage();
	void savepara();
	void getcell(int x, int y);
	void gettab(QTableWidgetItem * kkk);
	//void getblack();
};



