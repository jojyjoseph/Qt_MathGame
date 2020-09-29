#include "MathGame.h"

#include <QWidget>
#include <QMainWindow>
#include <QMenuBar>
#include <QToolBar>
#include <QMessageBox>
#include <QAction>
#include <QIcon>
#include <QDockWidget>
#include <QListWidget>
#include <QGraphicsView >
#include <QGraphicsScene>
#include <QBrush>
#include <QPen>


MathGame::MathGame(QWidget *parent)
    : QMainWindow(parent)
{
	// set up central widget
	QGraphicsView * gv = new QGraphicsView(this);
	setCentralWidget(gv);

	// operation on the central widget - To be refactored

	gv->setScene(new QGraphicsScene(gv));
	QGraphicsScene* scene = gv->scene();
	QBrush greenBrush(Qt::green);
	QBrush blueBrush(Qt::blue);
	QPen outlinePen(Qt::black);
	outlinePen.setWidth(2);
	scene->addRect(100, 0, 80, 100, outlinePen, blueBrush);

	// create Actions
	createActions();

	// create Menu bar
	createMenus();

	// create Tool bar
	createToolBar();

	// create Dock Windows
	createDockWindows();
}

void MathGame::createMenus(void)
{
	// File Menu
	fileMenu = menuBar()->addMenu(tr("&File"));
	fileMenu->addAction(newFileAction);
	fileMenu->addAction(openFileAction);

	// View Menu
	fileMenu = menuBar()->addMenu(tr("&View"));

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

void MathGame::createDockWindows()
{
	
	QDockWidget* dock = new QDockWidget(tr("Customers"), this);
	dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
	customerList = new QListWidget(dock);
	customerList->addItems(QStringList()
		<< "John Doe, Harmony Enterprises, 12 Lakeside, Ambleton"
		<< "Jane Doe, Memorabilia, 23 Watersedge, Beaton"
		<< "Tammy Shea, Tiblanka, 38 Sea Views, Carlton"
		<< "Tim Sheen, Caraba Gifts, 48 Ocean Way, Deal"
		<< "Sol Harvey, Chicos Coffee, 53 New Springs, Eccleston"
		<< "Sally Hobart, Tiroli Tea, 67 Long River, Fedula");
	dock->setWidget(customerList);
	addDockWidget(Qt::RightDockWidgetArea, dock);

	dock = new QDockWidget(tr("Paragraphs"), this);
	paragraphsList = new QListWidget(dock);
	paragraphsList->addItems(QStringList()
		<< "Thank you for your payment which we have received today."
		<< "Your order has been dispatched and should be with you "
		"within 28 days."
		<< "We have dispatched those items that were in stock. The "
		"rest of your order will be dispatched once all the "
		"remaining items have arrived at our warehouse. No "
		"additional shipping charges will be made."
		<< "You made a small overpayment (less than $5) which we "
		"will keep on account for you, or return at your request."
		<< "You made a small underpayment (less than $1), but we have "
		"sent your order anyway. We'll add this underpayment to "
		"your next bill."
		<< "Unfortunately you did not send enough money. Please remit "
		"an additional $. Your order will be dispatched as soon as "
		"the complete amount has been received."
		<< "You made an overpayment (more than $5). Do you wish to "
		"buy more items, or should we return the excess to you?");
	dock->setWidget(paragraphsList);
	addDockWidget(Qt::RightDockWidgetArea, dock);
	
	connect(paragraphsList, &QListWidget::currentTextChanged,
		this, &MathGame::dummyFunction);
		
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