#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_MathGame.h"

class MathGame : public QMainWindow
{
    Q_OBJECT

public:
    MathGame(QWidget *parent = Q_NULLPTR);

private:
    Ui::MathGameClass ui;
};
