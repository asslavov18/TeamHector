#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

ofstream inputData("FishData.txt");
ifstream outputData("FishData.txt");
bool checkForMatch = false;

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
	string data;
	cin >> data;
	inputData << data << endl;
}

void outputFishData()
{
	string data;
	while (getline(outputData, data))
	{
		cout << data << endl;
	}
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
			break;
	}
}

int main()
{
	printMenu();
}