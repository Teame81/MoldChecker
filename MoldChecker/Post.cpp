#include "pch.h"
#include "Post.h"

Post::Post(Date inDate, string inLocation, string inTemp, string inMoist)
{
	 
	dDate = inDate;
	sLocation = inLocation;
	fTemp = stof(inTemp);
	iMoist = stoi(inMoist);
}

void Post::printMe()
{
	cout << dDate.sPrintMe()
		<< " " << sLocation
		<< " " << fTemp
		<< " " << iMoist << endl;
}

float Post::getTemp()
{
	return fTemp;
}

string Post::getLocation()
{
	return sLocation;
}

string Post::getDate()
{
	return dDate.sYearMonthDay();
}

void Post::addMoist(int inMoist)
{
	iMoist += inMoist;
}

void Post::addTemp(float inTemp)
{
	fTemp += inTemp;
}

int Post::getMoist()
{
	return iMoist;
}
