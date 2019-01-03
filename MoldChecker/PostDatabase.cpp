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
	vPost.push_back(inPost);
}

void PostDatabase::printAllData()
{
	int i = 1;
	for (auto it = vPost.begin(); it != vPost.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}

float PostDatabase::fMediumTemperature()
{
	float fTotalTemp{};
	int iTotalPosts{};

	for (auto it = vPost.begin(); it != vPost.end(); iTotalPosts++, it++)
	{
		fTotalTemp = fTotalTemp + (*it).getTemp();
	}
	return fTotalTemp / (float)iTotalPosts;
}

void PostDatabase::printMediumTemperature()
{
	cout << "Medium temperature: " << this->fMediumTemperature();
}

void PostDatabase::sortInAndOut()
{
	for (auto it = vPost.begin(); it != vPost.end(); it++)
	{
		if ((*it).getLocation() == "Inne")
		{
			vIn.push_back((*it));
		}
		else if ((*it).getLocation() == "Ute")
		{
			vOut.push_back((*it));
		}
	}


}

void PostDatabase::sortOutMedium()
{
	Post tempPost{ vOut.at(0) };
	
	for (auto it = vOut.begin(); it != vOut.end();it++)
	{
		int iCounter{};
		if ((*it).getDate() == (*it.operator+(1)).getDate())
		{
			tempPost.addMoist((*it.operator+(1)).getMoist());
			tempPost.addTemp((*it.operator+(1)).getTemp());
			iCounter++;
		}
		else if ((*it).getDate() != (*it.operator+(1)).getDate())
		{
			Date date{ (*it).getDate() };
			float tempTemp = tempPost.getTemp() / (float)iCounter;
			int tempMoist = tempPost.getMoist() / iCounter;
			vOutMediumPerDay.push_back(Post(date, (string)"Ute", to_string(tempTemp), to_string(tempMoist)));
		}
		
		// Här är jag!! Note to self Måste updatera Post klassen att ta imot integers och float ist for Strings occh
		// inte knvertera det i efter hand som jag gör nu. eller??

	}
}
