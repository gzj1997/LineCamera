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

	QString title = u8"新产品名称";
	QString Tlabel = u8"请输入新产品名称";
	bool ok = false;
	QString name = QInputDialog::getText(this, title, Tlabel, QLineEdit::Normal, u8"新产品名称", &ok);

	emit sendsignal();
	this->close();
}

void LoginData::getproductname()
{




	emit sendsignal();
	this->close();
}
