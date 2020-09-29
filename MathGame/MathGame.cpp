#include "MathGame.h"

#include "QWidget"
#include <QMainWindow>
#include "QMenuBar"
#include "QToolBar"
#include "QMessageBox"
#include "QAction"
#include "QIcon"

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
	connect(helpMenu->addAction(tr("3rd &Party")), &QAction::triggered, this, &MathGame::aboutQt);
}

void MathGame::createActions(void)
{
	// new File Action
	newFileAction = new QAction(tr("&New"));
	newFileAction->setStatusTip(tr("Create a new file"));
	newFileAction->setIcon(QIcon(":/icons/document.png"));
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
	fileToolBar->addAction(newFileAction);
}


void MathGame::aboutQt()
{
	QMessageBox::about(this, tr("3rd Party"), tr("The Qt GUI Toolkit is Copyright © 2013 Digia Plc and/or its subsidiary(-ies).\n"
		"Contact: http://www.qt-project.org/legal\n"
		"Qt is available under the LGPL.\n"
		"\n"
		"Portions part of the examples of the Qt Toolkit, under the BSD license.\n"
		"Copyright © 2013 Digia Plc and/or its subsidiary(-ies).\n"
		"Contact: http://www.qt-project.org/legal\n"

		"\n"
		"BSD License Disclaimer for Qt Toolkit and ErrorList Widget\n"
		"THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "
		"\"AS IS\" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT "
		"LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR "
		"A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT "
		"OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, "
		"SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT "
		"LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, "
		"DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY "
		"THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT "
		"(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE "
		"OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.\n"
		"\n"
		"Fugue Icons\n"
		"© 2013 Yusuke Kamiyamane. All rights reserved.\n"
		"These icons are licensed under a Creative Commons"
		"Attribution 3.0 License.\n"
		"<http://creativecommons.org/licenses/by/3.0/>"));
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