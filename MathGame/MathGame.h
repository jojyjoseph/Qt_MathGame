#pragma once

#include <QtWidgets/QMainWindow>
#include <QMenu>
#include <QAction>
#include <QToolBar>
#include <QTextEdit>
#include <QListWidget>

class MathGame : public QMainWindow
{
	Q_OBJECT

public:
	MathGame(QWidget* parent = Q_NULLPTR);

private:
	void createMenus(void);
	void createActions(void);
	void createToolBar(void);
	void createDockWindows(void);


	// Menus
	QMenu* fileMenu;
	QMenu* viewMenu;
	QMenu* helpMenu;

	// Tool bar
	QToolBar* fileToolBar;

	// Actions
	QAction* newFileAction;
	QAction* openFileAction;

	//
	QTextEdit* textEdit;
	QListWidget* customerList;
	QListWidget* paragraphsList;


	// Methods
	void newFileMethod(void);
	void dummyFunction(void);
	void aboutQt(void);

};
