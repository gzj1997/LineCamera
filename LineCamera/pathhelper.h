#pragma once
#include<Qstring.h>
#include<String.h>
#include<Qdir.h>
#include<qdebug.h>
#include <io.h>
#include <direct.h>
#define PATH_DELIMITER '\\'

using namespace std;
static string exepath;
static string productPath;
static vector<QString> productNames;
static string  dataPath;
static string  productname;

class PathHelper
{
public:
	PathHelper()
	{

	}
	 ~PathHelper()
	 {
	 }
	  static void  initial()
	 {
		  exepath = QDir::currentPath().toStdString();
		  dataPath = exepath + "/Data";
		  productPath = dataPath + "/Product";
		 // qDebug() << QString::fromStdString(productPath);
	 }
	  static bool newproduct(QString ProductName)
	  {
		  PathHelper::initial();
		  QString pname = QString::fromStdString(productPath)+"/" + ProductName;
		  if (!createDirectory(pname))
		  {
			  return false;
		  }
		  productname = ProductName.toStdString();
		  qDebug() << QString::fromStdString(productname);
		  return true;

	  }
	  static bool createDirectory(QString folder) {

	
		  // ���Ŀ¼�Ƿ���ڣ������������½�
		  QDir dir;
		  if (!dir.exists(folder))
		  {
			  bool res = dir.mkpath(folder);
			  return true;
		  }
		  else {
			  return false;
		  }

	  }
	  void static GetAllFileFolder( std::vector<QString> &folder)
	  {
		  PathHelper::initial();
		  QString dirPath = QString::fromStdString(productPath);

		  QDir dir(dirPath);
		  dir.setFilter(QDir::Dirs);
		 
		  foreach(QFileInfo fullDir, dir.entryInfoList())

		  {
			  if (fullDir.fileName() == "." || fullDir.fileName() == "..") continue;
			  folder.push_back(fullDir.baseName());
			 
			 // this->GetAllFileFolder(fullDir.absoluteFilePath(), folder);
		  }
		  productNames = folder;
	  }
private:

};




