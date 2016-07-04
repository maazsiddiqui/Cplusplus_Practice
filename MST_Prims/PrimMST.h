#include <iostream>
#include "graphNodeLL.h"
#include "edgeNodeLL.h"
using namespace std;

class PrimMST {

private:
	int N; // no. of nades in G
	int totalCost;
	int* graphNodeIDarray;
	edgeNodeLL edgeList;
	graphNodeLL setA;
	graphNodeLL setB;
	edgeNodeLL MSTofG;

public:
	PrimMST(int a);
	int getN();
	int getTotalCost();
	void setN(int a);
	void setTotalCost(int a);
	void startPrim(char* outfile);
	void insertEdgeList(int a, int b, int c);
	void printEdgeList(char* outfile);
	void printGraphNodeIDarray(char* outfile);
	void printMSTofG(char* a);
	~PrimMST();
};
