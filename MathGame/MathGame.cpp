#include "MathGame.h"

#include "QMenuBar"

MathGame::MathGame(QWidget *parent)
    : QMainWindow(parent)
{
	// set up central widget
	QWidget *widget = new QWidget;
	setCentralWidget(widget);

	// create Actions
	createActions();

	// create Menu bar
	createMenus();
}

void MathGame::createMenus(void)
{
	// File Menu
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newFileAction);
	fileMenu->addAction(openFileAction);

	// Help Menu
	helpMenu = menuBar()->addMenu(tr("&Help"));
}

void MathGame::createActions(void)
{
	// new File Action
	newFileAction = new QAction(tr("&New"));
	newFileAction->setStatusTip(tr("Create a new file"));
	connect(newFileAction, &QAction::triggered, this, 
		&MathGame::newFileMethod
	);

	// open File Action
	openFileAction = new QAction(tr("&Open"));
}

void MathGame::newFileMethod(void)
{

}