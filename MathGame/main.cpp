#include "MathGame.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MathGame w;
    w.show();
    return a.exec();
}
