/*
INTRODUCTION TO C++
LEARNING THE BASICS

- all running things must live inside main, and main must return an int. 
- writing to console requires library we include.

*/

#include <iostream>
#include <string>

using namespace std;

int main() {
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

	return EXIT_SUCCESS;
}