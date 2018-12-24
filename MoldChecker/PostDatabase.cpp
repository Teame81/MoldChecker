#include "pch.h"
#include "PostDatabase.h"

PostDatabase::PostDatabase()
{
	
}

PostDatabase::~PostDatabase()
{
}

void PostDatabase::addPost(Post inPost)
{
	post.push_back(inPost);
}

void PostDatabase::printAllData()
{
	int i = 1;
	for (auto it = post.begin(); it != post.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}

float PostDatabase::fMediumTemperature()
{
	float fTotalTemp{};
	int iTotalPosts{};
	for (auto it = post.begin(); it != post.end(); iTotalPosts++, it++)
	{
		fTotalTemp = fTotalTemp + (*it).getTemp();
	}
	return fTotalTemp / (float)iTotalPosts;
}

void PostDatabase::printMediumTemperature()
{
	cout << "Medium temperature: " << this->fMediumTemperature();
}
