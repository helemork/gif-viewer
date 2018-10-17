// Header Guard:
#pragma once

// Making declaration of the class which represents the window in the program
#include <QWidget>
#include <QLabel>
#include <QListWidget>
#include <QDir>

class Window :public QWidget{
	Q_OBJECT
public: 
	Window();
	public slots:
	void selectDirectory();
	void selectimageFromThumb(QListWidgetItem *item);
	void nextGif(bool);
	void backDirectory();
private:
	QLabel* imagePlaceHolder;
	QDir root = QDir("D:/GIFS/");
	QListWidget* thumbdisplayer;
	void fillThumbViewer();

};