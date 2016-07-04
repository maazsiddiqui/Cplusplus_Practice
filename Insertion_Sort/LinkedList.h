#include <iostream>

class LinkedList {

	struct Node { // nested Node struct
		int data;
		Node* next;

		Node::Node() : data(-9999), next(NULL) {} // default constructor

		Node::Node(int a) : data(a), next(NULL) {} // constructor with only integer parameter

		// getter functions

		int Node::getData() {
			return data;
		}

		Node* Node::getNext() {
			return next;
		}

		// setter functions

		void Node::setNext(Node* n) {
			next = n;
		}

	};

	Node* head;

public:

	LinkedList::LinkedList(); // default constructor for Linked List

	void LinkedList::insert(int a); // insert function which will also help in sorting

	std::string LinkedList::printLL(); // special format Linked List print function

	LinkedList::~LinkedList(); // destructor to free memory

};