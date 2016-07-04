#include <iostream>
using namespace std;

class pointNode {

private:
	int xdata;
	int ydata;
	int label;
	int distance;
	pointNode* next;

public:

	pointNode();

	pointNode(int a, int b, int c);

	int getXdata();
	int getYdata();
	int getLabel();
	double getDistance();
	pointNode* getNext();

	void setXdata(int a);
	void setYdata(int a);
	void setLabel(int a);
	void setDistance(double a);
	void setNext(pointNode* n);
	
	string printPointnode();

	~pointNode();
};


