#include "LoginData.h"

LoginData::LoginData(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
}

LoginData::~LoginData()
{

}

void LoginData::newproduct()
{
	bool isok = true;

	QString title = u8"�²�Ʒ����";
	QString Tlabel = u8"�������²�Ʒ����";
	bool ok = false;
	QString name = QInputDialog::getText(this, title, Tlabel, QLineEdit::Normal, u8"�²�Ʒ����", &ok);

	emit sendsignal();
	this->close();
}

void LoginData::getproductname()
{




	emit sendsignal();
	this->close();
}
