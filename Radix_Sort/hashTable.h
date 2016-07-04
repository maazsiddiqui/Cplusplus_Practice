#ifndef D
#define D

#include <iostream>
#include "LLQueue.h"
#include "Node.h"
using namespace std;

class hashTable {

private:
	LLQueue* array[10];
	char* outFile; // pointer to argv[2]

public:

	hashTable();

	void printTable();
	
	void printFileTable(char* outputFile);
	
	LLQueue* getArray(int x);
	
	~hashTable();

};


#endif
