#include "LineCamera.h"
#include <QtWidgets/QApplication>
#include"helper.h"
#include"DMC2210.h"

 //LineCamera *call_show;


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);

	//ÔË¶¯¿ØÖÆ¿¨£»

	LineCamera w;
//	call_show = &w;
	w.show();
	return a.exec();
}
