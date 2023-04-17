#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

//Student class header file and declarations

class Student {
public:
	Student();
	// Accessor Functions
	string GetID();
	string GetFirstName();
	string GetLastName();
	string GetEmailAddress();
	int GetAge();
	int GetDaysToComp1();
	int GetDaysToComp2();
	int GetDaysToComp3();
	degree GetDegreeProg();

	// Mutator Functions
	void SetID(string id);
	void SetFirstName(string fName);
	void SetLastName(string lName);
	void SetEmailAddress(string emailAd);
	void SetAge(int yrsOld);
	void SetDaysToComp(int compTime1, int compTime2, int compTime3);
	void SetDegreeProgram(degree degrPr);

	// Output Functions
	void PrintID();
	void PrintFirstName();
	void PrintLastName();
	void PrintEmailAddress();
	void PrintAge();
	void PrintDaysToComp();
	void PrintDegreeProg();
	void PrintAllStudentInfo();

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComp[3];
	degree degrProg;

};


#endif

