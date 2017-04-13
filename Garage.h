#pragma once
#include "Stack.h"
#include "Car.h"
#include <iostream>
using namespace std;

template<class T> class Garage
{
public:
	Garage() {}

	~Garage() {}

	/* Pre: If LANE 1 is not full, then car is pushed onto stack LANE 1. Otherwise - LANE 2.
	   Post: The parking lane nuber is displayed in case of successful operation.
	   Otherwise (if both lanes were full), no lane number is assigned and result of operation = false*/
	bool arrival(Car& car)
	{
		if (!lane_1.IsFull())
		{
			cout << " lane 1   \n";
			lane_1.push(car);
			return true;
		}
		else if (!lane_2.IsFull())
		{
			cout << " lane 2   \n";
			lane_2.push(car);
			return true;
		}
		else
		{
			cout << "  ---     ";
			return false;
		}
	} // end arrival


	/* The top car from source lane is moved to destination lane, and move counter incremented by 1.*/
	void moveCar(Stack<T>& source, Stack<T>& dest)
	{
		dest.push(source.Top());
		dest.Top().addMove();
		source.pop();
	}


	/* Pre: If car is not fount in the garage, the result of operation = false.
	   Post: If car was not retrieved from the LANE 1, it's retrieved from the LANE 2.
	   And result of operation = true is returned.*/
	bool departure(Car& car)
	{
		if (lane_1.search(car) < 0 && lane_2.search(car) < 0)
			return false;

		if (!retrieveCar(lane_1, lane_2, 1, car))
		{
			retrieveCar(lane_2, lane_1, 2, car);
		}
		return true;

	} // end departure


	/* Pre: If the REQUESTED for departure car isn't found in the current lane, returns false.
	   Post: The REQUESTED car is retrieved from the current lane.
	   All cars, moved to street in process, are returned back to garage.*/
	bool retrieveCar(Stack<T>& currentLane, Stack<T>& otherLane, int currentLaneNumber, Car& car)
	{
		if (currentLane.search(car) >= 0)
		{
			// REQUESTED car is on Top-------------------------------------------------------------------------------
			if (car == currentLane.Top())
			{
				cout << " lane " << currentLaneNumber << "   moved " << currentLane.Top().getMoveCount() << " times\n";
				currentLane.pop();
			}

			// REQUESTED car is  NOT on Top--------------------------------------------------------------------
			else
			{
				// move all cars to get access to the REQUESTED car
				int topCarIndex = currentLane.search(currentLane.Top());
				int reqCarIndex = currentLane.search(car);

				for (int j = topCarIndex; j > reqCarIndex; j--)
				{
					if (!otherLane.IsFull())
						moveCar(currentLane, otherLane);
					else
						moveCar(currentLane, street);
				}

				// pop the REQUESTED car ----------------------------------------------------------------------------
				cout << " lane " << currentLaneNumber << "   moved " << currentLane.Top().getMoveCount() << " times\n";
				currentLane.pop();
				clearStreet();
			}
			return true;
		}
		else
			return false;
	} // end retrieveCar



	/* Post: All cars, that were moved to street are returned back to garage.*/
	void clearStreet()
	{
		while (!street.IsEmpty())
		{
			if (!lane_1.IsFull())
				moveCar(street, lane_1);
			else
				moveCar(street, lane_2);
		}
	} // end clearStreet


private:
	Stack<T> lane_1;
	Stack<T> lane_2;
	Stack<T> street;
}; // end Garage