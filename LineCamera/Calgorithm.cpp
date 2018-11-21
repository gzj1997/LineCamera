#include "Calgorithm.h"
#include<String>
#include"HalconCpp.h"
Calgorithm::Calgorithm(QWidget *parent)
	: QDialog(parent)
{

	ui.setupUi(this);
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0, 681, 141, MainWndID, "visible", "", &hv_WindowID);
	qDebug() << "---------";
	initial();
}

Calgorithm::Calgorithm(QWidget *parent,HalconCpp::HObject image)
	: QDialog(parent)
{
	ui.setupUi(this);
	MainWndID = (Hlong)this->ui.label->winId();
	OpenWindow(0, 0, 681, 141, MainWndID, "visible", "", &hv_WindowID);
	himage = image.Clone();
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

	para = new Para();
	showlist = new ShowList();
	para->dth = 25;
	QTableWidgetItem *aItem;
	aItem = new QTableWidgetItem(QString("字符内容"));
	
	//ui.tableWidget->resizeColumnsToContents();//根据内容自动改变列的大小
	//ui.tableWidget->resizeRowsToContents();//根据内容自动改变行的大小
	ui.tableWidget->setColumnCount(3);//设置列数为10
	ui.tableWidget->setRowCount(1);//设置行数为10
	
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
	//ui.tableWidget->verticalHeader()->setmo(QHeaderView::Stretch);//行自适应宽度                                                                                                      

	//QStandardItemModel  *model = new QStandardItemModel();

	//model->setColumnCount(2);

	//model->setHeaderData(0, Qt::Horizontal, QString::fromLocal8Bit("卡号"));

	//model->setHeaderData(1, Qt::Horizontal, QString::fromLocal8Bit("姓名"));
	//ui.tableView->setModel(model);


}


void Calgorithm::readpara()
{
		 QString dpath = QString::fromStdString(allpath) + "/para.xml";
		 QFile file(dpath);
		 if (!file.open(QFile::ReadOnly | QFile::Text)) {
			 qDebug() << dpath+"-----jj----";
			 return;
		 }
		 QXmlStreamReader reader(&file);

		 while (!reader.atEnd()) {
			 reader.readNext();
			 if (reader.isStartElement()) {
				 if (reader.name() == "thr")
				 {
					 para->thr = reader.attributes().value("thr").toInt();
					 qDebug() << para->thr;
				 }
				 if (reader.name() == "dth")
				 {
					 para->dth = reader.attributes().value("dth").toInt();
				 }
				 if (reader.name() == "area")
				 {
					 para->area_min = reader.attributes().value("area_min").toInt();
					 para->area_max = reader.attributes().value("area_max").toInt();
				 }
				 if (reader.name() == "width")
				 {
					 para->width_min = reader.attributes().value("width_min").toInt();
					 para->width_max = reader.attributes().value("width_max").toInt();
				 }
			 }
		 }
		 file.close();
		 if (reader.hasError()) {
			 std::cerr << "Error: Failed to parse file "
				 << qPrintable(dpath) << ": "
				 << qPrintable(reader.errorString()) << std::endl;
		 }
		 else if (file.error() != QFile::NoError) {
			 std::cerr << "Error: Cannot read file " << qPrintable(dpath)
				 << ": " << qPrintable(file.errorString())
				 << std::endl;
		 }

}

void Calgorithm::suanfa1()
{
	qDebug() << "hhhhhhhh" ;
}
void Calgorithm::getpara()
{
	para->thr = scrollnum;
	int rowNum = ui.tableWidget->rowCount();
	QString msg;
	for (int i = 0; i<rowNum-1; i++) {
		QWidget *widget = ui.tableWidget->cellWidget(i, 0);
		QComboBox *combox = (QComboBox*)widget;
		msg = combox->currentText() ;
		if (msg == "area")
		{
			para->area_min = ui.tableWidget->item(i,1)->text().toInt();
			para->area_max = ui.tableWidget->item(i, 2)->text().toInt();
		}
		if (msg == "height" || msg == "width")
		{
			para->width_min = ui.tableWidget->item(i, 1)->text().toInt();
			para->width_max = ui.tableWidget->item(i, 2)->text().toInt();
		}
	}
	
}
void Calgorithm::savepara()
{
	QString dpath = QString::fromStdString(allpath) + "/para.xml";
	QFile file(dpath);
	file.open(QIODevice::WriteOnly);
	QXmlStreamWriter xmlWriter(&file);
	xmlWriter.setAutoFormatting(true);
	xmlWriter.writeStartDocument();
	xmlWriter.writeStartElement("para");
	xmlWriter.writeStartElement("thr");
	xmlWriter.writeAttribute("thr", QString::number(para->thr));
	xmlWriter.writeEndElement();
	xmlWriter.writeStartElement("dth");
	xmlWriter.writeAttribute("dth", QString::number(para ->dth));
	xmlWriter.writeEndElement();
	xmlWriter.writeStartElement("area");
	xmlWriter.writeAttribute("area_min", QString::number(para ->area_min ));
	xmlWriter.writeAttribute("area_max", QString::number(para ->area_max ));
	xmlWriter.writeEndElement();
	xmlWriter.writeStartElement("width");
	xmlWriter.writeAttribute("width_min", QString::number(para ->width_min ));
	xmlWriter.writeAttribute("width_max", QString::number(para ->width_max ));
	xmlWriter.writeEndElement();
	xmlWriter.writeEndElement();
	xmlWriter.writeEndDocument();


	file.close();
}
void Calgorithm::Getscrollnum()
{
//	QString str( " 值：");
	
	if ( (ui.radioButton)->isChecked())
	{
		scrollnum = ui.horizontalSlider->value();
	}
	else if (ui.radioButton_2->isChecked())
	{
		scrollnum = ui.horizontalSlider->value();
		scrollnum += 128;
	}
//	str += scrollnum;
//	qDebug() << str;
//	std::cout << " 值：" << scrollnum;
	ui.label_2->setText(QStringLiteral("值：")+  QString::number( scrollnum));
}
void Calgorithm::returnmain()
{
	savepara();

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
	getpara();
}

void Calgorithm::sdetect()
{

	HalconCpp::HObject  ho_Image, ho_ImageMean, ho_RegionDynThresh;
	HalconCpp::HObject  ho_ConnectedRegions, ho_SelectedRegions, ho_SortedRegions;
	HalconCpp::HObject  ho_ObjectSelected;
	HalconCpp::HObject cir;
	// Local control variables
	HalconCpp::HTuple  hv_thr, hv_dth, hv_zxmj, hv_zxck, hv_r;
	HalconCpp::HTuple  hv_c, hv_area, hv_Area1, hv_Row1, hv_Column1, hv_a;
	HalconCpp::HTuple  hv_Number, hv_Area, hv_Row, hv_Column;
	ho_Image = himage;
	if (!himage.IsInitialized())
	{
		qDebug() << "no image";
		return;
	}
	hv_thr = para->thr;
	hv_dth = para->dth;
	hv_zxmj = para->area_min;
	hv_zxck = para->width_min;
	qDebug() << para->area_min << para->thr;
	hv_r = 0;
	hv_c = 0;
	hv_area = 0;
	MeanImage(ho_Image, &ho_ImageMean, hv_thr, hv_thr);
	DynThreshold(ho_Image, ho_ImageMean, &ho_RegionDynThresh, hv_dth, "dark");
	//dilation_circle (RegionDynThresh, RegionDilation, 1)
	Connection(ho_RegionDynThresh, &ho_ConnectedRegions);
	SelectShape(ho_ConnectedRegions, &ho_SelectedRegions, ((HalconCpp::HTuple("area").Append("height")).Append("width")),
		"or", (hv_zxmj.TupleConcat(hv_zxck)).TupleConcat(hv_zxck), ((HalconCpp::HTuple(999999).Append(9999999)).Append(9999999)));
	CountObj(ho_SelectedRegions, &hv_Number);
	showlist->num = hv_Number;
	if (0 != (hv_Number == 0))
	{
		hv_r = 0;
		hv_c = 0;
		hv_area = 0;
	}
	else if (0 != (hv_Number == 1))
	{
		AreaCenter(ho_SelectedRegions, &hv_Area, &hv_Row, &hv_Column);
		hv_r = hv_Row;
		hv_c = hv_Column;
		hv_area = hv_Area;
		HalconCpp::GenCircle(&cir,hv_Area, hv_Row,200);
	}
	else if (0 != (hv_Number>1))
	{
		SortRegion(ho_SelectedRegions, &ho_SortedRegions, "upper_right", "false", "column");
		SelectObj(ho_SortedRegions, &ho_ObjectSelected, 1);
		AreaCenter(ho_ObjectSelected, &hv_Area, &hv_Row, &hv_Column);
		hv_r = hv_Row;
		hv_c = hv_Column;
		hv_area = hv_Area;
		HalconCpp::GenCircle(&cir, hv_Area, hv_Row, 200);
	}
	if (hv_Number >0)
	{
		AreaCenter(ho_SelectedRegions, &hv_Area1, &hv_Row1, &hv_Column1);
		HalconCpp::DispObj(cir, hv_WindowID);
		resultimage = ho_SelectedRegions;
		for (int  i = 0; i < (int)hv_Number; i++)
		{
			Result* aa = new Result() ;
			aa->x = (int)((const HalconCpp::HTuple&)hv_Row1)[i].D();
			aa->y = (int)((const HalconCpp::HTuple&)hv_Column1)[i].D();
			aa->area = (int)((const HalconCpp::HTuple&)hv_Area1)[i].D();
			showlist->result.push_back(*aa);
		}
	}
}

void Calgorithm::ssaveresult()
{
	if (showlist->num == 0)
	{
		ui.textEdit->setText("no spot");
	}
	else 
	{
		ui.textEdit->setText("spot number is "+QString::number(showlist->num));
		list<Result>::iterator i;
		for ( i = showlist->result.begin(); i !=showlist->result.end(); i++)
		{
			ui.textEdit->append("x:"+ QString::number( (*i).x )+"\ty:"+ QString::number((*i).y)+"\tarea:"+ QString::number((*i).area));
		}
	}
}

void Calgorithm::readimage()
{
	QString curPath = QString::fromStdString(allpath);
	QString title = u8"选取图片";
	QString filter = "image(*.jpg *.png *bmp)";
	QString imagename = QFileDialog::getOpenFileName(this,
		title,curPath,filter);
	HalconCpp::ReadImage(&himage,(HalconCpp::HTuple)(imagename.toStdString().c_str()));
	HalconCpp::DispObj(himage, hv_WindowID);
}

void Calgorithm::saveimage()
{
	string a = allpath;
	a += "/test.bmp";
	if (resultimage.IsInitialized())
	{
		HalconCpp::WriteImage(resultimage, "bmp", 0, a.c_str());
	}

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
