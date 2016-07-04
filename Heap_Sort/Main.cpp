#include <iostream>
#include <fstream> // class necessary to read files
#include "HeapSort.h" // Heap Sort class
using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 3) { // checking for arguments
		cout << "no argument provided\n";
		return -1;
	}

	ifstream myfile(argv[1]); // input file reader from argument
	int dummy, size = 0;
	while (myfile >> dummy) size++; // array size from input data
	myfile.close(); // close input file

	if (size > 0) {
		HeapSort temp(size + 1, argv[1], argv[2]); // array size, input file, output file
		temp.DeleteHeap(); // heap deleted, all allocated space released
	}

	return 0;

} // end of main