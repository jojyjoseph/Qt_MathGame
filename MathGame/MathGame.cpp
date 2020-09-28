#include "MathGame.h"

#include "QMenuBar"
#include "QToolBar"
#include "QMessageBox"

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

	// create Tool bar
	createToolBar();
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
		&MathGame::dummyFunction
	);

	// open File Action
	openFileAction = new QAction(tr("&Open"));
}

void MathGame::createToolBar(void)
{
	//fileToolBar = new QToolBar;
	//addToolBar(Qt::TopToolBarArea,fileToolBar);
	//fileToolBar = this->addToolBar(tr("File"));
	//QToolBar *toolbar 
	fileToolBar = addToolBar("main toolbar");
	fileToolBar->addAction("New File");
}

void MathGame::newFileMethod(void)
{
}

void MathGame::dummyFunction(void)
{
	QMessageBox msgBox;
	msgBox.setText("This is a test function message box");
	msgBox.exec();
}