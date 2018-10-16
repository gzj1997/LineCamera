#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LineCamera.h"

class LineCamera : public QMainWindow
{
	Q_OBJECT

public:
	LineCamera(QWidget *parent = Q_NULLPTR);

private:
	Ui::LineCameraClass ui;
};
