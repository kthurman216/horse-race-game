/*
 * main.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: Kayla
 */

#include "Horse.h"
#include <iostream>
#include <string>
#include <ctime>
#include <cctype>

using namespace std;

void runRace(Horse[], int, int);
void again(Horse[], int, int);
int checkWin(Horse[], int, int);


int main()
{
	//seed random number generator for horse maxRunSpeed and distTraveled
	unsigned seed = time(0);
	srand(seed);

	//variable to hold number of horses in the race
	int numHorse;

	//prompt user to enter the number of horses in the race
	cout << "How many horses are in the race?\n";
	cin >> numHorse;
	cin.ignore();

	//validate the number of horses is not negative or one
	while (numHorse <= 1)
	{
		cout << "Please enter a valid number of horses (1 or more).\n";

		cout << "How many horses are in the race?\n";
		cin >> numHorse;
		cin.ignore();
	}

	//creates array of horse objects
	Horse * hArr = new Horse[numHorse];

	//sets names and riders for horse objects
	for (int i = 0; i < numHorse; i++)
	{
		string hName = "", rName= "";

		//prompts user for horse names, sets names
		cout << "Please give me the name for horse " << i + 1 << ":" << endl;
		getline(cin, hName);
		hArr[i].setName(hName);



		//prompts user for rider names, sets riders
		cout << "Please give me the name for rider " << i + 1 << ":" << endl;
		getline(cin, rName);
		hArr[i].setRider(rName);
	}

	int raceDist;
	//prompts user for length of race
	cout << "Please enter the distance of the race: \n";
	cin >> raceDist;
	cin.ignore();

	//validates race length is not negative and greater than 100
	while (raceDist < 100)
	{
		cout << "Please enter a valid race length (greater than 100).\n";

		cout << "Please enter the distance of the race: \n";
		cin >> raceDist;
	}

	runRace(hArr, numHorse, raceDist);




	//clears dynamically allocated pointer and resets to null
	delete [] hArr;
	hArr = nullptr;

	return 0;
}


void runRace(Horse horseArr[], int hNum, int raceLen)
{
	char choice = ' ';
	int winner = -1;
	static int raceTotal = 1;

	//runs race as long as user wishes to continue
	do {
		//loop runs a second for each horse
		for (int i = 0; i < hNum; i++)
		{
			horseArr[i].runASecond();
			horseArr[i].displayHorse(raceLen);

			if (checkWin(horseArr, hNum, raceLen) != -1)
			{
				winner = checkWin(horseArr, hNum, raceLen);
			}
		}

		//if there is no winner asks if user wants to continue race
		if (winner == -1)
		{
			cout << "Continue the race? (y/n)?:\n";
				cin >> choice;
				while (tolower(choice) != 'y' && tolower(choice) != 'n')
				{
					cout << "Please enter a valid choice (y/n).\n";
					cout << "Continue the race? (y/n)?:\n";
					cin >> choice;
				}
		}
		else
		{
			//adds race won to winning horse
			horseArr[winner].addRaceWon();

			//displays winning stats for horses
			for (int i = 0; i < hNum; i++)
			{
				cout 	<< horseArr[i].getName() << " has won " << horseArr[i].getRacesWon()
						<< "/" << raceTotal << " races.\n";
			}

			raceTotal++;

			//calls again function
			again(horseArr, hNum, raceLen);
		}

	} while (tolower(choice) == 'y' && winner == -1);
}

//resets values if user would like to run another race
void again(Horse horseArray[], int hNum, int raceLen)
{
	char choice = ' ';
	//asks if user would like to run another race
	cout << "Would you like to start a new race? (y/n)\n";
	cin >> choice;

	//validates user input
	while (tolower(choice) != 'y' && tolower(choice) != 'n')
	{
		cout << "Please enter a valid choice (y/n).\n";

		cout << "Would you like to start a new race? (y/n)\n";
		cin >> choice;
	}

	if (tolower(choice) == 'y')
	{
		for (int i = 0; i < hNum; i++)
		{
			horseArray[i].sendToGate();
		}

		runRace(horseArray, hNum, raceLen);
	}
}

int checkWin(Horse horseArr[], int hNum, int raceLen)
{
	int winIndex = -1, highDist = 0;

	for (int i = 0; i < hNum; i++)
	{
		if (horseArr[i].getDistTraveled() > raceLen)
		{
			if (horseArr[i].getDistTraveled() > highDist)
			{
				highDist = horseArr[i].getDistTraveled();
				winIndex = i;
			}
		}
	}

	return winIndex;
}
