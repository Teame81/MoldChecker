#include "pch.h"
#include <iostream>
#include <fstream>
//#include <iomanip>
#include <string>
#include <vector>
#include <stdio.h>
#include <Windows.h>


using namespace std;

int main()
{
	ifstream inFile;
	int counter{};
	vector<string>fileData;
	fileData.reserve(600000);
	//string SfileData[600000];
	string sDate{};
	string sTime{};
	string sLocation{};
	string sTemp{};
	string sMoist{};
	float fTemp{};
	int iMoist{};
	int post{1};
	const string fileName = "TempFuktData2.csv";

	inFile.open(fileName);
	
	while (inFile.good())
	{
		
		getline(inFile, sDate, ' ');
		getline(inFile, sTime, ';');
		getline(inFile, sLocation, ';');
		getline(inFile, sTemp, ';');
		cout << "Log sTemp: " << sTemp << endl;
		fTemp = stof(sTemp);
		getline(inFile, sMoist, '\n');
		iMoist = stoi(sMoist);
		cout << post << ". ";
		cout << sDate << " " << sTime << " " << sLocation << " " << sTemp << " " << sMoist << endl;
		++post;
		if (post == 10)
		{
			cin.get();
		}
	}
	cout << endl << "Number of posts: " << post;
	//while (!inFile.eof())
	//{
	//	//inFile >> SfileData[y];
	//	string tempDataDump = "";
	//	inFile >> tempDataDump;
	//	fileData.push_back(tempDataDump);
	//}
	//for (auto n : fileData) {
	//	cout << n << endl;
	//}
	///*for (auto it = fileData.begin(); it != fileData.end(); it++)
	//{
	//	cout << *it << endl;
	//	counter++;
	//}*/
	////cout << endl << "Number of entries: " << counter / 2;

}
