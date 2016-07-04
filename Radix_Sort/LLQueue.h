#ifndef C
#define C

#include <iostream>
#include "Node.h"
using namespace std;

class LLQueue {

	Node* head;
	Node* tail;
	char* outFile; // pointer to argv[2]

public:

	LLQueue(); // default constructor for Linked List
	
	void addTail(string a); // insert function which will also help in sorting

	string deleteHead();

	bool isEmpty();

	void printQueue(); // special format Linked List print function
	
	void printFileQueue(char* outputFile);

	~LLQueue(); // destructor to free memory

};

#endif
