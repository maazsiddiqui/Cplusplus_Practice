#include <iostream>
using namespace std;

class graphNode {

private:
	int nodeID;
	graphNode* next;
	
public:
	graphNode();
	graphNode(int a);
	int getnodeID();
	graphNode* getNext();
	void setNodeID(int a);
	void setNext(graphNode* a);
	string printGraphNode();
};




