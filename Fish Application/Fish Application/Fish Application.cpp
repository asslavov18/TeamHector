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
	printf("6. Login as admin\n");
}

void inputFishData()
{

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
	}

	cout << endl << "Enter 0 to escape";
}

/*void removeFishData()
{
	int* choice = new int;
	outputFishData();
	printf("Enter a number row you want to remove: ");
	cin >> *choice;
}*/

bool compator(string a, string b)
{
	return a < b;
}


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

void checkForMatchAdminData()
{
	int counter = 0;
	string outputData;
	string inputCheckData;
	ifstream adminData("AdminData.txt");
	while (getline(adminData, outputData))
	{
		cin >> inputCheckData;
		if (outputData==inputCheckData)
		{
			counter++;
		}
	}

	if (counter == 2)
	{
		checkForMatch = true;
	}
}


void startProgram()
{
	int* choice = new int;
	cin >> *choice;

	switch (*choice)
	{
		case 1:
		outputFishData();
		break;

		case 2:
			if (checkForMatch)
			{
				outputFishData();
			}
			break;
	}
}

int main()
{
	inputFishData();
	inputFishData();
	system("cls");
	outputFishData();
}