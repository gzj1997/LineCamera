#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LineCamera.h"
#include "HalconCpp.h"
#include "SapClassBasic.h"
#include"Camera.h"


using namespace HalconCpp;


class LineCamera : public QMainWindow
{
	Q_OBJECT;

public:
	LineCamera(QWidget *parent = Q_NULLPTR);
	Camera *cameras[5];
    Hlong MainWndID;
	// Local control variables 
	HTuple  hv_Width, hv_Height;
    HTuple  hv_WindowID;
	HObject  ho_SelectedRegions;
	static void showlineimage(HalconCpp::HObject hv_image);
	
private:
	Ui::LineCameraClass ui;
	private slots:

	void btnopen();
	void btnclose();
	void btnstop();
	void showimage();
	void linkdevice();

};

