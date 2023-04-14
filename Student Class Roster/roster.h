#pragma once
#ifndef ROSTER_H
#define ROSTER_H

#include "degree.h"
#include "student.h"
#include <string>

using namespace std;

static const unsigned int TOTAL_STUDENTS = 5;

// Part E1 & 2: Creating a Roster class with the provided parameters.
class Roster {
private:
	int i = -1;

public:
	Student* classRosterArray[TOTAL_STUDENTS] = { nullptr, nullptr, nullptr, nullptr, nullptr };

	// Part E3: Define the set of functions provided in task overview: add, remove.
	void ClassRosterParse(string record);
	void add(string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int days1,
		int days2,
		int days3,
		DegreeProgram degree);
	void remove(string studentID);
	void printAll();
	void printAvgDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degree);

	// Part F5: Implement the destructor to relase the memory that was allocated dynamically in Roster.
	~Roster();

};

#endif