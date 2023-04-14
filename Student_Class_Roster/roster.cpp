#include "roster.h"
#include "degree.h"
#include "student.h"

#include <iostream>
#include <string>
#include <vector>
#include <sstream>

using namespace std;

// Part E3.3a: Define a add function that instances variables from part D1 and updates the roster.
void Roster::add(string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int days1,
	int days2,
	int days3,
	DegreeProgram degree) {
	int CourseDays[] = { days1, days2, days3 };

	classRosterArray[++i] = new Student(studentID, firstName, lastName, emailAddress, age, CourseDays, degree);
}

// Part E3.3b: Define a remove function that removes students from the roster using the student ID. If the student ID does not exists the function prints an errormessage indiciating the record does not exist.
void Roster::remove(string studentID) {
	cout << "Checking for student record with student ID of " << studentID << ". - " << flush;
	for (int j = 0; j < TOTAL_STUDENTS; ++j) {
		if (classRosterArray[j] == nullptr) {
			cout << "This student record does not exist." << endl;
			break;
		}
		else if (studentID == classRosterArray[j]->Student::getStudentId()) {
			classRosterArray[j] = nullptr;
			cout << "This student record has now been removed.";
		}
	}
}

// Part E3.2: Create a student object in the data table provided. Parse each set of data in the "Student Data Table" and add each student object to "classRosterArray".
void Roster::ClassRosterParse(string record) {
	vector<string> token;
	DegreeProgram testDegree;
	for (int i = 0; i < TOTAL_STUDENTS; ++i) {
		stringstream ss(record);

		while (ss.good()) {
			string subStr;
			getline(ss, subStr, ',');
			token.push_back(subStr);
		}

		if (token[8] == "SECURITY") {
			testDegree = DegreeProgram::SECURITY;
		}
		if (token[8] == "NETWORK") {
			testDegree = DegreeProgram::NETWORK;
		}
		if (token[8] == "SOFTWARE") {
			testDegree = DegreeProgram::SOFTWARE;
		}
	}
	Roster::add(token.at(0), token.at(1), token.at(2), token.at(3), stoi(token.at(4)), stoi(token.at(5)),
		stoi(token.at(6)), stoi(token.at(7)), testDegree);
}

// Part E3.3c: Define a function that prints a complete tab-separated list of student data in the format provided in task overview. This function should loop through all the students in "classRosterArray" and call print() function for each student.
void Roster::printAll() {
	cout << endl << "Displaying all current students: " << endl;
	for (int j = 0; j < TOTAL_STUDENTS; ++j) {
		if (classRosterArray[j] != nullptr) {
			classRosterArray[j]->Student::printAllStudentInfo();
		}
	}
}

// Part E3.3d: Define a function that prints the student's average number of days in the three courses. Identidy the student using the "studentID" parameter.
void Roster::printAvgDaysInCourse(string studentID) {
	// cout << endl << "Average number of days spent on a course, per student:" << endl;
	for (int i = 0; i < TOTAL_STUDENTS; ++i) {
		if (studentID == classRosterArray[i]->Student::getStudentId()) {
			int* days = classRosterArray[i]->getCourseDays();
			int avgDays = (days[0] + days[1] + days[2]) / 3;
			cout << "Student with ID " << studentID << " spent an average of " << avgDays << " days on a course." << endl;
			// cout << avgDays << endl;
		}
	}
}

// Part E3.3e: Define a function that will verify the student emails and will display any invalid email addresses to the user.
void Roster::printInvalidEmails() {
	// cout << endl << "Displaying list of invalid email addresses: " << endl;
	for (int j = 0; j < TOTAL_STUDENTS; ++j) {
		string emailAd = classRosterArray[j]->getEmailAddress();
		if ((emailAd.find(' ') != string::npos) || (emailAd.find('.') == string::npos) || (emailAd.find('@') == string::npos)) {
			cout << "Student ID:" << classRosterArray[j]->getStudentId() << "'s email address - " << emailAd << " is not valid." << endl;
		}
	}
	cout << endl;
	return;
}
// Part E3.3f: Define a function that will print out student information for a degree program specified by an enumerated type.
void Roster::printByDegreeProgram(DegreeProgram degree) {
	cout << endl << "Showing students enrolled in this degree program:" << endl;
	for (int i = 0; i < TOTAL_STUDENTS; ++i) {
		if (classRosterArray[i] != nullptr) {
			if (degree == classRosterArray[i]->Student::getDegree()) {
				classRosterArray[i]->Student::printAllStudentInfo();
			}
			if (TOTAL_STUDENTS == 0) {
				cout << "There are no students currently enrolled in this degree" << endl;
			}
		}
	}
	cout << endl;
}

// Part F: Implement a destructor to release the memory that was allocated dynamically in Roster.
Roster::~Roster() {}