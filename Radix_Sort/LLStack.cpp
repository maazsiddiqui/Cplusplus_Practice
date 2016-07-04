#include <iostream>
#include <fstream> // class necessary to read files
//#include <sstream> // required to convert int to string easily
#include "LLStack.h" // Linked List header

using namespace std;

LLStack::LLStack() { // default constructor
	Top = nullptr;
}

Node* LLStack::getTop() {
	
	return Top;
}

void LLStack::push(string a) { // push new node on top of stack

	Node* n = new Node(a);
	
	if (Top == nullptr) Top = n;
	else {
		n->setNext(Top);
		Top = n;
	}
	return;
}

string LLStack::pop() {
	
	string temp = "";
	Node* n = Top;
	
	if (isEmpty() != 1) {
		temp = Top->getData();
		Top = Top->getNext();
		delete n;
	}
	return temp;
}

bool LLStack::isEmpty() {
	return (Top == nullptr);
}

void LLStack::printStack() { // special format output function as required

	Node* current = Top;
	
	while (current != nullptr) {
		cout << current->getData() << " ";
		current = current->getNext();
	}	

	return;
}

void LLStack::printToFile(char* outputFile) {

	ofstream myoutfile(outputFile, ios::app); //open output file
	
	outFile = outputFile;
	Node* current = Top;

	myoutfile << "Stack";

	while (current != nullptr) {
		myoutfile << " --> (" + current->getData() + ")" ;
		current = current->getNext();
	}
	
	myoutfile << endl;
	
	myoutfile.close(); // close output file
	return;
}


LLStack::~LLStack() { // destructor to free memory
	
	Node* current = Top;
	Node* x;
	
	while (current != nullptr) {
		x = current;
		current = current->getNext();
		delete x; // release memory one by one
	}
	
}
