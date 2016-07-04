#include "graphNode.h"


graphNode::graphNode() {
	nodeID = 9999;
	next = nullptr;
}

graphNode::graphNode(int a) {
	nodeID = a;
	next = nullptr;
}

int graphNode::getnodeID() {
	return nodeID;
}
	
graphNode* graphNode::getNext() {
	return next;
}
	
void graphNode::setNodeID(int a) {
	nodeID = a;
	return;
}

void graphNode::setNext(graphNode* a) {
	next = a;
	return;
}

string graphNode::printGraphNode() {
	return (to_string(nodeID+1)); // assuming node labels start from 1 not 0
}





	

