#include <iostream>
#include "Node.h"

Node::Node() : data("-9999"), next(nullptr) {

}

Node::Node(string a) : data(a), next(nullptr) {

}

string Node::getData() {
	return data;
}

Node* Node::getNext() {
	return next;
}

void Node::setNext(Node* n) {
	next = n;
}

Node::~Node() {}
