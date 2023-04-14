#include "degree.h"
#include "student.h"
#include "roster.h"

#include <iostream>

using namespace std;

int main() {

	// Part A: Modified "studentData Table".
	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Walter,Galeziowski,wgalezi@wgu.edu,26,35,40,25,SOFTWARE"
	};

	// Part F1: Printed out: course title, programming language used, student ID and name.
	cout << "Course: Scripting and Programming: Applications - C867" << endl;
	cout << "Programming language used in this assignment: C++" << endl;
	cout << "WGU Student ID: 001161834" << endl;
	cout << "Name: Walter Galeziowski" << endl;

	// Part F2 & F3: Create an instance of Roster class to "classRoster" and add each student to "classRoster".	
	Roster classRoster;

	for (int i = 0; i < TOTAL_STUDENTS; ++i) {
		classRoster.ClassRosterParse(studentData[i]);
	}

	// Part F4: Conversion of pseudocode provided to complete the rest of the "main()" function:	
	classRoster.printAll();

	cout << endl;

	cout << "Displaying list of invalid email addresses:" << endl;
	classRoster.printInvalidEmails();

	cout << endl << "Average number of days spent on a course, per student:" << endl;
	for (int j = 0; j < TOTAL_STUDENTS; ++j) {
		classRoster.printAvgDaysInCourse(classRoster.classRosterArray[j]->Student::getStudentId());
	}

	classRoster.printByDegreeProgram(DegreeProgram::SOFTWARE);

	classRoster.remove("A3");
	cout << endl;

	classRoster.printAll();
	cout << endl;

	classRoster.remove("A3");
	cout << endl;

	// Part F5: Implement a destructor to release the memory that was allocated dynamically in Roster.
	classRoster.~Roster();

	cout << "Sequence Complete" << endl;

	return 0;
}