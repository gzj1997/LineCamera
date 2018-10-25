#include "Camera.h"
#include"HalconCpp.h"


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
static int numxfer;

 void Camera:: XferCallbackLft(SapXferCallbackInfo * pInfoLft) 
{
	Camera *pGrabQtLft = (Camera *)pInfoLft->GetContext();
	
	HalconCpp::HObject NewPartImage;
	
	int mm = pGrabQtLft->m_Buffers->GetWidth(); 

	int nn = pGrabQtLft->m_Buffers->GetHeight();

	 int size = mm * nn * sizeof(BYTE);/////96 * 4096 为图片的大小
	 BYTE *dataBuf = new BYTE[size];
	 dataBuf = (byte *)malloc(mm * nn * sizeof(byte));///将图片大小赋给dataBuf
    	pGrabQtLft->m_Buffers->Read(0, mm * nn, dataBuf);///将图片数据赋给dataBuf
	 GenImage1(&NewPartImage, "byte", mm, nn, (Hlong)dataBuf);
	 
	 pGrabQtLft->imagelist.push(NewPartImage);

	 pGrabQtLft->processimage();
	 
	 delete dataBuf;
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
			m_Buffers =new SapBufferWithTrash(2, m_AcqDevice);
			m_Buffers->SetWidth(1024);
		//	m_View =new SapView(m_Buffers);
			m_Xfer = new SapAcqDeviceToBuf(m_AcqDevice, m_Buffers, XferCallbackLft,this);

			if ( !CreateObjects())
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
	string filename = "";
	filename.append("C:/Users/Administrator/Desktop/tp/new");
	numxfer++;
	stringstream stream;
	stream << numxfer;
	filename.append(stream.str());
	filename.append(".bmp");
	char* file = (char*)filename.data();
	HalconCpp::WriteImage( imagelist.front(), "bmp", 0, (HalconCpp::HTuple)file);
//	(LineCamera *)linecameraaddr->

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
