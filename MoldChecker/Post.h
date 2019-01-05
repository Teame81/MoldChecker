#pragma once
#include "Date.h"

class Post : public Date
{
public:
	Post(Date inDate, string inLocation, string inTemp, string inMoist);
	Post(Date inDate, string inLocation, float inTemp, int inMoist);
	void printMe();
	float getTemp();
	string getLocation();
	string getDate();
	void addMoist(int inMoist);
	void addTemp(float inTemp);
	int getMoist();
	void setTemp(float inTemp);
	void setMoist(int inMoist);
private:
	Date dDate;
	string sLocation;
	float fTemp;
	int iMoist;

};