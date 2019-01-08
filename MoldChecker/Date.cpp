#include "pch.h"
#include "Date.h"

Date::Date(string inDate)
{
	sFullDate = inDate;
	if (inDate.length() >= 10)
	{
		iDay = (stoi(inDate.substr(8, 2)));
	}
	if (inDate.length() >= 7)
	{
		iMonth = (stoi(inDate.substr(5, 2)));
	}
	if (inDate.length() >= 4)
	{
		iYear = (stoi(inDate.substr(0, 4)));
	}

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
	if (iDay <10)
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + "0" + to_string(iDay);
	}
	else
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + to_string(iDay);
	}
	return YearMonthDay;
}
