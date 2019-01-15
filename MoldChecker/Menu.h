#pragma once
#include "PostDatabase.h"

class Menu
{
public:

	Menu();
	~Menu();
	
	void mainMenu(PostDatabase &mDatabase);
	void outDoorMenu(PostDatabase &mDatabase);

	char menuInput();

private:
	
};

