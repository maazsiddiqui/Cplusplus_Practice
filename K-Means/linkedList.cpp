#include "linkedList.h"

LinkedList::LinkedList() { // default constructor with dummy node of value -9999
	head = new pointNode();
}

void LinkedList::insert(int a, int b, int c) { // insert function which also helps sorting

	pointNode* n = new pointNode(a, b, c);
	pointNode* current = head; // temp pointer created to find insert location

	// while loop will verify that next node is not null and value of is less than new node
	
	while (current->getNext() != NULL) {
		current = current->getNext(); // if all conditions meet, jump to next node
	}

	// duplicate numbers are allowed in our linked list so no need to check for any condition here

	n->setNext(current->getNext());
	current->setNext(n);
}

pointNode* LinkedList::getNextNode() {
	return head->getNext();
}

void LinkedList::printLL() { // special format output function as required

	pointNode* current = head->getNext();
	
	while(current != NULL) {
		current->printPointnode();
		current = current->getNext();
	}
	return;
}

void LinkedList::putonImage(int** myArray) {

	pointNode* current = head->getNext();

	while(current != NULL) {
		myArray[current->getXdata()][current->getYdata()] = current->getLabel();		
		current = current->getNext();
	}
	return;
}

double LinkedList::avgCenterx(int a) {
	
	pointNode* current = head->getNext();
	
	int sumx = 0;
	int nop = 0;
	double result = 0;
	
	while(current != NULL) {

		if(current->getLabel() == a) {
			sumx += current->getXdata();
			nop++;
		}		
		current = current->getNext();
	}
	
	result = (double) sumx/nop;
	return result;	
}


double LinkedList::avgCentery(int a) {
	
	pointNode* current = head->getNext();
	
	int sumy = 0;
	int nop = 0;
	double result = 0;
	
	while(current != NULL) {
		
		if(current->getLabel() == a) {
			sumy = sumy + current->getYdata();
			nop++;
		}		
		current = current->getNext();
	}
	
	result = (double)sumy/nop;
	return result;
}

LinkedList::~LinkedList() { // destructor to free memory
	
	pointNode* current = head;
	pointNode* x;
	
	while (current != NULL) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
}
