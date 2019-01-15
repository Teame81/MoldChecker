#include "pch.h"
#include "PostDatabase.h"
#include <algorithm>

PostDatabase::PostDatabase()
{
}

PostDatabase::~PostDatabase()
{
}

void PostDatabase::loadEssentials()
{
	cout << "Sorting vectors!\n";
	this->sortInAndOut();
	this->sortOutMedium();
	this->sortInMedium();
	this->setTempDiff();
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
	cout << "Medium temperature for the whole list: " << this->fMediumTemperature() << "\n";
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

	for (auto it = vOut.begin(); it != vOut.end();it++)
	{
		
		if (it < vOut.end()-1)
		{
			if ((*it).sGetDate() == (it + 1)->sGetDate())
			{
				tempPost.addMoist((it + 1)->getMoist()); //UPPGRADERING PÅ G skapa en temporär variable
				tempPost.addTemp((it + 1)->getTemp());   // Istället för att uppgradera en hel post med add 
				iCounter++;							     //metoden
			}
			else if (((*it).sGetDate() != ((it + 1)->sGetDate())))
			{
				if (iCounter == 0)
				{
					iCounter++;
				}
				
				Post tP(Date((it)->sGetDate()), it->getLocation(), tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
				vOutMediumPerDay.push_back(tP);
				iCounter = 0;
				tempPost.setMoist(0);
				tempPost.setTemp(0.f);
			}
			else  
			{
				cout <<"Not Valid" << endl;
			}
		}	
		
		if (it == vOut.end()-1)
		{
			if (iCounter == 0)
			{
				iCounter++;
			}
			Post tP(Date((it)->sGetDate()), it->getLocation(), tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
			vOutMediumPerDay.push_back(tP);
		}
	}
}

void PostDatabase::sortInMedium()
{
	Post tempPost{ vIn.at(0) };
	int iCounter{};

	for (auto it = vIn.begin(); it != vIn.end(); it++)
	{

		if (it < vIn.end() - 1)
		{
			if ((*it).sGetDate() == (it + 1)->sGetDate())
			{
				tempPost.addMoist((it + 1)->getMoist());
				tempPost.addTemp((it + 1)->getTemp());
				iCounter++;
			}
			else if (((*it).sGetDate() != ((it + 1)->sGetDate())))
			{
				if (iCounter == 0)
				{
					iCounter++;
				}

				Post tP(Date((it)->sGetDate()), it->getLocation(), tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
				vInMediumPerDay.push_back(tP);
				iCounter = 0;
				tempPost.setMoist(0);
				tempPost.setTemp(0.f);
			}
			else
			{
				cout << "None Valid" << endl;
			}
		}

		if (it == vIn.end() - 1)
		{
			if (iCounter == 0)
			{
				iCounter++;
			}
			Post tP(Date((it)->sGetDate()), it->getLocation(), tempPost.getTemp() / (float)iCounter, tempPost.getMoist() / iCounter);
			vInMediumPerDay.push_back(tP);
		}
	}
}

void PostDatabase::setTempDiff()
{
	float diff{};
	for (vector<Post>::iterator itIn = vInMediumPerDay.begin(), itOut = vOutMediumPerDay.begin(); itIn != vInMediumPerDay.end() || itOut != vOutMediumPerDay.end(); itIn++, itOut++)
	{
		diff = itIn->getTemp() - itOut->getTemp();
		if (diff < 0)
			diff = (-diff);//If negative diffrance make it positive
		itIn->setTempDiff(diff);
		itOut->setTempDiff(diff);

	}

}

void PostDatabase::printInMediumPerDay()
{
	cout << endl << "Medium per dag(Inne):" << endl;
	int i = 1;
	for (auto it = vInMediumPerDay.begin(); it != vInMediumPerDay.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}


void PostDatabase::printOutMediumPerDay()
{
	cout << endl << "Medium per dag(Ute):" << endl;
	int i = 1;
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); i++, it++)
	{
		cout << i << ". ";
		(*it).printMe();
	}
}

Post PostDatabase::searchForDateInPostVector(vector<Post> inVec, int inInt)
{
	this->sortByDate(inVec);
	int whereAt = int(inVec.size() / 2);
	int tempMax = int(inVec.size());
	int tempMin = 0;
	
	vector<Post>::iterator it = inVec.begin() + whereAt;
	int tempInt = it->iGetDate();
	while (inInt != it->iGetDate())
	{
		if (inInt < it->iGetDate())
		{
			tempMax = whereAt - 1;
			whereAt = tempMin + (tempMax - tempMin) / 2;
			it = inVec.begin() + whereAt;
		}
		else
		{
			tempMin = whereAt;
			whereAt = tempMin + (tempMax - tempMin) / 2;
			it = inVec.begin() + whereAt;
		}
	}
	return (*it);
}

vector<Post> PostDatabase::getVector(string inString)
{
	if(inString == "vPost")
		return vPost;

	if (inString == "vIn")
		return vIn;

	if (inString == "vInMediumPerDay")
		return vInMediumPerDay;

	if (inString == "vOut")
		return vOut;

	if (inString == "vOutMediumPerDay")
		return vOutMediumPerDay;
}

void PostDatabase::sortHotToCold(vector<Post> inVec)
{
	
	sort(inVec.begin(), inVec.end(), [](Post & a, Post & b) 
	{
		return a.getTemp() > b.getTemp();
	});
	
	int i{1};
	for (auto a : inVec)
	{
		cout << i++ << ": ";
		a.printMe();
	}
	
}

void PostDatabase::sortDryToMoist(vector<Post> inVec)
{
	
	sort(inVec.begin(), inVec.end(), [](Post & a, Post & b)
	{
		return a.getMoist() < b.getMoist();
	});

	int i{ 1 };
	for (auto a : inVec)
	{
		cout << i++ << ": ";
		a.printMe();
	}
}

void PostDatabase::sortLowToHighMold(vector<Post> inVec)
{
	
	sort(inVec.begin(), inVec.end(), [](Post & a, Post & b)
	{
		return a.getMoldRisk() < b.getMoldRisk();
	});

	int i{ 1 };
	for (auto a : inVec)
	{
		cout << i++ << ": ";
		a.printMe();
	}
}

void PostDatabase::sortByDate(vector<Post> inVec)
{
	
	sort(inVec.begin(), inVec.end(), [](Post & a, Post & b)
	{
		return a.iGetDate() < b.iGetDate();
	});

	int i{ 1 };
	for (auto a : inVec)
	{
		cout << i++ << ": ";
		a.printMe();
	}
}

void PostDatabase::sortByTempDiffHighToLow()
{
	//Sort indoor vector
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.getTempDiff() > b.getTempDiff();
	});
	int i{ 1 };
	cout << "\n Indoors medium per day list sorted by temperature difference: \n";
	for (auto a : vInMediumPerDay)
	{
		cout << i++ << ": ";
		a.printMe();
	}
	//Sort outdoor vector
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.getTempDiff() > b.getTempDiff();
	});
	i = 1;
	cout << "\n Outdoors medium per day list sorted by temperature difference: \n";
	for (auto a : vInMediumPerDay)
	{
		cout << i++ << ": ";
		a.printMe();
	}

}


void PostDatabase::printMetrologicAutumn()
{
	this->sortByDate(vOutMediumPerDay);
	int iCounter{}; 
	int iCounterInternLoop{};
	bool escape{ false };
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); it++)
	{
		iCounterInternLoop++;
		if (it->getMonth() >= 8 && it < (vOutMediumPerDay.end()-6))
		{


			for (auto it2 = it; it2 < (vOutMediumPerDay.begin() + (iCounterInternLoop + 5)); it2++)
			{
				if((it->getTemp() > 0 && it->getTemp() < 10.0f) && ((it2 + 1)->getTemp() > 0 && (it2 + 1)->getTemp() <= 10.f))
				{
					iCounter++;

				}
				if (iCounter == 5)
				{
					cout << "Metrologic autumn:" << it->sPrintMe();
					escape = true;
					break;
				}

			}
		
		

		
			iCounter = 0;
		}
		if (escape)
		{
			break;
		}

	}
	cout << "\n " << "There where no metrologic autumn in this data!" << "\n";

}

void PostDatabase::printMetrologicWinter()
{
	this->sortByDate(vOutMediumPerDay);
	int iCounter{};
	int iCounterInternLoop{};
	bool escape{ false };
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); it++)
	{
		iCounterInternLoop++;
		if (it < (vOutMediumPerDay.end() - 6))
		{


			for (auto it2 = it; it2 < (vOutMediumPerDay.begin() + (iCounterInternLoop + 5)); it2++)
			{
				if ((it->getTemp() < 0) && ((it2 + 1)->getTemp()))
				{
					iCounter++;

				}
				if (iCounter == 5)
				{
					cout << "Metrologic Winter:" << it->sPrintMe();
					escape = true;
					break;
				}

			}




			iCounter = 0;
		}
		if (escape)
		{
			break;
		}

	}
	cout << "\n " << "There where no metrologic winter in this data!" << "\n";

}
