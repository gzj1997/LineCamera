#pragma once
#include<string.h>
#include <iostream>
#include<qxmlstream.h>
#include<qdebug.h>
#include<qdom.h>
using namespace std;
 struct DataSelected
{
public:
	 string name;
    bool istoshow;
 };

 class DataPath
 {
 public:
	 string name;
	 int expose;
	 double pixel;
	 int gain;
	 int photowidth;
	 int speed_heng;
	 int speed_zong;
	 long position;
	 long positiona;
	 long positionb;
	 void saveposition(int heng,int zong) {
		 //打开文件
		 QString dpath = QDir::currentPath() + "/Data/Position.xml";

		 QFile file(dpath); //相对路径、绝对路径、资源路径都可以
		 if (!file.open(QFile::ReadOnly))
			 return;
		 //更新一个标签项,如果知道xml的结构，直接定位到那个标签上定点更新
		 //或者用遍历的方法去匹配tagname或者attribut，value来更新
		 QDomDocument doc;
		 if (!doc.setContent(&file))
		 {
			 file.close();
			 return;
		 }
		 file.close();

		 QDomElement root = doc.documentElement();
		 QDomNodeList list = root.elementsByTagName("Speed");

		 QDomNode node = list.at(0);
		 node.toElement().setAttribute("speed_heng", heng);
		 node.toElement().setAttribute("speed_zong", zong);
		 if (!file.open(QFile::WriteOnly | QFile::Truncate))
			 return;
		 //输出到文件
		 QTextStream out_stream(&file);
		 doc.save(out_stream, 4); //缩进4格
		 file.close();
	 }
	 void savecameraset() {

		 QString dpath = QDir::currentPath() + "/Data/CameraSettings.xml";
		 QFile file(dpath);
		 file.open(QIODevice::WriteOnly);
		 QXmlStreamWriter xmlWriter(&file);
		 xmlWriter.setAutoFormatting(true);
		 xmlWriter.writeStartDocument();
		 xmlWriter.writeStartElement("CCD1");
		 xmlWriter.writeAttribute("name", QString::fromStdString(name));
		 xmlWriter.writeAttribute("PixelDist", QString::number(pixel));
		 xmlWriter.writeAttribute("ExposureTime", QString::number(expose));
		 xmlWriter.writeAttribute("Gain", QString::number(gain));
		 xmlWriter.writeAttribute("PhotoWidth", QString::number(photowidth));
		 xmlWriter.writeEndElement();
		 xmlWriter.writeEndDocument();
		 file.close();
	 }
	 void readposition() {
		 QString dpath = QDir::currentPath() + "/Data/Position.xml";
		 QFile file(dpath);
		 if (!file.open(QFile::ReadOnly | QFile::Text)) {
			 std::cerr << "Error: Cannot read file " << qPrintable(dpath)
				 << ": " << qPrintable(file.errorString())
				 << std::endl;
		 }
		 QXmlStreamReader reader(&file);
		 while (!reader.atEnd()) {
			 reader.readNext();
			 if (reader.isStartElement()) {
				 if (reader.name() == "Position")
				 {
					 position = reader.attributes().value("Pos").toLong();
					 positiona = reader.attributes().value("Posa").toLong();
					 positionb = reader.attributes().value("Posb").toLong();
				 }
				 if (reader.name() == "Speed")
				 {
					 speed_heng = reader.attributes().value("speed_heng").toInt();
					 speed_zong = reader.attributes().value("speed_zong").toInt();
					// qDebug() << reader.readElementText();
				 }
				
				// qDebug() << reader.name() << reader.attributes().value("speed_zong").toInt();
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
	 void readcameraset() {
		 QString dpath = QDir::currentPath() + "/Data/CameraSettings.xml";
		 QFile file(dpath);
		 if (!file.open(QFile::ReadOnly | QFile::Text)) {
			 std::cerr << "Error: Cannot read file " << qPrintable(dpath)
				 << ": " << qPrintable(file.errorString())
				 << std::endl;
		 }
		 QXmlStreamReader reader(&file);
		 while (!reader.atEnd()) {
			 reader.readNext();
			 if (reader.isStartElement()) {
				 if (reader.name() == "CCD1")
				 {
					 name = reader.attributes().value("name").toString().toStdString();
					 pixel = reader.attributes().value("PixelDist").toDouble();
					 expose = reader.attributes().value("ExposureTime").toInt();
					 gain = reader.attributes().value("Gain").toInt();
					 photowidth = reader.attributes().value("PhotoWidth").toInt();
				 }
				// qDebug() << reader.name() << reader.attributes().value("PhotoWidth").toInt();
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
 };

