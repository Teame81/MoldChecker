#include "pch.h"
#include "Post.h"

Post::Post(Date inDate, string inLocation, string inTemp, string inMoist)
{
	 
	dDate = inDate;
	sLocation = inLocation;
	fTemp = stof(inTemp);
	iMoist = stoi(inMoist);
	iMoldRisk = calculateMold(fTemp, iMoist);
}

Post::Post(Date inDate, string inLocation, float inTemp, int inMoist)
{
	dDate = inDate;
	sLocation = inLocation;
	fTemp = inTemp;
	iMoist = inMoist;
	iMoldRisk = calculateMold(fTemp, iMoist);
}

float Post::calculateMold(float inTemp, int inMoist)
{
	float moldindex = (-0.0015 * pow(inTemp, 3)) + (0.1193 * pow(inTemp, 2)) - (2.9878 * inTemp) + 102.96;

	return inMoist - moldindex;
}

void Post::printMe()
{
	cout << dDate.sPrintMe()
		<< " " << sLocation
		<< " " << fTemp
		<< " " << iMoist
		<< " " << iMoldRisk 
		<< " " << fTempDiff << "\n";
}

string Post::sPrintMe()
{
	return dDate.sPrintMe() + " " + sLocation + " " + to_string(fTemp) + " " + to_string(iMoist)+ " " + to_string(iMoldRisk) + "\n";
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

float Post::getMoldRisk()
{
	return iMoldRisk;
}

int Post::getMonth()
{
	return dDate.getMonth();
}

void Post::setTempDiff(float InDiff)
{
	fTempDiff = InDiff;
}

float Post::getTempDiff()
{
	return fTempDiff;
}
