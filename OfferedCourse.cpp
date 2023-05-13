#include <iostream>
#include <string>
#include <fstream>

#include "OfferedCourse.h"

using namespace std;

//Sets Section
void OfferedCourse::SetSection(string inpSection)
{
    section = inpSection;
}

//Sets CRN
void OfferedCourse::SetCRN(string inpCRN)
{
    crn = inpCRN;
}

//Sets Instructor Name
void OfferedCourse::SetInstructor(string inpFName, string inpLName)
{
    instructorName = inpFName.substr(1) + " " + inpLName;
}

//Sets Course Start Day
void OfferedCourse::SetDayStart(string inpDayStart)
{
    dayStart = inpDayStart;
}

//Sets Course End Day
void OfferedCourse::SetDayEnd(string inpDayEnd)
{
    dayEnd = inpDayEnd;
}

//Gets Section
string OfferedCourse::GetSection()
{
    return section;
}

//Gets CRN
string OfferedCourse::GetCRN()
{
    return crn;
}

//Gets Instructor Name
string OfferedCourse::GetInstructorName()
{
    return instructorName;
}

//Gets Start Day (first day of week course meets)
string OfferedCourse::GetDayStart()
{
    return dayStart;
}

//Gets End Day (Last day of week course meets)
string OfferedCourse::GetDayEnd()
{
    return dayEnd;
}

//Prints information in east to read format
void OfferedCourse::PrintInfo(ofstream& outText)
{
    outText << "   Course: " << GetCourseSubject() << " " << GetCourseNumber() << endl;
    outText << "   Title: " << GetCourseTitle() << endl;
    outText << "   Section: " << GetSection() << endl;
    outText << "   Hours: " << GetCourseHours() << endl;
    outText << "   CRN: " << GetCRN() << endl;
    outText << "   Term: " << GetCourseTerm() << endl;
    outText << "   Instructor: " << GetInstructorName() << endl;
    outText << "   Second Class Day (if applicable): " << GetDayEnd() << endl << endl;
}