#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

//Creating FISH_DATA struct for to safe the data from the file
struct FISH_DATA {
	string name;
	string color;
	int lifeTime;
	string euryhaline;
};

//Namespace for the global variables
namespace global {
	ofstream inputData;
	ifstream outputData("FishData.txt");
	bool checkForMatch = false;
	int fishPostion = 10;
	string choiceToFind;
	int choiceToFindForLifetime;
	int* findChoice = new int;

	//Default FISH_DATA
	FISH_DATA fishes[30] = {
		{"Yellow Discuss", "Yellow",13,"Fresh Water"},{"Chromis","Blue",13,"Salt Water"},{"Anthias","Colurful",3,"Salt Water"},
		{"Royal Gramma","Purple",5,"Fresh Water"},{"Kissing Gourami","Orange",6,"Fresh Water"},{"Yellow Tang","Yellow",30,"Salt Water"},
		{"Clown Fish","Orange",4,"Salt Water"},{"Black Molly","Black",3,"Fresh Water"},{"Purple Tang","Purple",25,"Salt Water"},
		{"Blue Discuss","Blue", 10, "Fresh Water"}
	};
};

//Input the reconstructed struct into the file
void rememberFishDataInFile()
{
	global::inputData.open("FishData.txt", ofstream::trunc);
	for (int i = 0; i < global::fishPostion; i++)
	{
		global::inputData << global::fishes[i].name << " ";
		global::inputData << global::fishes[i].color << " ";
		global::inputData << global::fishes[i].lifeTime << " ";
		global::inputData << global::fishes[i].euryhaline << endl;
	}
}

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
	if (setColor(FOREGROUND_RED | FOREGROUND_INTENSITY) && global::checkForMatch == false)
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
	if (global::checkForMatch == false)
	{
		printf("6. Login as admin\n");
	}
	printf("0. Exit\n");

	printf("\nEnter your choice: ");

}

//Input into the struct
void inputFishData()
{
	cin.ignore();
	system("cls");

	printf("Enter Fish Name: ");

	getline(cin, global::fishes[global::fishPostion].name);

	printf("Enter Fish Color: ");

	getline(cin, global::fishes[global::fishPostion].color);

	printf("Enter Fish Lifetime: ");

	cin >> global::fishes[global::fishPostion].lifeTime;
	cin.ignore();

	printf("Enter Fish Euryhaline: ");

	getline(cin, global::fishes[global::fishPostion].euryhaline);

	//Into the file
	rememberFishDataInFile();

	global::fishPostion++;


}

void outputFishData()
{
	system("cls");
	int fishNumber = 1;

	for (int i = 0; i < global::fishPostion; i++)
	{
		cout << fishNumber << "." << " Name: " << global::fishes[i].name << "  Color: " << global::fishes[i].color << "  Lifetime: " << global::fishes[i].lifeTime << " year(s)" << " Euryhaline: " << global::fishes[i].euryhaline << endl;
		fishNumber++;
	}
}

//Function which we use for removing fish data
//From the struct and from the file
void removeFishFromData()
{
	outputFishData();
	int* choice = new int;
	printf("\nEnter 0 to return to the main menu");
	printf("\n\nEnter a number row you want to remove: ");
	cin >> *choice;

	while (*choice != 0)
	{
		global::fishPostion--;
		for (int i = *choice - 1; i < global::fishPostion; i++)
		{
			global::fishes[i] = global::fishes[i + 1];
		}
		outputFishData();
		printf("\nEnter 0 to return to the main menu");
		printf("\n\nEnter a number row you want to remove: ");
		cin >> *choice;
		rememberFishDataInFile();
	}

	delete choice;

}

FISH_DATA sortData(int choice)
{
	switch (choice)
	{
		//Sort by name alphabetically
	case 1:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].name >= global::fishes[j + 1].name) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by name alphabetically reversed
	case 2:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].name <= global::fishes[j + 1].name) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by color alphabetically
	case 3:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].color >= global::fishes[j + 1].color) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by color alphabetically reversed
	case 4:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].color <= global::fishes[j + 1].color) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by lifetime largest to smallest		
	case 5:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].lifeTime <= global::fishes[j + 1].lifeTime) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by lifetime smallest to largest	
	case 6:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].lifeTime >= global::fishes[j + 1].lifeTime) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by euryhaline alphabetically
	case 7:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].euryhaline >= global::fishes[j + 1].euryhaline) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;

		//Sort by euryhaline alphabetically reversed
	case 8:
		for (int i = 0; i < global::fishPostion; i++)
		{
			for (int j = 0; j < global::fishPostion - 1; j++)
			{
				if (global::fishes[j].euryhaline <= global::fishes[j + 1].euryhaline) {
					swap(global::fishes[j], global::fishes[j + 1]);
				}
			}
		}
		break;
	}

	return global::fishes[global::fishPostion];
}

void printSortingMenu()
{
	system("cls");
	printf("1. Sort by name alphabetically\n");
	printf("2. Sort by name alphabetically reversed\n");
	printf("3. Sort by color alphabetically\n");
	printf("4. Sort by color alphabetically reversed\n");
	printf("5. Sort by lifetime largest to smallest\n");
	printf("6. Sort by lifetime smallest to largest\n");
	printf("7. Sort by euryhaline alphabetically\n");
	printf("8. Sort by euryhaline alphabetically reversed\n");
	printf("0. Return to the main menu\n");

	printf("\nEnter your choice: ");
}

void printFindingByParametersMenu()
{
	system("cls");
	printf("1. Find by name\n");
	printf("2. Find by color\n");
	printf("3. Find by lifetime\n");
	printf("4. Find by euryhaline\n");
	printf("0. Return to the main menu\n");

	printf("\nEnter your choice: ");
}

void printFindByMenu()
{
	cin.ignore();
	system("cls");
	if (*global::findChoice == 1)
	{

		printf("Enter a fish name: ");
		getline(cin, global::choiceToFind);
	}

	if (*global::findChoice == 2)
	{

		printf("Enter a fish color: ");
		getline(cin, global::choiceToFind);
	}

	if (*global::findChoice == 3)
	{
		printf("Enter a fish lifetime: ");
		cin >> global::choiceToFindForLifetime;
	}

	if (*global::findChoice == 4)
	{

		printf("Enter a fish euryhaline: ");
		getline(cin, global::choiceToFind);
	}
}

//Print found fishes
void printFoundByParameter()
{
	system("cls");
	int fishNumber = 1;

	switch (*global::findChoice)
	{
		//Found by name
	case 1:

		for (int i = 0; i < global::fishPostion; i++)
		{
			if (global::choiceToFind == global::fishes[i].name)
			{
				cout << fishNumber << "." << " Name: " << global::fishes[i].name << "  Color: " << global::fishes[i].color << "  Lifetime: " << global::fishes[i].lifeTime << " year(s)" << " Euryhaline: " << global::fishes[i].euryhaline << endl;
				fishNumber++;
			}
		}
		break;

		//Found by color
	case 2:

		for (int i = 0; i < global::fishPostion; i++)
		{
			if (global::choiceToFind == global::fishes[i].color)
			{
				cout << fishNumber << "." << " Name: " << global::fishes[i].name << "  Color: " << global::fishes[i].color << "  Lifetime: " << global::fishes[i].lifeTime << " year(s)" << " Euryhaline: " << global::fishes[i].euryhaline << endl;
				fishNumber++;
			}
		}
		break;

		//Found by lifetime
	case 3:
		cin.ignore();

		for (int i = 0; i < global::fishPostion; i++)
		{
			if (global::choiceToFindForLifetime == global::fishes[i].lifeTime)
			{
				cout << fishNumber << "." << " Name: " << global::fishes[i].name << "  Color: " << global::fishes[i].color << "  Lifetime: " << global::fishes[i].lifeTime << " year(s)" << " Euryhaline: " << global::fishes[i].euryhaline << endl;
				fishNumber++;
			}
		}
		break;

		//Found by euryhaline
	case 4:

		for (int i = 0; i < global::fishPostion; i++)
		{
			if (global::choiceToFind == global::fishes[i].euryhaline)
			{
				cout << fishNumber << "." << " Name: " << global::fishes[i].name << "  Color: " << global::fishes[i].color << "  Lifetime: " << global::fishes[i].lifeTime << " year(s)" << " Euryhaline: " << global::fishes[i].euryhaline << endl;
				fishNumber++;
			}
		}
		break;

	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
}

//Checks if the data from the file and from the input
// Is matching. If it is it returns true
//Else false
void checkForMatchAdminData()
{
	system("cls");
	cin.ignore();
	int counter = 0;
	string* outputData = new string;
	string* inputCheckData = new string;
	ifstream adminData("AdminData.txt");
	printf("Enter admin email: ");
	while (getline(adminData, *outputData))
	{
		getline(cin, *inputCheckData);
		if (*outputData == *inputCheckData)
		{
			counter++;
		}
		printf("Enter admin password: ");

	}

	if (counter == 2)
	{
		global::checkForMatch = true;
	}

	delete outputData;
	delete inputCheckData;;
}


void startProgram()
{
	rememberFishDataInFile();

	int* choice = new int;
	printMenu();
	cin >> *choice;

	switch (*choice)
	{
	case 1:
		outputFishData();
		cout << endl << "Press Enter to escape: ";
		cin.get();
		cin.ignore();
		startProgram();
		break;

	case 2:
		if (global::checkForMatch)
		{
			inputFishData();
			startProgram();
		}
		else {
			startProgram();
		}
		break;

	case 3:
		if (global::checkForMatch)
		{
			removeFishFromData();
			startProgram();
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
			sortData(sortChoice);
			break;

		case 2:
			sortData(sortChoice);
			break;

		case 3:
			sortData(sortChoice);
			break;

		case 4:
			sortData(sortChoice);
			break;

		case 5:
			sortData(sortChoice);
			break;

		case 6:
			sortData(sortChoice);
			break;

		case 7:
			sortData(sortChoice);
			break;

		case 8:
			sortData(sortChoice);
			break;

		case 0:
			startProgram();
			break;

		default:
			startProgram();
			break;
		}
		rememberFishDataInFile();
		startProgram();
		break;

	case 5:
		printFindingByParametersMenu();
		cin >> *global::findChoice;
		switch (*global::findChoice)
		{
		case 1:
			printFindByMenu();
			printFoundByParameter();
			break;

		case 2:
			printFindByMenu();
			printFoundByParameter();
			break;

		case 3:
			printFindByMenu();
			printFoundByParameter();
			break;

		case 4:
			printFindByMenu();
			printFoundByParameter();
			break;

		case 0:
			break;

		default:
			break;
		}
		startProgram();
		break;

	case 6:
		checkForMatchAdminData();
		startProgram();
		break;

	case 0:
		exit(1);

	default:
		startProgram();
		break;
	}

	delete choice;
	delete global::findChoice;
}

int main()
{
	startProgram();
}