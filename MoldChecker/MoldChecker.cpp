#include "pch.h"

#include <fstream>
#include <vector>
#include <Windows.h>
#include "Date.h"
#include "Post.h"
#include "PostDatabase.h"
#include <math.h>

using namespace std;
void readFileData(const string fileName);
PostDatabase database;

int main()
{


	readFileData("tempdata4.csv");
	//readFileData("timesaver.csv");

	database.printMediumTemperature();
	
	database.loadEssentials();
	//MENU LOOP starts here

	Post tPost = database.searchForDateInPostVector(database.getVector("vOutMediumPerDay"), 20160603);
	tPost.printMe();
	//database.sortHotToCold(database.getVector("vOutMediumPerDay"));
	//database.sortDryToMoist(database.getVector("vOutMediumPerDay"));

	database.printMetrologicAutumn();
	database.printMetrologicWinter();
	

	database.sortByTempDiffHighToLow();
	cin.get();
	
	

}

void readFileData(const string fileName)
{
	ifstream inFile;
	
	string sDate{};
	string sTime{};
	string sLocation{};
	string sTemp{};
	string sMoist{};

	int iNrOfPosts{ 1 };

	inFile.open(fileName);

	while (inFile.good())
	{
		if (iNrOfPosts % 10000 == 1)
			cout << "*Loading data from file*";
		if (iNrOfPosts % 20000 == 1)
			system("CLS");

		getline(inFile, sDate, ';');
		//getline(inFile, sTime, ';');
		getline(inFile, sLocation, ';');
		getline(inFile, sTemp, ';');
		getline(inFile, sMoist, '\n');

		Date date = sDate;
		Post post(date, sLocation, sTemp, sMoist);

		database.addPost(post);

		++iNrOfPosts;

	}
	cout << "Done!\nNumber of posts: " << iNrOfPosts << endl;
}
