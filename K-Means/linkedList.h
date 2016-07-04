#include <iostream>
#include "pointNode.h"
using namespace std;

class LinkedList {

	pointNode* head;

public:

	LinkedList(); // default constructor for Linked List

	void insert(int a, int b, int c); // insert function which will also help in sorting
	
	void printLL(); // special format Linked List print function
	
	void putonImage(int** myArray);
	
	double avgCentery(int a);
	
	double avgCenterx(int a);
	
	pointNode* getNextNode();
	
	~LinkedList(); // destructor to free memory

};
