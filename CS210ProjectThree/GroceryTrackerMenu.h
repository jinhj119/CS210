#ifndef GROCERYTRACKERMENU_H
#define GROCERYTRACKERMENU_H
#include <map> 
#include <string>
using namespace std;

class GroceryTrackerMenu {

	public:
		void OpenMenu(); // opens input menu for user and calls other functions 
		
	private:
		map<string, int> itemFrequency; // initialize map for item, item frequency from the data file 
		int SearchItemFrequency(string item); // uses user input to search the map for the frequency of that item (user string input) and returns an int
		void PrintListFrequencies(); // uses map to print all items and their frequencies (int value) from the data file
		void PrintListHistogram(); // uses map to print all items and their frequencies represented by asteriks (char) from the data file
		void ReadDataFile(); // opens the provided data file, takes in all the strings from the file and increments when it encounters the same string and stores it inside the map
		void CreateBackupFile(); // creates a data file and uses the map to print all strings and frequencies (int value) into the created data file
		
};

#endif