#include <iostream>
#include "class_Student.h"
#include "class_Roster.h"
using namespace std;

// default constructor
Roster::Roster() {
	
	courseName = "";
	courseCode = "";
	courseCredits = 0;
	courseInstructor = "";
	count = 0;
	capacity = 10;
	list = new Student*[capacity];
	
}	// end of default constructor

//	copy constructor
Roster::Roster(const Roster& b) {
	
	courseName = b.courseName;
	courseCode = b.courseCode;
	courseCredits = b.courseCredits;
	courseInstructor = b.courseInstructor;
	count = b.count;
	capacity = b.capacity;
	list = new Student*[capacity];
	
	for (int i = 0; i < b.count; i++) {
		list[i] = new Student(*(b.list[i]));
	}
	
}	// end of copy constructor

//	constructor to initialize Roster by accepting all the parameters
Roster::Roster(string course_Name, string course_Code, int course_Credits, string course_Instructor, int capacity_) {
	
	courseName = course_Name;
	courseCode = course_Code;
	courseCredits = course_Credits;
	courseInstructor = course_Instructor;
	count = 0;
	if (capacity_ > 0) capacity = capacity_;
	else capacity = 10;
	list = new Student*[capacity];
	
}	// end of constructor

// Destructor
Roster::~Roster() {
	
	if (this != NULL) {
		for (int i = 0; i < count; i++) {
			delete list[i];
		}
		delete [] list;
	}
	
}

// ========== Accessor Functions ========== //

string Roster::getCname() {
	return courseName;
}

string Roster::getCcode() {
	return courseCode;
}

int Roster::getCcredits() {
	return courseCredits;
}

string Roster::getCinstructor() {
	return courseInstructor;
}

int Roster::getCount() {
	return count;
}

void Roster::getList(int n) {
	cout << *(list[n-1]);
	cout << endl;
}

Student Roster::getStudent(int i) {
	return *(list[i]);

}

// ========== Mutator Functions ========== //

void Roster::setCname(string n) {
	courseName = n;
}

void Roster::setCcode(string n) {
	courseCode = n;
}

void Roster::setCcredits(int n) {
	courseCredits = n;
}

void Roster::setCinstructor(string n) {
	courseInstructor = n;
}

void Roster::setList(Student s) {
	
	if (count >= capacity) grow();
	list[count] = new Student;
	*(list[count]) = s;	
	count++;
	sort(list, count-1);
	
}

// ========== Add Function ========== //

void Roster::add() {
	
	if (count >= capacity) grow();
	Student s1;
	cin >> s1;
	list[count] = new Student;
	*(list[count]) = s1;
	count++;
	sort(list, count-1);
	
}	// end of add function

// ========== Delete Function ========== //

void Roster::del(int n) {
	
	if (n >= 1 && n <= count) {
		*(list[n-1]) = *(list[count-1]);
		delete list[count-1];
		count--;
	sort(list, count-1);
	}
	
	else cout << "Wrong index";
	
}	// end of delete function

// ========== Search Function ========== //

void Roster::search() {
	
	string first;
	string last;
	
	cout << "SEARCH STUDENT" << endl;
	cout << "Give student's first name: ";
	cin >> first;
	cout << "Give student's last name: ";
	cin >> last;

	for (int n = 0; n < count; n++) {
		if ((list[n]->Student::get_lastName() == last) && (list[n]->Student::get_firstName() == first)) {
			cout << endl;
			cout << *(list[n]);
			cout << "Found student on location: " << n+1 << endl << endl;
			return;
		}
	}
	cout << "No Student Found" << endl;
}	// end of search function

// ========== Operator Overloading ========== //

Roster& Roster::operator = (const Roster& b) {

	if (this == &b) return *this;
	else {
		courseName = b.courseName;
		courseCode = b.courseCode;
		courseCredits = b.courseCredits;
		courseInstructor = b.courseInstructor;
		count = b.count;
		capacity = b.capacity;
		if (list != NULL) {
			for (int i = 0; i < count; i++) {
				delete list[i];
			}
			delete [] list;
		}
		list = new Student*[b.capacity];
		for (int i = 0; i < b.count; i++) {
			list[i] = new Student(*(b.list[i]));
		}
		return *this;
	}
} // end of = operator

istream& operator >> (istream& in, Roster& a) {

	cout << "Give Course Name: ";
	getline (cin, a.courseName);
	
	cout << "Give Course Code: ";
	getline (cin, a.courseCode);
	
	cout << "Give Course Credits: ";
	cin >> a.courseCredits;
	cin.ignore(1000, '\n');
	
	cout << "Give Course Instructor: ";
	getline (cin, a.courseInstructor);
	
}	// end of cin operator

ostream& operator << (ostream& out, const Roster& a) {
	
	cout << endl;
	cout << "======================================" << endl;
	cout << "Course Name: " << a.courseName << endl;
	cout << "Course Code: " << a.courseCode << endl;
	cout << "Course Credits: " << a.courseCredits << endl;
	cout << "Course Instructor: " << a.courseInstructor << endl;
	cout << "======================================" << endl << endl;
	
	for (int n = 0; n < a.count; n++) {
		cout << "Student " << n+1 << endl;
		cout << "--------------------------------------" << endl;
		cout << *(a.list[n]);
		cout << endl;
	}
	cout << "======================================" << endl;
	
}	// end of cout operator

// ========== Sort Function ========== //

void Roster::sort(Student* a[], int size) {

	for (int i = 0; i <= size; i++) {
		int smallestindex = i;
		
		for (int j = i + 1; j <= size; j++) {
		
			if (*(a[j]) < *(a[smallestindex])) {
				smallestindex = j;
			}
			
			if (i != smallestindex) {
				Student temp = *(a[i]);
				*(a[i]) = *(a[smallestindex]);
				*(a[smallestindex]) = temp;
			}
		}	
	}
}	// end of sort function

// ========== Grow Function ========== //

void Roster::grow() {
	
	Student** temp = list;
	list = new Student*[capacity * 2];
	
	for (int i = 0; i < capacity; i++) {
		list[i] = temp[i];
	}
	
	delete [] temp;
	capacity = capacity * 2;
} // end of grow function
