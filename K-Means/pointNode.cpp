#include "pointNode.h"

pointNode::pointNode() : xdata(-9999), ydata(-9999), distance(9999), label(-9999), next(nullptr) {

}

pointNode::pointNode(int a, int b, int c) : xdata(a), ydata(b), label(c), distance(9999), next(nullptr) {

}

int pointNode::getXdata() {
	return xdata;
}

int pointNode::getYdata() {
	return ydata;
}

int pointNode::getLabel() {
	return label;
}

double pointNode::getDistance() {
	return distance;
}

pointNode* pointNode::getNext() {
	return next;
}

void pointNode::setXdata(int a) {
	xdata = a;
	return;	
}

void pointNode::setYdata(int a) {
	ydata = a;
	return;
}

void pointNode::setLabel(int a) {
	label = a;
	return;
}
void pointNode::setDistance(double a) {
	distance = a;
	return;
}

void pointNode::setNext(pointNode* n) {
	next = n;
}

string pointNode::printPointnode() {
	return (to_string(getXdata())+ " " + to_string(getYdata()) + " " + to_string(getLabel()) + " ");
}

pointNode::~pointNode() {}

