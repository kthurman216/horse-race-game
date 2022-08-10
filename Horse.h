/*
 * Horse.h
 *
 *  Created on: Mar 13, 2021
 *      Author: Kayla
 */

#include <iostream>
#include <string>

using namespace std;

#ifndef HORSE_H_
#define HORSE_H_


class Horse
{
	private:
		string name;
		string rider;
		int maxRunDist;
		int distTraveled;
		int racesWon;
	public:
		Horse(string name = " ", string rider = " ");
		void setName(string);
		void setRider(string);
		void addRaceWon();
		void sendToGate();
		void runASecond();
		void displayHorse(int);
		string getName() const
			{ return name; }
		string getRider() const
			{ return rider; }
		int getMaxRun() const
			{ return maxRunDist; }
		int getDistTraveled() const
			{ return distTraveled; }
		int getRacesWon() const
			{ return racesWon; }
};




#endif /* HORSE_H_ */
