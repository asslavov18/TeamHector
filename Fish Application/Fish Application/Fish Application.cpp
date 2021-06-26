#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <Windows.h>
using namespace std;

ofstream inputData("FishData.txt");
ifstream outputData("FishData.txt");
bool checkForMatch = false;
int fishPostion=10;
bool check = true;

struct FISH_DATA {
	string name;
	string color;
	int lifeTime;
	string euryhaline;
};

FISH_DATA fishes[100] = { 
	{"Yellow Discuss", "Yellow",13,"Fresh Water"},{"Chromis","Blue",13,"Salt Water"},{"Anthias","Colurful",3,"Salt Water"},
	{"Royal Gramma","Purple",5,"Fresh Water"},{"Kissing Gourami","Orange",6,"Fresh Water"},{"Yellow Tang","Yellow",30,"Salt Water"},
	{"Clown Fish","Orange",4,"Salt Water"},{"Black Molly","Black",3,"Fresh Water"},{"Purple Tang","Purple",25,"Salt Water"},
	{"Blue Discuss","Blue", 10, "Fresh Water"}
};

void rememberFishDataInTxtFile()
{
	for(int i = 0; i < fishPostion; i++)
	{
		inputData << fishes[i].name<<" ";
		inputData << fishes[i].color<<" ";
		inputData << fishes[i].lifeTime<<" ";
		inputData << fishes[i].euryhaline<<endl;
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
	printf("0. Exit\n");

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
	inputData << fishes[fishPostion].lifeTime<<" ";
	cin.ignore();

	printf("Enter Fish Euryhaline: ");

	getline(cin,fishes[fishPostion].euryhaline);
	inputData << fishes[fishPostion].euryhaline << endl;

	fishPostion++;

	
}

void outputFishData()
{
	system("cls");
	string data;
	int fishNumber = 1;

	for (int i = 0; i < fishPostion; i++)
	{
		cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << " Euryhaline: "<<fishes[i].euryhaline<< endl;
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

FISH_DATA sortByEuryhalineAlpabetically()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].euryhaline >= fishes[j + 1].euryhaline) {
				swap(fishes[j], fishes[j + 1]);
			}
		}
	}

	return fishes[fishPostion];
}

FISH_DATA sortByEuryhalineAlpabeticallyReversed()
{
	for (int i = 0; i < fishPostion; i++)
	{
		for (int j = 0; j < fishPostion - 1; j++)
		{
			if (fishes[j].euryhaline <= fishes[j + 1].euryhaline) {
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
	printf("5. Sort by lifetime largest to smallest\n");
	printf("6. Sort by lifetime smallest to largest\n");
	printf("7. Sort by euryhaline alphabetically\n");
	printf("8. Sort by euryhaline alphabetically reversed\n");
	printf("0. Return to the main menu\n");
	
	printf("\nEnter your choice: ");
}

string choiceToFind;
int choiceToFindForLifetime;
int findChoice;
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
	if (findChoice == 1)
	{
		
		printf("Enter a fish name: ");
		getline(cin, choiceToFind);
	}

	if (findChoice == 2)
	{
	
		printf("Enter a fish color: ");
		getline(cin, choiceToFind);
	}

	if (findChoice == 3)
	{
		printf("Enter a fish lifetime: ");
		cin >> choiceToFindForLifetime;
	}

	if (findChoice == 4)
	{
	
		printf("Enter a fish euryhaline: ");
		getline(cin, choiceToFind);
	}
}

void printFoundByName()
{
	system("cls");
	int fishNumber = 1;
	for (int i = 0; i < fishPostion; i++)
	{
		if (choiceToFind == fishes[i].name)
		{
			cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << " Euryhaline: " << fishes[i].euryhaline << endl;
			fishNumber++;
		}
	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
}

void printFoundByColor()
{
	system("cls");
	int fishNumber = 1;
	for (int i = 0; i < fishPostion; i++)
	{
		if (choiceToFind == fishes[i].color)
		{
			cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << " Euryhaline: " << fishes[i].euryhaline << endl;
			fishNumber++;
		}
	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
}

void printFoundByLifeTime()
{
	cin.ignore();
	system("cls");
	int fishNumber = 1;
	for (int i = 0; i < fishPostion; i++)
	{
		if (choiceToFindForLifetime == fishes[i].lifeTime)
		{
			cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << " Euryhaline: " << fishes[i].euryhaline << endl;
			fishNumber++;
		}
	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
}

void printFoundByEuryhaline()
{
	system("cls");
	int fishNumber = 1;
	for (int i = 0; i < fishPostion; i++)
	{
		if (choiceToFind == fishes[i].euryhaline)
		{
			cout << fishNumber << "." << " Name: " << fishes[i].name << "  Color: " << fishes[i].color << "  Lifetime: " << fishes[i].lifeTime << " year(s)" << " Euryhaline: " << fishes[i].euryhaline << endl;
			fishNumber++;
		}
	}

	cout << endl << "Press Enter to escape: ";
	cin.get();
}

void checkForMatchAdminData()
{
	system("cls");
	cin.ignore();
	int counter = 0;
	string outputData;
	string inputCheckData;
	ifstream adminData("AdminData.txt");
	printf("Enter admin email: ");
	while (getline(adminData, outputData))
	{
		getline(cin, inputCheckData);
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
	if (check)
	{
		rememberFishDataInTxtFile();
		check = false;
	}

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

						case 7:
						sortByEuryhalineAlpabetically();
						break;

						case 8:
						sortByEuryhalineAlpabeticallyReversed();
						break;

						case 0:
						startProgram();
						break;

						default:
						startProgram();
						break;
				}
			startProgram();
			break;

		case 5:
			printFindingByParametersMenu();
			cin >> findChoice;
				switch (findChoice)
				{
					case 1:
					printFindByMenu();
					printFoundByName();
					break;

					case 2:
					printFindByMenu();
					printFoundByColor();
					break;

					case 3:
					printFindByMenu();
					printFoundByLifeTime();
					break;

					case 4:
					printFindByMenu();
					printFoundByEuryhaline();
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
}

int main()
{
	startProgram();
}