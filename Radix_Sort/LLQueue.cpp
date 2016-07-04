#include <iostream>
#include <fstream> // class necessary to read files
//#include <sstream> // required to convert int to string easily
#include "LLQueue.h" // Linked List header

using namespace std;

LLQueue::LLQueue() { // default constructor
	
	head = new Node();
	tail = head;
}

void LLQueue::addTail(string a) { // push new node on top of queue

	Node* n = new Node(a);
	
	n->setNext(tail->getNext());
	tail->setNext(n);
	tail = tail->getNext();
	
	return;
}

string LLQueue::deleteHead() {
	
	if (isEmpty()) return "Empty Queue";
	
	Node* current = head->getNext();
	if (current == tail) tail = head;
	head->setNext(current->getNext());
	string temp = current->getData(); // head point to dummy so skipping head
//	delete current;
	
	return temp;
}

bool LLQueue::isEmpty() {
	return (head == tail);
}

void LLQueue::printQueue() { // special format output function as required

	Node* current = head->getNext();
	
	while (current != nullptr) {
		cout << current->getData() << " ";
		current = current->getNext();
	}	

	return;	

}

void LLQueue::printFileQueue(char* outputFile) {

	ofstream myoutfile(outputFile, ios::app); //open output file
	
	outFile = outputFile;
	Node* current = head->getNext();

	while (current != nullptr) {
		myoutfile << " --> (" + current->getData() + ")" ;
		current = current->getNext();
	}
	
	myoutfile.close(); // close output file
	return;
}


LLQueue::~LLQueue() { // destructor to free memory
	
	Node* current = head;
	Node* x;
	
	while (current != nullptr) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
	
}
