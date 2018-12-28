#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LineCamera.h"
#include "HalconCpp.h"
#include "SapClassBasic.h"
#include"helper.h"
#include "Calgorithm.h"
#include"Cconsole.h"
#include<qdebug.h>
#include"DMC2210.h"
#include<qmessagebox.h>
#include"LoginData.h"
#include<qxmlstream.h>
#include"datahelper.h"
#include<thread>
#include<qdir.h>
#define NAME_LENGTH  30
using namespace HalconCpp;

static int numxfer;

using namespace std;

class Camera
{
public:
	Camera();
	~Camera();
public:
	static void XferCallbackLft(SapXferCallbackInfo *pInfoLft);	//回调函数
	bool Link();
	
	HalconCpp::HObject image;
	HalconCpp::HObject himage;
	HalconCpp::HObject errorimage;
	queue <HalconCpp::HObject> imagelist;
	
	long errorx = 0, errory = 0;
	int thesameerror = 0;
	
	void processimage();
	void OnGrab();
	void OnFreeze();
	char serverName[NAME_LENGTH];
	char resourceName[NAME_LENGTH];
	int serverCount;

	string logicname;
	string devicename;
	double pixeldist;
	int exposuretime;
	int gain;
	int photowidth;
	const char* ccfpath;
	QList<DataSelected> *dataselectlist;
	void * Lcamera;
	//void* linecameraaddr;
	void  sf_test(long x, long y);
	bool  letitgo();
private:	//私有变量	
	BOOL DestroyObjects();
	BOOL CreateObjects();

	SapLocation *pLocLft;

	SapAcqDevice	*m_AcqDevice;
	SapBuffer		*m_Buffers;
	SapTransfer		*m_Xfer;
	SapView        *m_View;

	SapAcquisition *pAcqLft;
	SapAcqToBuf *pTransferLft;
};



class LineCamera : public QMainWindow
{
	Q_OBJECT


public:
	LineCamera(QWidget *parent = Q_NULLPTR);
	Camera *cameras[5];
	
    Hlong MainWndID;
	// Local control variables 
	HTuple  hv_Width, hv_Height;
    HTuple  hv_WindowID;
	HObject  ho_SelectedRegions;
	HObject h_testimage;
	int numm = 0;
	int speed_heng;
	int speed_zong;
	long position;

	

	static void showlineimage(HalconCpp::HObject hv_image, LineCamera * lcamera);
	void initail();
	void readcamerasetting();
	void LoadCameraResultToShowData();
	void startrun();
	void readtestpara();
	void run();
private:
	Ui::LineCameraClass ui;
	private slots:
	void setAlgorithm();
	void setconsole();
	void reshow();
	void btnopen();
	void btnclose();
	void btnstop();
    void showimage();
	void linkdevice();
	void getproduct();
	//void returnlogindata();
	void test();
	void geta();
	void getb();

};

static LineCamera * LLc;

