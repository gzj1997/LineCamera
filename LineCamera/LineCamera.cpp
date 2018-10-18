#include "LineCamera.h"




LineCamera::LineCamera(QWidget *parent)
	: QMainWindow(parent)
{

	//¶ÁÈ¡setting

    
	cameras[0] = new Camera();

	

	ui.setupUi(this);

	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0,1024,4096, MainWndID, "visible", "", &hv_WindowID);
	ui.centralWidget->setStyleSheet("background-color: rgb(199, 237, 233)");
}

void LineCamera::btnopen()
{
	cameras[0]->OnGrab();
}




void LineCamera::showlineimage(HalconCpp::HObject hv_image)
{
}

void LineCamera::btnclose()
{
	cameras[0]->OnFreeze();
	QString aa;
//	aa = cameras[0]->num1;
	//ui.lineEdit->setText( aa);
}
void LineCamera::btnstop()
{
	HalconCpp::CloseWindow(hv_WindowID);
}

void LineCamera::showimage()
{
	HObject hv_image;
	HTuple  hv_Width, hv_Height;
	ReadImage(&hv_image, "C:/Users/Administrator/Desktop/MyProject/I1.bmp");
	GetImageSize(hv_image, &hv_Width, &hv_Height);
	//OpenWindow(0, 0, hv_Width/2, hv_Height /4, MainWndID, "visible", "", &hv_WindowID);
	HalconCpp::DispObj(hv_image, hv_WindowID);
	//HalconCpp::WriteImage(hv_image, "bmp", 0, "C:/Users/Administrator/Desktop/MyProject/I7.bmp");
}

void LineCamera::linkdevice()
{
	cameras[0]->Link();
	QString a = "";
	a.append(cameras[0]->serverName);
	a.append(cameras[0]->resourceName);
	
	ui.lineEdit->setText(a);
	
}
