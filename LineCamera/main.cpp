#include "LineCamera.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	LineCamera w;
	w.show();
	return a.exec();
}
