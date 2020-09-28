#pragma once

#include <QtWidgets/QMainWindow>
#include "QMenu"
#include "QAction"

class MathGame : public QMainWindow
{
    Q_OBJECT

public:
    MathGame(QWidget *parent = Q_NULLPTR);

private:
	void createMenus(void);
	void createActions(void);



	// Menus
	QMenu * fileMenu;
	QMenu * helpMenu;


	// Actions
	QAction * newFileAction;
	QAction * openFileAction;

	// Methods
	void newFileMethod(void);
};
