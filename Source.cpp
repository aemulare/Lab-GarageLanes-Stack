/***************************************************************************************************
									CSC 326 Information Structures
												Lab #2
									 The Parking Garage (Stack)
									  Student: Maria Romanova

***************************************************************************************************/


#include <iostream>
#include <fstream>
#include "Messages.h"
#include "Garage.h"
#include "Shell.h"
#include "Car.h"
using namespace std;


int main()
{
	Shell<string> shell;	// to format output
	Garage<Car> g;

	char status = ' ';		// 'A' - arrival, 'D' - departure
	string plateNumber;		// any string with no restrictions
	int lineCounter = 0;	// counts lines in file
	int errorCounter = 0;	// counts invalid entries in file (which does not begin with A or D)
	ifstream inFile;

	shell.displayHeader();

	// open file --------------------------
	inFile.open(FILE_NAME);
	if (!inFile)
	{
		shell.highlight(ERROR_OPEN_FILE, 12);	// error message text in light_red
		Sleep(5000);							// delay output for 5 sec
		return 1;
	}

	// check file for invalid entries --------------------------------------------
	while (!inFile.eof())
	{
		inFile >> status >> plateNumber;
		if (status != 'A' && status != 'D')
			errorCounter++;
	}

	if (errorCounter > 0)
	{
		shell.highlight(INVALID_FILE, 12);		// error message text in light_red
		cout << "\n\tNumber of invalid entries = " << errorCounter << endl;
		Sleep(5000);							// delay output for 5 sec
		return 1;
	} // end check file for invalid entries ----------------------------------------


	// return to the beginning of the file
	inFile.clear();
	inFile.seekg(0, ios::beg);


	// Processing valid file -------------------------
	while (!inFile.eof())
	{
		lineCounter++;

		inFile >> status >> plateNumber;
		Car car(plateNumber);

		cout << "\n\t" << lineCounter << "\t";

		if (status == 'A')
		{
			shell.highlight(ARRIVAL, 10);			// message "Arrival" in light_green
			cout << plateNumber << "   ";
			if (!g.arrival(car))						
				shell.highlight(FULL_GARAGE);		// message "Garage is FULL" in light_gray
		}

		else //(status == 'D')
		{
			shell.highlight(DEPARTURE, 12);			// message "Departure" in light_red
			cout << plateNumber << "   ";
			if (!g.departure(car))
				shell.highlight(CAR_NOT_FOUND, 14); // error message "NOT IN THE GARAGE" in light_yellow
		}
	}// end while
		
	inFile.close();	

	// pause screen
	cout << "\n\n\t";
	system("pause");
	return 0;

} // End main()



