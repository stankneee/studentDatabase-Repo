#include <iostream>
#include <string>
#include "degree.h"
using namespace std;
#include "student.h"

//Student class function definitions

//Constructor
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToComp[0] = 0;
	this->daysToComp[1] = 0;
	this->daysToComp[2] = 0;
	this->degrProg;
}
//Set Student ID
void Student::SetID(string id) {
	this->studentID = id;

	return;
}
//Set Student First Name
void Student::SetFirstName(string fName) {
	this->firstName = fName;

	return;
}
//Set Student Last Name
void Student::SetLastName(string lName) {
	this->lastName = lName;

	return;
}
//Set Student Email
void Student::SetEmailAddress(string emailAd) {
	this->emailAddress = emailAd;

	return;
}
//Set Student Age
void Student::SetAge(int yrsOld) {
	this->age = yrsOld;

	return;
}
//Set Number of Days to Complete Each Course
void Student::SetDaysToComp(int compTime1, int compTime2, int compTime3) {
	this->daysToComp[0] = compTime1;
	this->daysToComp[1] = compTime2;
	this->daysToComp[2] = compTime3;

	return;
}
//Sets Students Degree Program
void Student::SetDegreeProgram(degree degrPr) {
	this->degrProg = degrPr;

	return;
}
//Gets Student ID
string Student::GetID() {
	return studentID;
}
//Gets Student First Name
string Student::GetFirstName() {
	return firstName;
}
//Gets Student Last Name
string Student::GetLastName() {
	return lastName;
}
//Gets Student Email
string Student::GetEmailAddress() {
	return emailAddress;
}
//Gets Student Age
int Student::GetAge() {
	return age;
}
//Gets Student Days To Finish Each Course
int Student::GetDaysToComp1() {
	return daysToComp[0];
}
int Student::GetDaysToComp2() {
	return daysToComp[1];
}
int Student::GetDaysToComp3() {
	return daysToComp[2];
}
//Get's Student Program
degree Student::GetDegreeProg() {
	return degrProg;
}
//Prints Student ID
void Student::PrintID() {
	cout << studentID;

	return;
}
//Prints Student First Name
void Student::PrintFirstName() {
	cout << firstName << endl;

	return;
}
//Prints Student Last Name
void Student::PrintLastName() {
	cout << lastName << endl;

	return;
}
//Prints Student Email
void Student::PrintEmailAddress() {
	cout << emailAddress << endl;

	return;
}
//Prints Student Age
void Student::PrintAge() {
	cout << age << endl;

	return;
}
//Prints Student Days Taken to Complete Each Course
void Student::PrintDaysToComp() {
	cout << daysToComp[0] << ", " << daysToComp[1] << ", " << daysToComp[2] << endl;

	return;
}
//Prints Student Degree Type
void Student::PrintDegreeProg() {
	string degreeString;
	if (degrProg == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degrProg == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degrProg == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}
	cout << degreeString << endl;

	return;
}
//Prints Student Info 
void Student::PrintAllStudentInfo() {
	string degreeString;
	if (degrProg == SECURITY) {
		degreeString = "SECURITY";
	}
	else if (degrProg == NETWORK) {
		degreeString = "NETWORK";
	}
	else if (degrProg == SOFTWARE) {
		degreeString = "SOFTWARE";
	}
	else {
		degreeString = "ERROR";
	}

	cout << studentID << "   First Name: " << firstName << "   Last Name: " << lastName << "   Age: " << age << "   daysInCourse: {" << daysToComp[0] << ", " << daysToComp[1]
		<< ", " << daysToComp[2] << "}   Degree Program: " << degreeString << "." << endl;

	return;
}
