#pragma once
#include "Post.h"
#include <vector>

class PostDatabase
{
public:
	PostDatabase();
	~PostDatabase();
	void addPost(Post inPost);
	void printAllData();
	float fMediumTemperature();
	void printMediumTemperature();
	void sortInAndOut();
	void sortOutMedium();
	void printOut();


private:
	vector<Post> vPost;
	vector<Post> vIn;
	vector<Post> vOut;
	vector<Post> vOutMediumPerDay;

};