#ifndef UNSORTEDLISTHEADER_H
#define UNSORTEDLISTHEADER_H
#include <fstream>

class UnsortedList {
private:
	int length = 5;
	int *list = new int[length]; // Initialize empty heap. 
	int counter = 0;
	bool quitProgram = false; // This will be used to quit out of the program.

public:
	UnsortedList();
	int GetLength() const; // Getters
	void PutItem(int); // Setter
	void PrintList(std::ostream&); //Printing method. Simply takes output file and prints it there.
	bool GetItem(int); // Prints out item.
	bool IsFull(); //simply checks if the list is full. 
	void DeleteItem(int); //should simply delete the respective item provided. 
	void MakeEmpty(); // Simply makes the list empty
	bool Quit();
};
#endif