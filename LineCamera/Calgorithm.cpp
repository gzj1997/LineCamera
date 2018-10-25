#include "Calgorithm.h"
#include<String>
Calgorithm::Calgorithm(QWidget *parent)
	: QDialog(parent)
{

	ui.setupUi(this);
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0, 1024, 4096, MainWndID, "visible", "", &hv_WindowID);
	initial();
}

Calgorithm::Calgorithm(QWidget *parent,HalconCpp::HObject image)
	: QDialog(parent)
{
	ui.setupUi(this);
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0, 1024, 4096, MainWndID, "visible", "", &hv_WindowID);
	HalconCpp::DispObj(image, hv_WindowID);
	initial();
}

Calgorithm::~Calgorithm()
{

}
void Calgorithm::initial()
{
	ui.horizontalSlider->setMinimum(0);
	ui.horizontalSlider->setMaximum(127);
	ui.radioButton->setChecked(true);

	QTableWidgetItem *aItem;
	aItem = new QTableWidgetItem(QString("�ַ�����"));
	
	//ui.tableWidget->resizeColumnsToContents();//���������Զ��ı��еĴ�С
	//ui.tableWidget->resizeRowsToContents();//���������Զ��ı��еĴ�С
	ui.tableWidget->setColumnCount(3);//��������Ϊ10
	ui.tableWidget->setRowCount(1);//��������Ϊ10
	
		ui.tableWidget->setColumnWidth(0, 90);
		ui.tableWidget->setColumnWidth(1, 86);
		ui.tableWidget->setColumnWidth(2, 86);

	for (size_t i = 0; i < 1; i++)
	{
		ui.tableWidget->setColumnWidth(i, 80);
	}
	QStringList header;
	header << "type" << "min"<<"max";
	ui.tableWidget->setHorizontalHeaderLabels(header);
	QComboBox *comBox = new QComboBox();
	comBox->addItem("area");
	comBox->addItem("height");
	comBox->addItem("width");
	ui.tableWidget->setCellWidget(0, 0, comBox);
	ui.tableWidget->setShowGrid(true);
	//ui.tableWidget->verticalHeader()->setmo(QHeaderView::Stretch);//������Ӧ���                                                                                                      

	//QStandardItemModel  *model = new QStandardItemModel();

	//model->setColumnCount(2);

	//model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("����"));

	//model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("����"));
	//ui.tableView->setModel(model);
}
void Calgorithm::suanfa1()
{
	qDebug() << "hhhhhhhh" ;
}
void Calgorithm::Getscrollnum()
{
	QString str( " ֵ��");
	
	if ( (ui.radioButton)->isChecked())
	{
		scrollnum = ui.horizontalSlider->value();
	}
	else if (ui.radioButton_2->isChecked())
	{
		scrollnum = ui.horizontalSlider->value();
		scrollnum += 128;
	}

	str += scrollnum;
	qDebug() << str;
	std::cout << " ֵ��" << scrollnum;
	ui.label_2->setText(QStringLiteral("ֵ��")+ scrollnum);
}
void Calgorithm::returnmain()
{
	emit sendsignal();
	this->close();
}
void Calgorithm::suanfa()
{
	Getsuanfa * Gs = new Getsuanfa(this);
	Qt::WindowFlags flags = Gs->windowFlags();
	Gs->setWindowFlags(flags | Qt::MSWindowsFixedSizeDialogHint);
	
	int ret = Gs->exec();
	if (ret == QDialog::Accepted)
	{
		switch (Gs->index_suanfa)
		{
		case 1: suanfa1(); break;
		default:
			break;
		}
	}
}
void Calgorithm::sinitial()
{

}

void Calgorithm::sdetect()
{

}

void Calgorithm::ssaveresult()
{

}

void Calgorithm::readimage()
{
	QString curPath = QDir::currentPath();
	QString title = "ѡȡͼƬ";
	QString filter = "image(*.jpg *.png *bmp)";
	QStringList imagename = QFileDialog::getOpenFileNames(this,
		title,curPath,filter);

}

void Calgorithm::getcell(int x, int y)
{

	ui.label_2->setText("aaa-----");
	qDebug() << x << y;
}

void Calgorithm::gettab(QTableWidgetItem* kkk)
{
	ui.label_2->setText( kkk->text() );
	int rowNum = kkk->row();
	// use d to delete a row
	if (rowNum!=0 &&( kkk->text().trimmed() == "d" || kkk->text().trimmed() == "D"))
	{
		ui.tableWidget->removeRow(rowNum);
		return;
	}
	//if last line then create a new row
	if (rowNum == ui.tableWidget->rowCount()-1)
	{
		ui.tableWidget->setRowCount(rowNum+2);
		QComboBox *comBox = new QComboBox();
		comBox->addItem("area");
		comBox->addItem("height");
		comBox->addItem("width");
		ui.tableWidget->setCellWidget(rowNum+1, 0, comBox);
	}

	//QString msg;
	//for (int i = 1; i<ui.tableWidget->columnCount(); i++) {
	//	QWidget *widget = ui.tableWidget->cellWidget(rowNum, i);
	//	QComboBox *combox = (QComboBox*)widget;
	//	msg = msg.append(combox->currentText()) + " ";
	//}

}
