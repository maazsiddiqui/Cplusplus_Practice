#ifndef B
#define B


#include <iostream>
#include "Node.h"
using namespace std;

class LLStack {

	Node* Top;
	char* outFile; // pointer to argv[2]

public:

	LLStack(); // default constructor for Linked List
	
	Node* getTop();
	
	void push(string a); // insert function which will also help in sorting

	string pop();

	bool isEmpty();

	void printStack(); // special format Linked List print function
	
	void printToFile(char* out);

	~LLStack(); // destructor to free memory

};

#endif
