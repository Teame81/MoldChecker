#pragma once


using namespace std;

class Date
{
public:
	Date(string inDate);
	Date();
	void printMe(); //Prints date of a datepost
	string sPrintMe(); // Returns a string of the full date
	string sYearMonthDay(); // Returns a string with year month and day
	string sYearMonthDayHour(); //Returns a string with year month ,day and hour
	int getYear(); // Gets year
	int getMonth(); // Gets month
	int getDay(); // Gets Day
	int getHour(); //Get hour
	int getMinute(); // Get minute
	int getSecond(); // Get second
	int iGetFullDate(); // Gets full date in int ex: 20160615
	

private:
	string sFullDate;
	int iYear;
	int iMonth;
	int iDay;
	int iHour;
	int iMinute;
	int iSecond;
};