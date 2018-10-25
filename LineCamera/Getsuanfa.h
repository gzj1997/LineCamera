#pragma once

#include <QDialog>
#include "ui_Getsuanfa.h"

class Getsuanfa : public QDialog
{
	Q_OBJECT

public:
	int index_suanfa;
	Getsuanfa(QWidget *parent = Q_NULLPTR);
	~Getsuanfa();

private:
	Ui::Getsuanfa ui;
	private slots:
	void suanfa1();


};
