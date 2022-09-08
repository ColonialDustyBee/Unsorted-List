#include "unsortedList.h"
#include <iostream>


UnsortedList::UnsortedList() {  };

int UnsortedList::GetLength() const { // this one works.
	return length;
}

void UnsortedList::PutItem(int itemToPlace) { // It doesn't put items correctly. It gives me arbitrary numbers, probably due to it being away from the index?
	if (counter != length) {
		list[counter] = itemToPlace; // Adds item to respective list
		std::cout << itemToPlace << " has been successfully added!" << std::endl;
		counter++;
	}
	else {
		std::cout << "Error in filling out list." << std::endl;
	}
}
void UnsortedList::PrintList(std::ostream& outPutFile) {
	outPutFile << "List is as follows: ";
	if (counter != -1) {
		for (int i = 0; i < counter; i++) {
			outPutFile << list[i] << " "; // Should simply print the list into the output file.
		}
	}
	else {
		outPutFile << "list is currently empty!" << std::endl;
	}
	outPutFile << std::endl;
}

bool UnsortedList::GetItem(int desiredItem) { // There's gotta be a better design for this.
	for (int i = 0; i < length; i++) {
		if (list[i] == desiredItem) { // Should go through array index by index and if list item has been found and it hasn't been found again
			return true;
		}
	}
	return false;
}
bool UnsortedList::IsFull() { // My thought process around this is: Go through list index by index, if array isn't filled with null (no items) it should return true, otherwise it should return false
	if (counter == length) {
		return true;
	}
	return false;
}
void UnsortedList::DeleteItem(int itemToDelete) { 
	int currentPos = 0; // Tracks position 
	int lengthOfArr = length;
	bool found = false;
	// We know what the length of the array is anyways, I'm more or less convinced however that this will result in an error if duplicates are indeed found.
	if (counter > 0) {
		for (int index = 0; index < counter; index++) { // Search the array
			if (list[index] == itemToDelete) {
				currentPos = index; // Save position to be able to iterate from there.
				found = true; // Position's been found!
			}
		}
		if (!found) {
			std::cout << itemToDelete << " not found, can't delete" << std::endl;
			return; // return to before.
		}
		if (currentPos < lengthOfArr) { // if the item was found.
			counter--; // Reduce "pointer" 
			for (int newIndex = currentPos; newIndex < lengthOfArr; newIndex++) { // Assign new values to the remaining values within the array
				list[newIndex] = list[newIndex + 1];
			}
		}
	}
	else {
		std::cout << "Couldn't delete anything off list, list is currently empty!";
	}
}

	// If item has been found, it should stop the search. 
	// It should delete it and then shift the remainder values and decrease the position of the array
void UnsortedList::MakeEmpty() { // This one would work automatically, it's simply freeing the space the array occupied originally since its a dynamic array
	// Maybe we can initialize a new array here, it would fall under the same guise anyways.
	delete list; // We delete the current array
	counter = 0; // Sets counter back to 0.
	length = 5;
	int* list = new int[length]; // Create a new one, initialize it with the length it had of the previous one
}
bool UnsortedList::Quit() { // This one works
	quitProgram = true;
	std::cout << "Program has successfully quit!" << std::endl;
	return quitProgram;
}