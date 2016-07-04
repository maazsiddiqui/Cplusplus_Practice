#include <iostream>
#include <sstream> // required to convert int to string easily
#include "LinkedList.h" // Linked List header
using namespace std;

LinkedList::LinkedList() { // default constructor with dummy node of value -9999
	
	head = new Node();
}

void LinkedList::insert(int a) { // insert function which also helps sorting

	Node* n = new Node(a);
	Node* current = head; // temp pointer created to find insert location

	// while loop will verify that next node is not null and value of is less than new node
	
	while (current->getNext() != NULL && current->getNext()->getData() < n->getData()) {
		current = current->getNext(); // if all conditions meet, jump to next node
	}

	// duplicate numbers are allowed in our linked list so no need to check for any condition here

	n->setNext(current->getNext());
	current->setNext(n);
}

std::string LinkedList::printLL() { // special format output function as required

	Node* current = head;

	string out = "listhead";
	
	for (int i = 0; current->getNext() != NULL && i < 10; i++) {
		out = out + " --> (" + to_string(current->getData()) + ", ";

		current = current->getNext();
		out += to_string(current->getData()) + ")";

		if (current->getNext() == NULL && i+1 < 10) {
			out += " --> (" + to_string(current->getData()) + ", -1)";
		}
	}
	return out;
}

LinkedList::~LinkedList() { // destructor to free memory
	
	Node* current = head;
	Node* x;
	
	while (current != NULL) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
}