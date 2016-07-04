#include <iostream>
#include "hashTable.h"
#include "LLStack.h"
using namespace std;

class RadixSort {

	int currentTable;
	int previousTable;
	int totalDigit;
	int index;
	hashTable HT[2];
	LLStack* Stack;
	char* outFile; // pointer to argv[2]

public:

	RadixSort(LLStack* myStack, int maxDigit, char* printFile);
	
	void startSorting();
	
	void addtoHash(string a);
	
	void printhashTable(int a);
	
	void TabletoTable();
	
	void printResult();
	
	// Getters
	
	int getcurrentTable();
	
	int getpreviousTable();
	
	int gettotalDigit();
	
	int getindex();
	
	// Setters
	
	void setcurrentTable(int a);
	
	void setpreviousTable(int a);
	
	void settotalDigit(int a);
	
	void setindex(int a);

	int hash(int a);
	
	~RadixSort();

};
