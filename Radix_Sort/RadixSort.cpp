#include <iostream>
#include <fstream>
#include "hashTable.h"
#include "RadixSort.h"

using namespace std;

RadixSort::RadixSort(LLStack* myStack, int maxDigit, char* printFile) {
	
	totalDigit = maxDigit;
	previousTable = 0;
	currentTable = 0;
	index = 0;
	outFile = printFile;
	Stack = myStack;
	
	startSorting();
	
}

void RadixSort::startSorting() {
	
	while (Stack->isEmpty() != true) addtoHash(Stack->pop());
	
	ofstream myoutfile(outFile, ios::app); //open output file
	myoutfile << endl << endl;
	myoutfile << "Current Table" << endl << endl;
	myoutfile.close(); // close output file
	
	printhashTable(getcurrentTable());
	
	ofstream myoutfile2(outFile, ios::app); //open output file
	myoutfile2 << endl;
	myoutfile2.close(); // close output file
	
	currentTable = 1;
	
	while (index < totalDigit) {

		TabletoTable();
		
		ofstream myoutfile3(outFile, ios::app);
		myoutfile3 << "Previous Table" << endl << endl;
		myoutfile3.close(); // close output file
		
		printhashTable(getpreviousTable());
		
		ofstream myoutfile4(outFile, ios::app);
		myoutfile4 << endl;
		myoutfile4.close(); // close output file	
	}
	
	currentTable = previousTable;
	
	ofstream myoutfile5(outFile, ios::app);
	myoutfile5 << "Current Table" << endl << endl;
	myoutfile5.close(); // close output file
	
	printhashTable(getcurrentTable());
	
	ofstream myoutfile6(outFile, ios::app);
	myoutfile6 << endl;
	myoutfile6.close(); // close output file

}


void RadixSort::addtoHash(string a) {
	
	int currentDigit = a.length() - index;
 	HT[currentTable].getArray(hash((a[currentDigit - 1]) - '0'))->addTail(a);
	return;

}

void RadixSort::TabletoTable() {
		
	for (int i = 0; i < 10; i++) {
	
		while (HT[previousTable].getArray(i)->isEmpty() != true) {
		
			string in = HT[previousTable].getArray(i)->deleteHead();
			addtoHash(in);

		}	
	
	}

	int temp = currentTable;
	currentTable = previousTable;
	previousTable = temp;
	
	index++;	
}

void RadixSort::printhashTable(int a) {	
	HT[a].printFileTable(outFile);
	return;
}

// Getters

int RadixSort::getcurrentTable() {
	return currentTable;
}

int RadixSort::getpreviousTable() {
	return previousTable;
}

int RadixSort::gettotalDigit() {
	return totalDigit;
}

int RadixSort::getindex() {
	return index;
}

// Setters

void RadixSort::setcurrentTable(int a) {
	currentTable = a;
	return;
}

void RadixSort::setpreviousTable(int a) {
	previousTable = a;
	return;
}

void RadixSort::settotalDigit(int a) {
	totalDigit = a;
	return;
}

void RadixSort::setindex(int a) {
	index = a;
	return;
}

int RadixSort::hash(int a) {
	if (a > 0) return a;
	else return 0;
}


void RadixSort::printResult() {

	ofstream myoutfile(outFile, ios::app);
	myoutfile << "Result: ";
	
	for (int i = 0; i < 10; i++) {
		
		while (HT[previousTable].getArray(i)->isEmpty() != true) {
		
			string in = HT[previousTable].getArray(i)->deleteHead();
			myoutfile << in << " ";
		}	
	}

	myoutfile.close(); // close output file
	return;
	
}

RadixSort::~RadixSort() {
	
//	delete HT;

}

