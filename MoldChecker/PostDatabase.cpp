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

void PostDatabase::printOutList()
{
	int i = 1;
	for (auto it = vOut.begin(); it != vOut.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}

void PostDatabase::printInList()
{
	int i = 1;
	for (auto it = vIn.begin(); it != vIn.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
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
	int iCounter{};
	int tempCounter{};
	int tempCounter2{};
	for (auto it = vOut.begin(); it != vOut.end();it++)
	{
		
		if (it < vOut.end()-1)
		{
			if ((*it).getDate() == (it + 1)->getDate())
			{
				tempPost.addMoist((it + 1)->getMoist());
				tempPost.addTemp((it + 1)->getTemp());
				iCounter++;
			}
			else if (((*it).getDate() != ((it + 1)->getDate())))
			{
				if (iCounter == 0)
				{
					iCounter++;
				}
				
				Post tP(Date((it)->getDate()), "Ute", tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
				vOutMediumPerDay.push_back(tP);
				iCounter = 0;
				tempPost.setMoist(0);
				tempPost.setTemp(0.f);
			}
			else  
			{
				cout << tempCounter++ << ". None Valid" << endl;
			}
		}	
		
		if (it == vOut.end()-1)
		{
			if (iCounter == 0)
			{
				iCounter++;
			}
			Post tP(Date((it)->getDate()), "Ute", tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
			vOutMediumPerDay.push_back(tP);
		}
	}
}


void PostDatabase::printOutMediumPerDay()
{
	int i = 1;
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}
