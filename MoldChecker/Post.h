#pragma once
#include "Date.h"

class Post : public Date
{
public:
	Post(Date inDate, string inLocation, string inTemp, string inMoist);
	Post(Date inDate, string inLocation, float inTemp, int inMoist);
	void printMe();
	float getTemp(); // Gets Temperature of post
	string getLocation(); // Gets Location of post
	string sGetDate(); // Gets string Date of post
	int iGetDate(); // Gets int value of date of a post
	void addMoist(int inMoist); // adds Moist to a post
	void addTemp(float inTemp); // adds Temperature to a post
	int getMoist(); // Gets moist from post
	void setTemp(float inTemp); // Sets temperature on a post
	void setMoist(int inMoist); // Sets Moist on a post
private:
	Date dDate;
	string sLocation;
	float fTemp;
	int iMoist;

};