#pragma once
#include<Qstring.h>
#include<String.h>
#include<Qdir.h>
class PathHelper
{
public:
	PathHelper();
	~PathHelper();
	 static QString exepath;
	 String aaa;

	 static QString productPath;

	 static QString dataPath;
	 static void getFiles(string path, vector<string>& files, vector<string> &ownname);
private:

};

PathHelper::PathHelper()
{
	exepath = QDir::currentPath();
	dataPath = exepath + "\data";
}

void PathHelper::getFiles(string path, vector<string>& files, vector<string> &ownname)
{
	/*files�洢�ļ���·��������(eg.   C:\Users\WUQP\Desktop\test_devided\data1.txt)
	ownnameֻ�洢�ļ�������(eg.     data1.txt)*/

	//�ļ����  
	long   hFile = 0;
	//�ļ���Ϣ  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//�����Ŀ¼,����֮  
			//�������,�����б�  
			if ((fileinfo.attrib &  _A_SUBDIR))
			{  /*
			   if(strcmp(fileinfo.name,".") != 0  &&  strcmp(fileinfo.name,"..") != 0)
			   getFiles( p.assign(path).append("\\").append(fileinfo.name), files, ownname ); */
			}
			else
			{
				files.push_back(p.assign(path).append("\\").append(fileinfo.name));
				ownname.push_back(fileinfo.name);
			}
		} while (_findnext(hFile, &fileinfo) == 0);
		_findclose(hFile);
	}
}
PathHelper::~PathHelper()
{
}


