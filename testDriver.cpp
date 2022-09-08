#include "unsortedList.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

int main() {
	ifstream inFile;
	ofstream outFile;
	string inputFileName, outputFileName, testName, command, number;
	bool quit = false, full = false, found = false;
	UnsortedList UL;
	cout << "Please enter name of input file: ";
	cin >> inputFileName;
	inFile.open(inputFileName);
	while (!inFile) {
		cout << "ERROR, file not found!, enter again: ";
		cin >> inputFileName;
		inFile.open(inputFileName);
	}
	cout << "\nPlease enter name of output file: ";
	cin >> outputFileName;
	outFile.open(outputFileName);
	cout << "\nPlease enter name of output label: ";
	cin.ignore();
	getline(cin, testName);
	outFile << testName << endl;
	while (!quit) {
		inFile >> command;
		if (command == "Quit") { // this one works
			cout << "Running " << command << endl;
			quit = UL.Quit();
		}
		else if (command == "PutItem") { // this one works
			inFile >> number;
			cout << "Running " << command << endl;
			int numberConvert = stoi(number);
			UL.PutItem(numberConvert);
		}
		else if (command == "GetItem") { // test this one
			inFile >> number;
			cout << "Running " << command << endl;
			int desiredNumber = stoi(number);
			cout << "Fetching item: " << desiredNumber << endl;
			found = UL.GetItem(desiredNumber);
			if (found == true) {
				outFile << desiredNumber << " has been found!" << endl;
				cout << desiredNumber << " has been found, result has been printed to output file" << endl;
			}
			else {
				outFile << desiredNumber << " not found!" << endl;
				cout << desiredNumber << " hasn't been found, result has been printed to output file" << endl;
			}
		}
		else if (command == "DeleteItem") { // This one works, but can be improved
			inFile >> number;
			int desiredNumber = stoi(number);
			UL.DeleteItem(desiredNumber);
		}
		else if (command == "PrintList") { // this one works
			cout << "Running " << command << endl;
			UL.PrintList(outFile);
		}
		else if (command == "GetLength") { // this one works
			cout << "Running " << command << endl;
			outFile << UL.GetLength() << " is the current length of the array" << endl;
		}
		else if (command == "IsFull") { // this one works
			cout << "Running " << command << endl;
			full = UL.IsFull();
			if (full == true) {
				outFile << "List is full!" << endl;
			}
			else {
				outFile << "List is not full!" << endl;
			}
		}
		else if (command == "MakeEmpty") { // This one works
			cout << "Running " << command << endl;
			UL.MakeEmpty();
			outFile << "List has been emptied!" << endl;
			cout << "list has been emptied!, result printed to output file" << endl;
		}
	}
	return 0;
}