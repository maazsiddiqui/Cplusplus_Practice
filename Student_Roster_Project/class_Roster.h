#ifndef CLASS_ROSTER_H
#define CLASS_ROSTER_H

#include <iostream>
#include "class_Student.h"
using namespace std;

// ========== Class for Roster ========== //

class Roster {

	private:
		string courseName;
		string courseCode;
		int courseCredits;
		string courseInstructor;
		int count;
		int capacity;
		Student** list;
		void grow();
		void sort(Student* a[], int size);

	public:
		// 	default constructor
		Roster();
		
		// copy constructor
		Roster(const Roster& b);
		
		//	constructor to initialize Roster by accepting all the parameters
		Roster(string course_Name, string courseCode, int course_Credits, string course_Instructor, int capacity_);
		
		//	destructor
		~Roster();
		
		//	required functions
		void add();
		void del(int n);
		void search();
		
		//	accessor functions
		string getCname();
		string getCcode();
		int getCcredits();
		string getCinstructor();
		void getList(int n);
		int getCount();
		Student getStudent(int i);
		
		//	mutator functions
		void setCname(string n);
		void setCcode(string n);
		void setCcredits(int n);
		void setCinstructor(string n);
		void setList(Student s);
		
		//	operator overload
		Roster& operator = (const Roster& b);
		friend istream& operator >> (istream& in, Roster& a);
		friend ostream& operator << (ostream& out, const Roster& a);
};

#endif
