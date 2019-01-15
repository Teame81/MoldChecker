#pragma once
#include "Post.h"
#include <vector>

class PostDatabase
{
public:
	PostDatabase();
	~PostDatabase();
	void loadEssentials(); //Loads 
	void addPost(Post inPost); // adds a post into the main vector(vPost)
	void printAllData(); // Prints all data in main vector(vPost)
	float fMediumTemperature(); // returns medium temperature of main vector(vPost)
	void printMediumTemperature(); // prints medium temperature of main vector(vPost)
	void printOutList(); //Prints all objects of the "out" vector(vOut)
	void printInList(); // Prints all the objects of the "in" vector(vIn)
	
	void sortLowToHighMold(); // Send in a vector to sort it from low to high mold risk
	void sortByDate();//Send in a vector sort it by date
	void sortByTempDiffHighToLow();//Sorts vOut/In_Medium per days vectors in Temprature diffrent order
	void sortDryToMoist(); // Send in a vector to sort it from dry to moist
	void sortByTemperature(); //Sort a vector by temperature
	
	Post searchForDateInPostVector(vector<Post> inVec, int inInt);//Search in a vector string "VectorName", Integer "Date"
	vector<Post> getVector(string inString); //Getter for vectors
	void printMetrologicAutumn(); //Prints wich day metrologic autumn starts
	void printMetrologicWinter();//Prints wich day metroligic autumn starts
	
private:
	void sortInAndOut(); // Sort out "Inne" / "Ute" into vIn vector and vOut vector
	void sortOutMedium(); // Fills the vOutMediumPerDay vector with the medium of all "Ute" posts
	void sortInMedium(); // Fills the vInMediumPerDay vectot with the medium of all "Inne" posts
	void setTempDiff(); // Sets temp diff on Out and In medium vector post

	vector<Post> vPost;
	vector<Post> vIn;
	vector<Post> vInMediumPerDay;
	vector<Post> vOut;
	vector<Post> vOutMediumPerDay;

	

};