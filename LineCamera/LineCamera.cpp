#include "LineCamera.h"



int currentPos;
volatile bool falsenut = false;
volatile long photox = 0;
volatile long photoy = 0;
bool isfirst = true;
int positiona = 4141;
int positionb = 29000;
int thr = 100;
int  dth = 25;
int areamin = 1500;
int widthmin = 15000;
int chuiqishijian = 1000;
bool on_catch = false;
HObject errorimage;

LineCamera::LineCamera(QWidget *parent)
	: QMainWindow(parent)
{

	//读取setting
	cameras[0] = new Camera();
//	qDebug() <<  "vvvvvvvvvv";
	cameras[0]->Lcamera = this;
	LLc = this;
	ui.setupUi(this);


	//MainWndID = (Hlong)this->ui.label->winId();
	//OpenWindow(0, 0, 512, 128, MainWndID, "visible", "", &hv_WindowID);
	HObject himage1;
	QString str = QDir::currentPath() +"/Data/I2.bmp";
	HalconCpp::ReadImage(&himage1,str.toStdString().c_str());
//	HalconCpp::DispObj(himage, hv_WindowID);


//	GetImageSize(himage, &hv_Width, &hv_Height);
//	SetWindowAttr("background_color", "black");
	MainWndID = (Hlong)this->ui.label->winId();
//	Hlong winid = (Hlong)this->ui.label->winId();
	//ui.label->setAlignment(Qt::AlignCenter);
//	qDebug() << (long)hv_Width<<"hv_Width";
	OpenWindow(0, 0, 681 , 141, MainWndID, "visible", "", &hv_WindowID);
	//HDevWindowStack::Push(hv_WindowID);
	//if (HDevWindowStack::IsOpen())
	//	DispObj(himage, HDevWindowStack::GetActive());
	//HDevWindowStack::Push(hv_WindowID);

	initail();
	this->setWindowFlags(this->windowFlags()&~Qt::WindowMaximizeButtonHint);
	this->show();
	
}
void LineCamera::initail()
{
	
	ui.centralWidget->setStyleSheet("background-color: rgb(255, 165, 0)");
	ui.verticalLayoutWidget_2->setStyleSheet("background-color: rgb(158, 137, 131)");
	ui.horizontalLayoutWidget->setStyleSheet("background-color: rgb(238, 233, 233)");

	//	ui.gridLayout->setMargin(2);

	readcamerasetting();
	isfirst = true;

	saveimage = new QAction(tr(u8"保存图片"), this);
	connect(saveimage, SIGNAL(triggered()), this, SLOT(ADDChange()));
	int card = d2210_board_init();
	if (card == 0)
	{
		QMessageBox::warning(this,"warning",u8"运动控制卡未连接",QMessageBox::Ok,QMessageBox::NoButton );
		this->close();
	}
	else 
	{
		d2210_set_encoder(Card::Axis0, 100000000 - 200000);
		//d2210_set_encoder(Card::Axis1, 100000000 - 200000);

		d2210_set_pulse_outmode(Card::Axis1, 0);
		d2210_write_SEVON_PIN(Card::Axis1, Card::On);
		d2210_set_profile(Card::Axis1, Card::minspeed, speed_zong, Card::acc, Card::acc);

		//到达限位
		d2210_t_vmove(Card::Axis1, 0);
		this_thread::sleep_for(std::chrono::milliseconds(100));
		int kkk = d2210_axis_io_status(1);
		while (!(kkk == 8192)) {
			kkk = d2210_axis_io_status(1);
			//	this_thread::sleep_for(std::chrono::milliseconds(300));
			//	qDebug() << d2210_get_encoder(1) << "K" << kkk;
		}
		qDebug() << d2210_get_encoder(1) << "K" << kkk;
		//  d2210_set_position(1, 0);
		d2210_set_encoder(Card::Axis1, 0);
		qDebug() << d2210_get_encoder(1);
		//到达图片
		d2210_t_vmove(Card::Axis1, 1);
		//	d2210_set_profile(Card::Axis1, Card::minspeed, 20000, Card::acc, Card::acc);
		int cut1 = d2210_get_encoder(Card::Axis1);
		int cut = cut1;
		while (cut < positiona) {
			this_thread::sleep_for(std::chrono::milliseconds(30));
		//	qDebug() << d2210_get_encoder(1) << "kkkkk";
			cut = d2210_get_encoder(Card::Axis1);
		}
		qDebug() << d2210_get_encoder(1);
		d2210_imd_stop(Card::Axis1);
	}
}

void LineCamera::readcamerasetting()
{
	DataPath *Dp;
	Dp = new DataPath();
	Dp->readcameraset();
	Dp->readposition();
	cameras[0]->devicename = Dp->name;
	chuiqishijian = Dp->pixel;
	cameras[0]->exposuretime = Dp->expose;
	cameras[0]->gain = Dp->gain;
	cameras[0]->photowidth = Dp->photowidth;
	position = Dp->position;
	positiona = Dp->positiona;
	positionb = Dp->positionb;
	//qDebug() << position<<"position";
	speed_heng = Dp->speed_heng;
	speed_zong = Dp->speed_zong;
}

void LineCamera::LoadCameraResultToShowData()
{

	QString dpath = QString::fromStdString(PathHelper::productPath)+ "/CCD1.xml";
	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
	cameras[0]->dataselectlist->clear();
	QXmlStreamReader reader(&file);
	while (!reader.atEnd()) {
		reader.readNext();
		if (reader.isStartElement()) {
			if (reader.name() != "结果")
			{
				DataSelected *ds = new DataSelected();
				ds->name = reader.name().toString().toStdString();
				ds->istoshow = reader.attributes().value("IsToShow").toString() == "true" ? true : false;
				cameras[0]->dataselectlist->push_back(*ds);
			}
			qDebug() << reader.name() << reader.attributes().value("IsToShow").toString();
		}
	}
	file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Failed to parse file "
			<< qPrintable(dpath) << ": "
			<< qPrintable(reader.errorString()) << std::endl;
	}
	else if (file.error() != QFile::NoError) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
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
	Ca->allpath = PathHelper::productPath;
	if (PathHelper::productname == "")
	{
		qDebug() << "no product";
	}
	qDebug() <<  QString::fromStdString( Ca->allpath);
	connect(Ca, SIGNAL(sendsignal()), this, SLOT(reshow()));
	Ca->setAttribute(Qt::WA_DeleteOnClose);
	Ca->show();
}

void LineCamera::startrun()
{
	on_catch = false;
	cameras[0]->OnGrab();

	d2210_set_pulse_outmode(Card::Axis0, 0);
	d2210_write_SEVON_PIN(Card::Axis0, Card::On);
	d2210_set_profile(Card::Axis0, Card::minspeed, speed_heng, Card::acc, Card::acc);
	d2210_t_vmove(Card::Axis0, 0);
}




void LineCamera::run()
{
	//qDebug() << "hhhhhhhhhhhhhhhhhhdddddddddddddd";
	while (true) {
		currentPos = (int)d2210_get_encoder(Card::Axis0);
		if (falsenut)
		{
			cameras[0]->OnFreeze();
			HalconCpp::DispObj(errorimage,hv_WindowID);
			//轴0 抵达位置;
			//d2210_imd_stop(Card::Axis0);
			d2210_change_speed(Card::Axis0, speed_heng/2);
			d2210_t_vmove(Card::Axis1, 1);
		//	this_thread::sleep_for(std::chrono::milliseconds(300));
			int currentPosy = (int)d2210_get_encoder(Card::Axis1);
			//qDebug() << photoy << "kkkkk" << position << "kkkkk" << photox + position;
			int kk = 0;
			int zz=0;
			while ((currentPos < photox + position || currentPosy <photoy )&& !(kk >0  && zz>0)) {
			//	this_thread::sleep_for(std::chrono::milliseconds(300));
				currentPos = (int)d2210_get_encoder(Card::Axis0);
				currentPosy = (int)d2210_get_encoder(Card::Axis1);
			//	qDebug() << currentPosy << "kkkkk"<< currentPos;
				//轴x到达
				if (currentPos > photox + position)
				{
					d2210_imd_stop(Card::Axis0);
					zz++;
				}
				//轴y到达
				if (currentPosy >photoy)
				{
					d2210_imd_stop(Card::Axis1);
					kk++;
				}
				
			}
			d2210_imd_stop(Card::Axis0);
			d2210_imd_stop(Card::Axis1);
		
		//	qDebug() << zz << kk;
			d2210_write_outbit(Card::Axis0, Card::chuiqizongkaiguan, Card::On);
			this_thread::sleep_for(std::chrono::milliseconds(1000));
		//	qDebug() << d2210_get_encoder(1) << "zzzzzz" << d2210_get_encoder(0);
			d2210_write_outbit(Card::Axis0, Card::chuiqizongkaiguan, Card::Off);
			//轴0返回
			d2210_set_profile(Card::Axis0, Card::minspeed, speed_heng, Card::acc, Card::acc);
			d2210_t_vmove(Card::Axis0, 1);
			d2210_t_vmove(Card::Axis1, 0);
			currentPos = (int)d2210_get_encoder(Card::Axis0);
			currentPosy = (int)d2210_get_encoder(Card::Axis1);
			kk = 0;
			zz = 0;
			int kkk = d2210_axis_io_status(1);
			while ((currentPos > photox -2000  || (kkk != 8192)) && !(kk >0 && zz>0)) {
				currentPos = (int)d2210_get_encoder(Card::Axis0);
				kkk = d2210_axis_io_status(1);
			 //   this_thread::sleep_for(std::chrono::milliseconds(300));
			//	qDebug() << d2210_get_encoder(1) << "zzzzzz" << d2210_get_encoder(0);
				if (currentPos < photox -2000)
				{
					d2210_imd_stop(Card::Axis0);
					kk = 1;
				}
				//轴y到达
				if (kkk == 8192)
				{
					d2210_set_encoder(Card::Axis1, 0);
					zz = 1;
				}
				
			}
			//重启
			startrun();
			falsenut = false;
		}
	}
}
void LineCamera::contextMenuEvent(QContextMenuEvent *)
{
	QCursor *qc = new QCursor();
	QMenu *menu = new QMenu(this);
	menu->addAction(saveimage); //添加菜单项1
	menu->exec(qc->pos()); //关联到光标
}
void LineCamera::readtestpara()
{
	QString dpath = QString::fromStdString(PathHelper::productname) + "/para.xml";
	qDebug() << dpath;
	QFile file(dpath);
	if (!file.open(QFile::ReadOnly | QFile::Text)) {
		qDebug() << dpath + "-----jj----";
		return;
	}
	QXmlStreamReader reader(&file);

	while (!reader.atEnd()) {
		reader.readNext();
		if (reader.isStartElement()) {
			if (reader.name() == "thr")
			{
				thr = reader.attributes().value("thr").toInt();
				qDebug() << thr;
			}
			if (reader.name() == "dth")
			{
				dth = reader.attributes().value("dth").toInt();
			}
			if (reader.name() == "area")
			{
				areamin = reader.attributes().value("area_min").toInt();
				qDebug() << areamin;
			//	para->area_max = reader.attributes().value("area_max").toInt();
			}
			if (reader.name() == "width")
			{
				widthmin = reader.attributes().value("width_min").toInt();
			//	para->width_max = reader.attributes().value("width_max").toInt();
			}
		}
	}
	file.close();
	if (reader.hasError()) {
		std::cerr << "Error: Failed to parse file "
			<< qPrintable(dpath) << ": "
			<< qPrintable(reader.errorString()) << std::endl;
	}
	else if (file.error() != QFile::NoError) {
		std::cerr << "Error: Cannot read file " << qPrintable(dpath)
			<< ": " << qPrintable(file.errorString())
			<< std::endl;
	}
}

void LineCamera::btnopen()
{
	if (isfirst)
	{
		readtestpara();
		linkdevice();
		startrun();
		d2210_set_position(Card::Axis0, 0);
		std::thread t(&LineCamera::run, this);
		t.detach();
		isfirst = false;
	}
	else
	{
		startrun();
	}

}

void LineCamera::showlineimage(HalconCpp::HObject hv_image, LineCamera* lcamera)
{
		if (lcamera->numm % 100 == 1) {
			//	lcamera->h_testimage = hv_image.Clone();
			qDebug() << "WriteImage" << lcamera->numm << "pos" << d2210_get_encoder(Card::Axis0);;
		//	HalconCpp::WriteImage(hv_image, "bmp", 0, "C:/Users/mxw/Desktop/tp/I2.bmp"); 
		//	HalconCpp::WriteImage(hv_image, "bmp", 0, "C:/Users/mxw/Desktop/tp/I2.bmp");
		}
		lcamera->numm++;
		HalconCpp::DispObj(hv_image, lcamera->hv_WindowID);

}

void LineCamera::btnclose()
{
	cameras[0]->OnFreeze();
	QString aa;
	d2210_imd_stop(Card::Axis0);
	d2210_imd_stop(Card::Axis1);
	//d2210_board_close();
//	aa = cameras[0]->num1;
	//ui.lineEdit->setText( aa);
}
void LineCamera::btnstop()
{
	d2210_imd_stop(Card::Axis0);
	//HalconCpp::CloseWindow(hv_WindowID);
}

void LineCamera::showimage()
{

	HObject himage;
	QString curPath = QDir::currentPath();
	QString title = "选取图片";
	QString filter = "image(*.jpg *.png *bmp)";
	QString imagename = QFileDialog::getOpenFileName(this,
		title, curPath, filter);
	HalconCpp::ReadImage(&himage, (HalconCpp::HTuple)(imagename.toStdString().c_str()));
	HalconCpp::DispObj(himage, hv_WindowID);
	h_testimage = himage;
	errorimage = himage;
	//MainWndID = (Hlong)this->ui.label->winId();
	//HDevWindowStack::Push(hv_WindowID);
	//if (HDevWindowStack::IsOpen())
	//	DispObj(himage, HDevWindowStack::GetActive());
	//HDevWindowStack::Push(hv_WindowID);

//	cameras[0]->sf_test(200, 1000);
	//d2210_t_vmove(Card::Axis0, 0);
	//photoy = 15100;
	////	this_thread::sleep_for(std::chrono::milliseconds(300));
	//int currentPosy = (int)d2210_get_encoder(Card::Axis0);
	//int aaa = currentPosy;
	//while ( currentPosy <photoy+aaa) {
	//	this_thread::sleep_for(std::chrono::milliseconds(300));
	//	currentPosy = (int)d2210_get_encoder(Card::Axis0);
	//	qDebug() << d2210_get_encoder(1) << "kkkkk" << d2210_get_encoder(0);
	////	轴y到达
	//	if (currentPosy >photoy+aaa)
	//	{
	//		d2210_imd_stop(Card::Axis0);
	//	}

	//}
	//d2210_imd_stop(Card::Axis0);
//	HObject hv_image;
//	HTuple  hv_Width, hv_Height;
//	ReadImage(&hv_image, "C:/Users/Administrator/Desktop/MyProject/I1.bmp");
//	GetImageSize(hv_image, &hv_Width, &hv_Height);
//	h_testimage = hv_image.Clone();
//	//OpenWindow(0, 0, hv_Width/2, hv_Height /4, MainWndID, "visible", "", &hv_WindowID);
//	HalconCpp::DispObj(hv_image, hv_WindowID);
//	//HalconCpp::WriteImage(hv_image, "bmp", 0, "C:/Users/Administrator/Desktop/MyProject/I7.bmp");
//	//string aa;
////	PathHelper::getcurrentdatapath(aa);
//	qDebug() << QString::fromStdString(productname);
/*
	d2210_set_pulse_outmode(Card::Axis1, 0);
	d2210_write_SEVON_PIN(Card::Axis1, Card::On);
	d2210_set_profile(Card::Axis1, Card::minspeed, 20000, Card::acc, Card::acc);
	
	d2210_t_vmove(Card::Axis1, 0);
	this_thread::sleep_for(std::chrono::milliseconds(300));
	int kkk = d2210_axis_io_status(1);
	while ( !(kkk == 4096 || kkk == 8192)) {
		kkk = d2210_axis_io_status(1);
		this_thread::sleep_for(std::chrono::milliseconds(300));
		qDebug() << d2210_get_encoder(1) << "K" << kkk;
	}
	qDebug() << d2210_get_encoder(1) <<"K"<<kkk;
	d2210_set_position(1,0);
*/
}

void LineCamera::linkdevice()
{
	
		cameras[0]->Link();
		QString a = "";
		a.append(cameras[0]->serverName);
		a.append(cameras[0]->resourceName);
		ui.lineEdit->setText(a);
}
void LineCamera::test()
{
	readcamerasetting();
}
void LineCamera::getproduct()
{
	LoginData *Ld;
	Ld = new LoginData(this);
	//connect(Ld, SIGNAL(sendsignal()), this, SLOT(returnlogindata()));
	//Ld->setAttribute(Qt::WA_DeleteOnClose);
	int ret =  Ld->exec();
	if (ret == QDialog::Accepted)
	{
		this->show();
		qDebug() << QString::fromStdString(PathHelper::productPath);
		Ld->close();
	}
	else if (ret == QDialog::Rejected)
	{
		qDebug() << "Rejected ";
	}
	//qDebug() << QString::fromStdString( PathHelper::aaa);
}

Camera::Camera()
{
	m_AcqDevice = NULL;
	m_Buffers = NULL;
	m_Xfer = NULL;
	m_View = NULL;
	//ccfpath = "aaaaaaaa";
	//qDebug() << ccfpath<<"kjjaaaaaaaaaaaaaaaa";
	serverCount = SapManager::GetServerCount();
	dataselectlist = new QList<DataSelected>();
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
	//dataBuf = (byte *)malloc(mm * nn * sizeof(byte));///将图片大小赋给dataBuf
	pGrabQtLft->m_Buffers->Read(0, mm * nn, dataBuf);///将图片数据赋给dataBuf
	GenImage1(&NewPartImage, "byte", mm, nn, (Hlong)dataBuf);
	//HalconCpp::WriteImage(NewPartImage, "bmp", 0, "C:/Users/mxw/Desktop/tp/I1.bmp");
	
	pGrabQtLft->imagelist.push(NewPartImage);
	pGrabQtLft->processimage();

	delete dataBuf;
	//free(dataBuf);
	NewPartImage.Clear();
}

bool Camera::Link()
{
	int serverIndex = 0;
	serverCount = SapManager::GetServerCount();
	qDebug() << serverCount;
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
			string str = (QDir::currentPath() + "/Data/11.ccf").toStdString();
			ccfpath = str.c_str();
		//	qDebug() << ccfpath << "ddddddddd";
		//	m_AcqDevice = new  SapAcqDevice(*pLocLft,"C:/Users/mxw/Desktop/LineCamera/LineCamera/Data/12.ccf");
			m_AcqDevice = new  SapAcqDevice(*pLocLft, ccfpath);
			//	m_AcqDevice->SetParameter(1, 1);
			m_Buffers = new SapBufferWithTrash(2, m_AcqDevice);
		//	m_Buffers->SetWidth(1024);                                                           
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
int xxxx = 0;
int area = 1;
int widthheight = 1;
void LineCamera::geta()
{
	area = ui.lineEdit_4->text().toInt();
	qDebug() << area;
}
void LineCamera::getb()
{
	widthheight = ui.lineEdit_3->text().toInt();
}

void LineCamera::ADDChange()
{
	QString filter = "image (*.bmp)";
	QString imagename =QFileDialog::getSaveFileName(this,u8"保存图片",QDir::currentPath(), filter);
	HalconCpp::WriteImage(errorimage, "bmp", 0, imagename.toStdString().c_str());
}

void Camera::processimage()
{
	try {


		HObject  ho_Image, ho_Region, ho_ImageMean, ho_RegionDynThresh;
		HObject  ho_RegionUnion, ho_ConnectedRegions, ho_SelectedRegions;
		HObject  ho_SortedRegions, ho_ObjectSelected;

		// Local control variables
		HTuple  hv_thr, hv_th, hv_dth, hv_zxmj, hv_zxck;
		HTuple  hv_r, hv_c, hv_area, hv_Number, hv_Area, hv_Row;
		HTuple  hv_Column;
		ho_Image = imagelist.front();
		himage = ho_Image;
		if (!himage.IsInitialized())
		{
			qDebug() << "no image";
			return;
		}


		hv_thr = thr;
		hv_th = dth;
		hv_dth = dth;
		hv_zxmj = areamin;
		hv_zxck = widthmin;
		hv_r = 0;
		hv_c = 0;
		hv_area = 0;

		Threshold(ho_Image, &ho_Region, 0, hv_thr);
		MeanImage(ho_Image, &ho_ImageMean, hv_th, hv_th);
		DynThreshold(ho_Image, ho_ImageMean, &ho_RegionDynThresh, hv_dth, "dark");
		Union2(ho_Region, ho_RegionDynThresh, &ho_RegionUnion);
		Connection(ho_RegionUnion, &ho_ConnectedRegions);
		SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, ((HTuple("area").Append("height")).Append("width")),
			"or", (hv_zxmj.TupleConcat(hv_zxck)).TupleConcat(hv_zxck), ((HTuple(99999000).Append(9999999)).Append(9999999)));
		CountObj(ho_SelectedRegions, &hv_Number);
		if (0 != (hv_Number == 0))
		{
			hv_r = 0;
			hv_c = 0;
			hv_area = 0;
		}
		else if (0 != (hv_Number == 1))
		{
			AreaCenter(ho_SelectedRegions, &hv_Area, &hv_Row, &hv_Column);
			hv_r = hv_Row;
			hv_c = hv_Column;
			hv_area = hv_Area;
		}
		else if (0 != (hv_Number>1))
		{
			SortRegion(ho_SelectedRegions, &ho_SortedRegions, "upper_right", "false", "column");
			SelectObj(ho_SortedRegions, &ho_ObjectSelected, 1);
			AreaCenter(ho_ObjectSelected, &hv_Area, &hv_Row, &hv_Column);
			hv_r = hv_Row;
			hv_c = hv_Column;
			hv_area = hv_Area;
		}
		if (hv_Number > 0)
		{
			long x = (long)hv_r[0].D();
			long y = 4096-(long)hv_c[0].D();
			qDebug() << x << y << "area" << (long)hv_area[0].D();
			OnFreeze();
			
			sf_test(x, y);
			
		}
		//xxxx++;
		//if (xxxx == 200)
		//{
		//	sf_test((long)hv_r, (long)hv_Column);
		//}
	}
	catch(exception e){
	}
	LineCamera::showlineimage(imagelist.front(),(LineCamera*)Lcamera);
	//GetCallBack( imagelist.front());
	imagelist.pop();
}

void Camera::sf_test(long x, long y)
{
	if (on_catch)
	{
		return;
	}
	falsenut = true;
	photox = d2210_get_encoder(Card::Axis0) + (long)(x / 2);
	double yy = y;
	yy = (yy / 4096) * positionb + positiona;
	photoy = (long)yy;
	on_catch = true;
	errorimage = himage;
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
