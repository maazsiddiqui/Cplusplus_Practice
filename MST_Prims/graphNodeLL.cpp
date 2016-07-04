#include "graphNodeLL.h"
#include <fstream>

graphNodeLL::graphNodeLL() {
	head = new graphNode();
}

void graphNodeLL::insertGraphNode(int a) {
	
	graphNode* n = new graphNode(a);
	graphNode* current = head; // temp pointer created to find insert location

	// while loop will verify that next node is not null and value of is less than new node
	
	while (current->getNext() != NULL && current->getNext()->getnodeID() < n->getnodeID()) {
		current = current->getNext(); // if all conditions meet, jump to next node
	}

	// duplicate numbers are allowed in our linked list so no need to check for any condition here

	n->setNext(current->getNext());
	current->setNext(n);
}

void graphNodeLL::deleteGraphNode(int a) {
	
	graphNode* n = head;
	
	while((n->getNext() != NULL) && (n->getNext()->getnodeID() != a)) {
		n = n->getNext();
	}
	
	graphNode* toDelete = n->getNext();
	if(toDelete != NULL) {
		n->setNext(toDelete->getNext());
		delete toDelete;
	}
	return;
}
	
bool graphNodeLL::isGraphNodeLLEmpty() {
	if (head->getNext() == NULL) return true;
	return false;	
}

void graphNodeLL::printGraphNodeLL(char* outfile) {
	
	graphNode* current = head->getNext();
	
	ofstream myoutfile(outfile, ios::app); // output file reader from argument
	myoutfile << "NodeID" << endl;
	
	while (current != NULL) {
		myoutfile << current->printGraphNode();
		myoutfile << endl;
		current = current->getNext();
	}
	myoutfile << endl;
	myoutfile.close();
	return;
}

bool graphNodeLL::findNode(int a) {
	
	graphNode* current = head->getNext();
	
	while (current != NULL) {
		if(current->getnodeID() == a) return true;
		current = current->getNext();
	}
	return false;
}

graphNodeLL::~graphNodeLL() {
	graphNode* current = head;
	graphNode* x;
	
	while (current != nullptr) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
}
