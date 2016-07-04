#include <iostream>
#include "edgeNode.h"
using namespace std;

class edgeNodeLL {

private:
	edgeNode* head;
	
public:
	edgeNodeLL();
	edgeNode* getEdgeNode();	
	void insertEdgeNode(int a, int b, int c);
	void deleteEdgeNode(int a, int b, int c);
	bool isEdgeNodeLLEmpty();
	void printEdgeNodeLL(char* a);
	~edgeNodeLL();
};
