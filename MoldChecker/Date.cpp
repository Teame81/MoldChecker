#include "pch.h"
#include "Date.h"

Date::Date(string inDate)
{
	iYear = (stoi(inDate.substr(0, 4)));
	iMonth = (stoi(inDate.substr(5, 2)));
	iDay = (stoi(inDate.substr(8, 2)));
}
