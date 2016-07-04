#include <iostream>
#include <sstream> // need to convert int to string easily
#include <fstream> // class necessary to read files
#include "LinkedList.h" // LinkedList class
using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 3) { // checking for arguments
		cout << "No argument provided\n";
		return -1;
	}

	ifstream myfile(argv[1]); // input file reader from argument
	ofstream myoutfile(argv[2]); // output file reader from argument

	LinkedList list1;

	int input;
	bool n = true;

	while (myfile >> input) { // reading intgers from file
			
		list1.insert(input); // inserting each integer in list and sorting it
		if (n != true) myoutfile << "\n";
		n = false;
		myoutfile << list1.printLL(); // sending out list to output file
	}

	myfile.close(); // close input file
	myoutfile.close(); // close output file
	
	return 0;
} // end of main