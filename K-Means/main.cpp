#include <iostream>
#include <fstream> // class necessary to read files
#include "kmeans.h"

using namespace std;

int main(int argc, char *argv[]) {

	if (argc < 4) { // checking for arguments
		cout << "No arguments provided\n";
		return -1;
	}

	int dummy = 0;
	kmeans mykmean;
	
	ifstream myfile(argv[1]); // input file reader from argument
	
	myfile >> dummy;
	mykmean.setk(dummy);

	myfile >> dummy;
	mykmean.setnumRow(dummy);
	
	myfile >> dummy;
	mykmean.setnumCol(dummy);

	int x;
	int y;
	int l = 1;
		
	while (myfile >> dummy) {
		x = dummy;
		myfile >> dummy;
		y = dummy;
		if (l > mykmean.getk()) l = 1;
		mykmean.listInsert(x, y, l);
		l++;
	}
	
	myfile.close(); // close input file

	mykmean.simplePrint(argv[2]); // output for 1st file
	mykmean.startClustering();
	mykmean.displayImage(argv[3]); // output for 2nd file after clustering
	
	return 0;

} // end of main
