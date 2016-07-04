#include <iostream>
#include "linkedList.h"
using namespace std;

class kmeans {

private:
	
	struct average { 
		double x;
		double y;
		
		void setx(double a) {
			x = a;
		}
				
		void sety(double a) {
			y = a;
		}
		
		double getx() {
			return x;
		}
				
		double gety() {
			return y;
		}
	};
	
	int k;
	double* kcenter; // distance
	LinkedList listHead;
	average* center;
	int numRow;
	int numCol;
	int** imageArray;
	bool labelChecker;

public:

	kmeans();
	void listInsert(int a, int b, int c);
	int getnumRow();
	int getnumCol();
	int getk();
	double getkcenter(int a);
	void computeDistance();
	
	void setnumRow(int a);
	void setnumCol(int a);
	void setk(int a);
	void setkcenter(int a, double b);
	
	void startClustering();
	void displayImage(char* outfile);
	void printcenter();
	void computeCenter();
	void simplePrint(char* outfile);

	~kmeans();
};
