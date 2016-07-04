#ifndef A
#define A

#include <iostream>
using namespace std;

class Node {

private:
	string data;
	Node* next;

public:

	Node();

	Node(string a);

	string getData();

	Node* getNext();

	void setNext(Node* n);

	~Node();
};

#endif
