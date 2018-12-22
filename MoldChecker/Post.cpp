#include "pch.h"
#include "Post.h"
#include "Date.h"

Post::Post(Date inDate, string inLocation, string inTemp, string inMoist)
{
	dDate = inDate;
	sLocation = inLocation;
	fTemp = stof(inTemp);
	iMoist = stoi(inMoist);

}

Post::~Post()
{
}