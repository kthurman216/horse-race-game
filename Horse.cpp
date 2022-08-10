/*
 * Horse.cpp
 *
 *  Created on: Mar 13, 2021
 *      Author: Kayla
 */

#include "Horse.h"
#include <iostream>
#include <string>
#include <ctime>

using namespace std;



Horse::Horse(string n, string r)
{
	setName(n);
	setRider(r);
	distTraveled = 0;
	racesWon = 0;
	maxRunDist = rand() % ((100-1) - 1 + 1) + 1;
}

void Horse::setName(string n)
{
	name = n;
}

void Horse::setRider(string r)
{
	rider = r;
}

void Horse::addRaceWon()
{
	racesWon += 1;
}

void Horse::sendToGate()
{
	distTraveled = 0;
}

void Horse::runASecond()
{


	distTraveled += rand() % ((maxRunDist-1) - 1 + 1) + 1;

}

void Horse::displayHorse(int raceDist)
{
	int raceInc = raceDist/20;

	if (distTraveled >= raceDist)
		cout << "|>>>>>>>>>>>>>>>>>>>>|>\t";
	else
	{
		cout << "|";

		for (int i = 1; i <= 20; i++)
		{

			if ((raceInc * i) == raceInc || distTraveled > (i * raceInc))
				cout << ">";
			else
				cout << " ";
		}

		cout << "|\t";
	}
	cout << getName();
	cout << ", ridden by " << getRider() << getDistTraveled() << endl;
}





