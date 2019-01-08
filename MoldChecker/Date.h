#pragma once
#include <string>

using namespace std;

class Date
{
public:
	Date(string inDate);
	Date();
	void printMe();
	string sPrintMe();
	string sYearMonthDay();
	int getYear();
	int getMonth();
	int getDay();
	

private:
	string sFullDate;
	int iYear;
	int iMonth;
	int iDay;
	int iHour;
	int iMinute;
	int iSecond;
};