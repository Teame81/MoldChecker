#include "pch.h"
#include "Date.h"

Date::Date(string inDate)
{
	sFullDate = inDate;
	iYear = (stoi(inDate.substr(0, 4)));
	iMonth = (stoi(inDate.substr(5, 2)));
	iDay = (stoi(inDate.substr(8, 2)));

}

Date::Date()
{
}

void Date::printMe()
{
	cout << sFullDate;
}

string Date::sPrintMe()
{
	return sFullDate;
}

string Date::sYearMonthDay()
{
	string YearMonthDay{};
	
	YearMonthDay = to_string(iYear) + to_string(iMonth) + to_string(iDay);
	
	return YearMonthDay;
}
