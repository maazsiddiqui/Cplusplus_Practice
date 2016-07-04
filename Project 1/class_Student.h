#ifndef CLASS_STUDENT_H
#define CLASS_STUDENT_H

#include <iostream>
#include "Date.h"
using namespace std;

// ========== Class for Student ========== //

class Student {

	private:
		
		string lastName;
		string firstName;
		string standing;
		int credits;
		double gpa;
		Date dob;
		Date mat;
		int id;
		
	public:
		
		//	default constructor that initializes everything to default value
		Student();
		
		//	constructor to initialize Student by accepting all the parameters
		Student(string lName, string fName, int cdts, double gp, Date dob_, Date mat_, int id_);

		//	Accessor Function Prototypes
		string get_lastName() const;
		string get_firstName() const;
		string get_standing() const;
		int get_credits() const;
		double get_gpa() const;
		Date get_dob() const;
		Date get_mat() const;
		int get_id() const;
		
		//	Mutator Function Prototypes
		void set_lastName(string a);
		void set_firstName(string b);
		void set_standing(string c);
		void set_credits(int d);
		void set_gpa(double e);
		void set_dob(Date f);
		void set_mat(Date i);
		void set_id(int l);
		
		//	Operator Overloading
		bool operator == (const Student& b) const;
		bool operator != (const Student& b) const;
		bool operator < (const Student& b) const;
		bool operator > (const Student& b) const;
		bool operator <= (const Student& b) const;
		bool operator >= (const Student& b) const;
		friend istream& operator >> (istream& in, Student& a);
		friend ostream& operator << (ostream& out, const Student& a);
		
};	// end of class student

#endif
