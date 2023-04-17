#ifndef ROSTER_H
#define ROSTER_H
#include <iostream>
#include <string>
#include "degree.h"
#include <array>

// Declarations for the Roster class

class Roster {
public:
    // Constructor with class size parameter
    Roster(int);

    // Accessor for student ID by index
    std::string GetStudentID(int index);

    // Adds a student to the roster
    void add(std::string studentData);

    // Removes a student from the roster by ID
    void remove(std::string studentID);

    // Prints all students in the roster
    void printAll();

    // Prints the average number of days each student took to complete their courses
    void printAverageDaysInCourse(std::string studentID);

    // Prints any invalid emails in the roster
    void printInvalidEmails();

    // Prints all students in the roster by degree program
    void printByDegreeProgram(degree degreeProgram);
    // Destructor
    ~Roster();

    // Size of the roster
    int classSize;

    // Index of the next available spot in the roster
    int index;

private:
    // Array of pointers to Student objects
    Student* classRosterArray[5];
};

#endif
