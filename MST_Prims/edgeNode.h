#include <iostream>
using namespace std;

class edgeNode {

private:
	int Ni;
	int Nj;
	int edgeCost;
	edgeNode* next;
	
public:
	edgeNode();
	edgeNode(int a, int b, int c);
	int getNi();
	int getNj();
	int getEdgeCost();
	edgeNode* getNext();
	void setNi(int a);
	void setNj(int a);
	void setEdgeCost(int a);
	void setNext(edgeNode* a);
	string printEdgeNode();
};
