#include <iostream>

class Node {

private:
	int data;
	Node* next;

public:

	Node();

	Node(int a);

	Node(int a, Node* n);

	int getData();

	Node* getNext();

	void setNext(Node* n);

	~Node();
};