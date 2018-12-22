#pragma once
#include "Date.h"

class Post
{
public:
	Post(Date inDate, string inLocation, string inTemp, string inMoist);
	~Post();

private:
	Date dDate;
	string sLocation;
	float fTemp;
	int iMoist;

};
