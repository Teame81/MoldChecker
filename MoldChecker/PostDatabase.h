#pragma once
#include "Post.h"
#include <vector>

class PostDatabase
{
public:
	PostDatabase();
	~PostDatabase();
	void addPost(Post inPost); // adds a post into the main vector(vPost)
	void printAllData(); // Prints all data in main vector(vPost)
	float fMediumTemperature(); // returns medium temperature of main vector(vPost)
	void printMediumTemperature();// prints medium temperature of main vector(vPost)
	void printOutList(); //Prints all objects of the "out" vector(vOut)
	void printInList(); // Prints alla the objects of the "in" vector(vIn)
	void sortInAndOut();// Sort out "Inne" / "Ute" into vIn vector and vOut vector
	void sortOutMedium();// Fills the vOutMediumPerDay vector with the medium of all "Ute" posts
	void sortInMedium(); // Fills the vInMediumPerDay vectot with the medium of all "Inne" posts
	void printInMediumPerDay();// Prints the vInMediumPerDay list
	void printOutMediumPerDay();// Prints the vOutMediumPerDay list
	Post searchForDateInPostVector(vector<Post> inVec, int inInt);//Search in a vector
	vector<Post> getVector(string inString);
private:
	vector<Post> vPost;
	vector<Post> vIn;
	vector<Post> vInMediumPerDay;
	vector<Post> vOut;
	vector<Post> vOutMediumPerDay;
	

};