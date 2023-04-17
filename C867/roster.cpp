#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
#include <array>
#include <string>
using namespace std;

//Roster Class function definitions

//Class Constructor
Roster::Roster(int classSz) {
    this->classSize = classSz;
    this->index = 0;
    for (int i = 0; i < classSize; ++i) {
        this->classRosterArray[i] = new Student;
    }
    return;
}
//Get student ID from Student class
string Roster::GetStudentID(int index) {

    string id = classRosterArray[index]->GetID();
    return id;
}
// Creating new Student objects in the classRosterArray
void Roster::add(string stdntData) {
    if (index < classSize) {
        string id, fname, lname, emailAd;
        int yrsOld, compTime1, compTime2, compTime3;

        classRosterArray[index] = new Student();

        int i = stdntData.find(",");
        id = stdntData.substr(0, i);
        classRosterArray[index]->SetID(id);

        int j = i + 1;
        i = stdntData.find(",", j);
        fname = stdntData.substr(j, i - j);
        classRosterArray[index]->SetFirstName(fname);

        j = i + 1;
        i = stdntData.find(",", j);
        lname = stdntData.substr(j, i - j);
        classRosterArray[index]->SetLastName(lname);

        j = i + 1;
        i = stdntData.find(",", j);
        emailAd = stdntData.substr(j, i - j);
        classRosterArray[index]->SetEmailAddress(emailAd);

        j = i + 1;
        i = stdntData.find(",", j);
        yrsOld = stoi(stdntData.substr(j, i - j));
        classRosterArray[index]->SetAge(yrsOld);

        j = i + 1;
        i = stdntData.find(",", j);
        compTime1 = stoi(stdntData.substr(j, i - j));

        j = i + 1;
        i = stdntData.find(",", j);
        compTime2 = stoi(stdntData.substr(j, i - j));

        j = i + 1;
        i = stdntData.find(",", j);
        compTime3 = stoi(stdntData.substr(j, i - j));
        classRosterArray[index]->SetDaysToComp(compTime1, compTime2, compTime3);

        j = i + 1;
        i = stdntData.find(",", j);
        string type = stdntData.substr(j, i - j);
        if (type == "SECURITY") {
            classRosterArray[index]->SetDegreeProgram(SECURITY);
        }
        else if (type == "NETWORK") {
            classRosterArray[index]->SetDegreeProgram(NETWORK);
        }
        else if (type == "SOFTWARE") {
            classRosterArray[index]->SetDegreeProgram(SOFTWARE);
        }
        else {
            cout << "Unknown Degree." << endl;
        }
        ++index;
    }
}
void Roster::remove(string id) {
    bool foundStudent = false;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i] == nullptr) {
            continue;
        }
        if (id == classRosterArray[i]->GetID()) {
            classRosterArray[i] = nullptr;
            foundStudent = true;
            break;
        }
    }
    if (!foundStudent) {
        cout << "Error: Student " << id << " Not Found." << endl;
    }
    else {
        cout << "Student " << id << " removed." << endl;
    }
}

void Roster::printAll() {
    cout << "All current students: " << endl;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i] != nullptr) {
            classRosterArray[i]->PrintAllStudentInfo();
        }
    }
    cout << endl;
}

void Roster::printAverageDaysInCourse(string id) {
    for (int i = 0; i < classSize; ++i) {
        if (id == classRosterArray[i]->GetID()) {
            int temparray[3] = { classRosterArray[i]->GetDaysToComp1(), classRosterArray[i]->GetDaysToComp2(), classRosterArray[i]->GetDaysToComp3() };
            double averageDays = (static_cast<double>(temparray[0]) + static_cast<double>(temparray[1]) + static_cast<double>(temparray[2])) / 3.0;
            cout << id << "'s Average Days In Courses: " << averageDays << endl;
        }
    }
}

void Roster::printInvalidEmails() {
    cout << "Invalid Email:" << endl;
    for (int i = 0; i < classSize; ++i) {
        string emailAd = classRosterArray[i]->GetEmailAddress();
        if ((emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos) || (emailAd.find('@') == string::npos)) {
            cout << classRosterArray[i]->GetID() << "'s email address " << emailAd << " is invalid." << endl;
        }
    }
    cout << endl;
}

void Roster::printByDegreeProgram(degree degrPr) {
    string degreeString;
    if (degrPr == SECURITY) {
        degreeString = "SECURITY";
    }
    else if (degrPr == NETWORK) {
        degreeString = "NETWORK";
    }
    else if (degrPr == SOFTWARE) {
        degreeString = "SOFTWARE";
    }
    else {
        degreeString = "ERROR";
    }
    cout << "Students within degree program: " << degreeString << endl;
    int numStudents = 0;
    for (int i = 0; i < classSize; ++i) {
        if (classRosterArray[i]->GetDegreeProg() == degrPr) {
            classRosterArray[i]->PrintAllStudentInfo();
            ++numStudents;
        }
    }
    if (numStudents == 0) {
        cout << "Error: No students found within this degree program." << endl;
    }
}

Roster::~Roster() {
    return;
}