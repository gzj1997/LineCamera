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
	queue <HalconCpp::HObject> imagelist;
	
	
	void processimage();
	void OnGrab();
	void OnFreeze();
	char serverName[NAME_LENGTH];
	char resourceName[NAME_LENGTH];
	int serverCount;
	void * Lcamera;
	//void* linecameraaddr;
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

static int numm = 0;

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

	static void showlineimage(HalconCpp::HObject hv_image, LineCamera * lcamera);
	void initail();
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

};

static LineCamera * LLc;

