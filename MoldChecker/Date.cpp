#include "pch.h"
#include "Date.h"

Date::Date(string inDate)
{
	sFullDate = inDate;
	if(inDate.length() >= 8) // if its a Long type of date with time ex: "2016-06-02 00:30:23"
	{
		if (inDate.length() >= 11)
		{
			iDay = (stoi(inDate.substr(8, 2)));
		}
		if (inDate.length() >= 8)
		{
			iMonth = (stoi(inDate.substr(5, 2)));
		}
		if (inDate.length() >= 4)
		{
			iYear = (stoi(inDate.substr(0, 4)));
		}
	}

	if (inDate.length() <= 8) // if its short trimmed date "20160602"
	{
		if (inDate.length() >= 8)
		{
			iDay = (stoi(inDate.substr(6, 2)));
		}
		if (inDate.length() >= 6)
		{
			iMonth = (stoi(inDate.substr(4, 2)));
		}
		if (inDate.length() >= 4)
		{
			iYear = (stoi(inDate.substr(0, 4)));
		}
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
	if (iDay <10 && iMonth <10)
	{
		YearMonthDay = to_string(iYear) + "0"+ to_string(iMonth) + "0" + to_string(iDay);
	}
	else if (iDay < 10)
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + "0" + to_string(iDay);
	}
	else if (iMonth < 10)
	{
		YearMonthDay = to_string(iYear) + "0" + to_string(iMonth) + to_string(iDay);
	}
	else
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + to_string(iDay);
	}
	

	return YearMonthDay;
}

int Date::getYear()
{
	return iYear;
}

int Date::getMonth()
{
	return iMonth;
}

int Date::getDay()
{
	return iDay;
}

int Date::iGetFullDate()
{	
	string YearMonthDay{};

	if (iDay < 10 && iMonth < 10)
	{
		YearMonthDay = to_string(iYear) + "0" + to_string(iMonth) + "0" + to_string(iDay);
	}
	else if (iDay < 10)
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + "0" + to_string(iDay);
	}
	else if (iMonth < 10)
	{
		YearMonthDay = to_string(iYear) + "0" + to_string(iMonth) + to_string(iDay);
	}
	else
	{
		YearMonthDay = to_string(iYear) + to_string(iMonth) + to_string(iDay);
	}
		return stoi(YearMonthDay);
}
