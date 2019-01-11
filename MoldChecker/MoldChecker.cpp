#include "pch.h"

#include <fstream>
#include <vector>
#include <Windows.h>
#include "Date.h"
#include "Post.h"
#include "PostDatabase.h"
#include <math.h>

using namespace std;

int main()
{
	int inTemp{ 15 };
	float moldindex = (-0.0015 * pow(inTemp, 3)) + (0.1193 * pow(inTemp, 2)) - (2.9878 * inTemp) + 102.96;
	cout << moldindex << endl;
	ifstream inFile;
	int counter{};
	
	string sDate{};
	string sTime{};
	string sLocation{};
	string sTemp{};
	string sMoist{};
	float fTemp{};
	int iMoist{};
	int iNrOfPosts{1};
	const string fileName = "timesaver.csv";
	//const string fileName = "tempdata4.csv";
	PostDatabase database{};

	inFile.open(fileName);
	
	while (inFile.good())
	{
		
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
	cout << "Number of posts: " << iNrOfPosts << endl;

	database.printMediumTemperature();
	database.sortInAndOut();
	database.sortOutMedium();
	database.sortInMedium();
	database.printOutMediumPerDay();
	database.printInMediumPerDay();
	Post tPost = database.searchForDateInPostVector(database.getVector("vOutMediumPerDay"), 20160603);
	tPost.printMe();
	database.sortHotToCold(database.getVector("vOutMediumPerDay"));
	database.sortDryToMoist(database.getVector("vOutMediumPerDay"));

	//float moldindex{}; // WORKING ON MOLD INDEX
	//int temp = 20;
	//float moldindex = (-0.0015 * pow(temp, 3)) + (0.1193 * pow(temp, 2)) - (2.9878 * temp) + 102.96;


	
	cin.get();
	
	

}