#include <iostream>
#include <string>

#include "Course.h"

using namespace std;

//Constructer given no inputs
Course::Course()
{
    courseNum = -1;
    courseTitle = "NoTitle";
}

//Sets Course Subject
void Course::SetCourseSubject(string inpSubj)
{
    courseSubject = inpSubj;
}


//Sets Course Number
void Course::SetCourseNumber(int inpNum)
{
    courseNum = inpNum;
}

//Sets Course Title
void Course::SetCourseTitle(string inpTitle)
{
    courseTitle = inpTitle;
}

//Sets Course Hours
void Course::SetCourseHours(string inpHours)
{
    courseHours = inpHours;
}

//Sets Course Term
void Course::SetCourseTerm(string inpTerm)
{
    courseTerm = inpTerm;
}

//Gets Course Subject
string Course::GetCourseSubject()
{
    return courseSubject;
}

//Gets Course Number
int Course::GetCourseNumber()
{
    return courseNum;
}

//Gets Course Title
string Course::GetCourseTitle()
{
    return courseTitle;
}

//Gets Course Hours
string Course::GetCourseHours()
{
    return courseHours;
}

//Gets Course Term
string Course::GetCourseTerm()
{
    return courseTerm;
}