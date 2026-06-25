#include "GroceryTrackerMenu.h"
#include <iostream>
#include <fstream>
#include <stdexcept>
using namespace std;

void GroceryTrackerMenu::OpenMenu() {

	try {
		ReadDataFile(); // function runs as soon as OpenMenu() runs in order to create and populate the map 
		CreateBackupFile(); // function runs after OpenMenu() and ReadDataFile() in order to create a back up file for the data
	}
	catch (runtime_error& e) {
		cout << e.what() << endl;
		return;
	}

	int choice;
	string item;
	
	do { // do while loop so the menu is executed once before the condition is checked
		cout << "Select a menu option" << endl;
		cout << "Option 1: Search for an item" << endl;
		cout << "Option 2: Print frequencies for all items" << endl;
		cout << "Option 3: Print histogram for all items" << endl;
		cout << "Option 4: Exit the program" << endl;
		cout << endl;
		
		cin >> choice;

		if (cin.fail()) { // if input is not an int
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Please type in a valid option (1-4)." << endl;
			cout << endl;
			continue;
		}

		cout << endl;

		switch (choice) {

		case 1:
			cout << "Type the item you are looking for" << endl;
			cin >> item;
			cout << SearchItemFrequency(item) << endl;
			cout << endl;
			break;

		case 2:
			PrintListFrequencies();
			break;

		case 3:
			PrintListHistogram();
			break;

		case 4:
			cout << "Exiting program" << endl;
			break;

		default: // if input is not 1 - 4
			cout << "Invalid option" << endl;
		}

	} while (choice != 4);
}

int GroceryTrackerMenu::SearchItemFrequency(string item) {

	if (itemFrequency.count(item) == 0) { 
		return 0;
	}

	return itemFrequency[item]; 
	
}

void GroceryTrackerMenu::PrintListFrequencies() {

	for (const auto& [key, value] : itemFrequency) { 
		// const auto& used to not copy data 
		// auto automatically detects data types, [key, value] are variables that store each key and value
		cout << key << " " << value << endl;
	}

	cout << endl;
}

void GroceryTrackerMenu::PrintListHistogram() {

	for (const auto& [key, value] : itemFrequency) {
		
		cout << key << " ";
		
		for (int i = 0; i < value; ++i) {
			cout << '*';
		}
		
		cout << endl;
	}

	cout << endl;
}

void GroceryTrackerMenu::ReadDataFile() {

	ifstream inFS;
	string item;

	inFS.open("CS210_Project_Three_Input_File.txt");

	if (!inFS.is_open()) {
		throw runtime_error("Could not open input file.");
	}

	while (inFS >> item) { // this reads the provided file and stores each string into the map 
		itemFrequency[item]++; 
	}

	inFS.close();
}

void GroceryTrackerMenu::CreateBackupFile() {

	ofstream outFS;

	outFS.open("frequency.dat");

	if (!outFS.is_open()) {
		throw runtime_error("Could not open data file frequency.dat.");
		
	}

	for (const auto& [key, value] : itemFrequency) {
		outFS << key << " " << value << endl;
	}

	outFS.close();
}