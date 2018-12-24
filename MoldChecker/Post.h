#pragma once
#include "Date.h"

class Post : public Date
{
public:
	Post(Date inDate, string inLocation, string inTemp, string inMoist);
	void printMe();
	float getTemp();

private:
	Date dDate;
	string sLocation;
	float fTemp;
	int iMoist;

};

