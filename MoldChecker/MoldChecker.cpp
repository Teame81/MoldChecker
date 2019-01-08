#include "pch.h"

#include <fstream>
#include <string>
#include <vector>
#include <Windows.h>
#include "Date.h"
#include "Post.h"
#include "PostDatabase.h"

using namespace std;

int main()
{
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
	cout << endl << "Number of posts: " << iNrOfPosts;

	cin.get();



	database.printMediumTemperature();
	
	cin.get();
	
	database.sortInAndOut();
	cout << "press enter to sort in OUT into days"<< endl;
	cin.get();


	database.sortOutMedium();
	database.sortInMedium();
	cout << "press enter to PRINT in OUT that are days" << endl;
	database.printOutMediumPerDay();
	database.printInMediumPerDay();

	cin.get();

	

}