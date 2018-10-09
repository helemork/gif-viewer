#include <window.hpp>
#include <iostream>
#include <string>
#include <QWidget>

#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>
#include <QPushButton>
#include <QFileDialog>
#include <QMovie>

using namespace std;

// MAKING FUNCTION TO CALL ON CLICK
void Window::selectimage() {
	cout << ("You clicked the button! Impressive!");
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"), NULL, tr("Image Files (*.png *.jpg *.bmp *.gif)"));
	cout << fileName.toStdString();
	if (fileName.endsWith(".gif")) {
		auto movie = new QMovie(fileName);
		imagePlaceHolder->setMovie(movie);
		movie->start();
	}
	else {
		// Add picture inside the app
		QImage uploadImage(fileName);
		//auto shrunk_logo = logoimage.scaledToHeight(40, Qt::SmoothTransformation);
		imagePlaceHolder->setPixmap(QPixmap::fromImage(uploadImage));
	}
}


Window::Window() {
	auto mainlayout = new QVBoxLayout();

	// Customize the Window
	setStyleSheet("background:#666666;padding:5px;");
	setWindowTitle("The Amazing App");
	setWindowIcon(QIcon(QString(ROOT_PATH) + "logo.png"));
	auto topbar = new QHBoxLayout();
	setLayout(mainlayout);
	mainlayout->addLayout(topbar);

	// Add picture inside the app
	QImage logoimage(QString(ROOT_PATH) + "logo.png");
	auto shrunk_logo = logoimage.scaledToHeight(40, Qt::SmoothTransformation);
	auto logo = new QLabel();
	logo->setPixmap(QPixmap::fromImage(shrunk_logo));
	topbar->addWidget(logo);

	// Add page title
	auto title = new QLabel();
	title->setText("The Amazing App");
	topbar->addWidget(title);

	// Making button
	auto browse = new QPushButton();
	browse->setText("Select Image");
	mainlayout->addWidget(browse);
	QObject::connect(browse, &QPushButton::clicked, this, &Window::selectimage);

	imagePlaceHolder = new QLabel();
	mainlayout->addWidget(imagePlaceHolder);

	// SHOW WINDOW:
	show();
}