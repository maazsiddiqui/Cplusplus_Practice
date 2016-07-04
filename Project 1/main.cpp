#include <iostream>
#include <string>
#include <cstdlib>	// required for exit(1)
#include <fstream>	// required to work with files
#include "class_Roster.h"
#include "class_Student.h"
using namespace std;

void grow(Roster** &a, int& n) {
	
	Roster** temp = a;
	a = new Roster*[n * 2];
	
	for (int i = 0; i < n; i++) {
		a[i] = temp[i];
	}
	
	delete [] temp;
	n = n * 2;
	
} // end of grow function

// ========== Main Program ========== //

int main() {
	
	Roster** allrosters = NULL;
	int capacity = 10;
	int size = 0;
	allrosters = new Roster*[capacity];
	
	ifstream rosters;
	rosters.open("rosters.txt");
		
	if (!rosters.is_open()) {
    
		cout << "Rosters file not found" << endl << endl;
	
	}
	
	else {
		
		string temp1;
		int temp2;

		for (int i = 0; !rosters.eof(); i++) {
			
			Roster temp;
			
			if (i < capacity) {
				
				getline(rosters, temp1, '|');
				temp.setCname(temp1);
				
				getline(rosters, temp1, '|');
				temp.setCcode(temp1);
				
				getline(rosters, temp1, '|');
				temp2 = atoi(temp1.c_str()); 
				temp.setCcredits(temp2);
				
				getline(rosters, temp1, '\n');
				temp.setCinstructor(temp1);
				
				Student s1;
				double temp3;
				int datetemp1, datetemp2, datetemp3;
				
				for (int p = 0; getline(rosters, temp1, '|') && temp1 != "end_roster"; p++) {
					
					s1.set_firstName(temp1);
					
					getline(rosters, temp1, '|');
					s1.set_lastName(temp1);
					
					getline(rosters, temp1, '|');	// skipping standings
					
					getline(rosters, temp1, '|');
					temp2 = atoi(temp1.c_str());
					s1.set_credits(temp2);
					
					getline(rosters, temp1, '|');
					temp3 = atof(temp1.c_str());
					s1.set_gpa(temp3);
				
					getline(rosters, temp1, '/');
					datetemp1 = atoi(temp1.c_str());
					
					getline(rosters, temp1, '/');
					datetemp2 = atoi(temp1.c_str());
					
					getline(rosters, temp1, '|');
					datetemp3 = atoi(temp1.c_str());
					
					Date temp4(datetemp1, datetemp2, datetemp3);
					s1.set_dob(temp4);
					
					getline(rosters, temp1, '/');
					datetemp1 = atoi(temp1.c_str());
					
					getline(rosters, temp1, '/');
					datetemp2 = atoi(temp1.c_str());
					
					getline(rosters, temp1, '|');
					datetemp3 = atoi(temp1.c_str());
					
					temp4 = Date(datetemp1, datetemp2, datetemp3);
					s1.set_mat(temp4);
					
					getline(rosters, temp1, '\n');
					temp2 = atoi(temp1.c_str());
					s1.set_id(temp2);
					
					temp.setList(s1);
				
				}
			
				getline(rosters, temp1);			
				allrosters[i] = new Roster(temp);
				size++;

			}

			else {

				grow(allrosters, capacity);
				--i;

			}
			
		}
	
		rosters.close();
		
		ofstream out;
		out.open("rosters.txt", ofstream::out | ofstream::trunc);	// delete everything in rosters file
		out.close();

	} 
	
	char ans;
	
	cout << "ROSTER MANAGEMENT SYSTEM" << endl << endl;
	cout << "A: Supervisor Mode (requires password)" << endl;
	cout << "B: User Mode" << endl;
	cout << "C: Exit Program" << endl << endl;
	
	cout << "SELECT ANY OPTION: ";
	cin >> ans;
	ans = toupper(ans);
	
	if (ans == 'A') {	// supervisor mode selected
		
		ifstream database;
		database.open("database.txt");
		
		if (!database.is_open()) {

    		cout << "Database not found" << endl;
    		
    		ofstream outfile("rosters.txt");
		
			for (int i = 0; i < size; i++) {
				
				if (i > 0) outfile << endl;
				
				outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
				<< '|' << allrosters[i]->getCinstructor() << endl;
				
				for (int k = 0; k < allrosters[i]->getCount(); k++) {
					
					Student s1(allrosters[i]->getStudent(k));
					Date birth(s1.get_dob());
					Date matric(s1.get_mat());
					
					outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
							<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
							<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
					
				}
				outfile << "end_roster|";
			}
	
			outfile.close();
    		
    		exit(1);

		}
		
		string user, pass, temp;		
		cout << "Type username: ";
		cin >> user;
				
		while (!database.eof()) {
			
			getline(database, temp, ' ');
			
			if (user == temp) {
				
				cout << "Type password: ";
				cin >> pass;
				
				getline(database, temp, '\n');
				
				if (pass == temp) {
				
					system("CLS");
				
					while(true) {
					
						cout << "ROSTER MANAGEMENT SYSTEM" << endl << endl;
						cout << "1: Create a new roster" << endl;
						cout << "2: Drop a roster by course number" << endl;
						cout << "3: Display roster information by course number" << endl;
						cout << "4: Display all rosters" << endl;
						cout << "5: Select a roster to perform more operations" << endl;
						cout << "6: Exit Program" << endl << endl;
						
						cout << "SELECT ANY OPTION: ";
						cin >> ans;
						cin.ignore(1000, '\n');
						
						if (ans == '1') {	// create a new roster
						
							Roster temp;
							cout << endl;
							cin >> temp;
							
							if (size < capacity) {
							
								allrosters[size] = new Roster(temp);
								size++;
							
							}
		
							else {
								
								grow(allrosters, capacity);
								allrosters[size] = new Roster(temp);
								size++;
								
							}
							
						}
						
						else if (ans == '2') {	// delete roster by course number
							
							string temp;
							cout << "Give course number to drop roster: ";
							cin >> temp;
							
							for (int i = 0; i < size; i++) {
		
								if (temp == allrosters[i]->getCcode()) {
		
									*(allrosters[i]) = *(allrosters[size-1]);
									delete allrosters[size-1];
									size--;
									break;
		
								}
		
							}
		
						}
						
						else if (ans == '3') {	// display roster info by course number
							
							string temp;
							cout << "Give course number to display roster: ";
							cin >> temp;
							
							for (int i = 0; i < size; i++) {
		
								if (temp == allrosters[i]->getCcode()) {
									cout << *allrosters[i];
									break;
		
								}
		
							}	
		
						}
						
						else if (ans == '4') {
		
							for (int p = 0; p < size; p++) {
		
								cout << "ROSTER " << p+1;
								cout << *allrosters[p];
		
							}
		
						}
						
						else if (ans == '5') {	// perform more operations on selected roster
										
							string str1;				
							cout << "Give course number to perform additional operations: ";
							cin >> str1;
								
							while (true) {
								
								for (int i = 0; i < size; i++) {
									
									if (str1 == allrosters[i]->getCcode()) {
										
										cout << endl;
										cout << "A: Insert new student" << endl;
										cout << "B: Remove a student" << endl;
										cout << "C: Update Student" << endl;
										cout << "D: List all students sorted" << endl;
										cout << "E: Exit Program" << endl << endl;
										
										cout << "SELECT ANY OPTION: ";
										char ans;
										cin >> ans;
										cin.ignore(1000, '\n');
										ans = toupper(ans);
										
										if (ans == 'A') {
											
											allrosters[i]->add();
											cout << *allrosters[i];
											
										}
										
										else if (ans == 'B') {
											
											int sid;
											cout << "Give student number to delete student: ";
											cin >> sid;
											cin.ignore(1000, '\n');
											allrosters[i]->del(sid);
											cout << *allrosters[i];
													
										}
										
										else if (ans == 'C') {	// update student on selected roster
											
											int sid;
											cout << "Give student number to update info: ";
											cin >> sid;
											cin.ignore(1000, '\n');
											allrosters[i]->del(sid);
											allrosters[i]->add();
											cout << *allrosters[i];
		
										}
										
										else if (ans == 'D') {
		
											cout << *allrosters[i];
									
										}
										
										else if (ans == 'E') {
		
											cout << "Goodbye." << endl;
											
											ofstream outfile("rosters.txt");
		
											for (int i = 0; i < size; i++) {
												
												if (i > 0) outfile << endl;
												
												outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
												<< '|' << allrosters[i]->getCinstructor() << endl;
												
												for (int k = 0; k < allrosters[i]->getCount(); k++) {
													
													Student s1(allrosters[i]->getStudent(k));
													Date birth(s1.get_dob());
													Date matric(s1.get_mat());
													
													outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
															<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
															<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
													
												}
												outfile << "end_roster|";
											}
									
											outfile.close();
											
											exit(1);
		
										}
										
										else {
		
											cout << "Wrong Selection. Goodbye." << endl;
											
											ofstream outfile("rosters.txt");
		
											for (int i = 0; i < size; i++) {
												
												if (i > 0) outfile << endl;
												
												outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
												<< '|' << allrosters[i]->getCinstructor() << endl;
												
												for (int k = 0; k < allrosters[i]->getCount(); k++) {
													
													Student s1(allrosters[i]->getStudent(k));
													Date birth(s1.get_dob());
													Date matric(s1.get_mat());
													
													outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
															<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
															<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
													
												}
												outfile << "end_roster|";
											}
									
											outfile.close();
											
											exit(1);
		
										}
		
									}
		
								}
		
							}	
		
						}
						
						else if (ans == '6') {
		
							cout << "Goodbye. Don't forget to check rosters.txt file";
							database.close();
							
							ofstream outfile("rosters.txt");
		
							for (int i = 0; i < size; i++) {
								
								if (i > 0) outfile << endl;
								
								outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
								<< '|' << allrosters[i]->getCinstructor() << endl;
								
								for (int k = 0; k < allrosters[i]->getCount(); k++) {
									
									Student s1(allrosters[i]->getStudent(k));
									Date birth(s1.get_dob());
									Date matric(s1.get_mat());
									
									outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
											<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
											<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
									
								}
								outfile << "end_roster|";
							}
					
							outfile.close();
							
							exit(1);						
		
						}
						
						else {
		
							cout << "Wrong selection. Goodbye.";
							database.close();
							
							ofstream outfile("rosters.txt");
		
							for (int i = 0; i < size; i++) {
								
								if (i > 0) outfile << endl;
								
								outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
								<< '|' << allrosters[i]->getCinstructor() << endl;
								
								for (int k = 0; k < allrosters[i]->getCount(); k++) {
									
									Student s1(allrosters[i]->getStudent(k));
									Date birth(s1.get_dob());
									Date matric(s1.get_mat());
									
									outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
											<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
											<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
									
								}
								outfile << "end_roster|";
							}
					
							outfile.close();
							
							exit(1);
		
						}
	
				}

			}
	
				else {
					cout << "Wrong Password. Goodbye" << endl;
					database.close();
					
					ofstream outfile("rosters.txt");
		
					for (int i = 0; i < size; i++) {
						
						if (i > 0) outfile << endl;
						
						outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
						<< '|' << allrosters[i]->getCinstructor() << endl;
						
						for (int k = 0; k < allrosters[i]->getCount(); k++) {
							
							Student s1(allrosters[i]->getStudent(k));
							Date birth(s1.get_dob());
							Date matric(s1.get_mat());
							
							outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
									<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
									<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
							
						}
						outfile << "end_roster|";
					}
			
					outfile.close();
					
					exit(1);
	
				}
	
			}
	
			else {
	
				getline(database, temp);	// current line skipper & move to next line
	
			}
	
		}
		
		cout << "User not found. Goodbye" << endl;
		database.close();
		
		ofstream outfile("rosters.txt");
		
		for (int i = 0; i < size; i++) {
			
			if (i > 0) outfile << endl;
			
			outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
			<< '|' << allrosters[i]->getCinstructor() << endl;
			
			for (int k = 0; k < allrosters[i]->getCount(); k++) {
				
				Student s1(allrosters[i]->getStudent(k));
				Date birth(s1.get_dob());
				Date matric(s1.get_mat());
				
				outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
						<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
						<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
				
			}
			outfile << "end_roster|";
		}

		outfile.close();
		
		exit(1);
	
	}
	
	else if (ans == 'B') {	// user mode selected
		
		string str1;				
		cout << "Give course number to perform additional operations: ";
		cin >> str1;
			
		while (true) {
			
			for (int i = 0; i < size; i++) {
				
				if (str1 == allrosters[i]->getCcode()) {
					
					cout << endl;
					cout << "A: Insert new student" << endl;
					cout << "B: Remove a student" << endl;
					cout << "C: Update Student" << endl;
					cout << "D: Exit Program" << endl << endl;
					
					cout << "SELECT ANY OPTION: ";
					char ans;
					cin >> ans;
					cin.ignore(1000, '\n');
					ans = toupper(ans);
					
					if (ans == 'A') {
						
						allrosters[i]->add();
					
					}
					
					else if (ans == 'B') {
						
						int sid;
						cout << "Give student number to delete student: ";
						cin >> sid;
						cin.ignore(1000, '\n');
						allrosters[i]->del(sid);
								
					}
					
					else if (ans == 'C') {	// update student on selected roster
						
						int sid;
						cout << "Give student number to update info: ";
						cin >> sid;
						cin.ignore(1000, '\n');
						allrosters[i]->del(sid);
						allrosters[i]->add();
						
					}
					
					else if (ans == 'D') {
						cout << "Goodbye." << endl;
						
						ofstream outfile("rosters.txt");
		
						for (int i = 0; i < size; i++) {
							
							if (i > 0) outfile << endl;
							
							outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
							<< '|' << allrosters[i]->getCinstructor() << endl;
							
							for (int k = 0; k < allrosters[i]->getCount(); k++) {
								
								Student s1(allrosters[i]->getStudent(k));
								Date birth(s1.get_dob());
								Date matric(s1.get_mat());
								
								outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
										<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
										<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
								
							}
							outfile << "end_roster|";
						}
				
						outfile.close();
						
						exit(1);
					}
					
					else {
						
						cout << "Wrong Selection. Goodbye." << endl;
						
						ofstream outfile("rosters.txt");
		
						for (int i = 0; i < size; i++) {
							
							if (i > 0) outfile << endl;
							
							outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
							<< '|' << allrosters[i]->getCinstructor() << endl;
							
							for (int k = 0; k < allrosters[i]->getCount(); k++) {
								
								Student s1(allrosters[i]->getStudent(k));
								Date birth(s1.get_dob());
								Date matric(s1.get_mat());
								
								outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
										<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
										<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
								
							}
							outfile << "end_roster|";
						}
				
						outfile.close();
						
						exit(1);
						
					}
				}
			}
		}	
	}
	
	else if (ans == 'C') {	// exit program
		
		cout << "Goodbye" << endl;
		
		ofstream outfile("rosters.txt");
		
		for (int i = 0; i < size; i++) {
			
			if (i > 0) outfile << endl;
			
			outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
			<< '|' << allrosters[i]->getCinstructor() << endl;
			
			for (int k = 0; k < allrosters[i]->getCount(); k++) {
				
				Student s1(allrosters[i]->getStudent(k));
				Date birth(s1.get_dob());
				Date matric(s1.get_mat());
				
				outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
						<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
						<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
				
			}
			outfile << "end_roster|";
		}

		outfile.close();
		exit(1);
		
	}
	
	else {
		
		cout << "Wrong Selection. Goodbye" << endl;
		
		ofstream outfile("rosters.txt");
		
		for (int i = 0; i < size; i++) {
			
			if (i > 0) outfile << endl;
			
			outfile << allrosters[i]->getCname() << '|' << allrosters[i]->getCcode() << '|' << allrosters[i]->getCcredits() 
			<< '|' << allrosters[i]->getCinstructor() << endl;
			
			for (int k = 0; k < allrosters[i]->getCount(); k++) {
				
				Student s1(allrosters[i]->getStudent(k));
				Date birth(s1.get_dob());
				Date matric(s1.get_mat());
				
				outfile << s1.get_firstName() << '|' << s1.get_lastName() << '|' << s1.get_standing() << '|' << s1.get_credits() 
						<< '|' << s1.get_gpa() << '|' << birth.getMonthNum() << '/' << birth.getDay() << '/' << birth.getYear() 
						<< '|' << matric.getMonthNum() << '/' << matric.getDay() << '/' << matric.getYear() << '|'<< s1.get_id() << endl;
				
			}
			outfile << "end_roster|";
		}

		outfile.close();

		
		exit(1);
	
	}

	return 0;

}
