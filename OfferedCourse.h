#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include "Course.h"

using namespace std;

class OfferedCourse : public Course {
    //Additional setters and getters for derived class
	public:
		void SetSection(string inpSection);
		void SetCRN(string inpCRN);
		void SetInstructor(string inpFName, string inpLName);
		void SetDayStart(string inpDayStart);
		void SetDayEnd(string inpDayEnd);
		string GetSection();
		string GetCRN();
		string GetInstructorName();
		string GetDayStart();
		string GetDayEnd();
		void PrintInfo(ofstream& outText);
    //Private string variables for derived class only (Instructor Section, CRN, Name, Location, and Class Time)
	private:
		string section;
		string crn;
		string instructorName;
		string dayStart;
		string dayEnd;
};