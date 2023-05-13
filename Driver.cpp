#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <vector>

#include "Course.h"
#include "OfferedCourse.h"

using namespace std;

//Eliminates excess non-alphabetic characters from various inputs from input file
void onlyAlpha(string& s)
{
	int i;

	for (i = 0; i < s.size(); i++)
	{
		if (s[i] == '_' || s[i] == '"')
		{
			s[i] = ' '; 
		}
	}
}

int main() {
	//Declares file streams
	ifstream inFile;
	ofstream outFile;

	//Variable of derived class OfferedCourse, child of base class Course
	OfferedCourse oCourse;

	//Input string variables from file
	int number;
	string subject, title, hours, term;
	string oSection, oCRN, oInstructor, oMeeting;
	string fnameInstructor, lnameInstructor, oDayStart, oDayEnd;
	string inFileName, outFileName;
	
	//Input variables from user or ints used for for loops and data management
	string userDate;
	int MonCount = 0, TuesCount = 0;
	int userLevel;
	int i = 0, j = 0;
	int indexInstance;

	//Vectors to store Course objects depending on start day
	vector<OfferedCourse> mondayStart;
	vector<OfferedCourse> tuesdayStart;

	//Modified input file comes from data files on Blackboard, exchanges spaces for underscores for each category.
	//Makes the data easier to read in.  Output file for final execution.
	inFileName = "CoursesFall2023UnderscoreReplace.txt";
	outFileName = "YourClassList.txt";

	//Opens data file
	inFile.open(inFileName);

	if (!inFile.is_open())
	{
		cout << "The input file failed to open.";
		return 1;
	}

	//Reads in data from data file for storage
	while (!inFile.fail())
	{
		//Reads one line of code for multiple variables
		inFile >> subject >> number >> oSection >> title >> hours;
		inFile >> oCRN >> term >> oInstructor >> oMeeting;

		//Sets OfferedCourse variables without non-numeric or non-alphabetic characters
		oCourse.SetCourseSubject(subject);
		oCourse.SetCourseNumber(number);
		oCourse.SetSection(oSection);

		//Course title has excess underscores
		onlyAlpha(title);
		oCourse.SetCourseTitle(title);
		
		//Sets more OfferedCourse variables
		oCourse.SetCourseHours(hours);
		oCourse.SetCRN(oCRN);

		//Course term has one underscore
		onlyAlpha(term);
		oCourse.SetCourseTerm(term);

		//Seperates first name from last name in data file, sets both
		fnameInstructor = oInstructor.substr(oInstructor.find(',') + 1, oInstructor.find('_'));
		onlyAlpha(fnameInstructor);

		lnameInstructor = oInstructor.substr(1, oInstructor.find(',') - 1);

		oCourse.SetInstructor(fnameInstructor, lnameInstructor);

		//Uses comma to identify if the class meets once or twice a week
		if (oMeeting.find(',') == string::npos)
		{
			oDayStart = oMeeting;
			oDayEnd = "";
		} else
		{
		//Identifies start and end date if there are two
			oDayStart = oMeeting.substr(1,oMeeting.find(',') - 1);
			oDayEnd = oMeeting.substr(oMeeting.find(',') + 1, oMeeting.size());
			onlyAlpha(oDayEnd);
		}
			
		oCourse.SetDayStart(oDayStart);
		oCourse.SetDayEnd(oDayEnd);

		//Appends total object to vector depending on its first class day of the week, with a counter
		if (oDayStart == "Monday")
		{
			mondayStart.push_back(oCourse);
			MonCount++;
		} else
		{
			tuesdayStart.push_back(oCourse);
			TuesCount++;
		}
	}

	//Dynamic memory meant to hold classes on the same day at the same level (from 1000 through 4000).
	//Holds max number of possible courses just for safety.
	OfferedCourse* monLevel = new OfferedCourse[MonCount];
	OfferedCourse* tuesLevel = new OfferedCourse[TuesCount];

	//Input file closed
	inFile.close();

	//Output file opened
	outFile.open(outFileName);

	if (!outFile.is_open())
	{
		cout << "At least one of the output files failed to open.";
		return 1;
	}

	//Prompts user for desired day and course level
	cout << "Do you want your class to start on Monday or Tuesday (type full day, case sensitive)? ";
	cin >> userDate;

	cout << "Do you want your class to be a 1000, 2000, 3000, or 4000 level (type full number)?:  ";
	cin >> userLevel;

	//Filters by user date if they input "Monday"
	if (userDate == "Monday")
	{
		//Determines if vector objects from Monday vector match user's course level
		for (i = 0; i < MonCount; i++)
		{
			if (mondayStart.at(i).GetCourseNumber() / 1000 == userLevel / 1000)
			{
				monLevel[j] = mondayStart.at(i);
				j++;
			}
		}

		//Outputs header for output file according to user inputs
		outFile << userDate << " Courses at a " << userLevel << " Level" << endl << endl;

		//Prints dynamic array with appropriate objects fitting parameters
		for (i = 0; i < j; i++)
		{
			monLevel[i].PrintInfo(outFile);
		}
	} else
	//Filters for "Tuesday" input
	{
		//Again, determines if vector objects from Tuesday vector match user's course level
		for (i = 0; i < TuesCount; i++)
		{

			if (tuesdayStart.at(i).GetCourseNumber() / 1000 == userLevel / 1000)
			{
				tuesLevel[j] = mondayStart.at(i);
				j++;
			}
		}

		//Output header
		outFile << userDate << " Courses at a " << userLevel << " Level" << endl << endl;

		//Prints dynamic array with appropriate objects fitting parameters
		for (i = 0; i < j; i++)
		{
			tuesLevel[i].PrintInfo(outFile);
		}
	}

	//Releases dynamic memory
	delete [] monLevel;
	delete [] tuesLevel;

	//Indicates where and how to find the desired class list
	cout << "Check your class list file (YourClassList.txt) to find the classes that fit your desired first day of the week and course level.\n";
	cout << "Have a good day!" << endl;

	//Closes output file
	outFile.close();

	return 0;
}
