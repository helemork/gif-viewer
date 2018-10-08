/*
INTRODUCTION TO C++
LEARNING THE BASICS

- all running things must live inside main, and main must return an int. 
- writing to console requires library we include.

*/

#include <iostream>
#include <string>
#include <QWidget>
#include <QApplication>
#include <QIcon>
#include <QLabel>
#include <QHBoxLayout>

using namespace std;

// argc is how many input variables the command line needs
// argv is the actual input parameters

int main(int argc, char ** argv) {

	// Initialise Qt.
	QApplication app(argc, argv);

	// MAKING WINDOW:
	auto window = new QWidget();

	// Customize the Window
	window->setStyleSheet("background:#666666;padding:5px;");
	window->setWindowTitle("The Amazing App");
	window->setWindowIcon(QIcon(QString(ROOT_PATH)+"logo.png"));
	auto topbar = new QHBoxLayout();
	window->setLayout(topbar);

	// Add picture inside the app
	QImage logoimage(QString(ROOT_PATH) + "logo.png");
	auto shrunk_logo = logoimage.scaledToHeight(40,Qt::SmoothTransformation);
	auto logo = new QLabel();
	logo->setPixmap(QPixmap::fromImage(shrunk_logo));
	topbar->addWidget(logo);
	
	// Add page title
	auto title = new QLabel();
	title->setText("The Amazing App");
	topbar->addWidget(title);


	// SHOW WINDOW:
	window->show();

	// RUN PROGRAM
	app.exec();


	/*
	cout << "THIS IS SOMETHING TO LOG. ";
	cout << "speak, friend, and enter. ";

	string result;
	cin >> result;
	if (result != "mellon") {
		cout << "You shall not pass";
	}
	else {
		cout << "Keep talking to close, you're accepted!";
		cin >> result;
	}
	*/

	return EXIT_SUCCESS;
}