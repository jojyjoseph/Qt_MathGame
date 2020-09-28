#include "MathGame.h"
#include <QtWidgets/QApplication>
#include <QDesktopWidget>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MathGame mainWin;
	mainWin.resize(QApplication::desktop()->availableGeometry(QApplication::desktop()->primaryScreen()).size() - QSize(64, 64)); // TODO: First start-up only!
	mainWin.move(32, 32); // TODO: First start-up only!
	mainWin.show();


    return a.exec();
}
