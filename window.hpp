// Header Guard:
#pragma once

// Making declaration of the class which represents the window in the program
#include <QWidget>
#include <QLabel>

class Window :public QWidget{
	Q_OBJECT
public: 
	Window();
	public slots:
	void selectimage();
private:
	QLabel* imagePlaceHolder;
};