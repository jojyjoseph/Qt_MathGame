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


	// Menus
	QMenu * fileMenu;


	// Actions
	QAction * newFileAction;
};
