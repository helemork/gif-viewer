/*
INTRODUCTION TO C++
LEARNING THE BASICS

- all running things must live inside main, and main must return an int. 
- writing to console requires library we include.

*/


#include <QApplication>
#include <window.hpp>

using namespace std;

// argc is how many input variables the command line needs
// argv is the actual input parameters

// When making object in c++ its usually in two files
// There's usually a header file ending in .h or .hpp and headers are usually declarations
// The source files usually ends in .cpp  source code is the definition.




int main(int argc, char ** argv) {

	// Initialise Qt.
	QApplication app(argc, argv);

	// MAKING WINDOW:
	auto window = new Window();
	

	// RUN PROGRAM
	app.exec();

	return EXIT_SUCCESS;
}