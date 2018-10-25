#include "Cconsole.h"
#include"DMC2210.h"
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
	speed = 0;
	ui.dial->setMinimum(0);
	ui.dial->setMaximum(50000);
	ui.dial->setNotchesVisible(true);
	
	ui.dial_2->setMinimum(0);
	ui.dial_2->setMaximum(50000);
	ui.dial_2->setNotchesVisible(true);
	
	
}
void Cconsole::Dialnum_1()
{
	Idial_1 =  ui.dial->value();
	ui.lineEdit->setText(QString::number(Idial_1, 8).trimmed());
}
void Cconsole::Dialnum_2()
{
	Idial_2 = ui.dial_2->value();
	ui.lineEdit_6->setText(QString::number(Idial_2, 8).trimmed());
}
void Cconsole::horizontal_speed()
{
	speed = speed < 1000 ? 1000 : speed;

	speed = ui.lineEdit->text().toInt();
	if (heng)
	{
		
		d2210_write_SEVON_PIN(Card::cardNo, Card::On);
		d2210_set_profile(Card::cardNo, 1000, speed,0.1,0.1);
	    d2210_t_vmove(Card::cardNo, 0);
		d2210_write_outbit(Card::cardNo, Card::chuiqizongkaiguan, Card::On);

		ui.pushButton->setText(u8"ºáÏòÍ£Ö¹ ");

	}
	else
	{
		d2210_decel_stop(Card::cardNo,0.1);
		d2210_write_outbit(Card::cardNo, Card::chuiqizongkaiguan, Card::Off);
		ui.pushButton->setText(u8"ºáÏòÆô¶¯ ");
	}
	heng = !heng;
}
void Cconsole::vertical_speed()
{
	if (zong)
	{

		ui.pushButton_3->setText(u8"×ÝÏòÍ£Ö¹ ");
	
	}
	else
	{
		ui.pushButton_3->setText(u8"×ÝÏòÆô¶¯ ");
	}
	zong = !zong;

}
void Cconsole::save_quit()
{

}
void Cconsole::testqi()
{
}
void Cconsole::returnmain()
{
	emit sendsignal();
	this->close();
}