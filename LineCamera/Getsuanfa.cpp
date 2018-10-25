#include "Getsuanfa.h"

Getsuanfa::Getsuanfa(QWidget *parent)
	: QDialog(parent)
{
	ui.setupUi(this);
	index_suanfa = 0;
}

Getsuanfa::~Getsuanfa()
{
}
void Getsuanfa::suanfa1() {
	index_suanfa = 1;
}