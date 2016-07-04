#include <iostream>
#include <fstream>
#include "PrimMST.h"
using namespace std;

int main(int argc, char* argv[]) {

	if (argc != 4) { // checking for arguments
		cout << "No arguments provided\n";
		return -1;
	}

	int dummy = 0;
		
	ifstream myfile(argv[1]); // input file reader from argument
	
	myfile >> dummy;
	PrimMST testPrim(dummy);

	int x, y, z;
		
	while (myfile >> dummy) {
		x = dummy;
		myfile >> dummy;
		y = dummy;
		myfile >> dummy;
		z = dummy;
		testPrim.insertEdgeList(x, y, z);
	}
	
	myfile.close(); // close input file

	testPrim.printGraphNodeIDarray(argv[3]);
	testPrim.printEdgeList(argv[3]);
	testPrim.startPrim(argv[3]);
	testPrim.printMSTofG(argv[2]);
	
	return 0;
}
