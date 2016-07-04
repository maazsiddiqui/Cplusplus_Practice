#include <iostream>
#include <cstdlib>		// required for exit(1)
#include "class_Student.h"	// linked with student header
#include "Date.h"
using namespace std;

//	1. constructor that initializes a Student by accepting all the parameters
	
Student::Student(string lName, string fName, int cdts, double gp, Date dob_, Date mat_, int id_) {

	lastName = lName;
	firstName = fName;
	credits = cdts;
	gpa = gp;
	dob = dob_;
	mat = mat_;
	
	if 		(credits < 0)						exit(1);
	else if (credits >= 0 && credits <= 26) 	standing = "Freshmen";
	else if (credits >= 27 && credits <= 59) 	standing = "Sophomore";
	else if (credits >= 60 && credits <= 89) 	standing = "Junior";
	else				 						standing = "Senior";
	
	id = id_;
		
}	// end of constructor 1
	
//	2. default constructor that initializes everything to default value
	
Student::Student() {
	
	lastName = " ";
	firstName = " ";
	standing = "Freshman";
	credits = 0;
	gpa = 0;
	dob;
	mat;
	id = 0;
	
}	// end of default constructor	

// ========== Accessor Functions ========== //

string Student::get_lastName() const 	{ 	return lastName;	}
string Student::get_firstName() const 	{	return firstName;	}		
string Student::get_standing() const	{	return standing;	}
int Student::get_credits() const		{	return credits;		}
double Student::get_gpa() const 		{	return gpa;			}
Date Student::get_dob() const			{	return dob;			}
Date Student::get_mat() const			{	return mat;			}
int Student::get_id() const				{	return id;			}

// end of accessor functions

// ========== Mutator Functions ========== //

void Student::set_lastName(string a)		{	lastName = a;		}
void Student::set_firstName(string b)		{	firstName = b;		}
void Student::set_gpa(double e)				{	gpa = e;			}
void Student::set_dob(Date f)				{	dob = f;			}
void Student::set_mat(Date i)				{	mat = i;			}
void Student::set_credits(int d)			{	credits = d;

	if 		(credits < 0)						exit(1);
	else if (credits >= 0 && credits <= 26) 	standing = "Freshmen";
	else if (credits >= 27 && credits <= 59) 	standing = "Sophomore";
	else if (credits >= 60 && credits <= 89) 	standing = "Junior";
	else				 						standing = "Senior";

}

void Student::set_id(int l)					{	id = l;				}

// end of mutator functions

// ========== Operator Overloading ========== //

bool Student::operator == (const Student& b) const {

	return (lastName == b.lastName && firstName == b.firstName && id == b.id);

}	// end of == operator

bool Student::operator != (const Student& b) const {

	return (lastName != b.lastName && firstName != b.firstName && id != b.id);

}	// end of != operator

bool Student::operator < (const Student& b) const {

	if (lastName < b.lastName) return true;
	else if (lastName == b.lastName && firstName < b.firstName) return true;
	else if (lastName == b.lastName && firstName == b.firstName && id < b.id) return true;
	else return false;

}	// end of < operator

bool Student::operator > (const Student& b) const {

	if (lastName > b.lastName) return true;
	else if (lastName == b.lastName && firstName > b.firstName) return true;
	else if (lastName == b.lastName && firstName == b.firstName && id > b.id) return true;
	else return false;

}	// end of > operator

bool Student::operator <= (const Student& b) const {

	if (lastName <= b.lastName) return true;
	else return false;
	
}	// end of <= operator

bool Student::operator >= (const Student& b) const {

	if (lastName >= b.lastName) return true;
	else return false;

}	// end of >= operator

istream& operator >> (istream& in, Student& a) {

	cout << "Give last name: ";
	getline (cin, a.lastName);
	
	cout << "Give first name: ";
	getline (cin, a.firstName);

	cout << "Total credits earned: ";
	cin >> a.credits;
	cin.ignore(1000, '\n');
	
	if 		(a.credits < 0)						exit(1);
	else if (a.credits >= 0 && a.credits <= 26) 	a.standing = "Freshmen";
	else if (a.credits >= 27 && a.credits <= 59) 	a.standing = "Sophomore";
	else if (a.credits >= 60 && a.credits <= 89) 	a.standing = "Junior";
	else				 							a.standing = "Senior";
	
	cout << "Total GPA: ";
	cin >> a.gpa;
	cin.ignore(1000, '\n');
	
	cout << "Provide date of birth" << endl;
	cin >> a.dob;
	cin.ignore(1000, '\n');
	
	cout << "Provide date of matriculation" << endl;
	cin >> a.mat;
	cin.ignore(1000, '\n');
	
	cout << "Provide ID: ";
	cin >> a.id;
	cin.ignore(1000, '\n');
	
	return in;

}	// end of cin operator

ostream& operator << (ostream& out, const Student& a) {

	cout << "Student Name: " << a.firstName << " " << a.lastName << endl;
	
	cout << "Total Credits Earned: " << a.credits << endl;
	
	cout << "Academic Standing: " << a.standing << endl;
	
	cout << "Total GPA: " << a.gpa << endl;
	
	cout << "Date of Birth: " << a.dob;
	
	cout << "Date of Matriculation: " << a.mat;
	
	cout << "ID: " << a.id << endl;
	
	cout << endl;
	
	return out;

}	// end of cout operator
