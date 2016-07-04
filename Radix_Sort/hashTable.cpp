#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "LLQueue.h"
using namespace std;

hashTable::hashTable() {
	for (int i = 0; i < 10; i++) {
		array[i] = new LLQueue(); 
	}
}


void hashTable::printTable() {
	for (int i = 0; i < 10; i++) {
		cout << "index " << i << '\t' << '\t';
		array[i]->printQueue();
		cout << endl;		
	}

}


void hashTable::printFileTable(char* outputFile) {
		
	outFile = outputFile;
		
	for (int i = 0; i < 10; i++) {
		ofstream myoutfile(outputFile, ios::app); //open output file
		myoutfile << endl << "index " << i << " ";
		myoutfile.close();
		array[i]->printFileQueue(outputFile);		
	}
	
		ofstream myoutfile(outputFile, ios::app); //open output file
		myoutfile << endl;
		myoutfile.close();
}
	
LLQueue* hashTable::getArray(int x) {
	return array[x];
}

hashTable::~hashTable() {
	
	for(int i = 0; i < 10; i++) {
		delete array[i];
	}
	
}
