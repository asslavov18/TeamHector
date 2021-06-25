#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
using namespace std;

ofstream inputData("FishData.txt");
ifstream outputData("FishData.txt");
bool checkForMatch = false;

void printMenu()
{
	printf("1. Show fish data\n");
	printf("2. Add fish data (Administration permissions needed!)\n");
	printf("3. Remove fish data (Administration permissions needed!)\n");
	printf("4. Sort fish data\n");
	printf("5. Find fish data by parameters\n");
	printf("6. Login as admin\n");
}

void inputFishData(string data)
{
	cin >> data;
	inputData << data << endl;
}

void outputFishData(string data)
{
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



int main()
{
	
	
}