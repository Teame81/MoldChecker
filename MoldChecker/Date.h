#pragma once
#include <string>

using namespace std;

class Date
{
public:
	Date(string inDate);
	

private:
	string sFullDate;
	int iYear;
	int iMonth;
	int iDay;
	int iHour;
	int iMinute;
	int iSecond;
};