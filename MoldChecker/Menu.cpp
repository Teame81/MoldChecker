#include "pch.h"
#include "Menu.h"


Menu::Menu()
{

}

Menu::~Menu()
{

}


void Menu::mainMenu(PostDatabase &mDatabase)
{
	bool loop = true;

	while (loop)
	{
		cout << "\n---------MAIN MENU---------\n";
		cout << "1. Outdoors menu.\n";
		cout << "2. Indoors menu.\n";
		cout << "3. Date for meteorological autumn.\n";
		cout << "4. Date for meteorological winter.\n";
		cout << "5. Print biggest temperature difference.\n";
		cout << "Q. Quit.\n";
		
		switch (menuInput())
		{
			case '1':
			{
				outDoorMenu(mDatabase);

			}
			break;
			case '2':
			{
				inDoorMenu(mDatabase);


			}
			break;
			case '3':
			{
				mDatabase.sortByDate();
				mDatabase.printMetrologicAutumn();
			}
			break;
			case '4':
			{
				mDatabase.sortByDate();
				mDatabase.printMetrologicWinter();

			}
			break;
			case '5':
			{
				mDatabase.sortByTempDiffHighToLow();
				mDatabase.printTempDiffList();

			}
			break;
			case 'Q':
			{
				cout << "Bye!";
				loop = false;
			}
			break;
		default:
			break;
		}
	}
}

void Menu::outDoorMenu(PostDatabase & mDatabase)
{
	bool loop = true;

	while (loop)
	{
		cout << "\n---------OUTDOOR MENU---------\n";
		cout << "1. Warmest to coldest day.\n";
		cout << "2. Driest to most moist day.\n";
		cout << "3. Least risk to highest mold risk.\n";
		cout << "4. Search for a specific day.\n";
		cout << "Q. Back.\n";

		switch (menuInput())
		{
		case '1':
		{
			mDatabase.sortByTemperature();
			mDatabase.printOutList();
		}
		break;
		case '2':
		{
			mDatabase.sortDryToMoist();
			mDatabase.printOutList();
		}
		break;
		case '3':
		{
			mDatabase.sortLowToHighMold();
			mDatabase.printOutList();
		}
		break;
		case '4':
		{
			mDatabase.sortByDate();
			int iSearch{};
			vector<Post>::iterator itCB = mDatabase.getOutVector().begin();
			vector<Post>::iterator itCE = mDatabase.getOutVector().end() - 1;
			cout << "Current range: " << itCB->iGetDate() <<" - " << itCE->iGetDate() <<"\nFormat ex(Y/M/D): 20160515\nEnter: ";
			cin >> iSearch;
			mDatabase.searchForDateInPostVector(mDatabase.getOutVector(), iSearch);
		}
		break;
		case 'Q':
		{
			loop = false;
		}
		break;
		default:
			break;
		}
	}
}

void Menu::inDoorMenu(PostDatabase & mDatabase)
{
	bool loop = true;

	while (loop)
	{
		cout << "\n---------INDOOR MENU---------\n";
		cout << "1. Warmest to coldest day.\n";
		cout << "2. Driest to most moist day.\n";
		cout << "3. Least risk to highest mold risk.\n";
		cout << "4. Search for a specific day.\n";
		cout << "Q. Back.\n";

		switch (menuInput())
		{
		case '1':
		{
			mDatabase.sortByTemperature();
			mDatabase.printInList();
		}
		break;
		case '2':
		{
			mDatabase.sortDryToMoist();
			mDatabase.printInList();
		}
		break;
		case '3':
		{
			mDatabase.sortLowToHighMold();
			mDatabase.printInList();
		}
		break;
		case '4':
		{
			mDatabase.sortByDate();
			int iSearch{};
			vector<Post>::iterator itCB = mDatabase.getInVector().begin();
			vector<Post>::iterator itCE = mDatabase.getInVector().end() - 1;
			cout << "Current range: " << itCB->iGetDate() << " - " << itCE->iGetDate() << "\nFormat ex(Y/M/D): 20160515\nEnter: ";
			cin >> iSearch;
			mDatabase.searchForDateInPostVector(mDatabase.getInVector(), iSearch);
		}
		break;
		case 'Q':
		{
			loop = false;
		}
		break;
		default:
			break;
		}
	}
}

char Menu::menuInput()
{

	char mInput{};
	
	while (mInput != '1' && mInput != '2' && mInput != '3' && mInput != '4' && mInput != '5' && mInput != 'Q')
	{
		cout << "\n>: ";
		cin >> mInput;
		mInput = toupper(mInput);
	}
	
		
	
	
	return mInput;
}
