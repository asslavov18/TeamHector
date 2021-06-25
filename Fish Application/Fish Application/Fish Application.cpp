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
}



int main()
{

	
}