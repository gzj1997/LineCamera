#pragma once

#include "SapClassBasic.h"
#include"HalconCpp.h"
#define NAME_LENGTH  30

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

	void processimage();
	void OnGrab();
	void OnFreeze();
	char serverName[NAME_LENGTH];
	char resourceName[NAME_LENGTH];
	int serverCount;
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
