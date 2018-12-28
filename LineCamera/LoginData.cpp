#include "LoginData.h"

LoginData::LoginData(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	addproductname();
}

LoginData::~LoginData()
{

}

void LoginData::addproductname()
{
	vector<QString> folder;
	PathHelper::GetAllFileFolder(folder);
	for each (QString var in folder)
	{
		ui.comboBox->addItem(var);
	}
	//qDebug() << QString::fromStdString(Dpath);
}

void LoginData::newproduct()
{

	QString title = u8"�²�Ʒ����";
	QString Tlabel = u8"�������²�Ʒ����";
	bool ok = false;
	QString name = QInputDialog::getText(this, title, Tlabel, QLineEdit::Normal, u8"�²�Ʒ����", &ok);
	if (ok && !name.isEmpty())
	{
		if (PathHelper::newproduct(name))
		{
		/*	Sdatapath = (QDir::currentPath() + "/data").toStdString();
			Sproduct = name.toStdString();*/

			this->accept();
			//emit sendsignal();
			//this->hide();
		}
		else {
			QMessageBox::warning(this, "warning", u8"��Ʒ���Ѵ���");
		}
	}
}

void LoginData::getproductname()
{
	PathHelper::initial();
//	Pname =  ui.comboBox->currentText().toStdString();
	this->accept();
	//Sdatapath1 = (QDir::currentPath() + "/data").toStdString();
	//Sproduct = productname;
	//emit sendsignal();
	//this->hide();
}
