#include "edgeNode.h"

edgeNode::edgeNode() {
	Ni = 9999;
	Nj = 9999;
	edgeCost = 9999;
	next = nullptr;
}
edgeNode::edgeNode(int a, int b, int c) {
	Ni = a;
	Nj = b;
	edgeCost = c;
	next = nullptr;
}

int edgeNode::getNi() {
	return Ni;
}

int edgeNode::getNj() {
	return Nj;
}

int edgeNode::getEdgeCost() {
	return edgeCost;
}

edgeNode* edgeNode::getNext() {
	return next;
}

void edgeNode::setNi(int a) {
	Ni = a;
	return;
}

void edgeNode::setNj(int a) {
	Nj = a;
	return;
}

void edgeNode::setEdgeCost(int a) {
	edgeCost = a;
	return;
}

void edgeNode::setNext(edgeNode* a) {
	next = a;
	return;
}

string edgeNode::printEdgeNode() {
	string temp = to_string(Ni) + "\t" + to_string(Nj) + "\t" + to_string(edgeCost);
	return temp;
}
