#include "student.h"
#include <iostream>

using namespace std;

// Part D2: Setting up an empty student record in the student class.
Student::Student() :
	studentID(""),
	firstName(""),
	lastName(""),
	emailAddress(""),
	age(0),
	CourseDays(new int[COURSE_DAY_SIZE]) {
	for (int i = 0; i < COURSE_DAY_SIZE; ++i) {
		this->CourseDays[i] = 0;
	}
}

// Part D2.a: An accessor for each instance variable from Part D1.
string Student::getStudentId() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
string Student::getEmailAddress() {
	return emailAddress;
}
int Student::getAge() {
	return age;
}
int* Student::getCourseDays() {
	return CourseDays;
}
DegreeProgram Student::getDegree() {
	return degree;
}

// Part D2.b: A mutator for each instance variable from Part D1.
void Student::setStudentId(string studentID) {
	this->studentID = studentID;
}
void Student::setFirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setLastName(string lastName) {
	this->lastName = lastName;
}
void Student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setAge(int age) {
	this->age = age;
}
void Student::setCourseDays(int CourseDays[]) {
	this->CourseDays = new int[COURSE_DAY_SIZE];
	for (int i = 0; i < COURSE_DAY_SIZE; ++i) {
		this->CourseDays[i] = CourseDays[i];
	}
}
void Student::setDegree(DegreeProgram degree) {
	this->degree = degree;
}

// Part D2.d: Constructor & using mutator functions to create an object in the student class.
Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int CourseDays[],
	DegreeProgram degree)
{
	setStudentId(studentID);
	setFirstName(firstName);
	setLastName(lastName);
	setEmailAddress(emailAddress);
	setAge(age);
	setCourseDays(CourseDays);
	setDegree(degree);
}

// Part D2.e: print() to print specific student data
void Student::printAllStudentInfo() {
	cout << getStudentId();
	cout << "\t" << "First name: " << getFirstName();
	cout << "\t" << "Last name: " << getLastName();
	/*
	Email address was commented out in order to allow for better formatting.
	cout << "\t" << "Email address: " << getEmailAddress() << "\t";
	*/
	cout << "\t" << "Age: " << getAge() << "\t";
	cout << "\t" << "Days in courses: ";
	int* days = getCourseDays();
	for (int i = 0; i < COURSE_DAY_SIZE; ++i) {
		cout << days[i] << " ";
	}
	cout << "\t";
	string degreeString = "";

	switch (getDegree()) {
	case DegreeProgram::SECURITY:
		degreeString = "SECURITY";
		break;
	case DegreeProgram::NETWORK:
		degreeString = "NETWORK";
		break;
	case DegreeProgram::SOFTWARE:
		degreeString = "SOFTWARE";
		break;
	}

	cout << "Degree: " << degreeString << "\t" << endl;

}
