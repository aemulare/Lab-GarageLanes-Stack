#pragma once
#include <iostream>
using namespace std;

class Car
{
public:
	Car()							// default constructor
	{
		plateNumber = "";
		moveCount = 0;
	}

	Car(const string& plateNum)		// parameterized constructor
	{
		plateNumber = plateNum;
		moveCount = 0;
	}

	string getPlateNumber() const { return plateNumber; }

	void addMove() { moveCount++; }

	int getMoveCount() const { return moveCount; }

	bool operator==(const Car& car) const { return(plateNumber == car.getPlateNumber()); }


private:
	string plateNumber;
	int moveCount;
};