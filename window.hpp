// Header Guard:
#pragma once

// Making declaration of the class which represents the window in the program
#include <QWidget>
#include <QLabel>
#include <QListWidget>

class Window :public QWidget{
	Q_OBJECT
public: 
	Window();
	public slots:
	void selectDirectory();
	void selectimageFromThumb(QListWidgetItem *item);
private:
	QLabel* imagePlaceHolder;
	QString root = "D:/GIFS/";
	QListWidget* thumbdisplayer;
	void fillThumbViewer();

};