#pragma once
#ifndef STUDENT_H
#define STUDENT_H

#include "degree.h"
#include <string>

using namespace std;

// Part D1: Create the class "Student" in the files student.h and student.cpp which includes the following variables: studentId, first name, last name, email address, age, array of number of days to complete each course and degree program.
class Student {
public:

	// Part D2.a: Accessors for each instance variable from part D1.
	string getStudentId();
	string getFirstName();
	string getLastName();
	string getEmailAddress();
	int getAge();
	int* getCourseDays();
	DegreeProgram getDegree();

	// Part D2.b: Mutators for each instance variable from part D2.
	void setStudentId(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setCourseDays(int CourseDays[]);
	void setDegree(DegreeProgram degree);

	// Part D2.d: Constructor using all of the input parameters provided in the table.
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int CourseDays[],
		DegreeProgram degree
	);

	// Part D2.e: Print specific student data	
	const int COURSE_DAY_SIZE = 3;

	virtual void printAllStudentInfo();


	// Part D2.c: Limiting external access to any instance variables, this can now only be done using accessor and mutator functions.	
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int* CourseDays;
	DegreeProgram degree;

	~Student();
};

#endif