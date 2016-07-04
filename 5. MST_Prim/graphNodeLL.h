#include <iostream>
#include "graphNode.h"
using namespace std;

class graphNodeLL {

private:
	graphNode* head;
	
public:
	graphNodeLL();	
	void insertGraphNode(int a);
	void deleteGraphNode(int a);
	bool isGraphNodeLLEmpty();
	void printGraphNodeLL(char* outfile);
	bool findNode(int a);
	~graphNodeLL();
};
