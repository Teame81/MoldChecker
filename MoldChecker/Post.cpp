#include "pch.h"
#include "Post.h"

Post::Post(Date inDate, string inLocation, string inTemp, string inMoist)
{
	 
	dDate = inDate;
	sLocation = inLocation;
	fTemp = stof(inTemp);
	iMoist = stoi(inMoist);
}

Post::Post(Date inDate, string inLocation, float inTemp, int inMoist)
{
	dDate = inDate;
	sLocation = inLocation;
	fTemp = inTemp;
	iMoist = inMoist;
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

string Post::sGetDate()
{
	return dDate.sYearMonthDay();
}

int Post::iGetDate()
{
	return dDate.iGetFullDate();
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

void Post::setTemp(float inTemp)
{
	fTemp = inTemp;
}

void Post::setMoist(int inMoist)
{
	iMoist = inMoist;
}
