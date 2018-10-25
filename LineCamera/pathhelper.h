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
	/*files存储文件的路径及名称(eg.   C:\Users\WUQP\Desktop\test_devided\data1.txt)
	ownname只存储文件的名称(eg.     data1.txt)*/

	//文件句柄  
	long   hFile = 0;
	//文件信息  
	struct _finddata_t fileinfo;
	string p;
	if ((hFile = _findfirst(p.assign(path).append("\\*").c_str(), &fileinfo)) != -1)
	{
		do
		{
			//如果是目录,迭代之  
			//如果不是,加入列表  
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


