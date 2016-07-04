#include "edgeNodeLL.h"
#include <fstream>

edgeNodeLL::edgeNodeLL() {
	head = new edgeNode();
}

void edgeNodeLL::insertEdgeNode(int a, int b, int c) {
	
	edgeNode* n = new edgeNode(a, b, c);
	edgeNode* current = head; // temp pointer created to find insert location

	// while loop will verify that next node is not null and value of is less than new node
	
	while (current->getNext() != NULL && current->getNext()->getEdgeCost() < n->getEdgeCost()) {
		current = current->getNext(); // if all conditions meet, jump to next node
	}

	// duplicate numbers are allowed in our linked list so no need to check for any condition here

	n->setNext(current->getNext());
	current->setNext(n);	
}

void edgeNodeLL::deleteEdgeNode(int a, int b, int c) {
	edgeNode* n = head;
	
	while((n->getNext() != NULL) && ((n->getNext()->getNi() != a) && (n->getNext()->getNj() != b) && (n->getNext()->getEdgeCost() != c))) {
		n = n->getNext();
	}
	
	edgeNode* toDelete = n->getNext();
	if(toDelete != NULL) {
		n->setNext(toDelete->getNext());
		delete toDelete;
	}
	return;
}

bool edgeNodeLL::isEdgeNodeLLEmpty() {
	if (head->getNext() == NULL) return true;
	return false;
}

edgeNode* edgeNodeLL::getEdgeNode() {
	return head;
}

void edgeNodeLL::printEdgeNodeLL(char* a) {
	
	edgeNode* current = head->getNext();
	ofstream myoutfile(a, ios::app); // output file reader from argument
	myoutfile << "Ni\t" << "Nj\t" << "Cost" << endl;
	
	int i = 0;
	while (current != NULL && i < 10) {
		myoutfile << current->printEdgeNode();
		myoutfile << endl;
		current = current->getNext();
		i++;
	}
	myoutfile << endl;
	myoutfile.close(); // close output file
	return;
}

edgeNodeLL::~edgeNodeLL() {
	edgeNode* current = head;
	edgeNode* x;
	
	while (current != nullptr) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
}
