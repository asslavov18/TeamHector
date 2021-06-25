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
	FISH_DATA fishData;

	printf("Enter Fish Name: ");

	getline(cin,fishData.name);
	inputData << fishData.name<<"  Color: ";
	fishes[fishPostion].name = fishData.name;

	printf("Enter Fish Color: ");

	getline(cin, fishData.color);
	inputData << fishData.color << "  Lifetime: ";
	fishes[fishPostion].color = fishData.color;

	printf("Enter Fish Lifetime: ");

	cin >> fishData.lifeTime;
	inputData << fishData.lifeTime<<" years"<<endl;
	fishes[fishPostion].lifeTime = fishData.lifeTime;

	fishPostion++;

	cin.ignore();
}

void outputFishData()
{
	string data;
	int fishNumber = 1;
	while (getline(outputData, data))
	{
		cout<<fishNumber<<"."<<" Name: "<< data << endl;
		fishNumber++;
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