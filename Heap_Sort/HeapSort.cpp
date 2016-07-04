#include <iostream>
#include <sstream> // required to convert int to string
#include <fstream> // class necessary to read files
#include "HeapSort.h" // link to heap sort class
using namespace std;

HeapSort::HeapSort(int a, char* i, char* o) {  // Constructor

	size = a;
	pArray = new int[size];
	inFile = i;
	outFile = o;

	for (int n = 0; n < size; n++) { // set all array positions to zero
		pArray[n] = 0;
	}
	
	buildHeap(); // start building heap array
}

void HeapSort::buildHeap() {

	ifstream myfile(inFile); // input file reader from argument
	ofstream myoutfile(outFile); // output file reader from argument
	
	int input;
	
	myoutfile << "Build Heap :" << endl;
	
	while (myfile >> input && !isHeapFull()) { // reading intgers from file
		string s = "";
		s = "Insert " + to_string(input) + "\t\t";
		insertOneDataItem(input);	// inserting one by one in array
		s += printHeap(10);
		myoutfile << s << endl;
	}
	
	myfile.close(); // close input file

	myoutfile << endl << "Final Heap :" << endl << printHeap(size) << endl << endl;
	
	myoutfile.close(); // close output file
	
	return;

}

void HeapSort::insertOneDataItem(int a) {
	
	pArray[0]++;
	pArray[pArray[0]] = a;
	bubbleUp();

	return;

}

void HeapSort::bubbleUp() {

	int current = pArray[0];

	while ((current / 2 > 0) && (pArray[current / 2] > pArray[current])) {

		int temp = pArray[current / 2];
		pArray[current / 2] = pArray[current];
		pArray[current] = temp;
		current = current / 2;
	}

	return;

}

bool HeapSort::isHeapFull() {

	if (pArray[0] == size - 1) return true;

	return false;

}

bool HeapSort::isHeapEmpty() {

	if (pArray[0] == 0) return true;

	return false;

}

string HeapSort::printHeap(int a) {

	string s = "";
	
	for (int j = 1; j <= pArray[0] && j <= a; j++) {
		s += to_string(pArray[j]) + " ";
	}

	return s;

}

void HeapSort::DeleteHeap() {

	DeleteRoot();

	delete[] pArray;
	pArray = NULL; 

	return;

}

void HeapSort::DeleteRoot() {

	ofstream myoutfile(outFile, ios::app); // output file reader from argument

	myoutfile << "Delete Heap :" << endl;

	while (!isHeapEmpty()) {
		string s = "";
		int lowest = pArray[1];
		s += "Delete " + to_string(lowest) + "\t\t";
		pArray[1] = pArray[pArray[0]];
		pArray[0]--;
		bubbleDown();
		s += printHeap(10);
		myoutfile << s << endl;
	}
	
	myoutfile << endl << "Final Heap :" << endl << printHeap(size);

	myoutfile.close(); // close output file

	return;

}

void HeapSort::bubbleDown() {

	int parentIndex = 1;
	int leftChild = parentIndex * 2;
	int rightChild = (parentIndex * 2) + 1;

	while (((leftChild <= pArray[0] && pArray[parentIndex] > pArray[leftChild]))
		|| ((rightChild <= pArray[0]) && pArray[parentIndex] > pArray[rightChild])) {

		if ((rightChild <= pArray[0]) && (pArray[leftChild] > pArray[rightChild])) {

			int temp = pArray[rightChild];
			pArray[rightChild] = pArray[parentIndex];
			pArray[parentIndex] = temp;
			parentIndex = rightChild;
		}

		else {

			int temp = pArray[leftChild];
			pArray[leftChild] = pArray[parentIndex];
			pArray[parentIndex] = temp;
			parentIndex = leftChild;
		}

		leftChild = parentIndex * 2;
		rightChild = (parentIndex * 2) + 1;

	}

	return;
}
