#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

ofstream inputData("FishData.txt");
ifstream outputData("FishData.txt");
bool checkForMatch = false;
int fishPostion=0;

struct FISH_DATA {
	string name;
	string color;
	int lifeTime;
};

FISH_DATA fishes[100];

//string fishLines[20];

bool setColor(WORD newColor)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

	if (hStdOut != INVALID_HANDLE_VALUE)
	{
		return SetConsoleTextAttribute(hStdOut, newColor);
	}

	return false;
}

void printMenu()
{
	system("cls");
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("1. Show fish data\n");
	setColor(FOREGROUND_RED | FOREGROUND_INTENSITY);
	if (setColor(FOREGROUND_RED | FOREGROUND_INTENSITY)&&checkForMatch==false)
	{
		printf("2. Add fish data (Administration permissions needed!)\n");
		printf("3. Remove fish data (Administration permissions needed!)\n");
	}
	else
	{
		setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
		if (setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE))
		{
			printf("2. Add fish data (Administration permissions needed!)\n");
			printf("3. Remove fish data (Administration permissions needed!)\n");
		}
	}
	setColor(FOREGROUND_INTENSITY | FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE);
	printf("4. Sort fish data\n");
	printf("5. Find fish data by parameters\n");
	if (checkForMatch == false)
	{
		printf("6. Login as admin\n");
	}

	printf("\nEnter your choice: ");
	
}

void inputFishData()
{
	cin.ignore();
	system("cls");

	printf("Enter Fish Name: ");

	getline(cin,fishes[fishPostion].name);
	inputData << fishes[fishPostion].name<<" ";

	printf("Enter Fish Color: ");

	getline(cin, fishes[fishPostion].color);
	inputData << fishes[fishPostion].color << " ";

	printf("Enter Fish Lifetime: ");

	cin >> fishes[fishPostion].lifeTime;
	inputData << fishes[fishPostion].lifeTime<<endl;

	fishPostion++;

	cin.ignore();
}

void outputFishData()
{
	system("cls");
	string data;
	int fishNumber = 1;
	/*while (getline(outputData, data))
	{
		cout<<fishNumber<<"."<<" Name: "<< data << endl;
		fishNumber++;
	}*/

	for (int i = 0; i < fishPostion; i++)
	{
		cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << endl;
		fishNumber++;
	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
	cin.ignore();
}

/*void removeFishData()
{
	int* choice = new int;
	outputFishData();
	printf("Enter a number row you want to remove: ");
	cin >> *choice;
}*/


FISH_DATA sortByNameAlphabetically()
{

	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].name >= fishes[j + 1].name) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}


FISH_DATA sortByNameAlphabeticallyReversed()
{

	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].name <= fishes[j + 1].name) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}


FISH_DATA sortByColorAlpabetically()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].color >= fishes[j + 1].color) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}

FISH_DATA sortByColorAlpabeticallyReversed()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].color <= fishes[j + 1].color) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}

FISH_DATA sortByLifetimeLargestToSmallest()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].lifeTime <= fishes[j + 1].lifeTime) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}

FISH_DATA sortByLifetimeSmallestToLargest()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].lifeTime >= fishes[j + 1].lifeTime) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}

void printSortingMenu()
{
	system("cls");
	printf("1. Sort by name alphabetically\n");
	printf("2. Sort by name alphabetically reversed\n");
	printf("3. Sort by color alphabetically\n");
	printf("4. Sort by color alphabetically reversed\n");
	printf("5. Sort by age largest to smallest\n");
	printf("6. Sort by age smallest to largest\n");
	
	printf("\nEnter your choice: ");
}

void checkForMatchAdminData()
{
	system("cls");
	int counter = 0;
	string outputData;
	string inputCheckData;
	ifstream adminData("AdminData.txt");
	printf("Enter admin email: ");
	while (getline(adminData, outputData))
	{
		cin >> inputCheckData;
		if (outputData==inputCheckData)
		{
			counter++;
		}
		printf("Enter admin password: ");
		
	}

	if (counter == 2)
	{
		checkForMatch = true;
	}
}


void startProgram()
{
	int* choice = new int;
	printMenu();
	cin >> *choice;

	switch (*choice)
	{
		case 1:
		outputFishData();
		startProgram();
		break;

		case 2:
			if (checkForMatch)
			{
				inputFishData();
				startProgram();
			}
			else {
				startProgram();
			}
			break;

		case 3:
			if (checkForMatch)
			{
				outputFishData();
			}
			else {
				startProgram();
			}
			break;
			
		case 4:
			int sortChoice;
			printSortingMenu();
			cin >> sortChoice;
				switch (sortChoice)
				{
						case 1:
						sortByNameAlphabetically();
						break;

						case 2:
						sortByNameAlphabeticallyReversed();
						break;

						case 3:
						sortByColorAlpabetically();
						break;

						case 4:
						sortByColorAlpabeticallyReversed();
						break;

						case 5:
						sortByLifetimeLargestToSmallest();
						break;

						case 6:
						sortByLifetimeSmallestToLargest();
						break;

						default:
						startProgram();
						break;
				}
			startProgram();
			break;

		case 5:
			break;

		case 6:
			checkForMatchAdminData();
			startProgram();
			break;

		default:
			startProgram();
			break;
	}

	delete choice;
}

int main()
{
	startProgram();
}