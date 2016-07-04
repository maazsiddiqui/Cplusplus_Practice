#include "kmeans.h"
#include <math.h>
#include <fstream>

kmeans::kmeans() {
	listHead;
}

void kmeans::listInsert(int a, int b, int c) {
	listHead.insert(a, b, c);
}

int kmeans::getnumRow() {
	return numRow;
}

int kmeans::getnumCol() {
	return numCol;
}

int kmeans::getk() {
	return k;
}

double kmeans::getkcenter(int a) {
	return kcenter[a];
}

void kmeans::setnumRow(int a) {
	numRow = a;
}

void kmeans::setnumCol(int a) {
	numCol = a;
}

void kmeans::setk(int a) {
	k = a;
}

void kmeans::setkcenter(int a, double b) {
	kcenter[a] = b;
}

void kmeans::simplePrint(char* outfile) {
	
	pointNode* current = listHead.getNextNode();
	
	ofstream myoutfile(outfile); //open output file

	myoutfile << getk() << endl;
	myoutfile << to_string(getnumRow()) << " " << to_string(getnumCol()) << endl;
 
	while(current != NULL) {
		myoutfile << current->printPointnode();
		myoutfile << endl;
		current = current->getNext();
	}
	
	myoutfile.close();
	return;
}
	
void kmeans::startClustering() {

	kcenter = new double[k];
	for(int i = 0; i < k; i++) kcenter[i] = 0;
	
	center = new average[k];
	for(int i = 0; i < k; i++) {
		center[i].setx(0);
		center[i].sety(0);
	}
	
	imageArray = new int*[numRow];
	for(int i = 0; i < numRow; ++i) {
    	imageArray[i] = new int[numCol];
	}
	
	for(int i = 0; i < numRow; i++) {
		for(int j = 0; j < numCol; j++) {
			imageArray[i][j] = 0;
		}
	}

	labelChecker = true;
		
	while (labelChecker) {
		labelChecker = false;
		computeCenter();
		computeDistance();	
	}

	listHead.putonImage(imageArray);	
	
}

void kmeans::computeCenter() {
	
	for (int i = 0; i < k; i++) {
		center[i].setx(listHead.avgCenterx(i+1));
		center[i].sety(listHead.avgCentery(i+1));
	}
	
}

void kmeans::computeDistance() {
	
	pointNode* current = listHead.getNextNode();
	
	double distance1 = 0;
	double distance2 = 0;
	double distance3 = 0;
	double distance4 = 0;
	
	while(current != NULL) {
		
		distance1 = sqrt((pow((double)(current->getXdata() - center[0].getx()), 2)) + pow((double)(current->getYdata() - center[0].gety()), 2));
		distance2 = sqrt((pow((double)(current->getXdata() - center[1].getx()), 2)) + pow((double)(current->getYdata() - center[1].gety()), 2));
		distance3 = sqrt((pow((double)(current->getXdata() - center[2].getx()), 2)) + pow((double)(current->getYdata() - center[2].gety()), 2));
		distance4 = sqrt((pow((double)(current->getXdata() - center[3].getx()), 2)) + pow((double)(current->getYdata() - center[3].gety()), 2));
		
		if ((current->getDistance()) > (int)distance1) {								
			current->setLabel(1);
			current->setDistance(distance1);
			labelChecker = true;
		}
		
		if ((current->getDistance()) > (int)distance2) {								
			current->setLabel(2);
			current->setDistance(distance2);
			labelChecker = true;
		}
		
		if ((current->getDistance()) > (int)distance3) {
			current->setLabel(3);
			current->setDistance(distance3);
			labelChecker = true;
		}
		
		if ((current->getDistance()) > (int)distance4) {
			current->setLabel(4);
			current->setDistance(distance4);
			labelChecker = true;
		}
		
		current = current->getNext();
		
	}
	
	return;
}

void kmeans::printcenter() {
		for(int i = 0; i < k; i++) {
			cout << center[i].getx() << " ";
			cout << center[i].gety();
			cout << endl;
		}
}
	
void kmeans::displayImage(char* outfile) {
	
	ofstream myoutfile(outfile); //open output file
	
	for(int i = 0; i < numRow; i++) {
		for(int j = 0; j < numCol; j++) {
			if (imageArray[i][j] != 0) myoutfile << imageArray[i][j];
			else myoutfile << " ";
		}
		myoutfile << endl;
	}
	myoutfile.close();
	return;
}

kmeans::~kmeans() {
	delete[] kcenter;
	delete[] center;
	
	for(int i = 0; i < numRow; ++i) delete [] imageArray[i];
	delete [] imageArray;
	
}
