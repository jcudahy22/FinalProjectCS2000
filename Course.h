#pragma once

#include <iostream>
#include <string>

using namespace std;

class Course {
	//Default constructor, destructor, and setters and getters for the base class
	public:
		Course();
		~Course() {};
		void SetCourseSubject(string inpSubj);
		void SetCourseNumber(int inpNum);
		void SetCourseTitle(string inpTitle);
		void SetCourseHours(string inpHours);
		void SetCourseTerm(string inpTerm);
		string GetCourseSubject();
		int GetCourseNumber();
		string GetCourseTitle();
		string GetCourseHours();
		string GetCourseTerm();
	//Private string variables for subject, title, hours and term.  Int variable needed for comparison later
	private:
		string courseSubject;
		int courseNum;
		string courseTitle;
		string courseHours;
		string courseTerm;
};
