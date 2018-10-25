#include "LineCamera.h"


LineCamera::LineCamera(QWidget *parent)
	: QMainWindow(parent)
{

	//读取setting
	cameras[0] = new Camera();
	cameras[0]->Lcamera = this;
	LLc = this;
	ui.setupUi(this);
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0,1024,4096, MainWndID, "visible", "", &hv_WindowID);
	initail();
	
}
void LineCamera::initail()
{
	ui.centralWidget->setStyleSheet("background-color: rgb(255, 165, 0)");
	ui.verticalLayoutWidget_2->setStyleSheet("background-color: rgb(158, 137, 131)");
	ui.horizontalLayoutWidget->setStyleSheet("background-color: rgb(238, 233, 233)");
	//	ui.gridLayout->setMargin(2);
	int card = d2210_board_init();
	if (card == 0)
	{
		QMessageBox::warning(this,"warning",u8"运动控制卡未连接",QMessageBox::Ok,QMessageBox::NoButton );
		this->close();
	}
	this->show();
}
void LineCamera::setconsole()
{
	Cconsole* Cc;
	Cc = new Cconsole(this);
	connect(Cc, SIGNAL(sendsignal()), this, SLOT(reshow()));
	Cc->setAttribute(Qt::WA_DeleteOnClose);
	Cc->show();

}
void LineCamera::reshow()
{
	this->show();
}
void LineCamera::setAlgorithm()
{
//	ui.lineEdit_2->setText("aaaaaaaaa");
	//this->hide();
	qDebug() << h_testimage.IsInitialized();
	Calgorithm *Ca;
	if (h_testimage.IsInitialized())
	{
		Ca = new Calgorithm(this,h_testimage);
	}
	else
	{
		Ca = new Calgorithm(this);
	}
	connect(Ca, SIGNAL(sendsignal()), this, SLOT(reshow()));
	Ca->setAttribute(Qt::WA_DeleteOnClose);
	Ca->show();
}


void LineCamera::btnopen()
{
	cameras[0]->OnGrab();
}


void LineCamera::showlineimage(HalconCpp::HObject hv_image, LineCamera* lcamera)
{
	/*string filename = "";
	filename.append("C:/Users/Administrator/Desktop/tp/hh");
	numxfer++;
	stringstream stream;
	stream << numxfer;
	filename.append(stream.str());
	filename.append(".bmp");
	char* file = (char*)filename.data();
	HalconCpp::WriteImage(hv_image, "bmp", 0, (HalconCpp::HTuple)file);*/

	if (numm >100)
	{
		lcamera->cameras[0]->OnFreeze();
	}
	if (numm % 10 == 1) {
		lcamera->h_testimage = hv_image.Clone();
	}
	HalconCpp::DispObj(hv_image, lcamera->hv_WindowID);

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
	h_testimage = hv_image.Clone();
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

void LineCamera::getproduct()
{
	LoginData *Ld;
	Ld = new LoginData(this);

	connect(Ld, SIGNAL(sendsignal()), this, SLOT(reshow()));
	Ld->setAttribute(Qt::WA_DeleteOnClose);
	Ld->show();
}




Camera::Camera()
{
	m_AcqDevice = NULL;
	m_Buffers = NULL;
	m_Xfer = NULL;
	m_View = NULL;
	serverCount = SapManager::GetServerCount();
}

Camera::~Camera()
{
	DestroyObjects();
}

void Camera::XferCallbackLft(SapXferCallbackInfo * pInfoLft)
{
	Camera *pGrabQtLft = (Camera *)pInfoLft->GetContext();

	HalconCpp::HObject NewPartImage;

	int mm = pGrabQtLft->m_Buffers->GetWidth();

	int nn = pGrabQtLft->m_Buffers->GetHeight();

	int size = mm * nn * sizeof(BYTE);/////96 * 4096 为图片的大小
	BYTE *dataBuf = new BYTE[size];
//	dataBuf = (byte *)malloc(mm * nn * sizeof(byte));///将图片大小赋给dataBuf
	pGrabQtLft->m_Buffers->Read(0, mm * nn, dataBuf);///将图片数据赋给dataBuf
	GenImage1(&NewPartImage, "byte", mm, nn, (Hlong)dataBuf);

	pGrabQtLft->imagelist.push(NewPartImage);

	pGrabQtLft->processimage();

	delete dataBuf;
	//free(dataBuf);
	NewPartImage.Clear();
}

bool Camera::Link()
{
	int serverIndex = 0;
	for (; serverIndex < serverCount; serverIndex++)
	{
		if (SapManager::GetResourceCount(serverIndex, SapManager::ResourceAcqDevice) != 0)
		{
			// Get Server Name Value
			SapManager::GetServerName(serverIndex, serverName, sizeof(serverName));
		}
	}
	serverIndex--;


	if (SapManager::GetResourceCount(serverName, SapManager::ResourceAcq) == 0)
	{
		for (int i = 0; i < SapManager::GetResourceCount(serverName, SapManager::ResourceAcqDevice); i++)
		{

			SapManager::GetResourceName(serverName, SapManager::ResourceAcqDevice, i, resourceName, sizeof(resourceName));
			pLocLft = new SapLocation(serverName, i);
			//	m_AcqDevice = new  SapAcqDevice(*pLocLft, "C:/Users/Administrator/Desktop/c++/defualt.ccf");
			m_AcqDevice = new  SapAcqDevice(*pLocLft, "C:/Users/Administrator/Desktop/12.ccf");
			//	m_AcqDevice->SetParameter(1, 1);
			m_Buffers = new SapBufferWithTrash(2, m_AcqDevice);
			m_Buffers->SetWidth(1024);
			//	m_View =new SapView(m_Buffers);
			m_Xfer = new SapAcqDeviceToBuf(m_AcqDevice, m_Buffers, XferCallbackLft, this);

			if (!CreateObjects())
			{

				return false;
			}

		}
	}
	return true;
}



BOOL Camera::DestroyObjects()
{
	// Destroy transfer object
	if (m_Xfer && *m_Xfer) m_Xfer->Destroy();

	// Destroy view object
	if (m_View && *m_View) m_View->Destroy();

	// Destroy buffer object
	if (m_Buffers && *m_Buffers) m_Buffers->Destroy();

	// Destroy acquisition object
	if (m_AcqDevice && *m_AcqDevice) m_AcqDevice->Destroy();

	return TRUE;
}

BOOL Camera::CreateObjects()
{

	// Create acquisition object
	if (!m_AcqDevice->Create())
	{
		DestroyObjects();
		return FALSE;
	}

	// Create buffer object
	if (m_Buffers && !*m_Buffers)
	{
		if (!m_Buffers->Create())
		{
			DestroyObjects();
			return FALSE;
		}
		// Clear all buffers
		m_Buffers->Clear();
	}
	// Create view object
	if (m_View && !*m_View && !m_View->Create())
	{
		DestroyObjects();
		return FALSE;
	}

	// Set next empty with trash cycle mode for transfer
	if (m_Xfer && m_Xfer->GetPair(0))
	{
		if (!m_Xfer->GetPair(0)->SetCycleMode(SapXferPair::CycleNextWithTrash))
		{
			DestroyObjects();
			return FALSE;
		}
	}

	// Create transfer object
	if (m_Xfer && !*m_Xfer && !m_Xfer->Create())
	{
		DestroyObjects();
		return FALSE;
	}
	return TRUE;
}

void Camera::processimage()
{
	/*string filename = "";
	filename.append("C:/Users/Administrator/Desktop/tp/new");
	numxfer++;
	stringstream stream;
	stream << numxfer;
	filename.append(stream.str());
	filename.append(".bmp");
	char* file = (char*)filename.data();
	HalconCpp::WriteImage(imagelist.front(), "bmp", 0, (HalconCpp::HTuple)file);*/
	//	(LineCamera *)linecameraaddr->

	LineCamera::showlineimage(imagelist.front(),(LineCamera*)Lcamera);
	//GetCallBack( imagelist.front());
	imagelist.pop();

}

void Camera::OnGrab()
{
	if (m_Xfer->Grab())
	{

	}
}

void Camera::OnFreeze()
{
	if (m_Xfer->Freeze())
	{
	}
}
