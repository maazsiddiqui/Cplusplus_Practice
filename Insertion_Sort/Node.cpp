#include <iostream>
#include "Node.h"

Node::Node() : data(-9999), next(NULL) {

	}

Node::Node(int a) : data(a), next(NULL) {

	}

	int Node::getData() {
		return data;
	}

	Node* Node::getNext() {
		return next;
	}

	void Node::setNext(Node* n) {
		next = n;
	}

	Node::~Node(){}
