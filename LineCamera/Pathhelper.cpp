#include"pathhelper.h"

string PathHelper::dataPath = "";
string PathHelper::exepath = "";
string PathHelper::productname = "";
string PathHelper::productPath = "";
QString PathHelper::errorimagepath = "E:/errorimage";

bool PathHelper::newimagepath()
{
	SYSTEMTIME sys;
	GetLocalTime(&sys);
	//errorimagepath = errorimagepath +"/"+sys.wYear+"-"+sys.wMonth+"-"+sys.wDay+"-"+sys.wHour+"-"+sys.wMinute;
	errorimagepath = errorimagepath + "/" + QString::number(sys.wYear) + "-" + QString::number(sys.wMonth) + "-" + QString::number(sys.wDay);
//	errorimagepath = errorimagepath + "/kk";
	qDebug() << errorimagepath;
	
	PathHelper::createDirectory(errorimagepath);
	return true;
}
