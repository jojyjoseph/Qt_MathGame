#pragma once

#include <QtWidgets/QMainWindow>
#include "QMenu"
#include "QAction"
#include "QToolBar"

class MathGame : public QMainWindow
{
    Q_OBJECT

public:
    MathGame(QWidget *parent = Q_NULLPTR);

private:
	void createMenus(void);
	void createActions(void);
	void createToolBar(void);


	// Menus
	QMenu * fileMenu;
	QMenu * helpMenu;

	// Tool bar
	QToolBar * fileToolBar;

	// Actions
	QAction * newFileAction;
	QAction * openFileAction;

	// Methods
	void newFileMethod(void);
	void dummyFunction(void);

};
