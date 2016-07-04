#include <iostream>
#include <fstream> // class necessary to read files
#include "LLStack.h"
#include "RadixSort.h"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 3) { // checking for arguments
		cout << "No argument provided\n";
		return -1;
	}

	ifstream myfile(argv[1]); // input file reader from argument
	
	string dummy = "";
	int totalDigit = 0; //dummy variable for part 1 of project. It will be moved to RadixSort class later
	LLStack myStack;

	while (myfile >> dummy) {

		if (totalDigit < dummy.length()) totalDigit = dummy.length();
		myStack.push(dummy);
	}

	myfile.close(); // close input file
	
	myStack.printToFile(argv[2]);
	
	RadixSort rs(&myStack, totalDigit, argv[2]);
	
	rs.printResult();
	
	return 0;

} // end of main
