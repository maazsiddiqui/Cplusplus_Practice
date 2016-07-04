#include "PrimMST.h"
#include <fstream>

PrimMST::PrimMST(int a) {
	N = a;
	totalCost = 0;
	
	graphNodeIDarray = new int[N];
	for(int i = 0; i < N; i++) graphNodeIDarray[i] = 0;
	
	edgeList;
	setA;
	setB;
	MSTofG;
}
	
int PrimMST::getN() {
	return N;
}

int PrimMST::getTotalCost() {
	return totalCost;
}	

void PrimMST::setN(int a) {
	N = a;
	return;
}

void PrimMST::setTotalCost(int a) {
	totalCost = a;
	return;
}
	
void PrimMST::startPrim(char* outfile) {
	
	int k = -1;
	for(int i = 0; (i < N) && (k < 0); i++) {
		if(graphNodeIDarray[i] > 0) k = i;	
	}
	
	setA.insertGraphNode(k);
	
	for(int i = k+1; i < N; i++) {
		if(graphNodeIDarray[i] > 0) {
			k = i;
			setB.insertGraphNode(k);
		}	
	}

	int n1, n2;

	edgeNode* current = edgeList.getEdgeNode();
	current = current->getNext(); // skipping dummy node
	
	while ((current != NULL) && !(setB.isGraphNodeLLEmpty())) {
		
		n1 = current->getNi() - 1;
		n2 = current->getNj() - 1;
		
		if(setA.findNode(n1) == setB.findNode(n2)) {

			MSTofG.insertEdgeNode(n1+1, n2+1, current->getEdgeCost());

			totalCost += current->getEdgeCost();
			
			if(setA.findNode(n1)) {
				setA.insertGraphNode(n2);
				setB.deleteGraphNode(n2);
							
			}			
			else {
				setA.insertGraphNode(n1);
				setB.deleteGraphNode(n1);				
			}
			
			current = edgeList.getEdgeNode();
			
			ofstream myoutfile(outfile, ios::app); // output file reader from argument
			myoutfile << "Set A ";
			myoutfile.close();
			setA.printGraphNodeLL(outfile);
						
			ofstream myoutfile2(outfile, ios::app); // output file reader from argument
			myoutfile2 << "Set B ";
			myoutfile2.close();	
			setB.printGraphNodeLL(outfile);
			
			ofstream myoutfile3(outfile, ios::app); // output file reader from argument
			MSTofG.printEdgeNodeLL(outfile);
			myoutfile3.close();	
			
		}
		
		current = current->getNext();
	}
}


void PrimMST::printMSTofG(char* a) {
	
	ofstream myoutfile(a, ios::app); // output file reader from argument
	MSTofG.printEdgeNodeLL(a);
	myoutfile.close();
	
	ofstream myoutfile2(a, ios::app); // output file reader from argument
	myoutfile2 << "Total Cost: " << totalCost << endl;
	myoutfile2.close();
	return;
}

void PrimMST::insertEdgeList(int a, int b, int c) {
	edgeList.insertEdgeNode(a, b, c);
	graphNodeIDarray[a-1]++;
	graphNodeIDarray[b-1]++;
	return;
}

void PrimMST::printEdgeList(char* outfile) {
	edgeList.printEdgeNodeLL(outfile);
	return;
}

void PrimMST::printGraphNodeIDarray(char* outfile) {

	ofstream myoutfile(outfile); //open output file
	myoutfile << "No. of edges in each node" << endl;

	for(int i = 0; i < getN(); i++) {
		myoutfile << "Node " << i+1 << ": " << graphNodeIDarray[i] << endl;
	}
	myoutfile << endl;
	myoutfile.close();
	return;
}
	
PrimMST::~PrimMST() {
	delete[] graphNodeIDarray;
}
