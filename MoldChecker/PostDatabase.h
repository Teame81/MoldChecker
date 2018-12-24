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

private:
	vector<Post> post;
};