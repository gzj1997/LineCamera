#include "Cconsole.h"
#include"DMC2210.h"
#include<thread>
Cconsole::Cconsole(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	initial();
}

Cconsole::~Cconsole()
{

}
void Cconsole::initial()
{
	heng = true;
	zong = true;
	speed_heng = 0;
	speed_zong = 0;
	ui.HengEdit->setText("0");
	ui.ZongEdit->setText("0");
	ui.dial->setMinimum(0);
	ui.dial->setMaximum(20000);
	ui.dial->setNotchesVisible(true);

	ui.dial_2->setMinimum(0);
	ui.dial_2->setMaximum(20000);
	ui.dial_2->setNotchesVisible(true);

	DataPath *Dp;
	Dp = new DataPath();
	Dp->readcameraset();
	Dp->readposition();
	name = QString::fromStdString(Dp->name);
	Spixel =QString::number( Dp->pixel);
	Sgain = QString::number(Dp->gain);
	Sexpose = QString::number( Dp->expose);
	speed_heng = Dp->speed_heng;
	speed_zong = Dp->speed_zong;
	
	Sphotowidth = QString::number(Dp->photowidth);
	ui.label_7->setText(name);
	ui.PixelEdit->setText( Spixel);
	ui.ExposeEdit->setText(Sexpose);
	ui.GainEdit->setText(Sgain);
	ui.WidthEdit->setText(Sphotowidth);
	ui.HengEdit->setText(QString::number(speed_heng));
	ui.ZongEdit->setText(QString::number(speed_zong));

}
void Cconsole::Dialnum_1()
{
	Idial_1 =  ui.dial->value();
	ui.ZongEdit->setText(QString::number(Idial_1, 8).trimmed());
}
void Cconsole::Dialnum_2()
{
	Idial_2 = ui.dial_2->value();
	ui.HengEdit->setText(QString::number(Idial_2, 8).trimmed());
}
void Cconsole::horizontal_speed()
{
	speed_heng = speed_heng < 1000 ? 1000 : speed_heng;
	speed_heng = ui.HengEdit->text().toInt();
	if (heng)
	{
		d2210_write_SEVON_PIN(Card::Axis0, Card::On);
		d2210_set_profile(Card::Axis0, Card::minspeed, speed_heng,Card::acc, Card::acc);
	    d2210_t_vmove(Card::Axis0, 0);
		qDebug()<< d2210_get_encoder(Card::Axis0);
		ui.pushButton->setText(u8"横向停止 ");
	}
	else
	{
		d2210_decel_stop(Card::Axis0, Card::acc);
		qDebug() << d2210_get_encoder(Card::Axis0);
		ui.pushButton->setText(u8"横向启动 ");
	}
	heng = !heng;
}
void Cconsole::vertical_speed()
{
	speed_zong = speed_zong < 1000 ? 1000 : speed_zong;
	speed_zong = ui.HengEdit->text().toInt();
	if (zong)
	{
		d2210_write_SEVON_PIN(Card::Axis1, Card::On);
		d2210_set_profile(Card::Axis1, Card::minspeed, speed_heng, Card::acc, Card::acc);
		d2210_t_vmove(Card::Axis1, 0);
		ui.pushButton_3->setText(u8"纵向停止 ");
	}
	else
	{
		d2210_decel_stop(Card::Axis1, 1000);
		ui.pushButton_3->setText(u8"纵向启动 ");
	}
	zong = !zong;
}
void Cconsole::save_quit()
{
	DataPath *Dh;
	Dh = new DataPath();
	Dh->name = ui.label_7->text().toStdString();;
	Dh->expose = ui.ExposeEdit->text().toInt();
	Dh->gain = ui.GainEdit->text().toInt();
	Dh->pixel = ui.PixelEdit->text().toDouble();
	Dh->photowidth = ui.WidthEdit->text().toInt();

	saveccf("Gain", Dh->gain);
	saveccf("ExposureTime", Dh->expose);
	saveccf("Height", Dh->photowidth);
	Dh->savecameraset();
	Dh->saveposition(ui.HengEdit->text().toInt(),ui.ZongEdit->text().toInt());

}
void Cconsole::saveccf(string name, double da)
{
	string str1 = (QDir::currentPath() + "/Data/11.ccf").toStdString();
	string str2 = (QDir::currentPath() + "/Data/11-1.ccf").toStdString();
	ifstream myfile(str1);
	ofstream outfile(str2, ios::app);
	string temp;
	if (!myfile.is_open())
	{
		QMessageBox::warning(this, "warning", u8"ccf文件不存在", QMessageBox::Ok, QMessageBox::NoButton);
	}
	while (getline(myfile, temp))
	{
		istringstream is(temp);    //将is绑定到str
		string s;
		is >> s;
		if (s == name)
		{
			double tt;
			is >> tt;
			cout << tt << endl;

			ostringstream  aa;
			aa << s << "\t" << da;
			temp = aa.str();
		}
		//while (is >> s)
		//{
		//	cout << s << endl;
		//}
		outfile << temp;
		outfile << endl;
	}
	myfile.close();
	outfile.close();
	remove(str1.c_str());
	rename(str2.c_str(), str1.c_str());
}
void Cconsole::testqi()
{
	int time = ui.PixelEdit->text().toDouble();
	d2210_write_outbit(Card::Axis0, Card::chuiqizongkaiguan, Card::On);
	//d2210_write_outbit(Card::Axis0, Card::chuiqizongkaiguan, Card::On);
	this_thread::sleep_for(std::chrono::milliseconds(time));
	//	qDebug() << d2210_get_encoder(1) << "zzzzzz" << d2210_get_encoder(0);
	d2210_write_outbit(Card::Axis0, Card::chuiqizongkaiguan, Card::Off);
}
void Cconsole::returnmain()
{
	emit sendsignal();
	this->close();
}