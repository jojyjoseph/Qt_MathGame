#include "MathGame.h"

#include "QMenuBar"

MathGame::MathGame(QWidget *parent)
    : QMainWindow(parent)
{
	// set up central widget
	QWidget *widget = new QWidget;
	setCentralWidget(widget);

	// create Menu bar
	createMenus();

}

void MathGame::createMenus(void)
{
	fileMenu = menuBar()->addMenu(tr("&File"));
}