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
	auto it = vOutMediumPerDay.begin();
	auto itR = vOutMediumPerDay.rbegin();

	for (it, itR; it != vOutMediumPerDay.begin() + 5 || itR != vOutMediumPerDay.rbegin() + 5; i++, itR++, it++)
	{
		cout << i << ". High: " << it->sPrintMe() << "\t Low: " << itR->sPrintMe() << "\n";
	}
}

void PostDatabase::printInList()
{
	int i = 1;
	auto it = vInMediumPerDay.begin();
	auto itR = vInMediumPerDay.rbegin();

	for (it, itR; it != vInMediumPerDay.begin() + 5 || itR != vInMediumPerDay.rbegin() + 5; i++, itR++, it++)
	{
		cout << i << ". High: " << it->sPrintMe() << "\t Low: " << itR->sPrintMe() << "\n";
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
				tempPost.addMoist((it + 1)->getMoist()); //UPPGRADERING P� G skapa en tempor�r variable
				tempPost.addTemp((it + 1)->getTemp());   // Ist�llet f�r att uppgradera en hel post med add 
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
			diff = (-diff);//If negative diffrence make it positive
		
		itIn->setTempDiff(diff);
		itOut->setTempDiff(diff);

	}

}



void PostDatabase::searchForDateInPostVector(vector<Post> inVec, int inInt)
{
	int whereAt = int(inVec.size() / 2);
	int tempMax = int(inVec.size());
	int tempMin = 0;
	vector<Post>::iterator it = inVec.begin() + whereAt;
	vector<Post>::iterator itCB = inVec.begin();
	vector<Post>::iterator itCE = inVec.end()-1;
	bool didFind{false};
	if (inInt >= itCB->iGetDate() && inInt <= itCE->iGetDate())
	{
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
				tempMin = whereAt+1;
				whereAt = tempMin + (tempMax - tempMin) / 2;
				it = inVec.begin() + whereAt;
			}
		}
		it->printMe();
		didFind = true;
	}
	if (didFind == false)
	{
		cout << "Date out of bounds\n";
	}
}

vector<Post> PostDatabase::getVector(string inString)
{
	if(inString == "vPost")
		return this->vPost;

	if (inString == "vIn")
		return this->vIn;

	if (inString == "vInMediumPerDay")
		return this->vInMediumPerDay;

	if (inString == "vOut")
		return this->vOut;

	if (inString == "vOutMediumPerDay")
		return this->vOutMediumPerDay;
}

void PostDatabase::sortDryToMoist()
{
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](const Post & a, const Post & b)
	{
		return a.getMoist() < b.getMoist();
	});
	sort(vOutMediumPerDay.begin(), vOutMediumPerDay.end(), [](const Post & a, const Post & b)
	{
		return a.getMoist() < b.getMoist();
	});
}

void PostDatabase::sortLowToHighMold()
{
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](const Post & a, const Post & b)
	{
		return a.getMoldRisk() < b.getMoldRisk();
	});
	sort(vOutMediumPerDay.begin(), vOutMediumPerDay.end(), [](const Post & a, const Post & b)
	{
		return a.getMoldRisk() < b.getMoldRisk();
	});
}

void PostDatabase::sortByDate()
{
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.iGetDate() < b.iGetDate();
	});
	sort(vOutMediumPerDay.begin(), vOutMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.iGetDate() < b.iGetDate();
	});

}

void PostDatabase::sortByTemperature()
{
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](const Post &a,Post &b)
	{
		return a.getTemp() > b.getTemp();
	});

	sort(vOutMediumPerDay.begin(), vOutMediumPerDay.end(), [](const Post &a, const Post &b)
	{
		return a.getTemp() > b.getTemp();
	});
}

void PostDatabase::sortByTempDiffHighToLow()
{
	//Sort indoor vector
	sort(vInMediumPerDay.begin(), vInMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.getTempDiff() > b.getTempDiff();
	});
	//Sort outdoor vector
	sort(vOutMediumPerDay.begin(), vOutMediumPerDay.end(), [](Post & a, Post & b)
	{
		return a.getTempDiff() > b.getTempDiff();
	});


}


void PostDatabase::printMetrologicAutumn()
{
	int iCounter{}; 
	int iCounterInternLoop{};
	bool escape{ false };
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); it++)
	{
		iCounterInternLoop++;
		if (it->getMonth() >= 8 && it < (vOutMediumPerDay.end()-6))
		{


			for (auto it2 = it; it2 < (vOutMediumPerDay.begin() + (iCounterInternLoop + 4)); it2++)
			{
				if((it2->getTemp() > 0 && it2->getTemp() < 10.0f) && ((it2 + 1)->getTemp() > 0 && (it2 + 1)->getTemp() <= 10.f))
				{
					iCounter++;

				}
				if (iCounter == 5)
				{
					cout << "Metrologic autumn: " << it->sPrintMe();
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
	if (!escape)
	{
		cout << "\nThere where no metrologic autumn in this data!" << "\n";
	}

}

void PostDatabase::printMetrologicWinter()
{
	int iCounter{};
	int iCounterInternLoop{};
	bool escape{ false };
	for (auto it = vOutMediumPerDay.begin(); it != vOutMediumPerDay.end(); it++)
	{
		iCounterInternLoop++;
		if (it < (vOutMediumPerDay.end() - 6))
		{
			for (auto it2 = it; it2 < (vOutMediumPerDay.begin() + (iCounterInternLoop + 4)); it2++)
			{
				if ((it2->getTemp() < 0) && ((it2 + 1)->getTemp()))
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
	if (!escape)
	{
		cout << "\nThere where no metrologic winter in this data!" << "\n";
	}
}

vector<Post> PostDatabase::getOutVector()
{
	return vOutMediumPerDay;
}
