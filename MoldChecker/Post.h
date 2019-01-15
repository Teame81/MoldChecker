#pragma once
#include "Date.h"

class Post : public Date
{
public:
	Post(Date inDate, string inLocation, string inTemp, string inMoist);//Constructur when reading from datafile
	Post(Date inDate, string inLocation, float inTemp, int inMoist);//Contructor used when merging the days
	float calculateMold(float inTemp, int inMoist);//
	void printMe(); // Prints the data in a post
	string sPrintMe(); //Returns the data in a post like a string
	float getTemp(); // Gets Temperature of post
	string getLocation(); // Gets Location of post
	string sGetDate(); // Gets string Date of post
	int iGetDate(); // Gets int value of date of a post
	void addMoist(int inMoist); // adds Moist to a post
	void addTemp(float inTemp); // adds Temperature to a post
	int getMoist(); // Gets moist from post
	void setTemp(float inTemp); // Sets temperature on a post
	void setMoist(int inMoist); // Sets Moist on a post
	float getMoldRisk(); // Gets the mold risk
	int getMonth(); // Returns month in Int
	void setTempDiff(float inDiff); // Sets the temperature difference
	float getTempDiff(); //Gets temperature difference

private:
	Date dDate;
	string sLocation{};
	float fTemp{};
	int iMoist{};
	float iMoldRisk{};
	float fTempDiff{};

};