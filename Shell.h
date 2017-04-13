#pragma once
#include <string>
#include <iostream>
#include <iomanip>
#include <windows.h>
using namespace std;


template<class T> class Shell
{
public:

	/*Postcondition: The header with information for user about program is displayed.
	The white text framed by two lines of green asterisks.*/
	void displayHeader()
	{
		changeTextColor(02);	// green text color
		cout << endl << setfill('*') << setw(90) << "*" << "\n\n";

		changeTextColor(15);	// white text color
		cout << "\t\t This program implements work with stacks.\n\n" 
			<< "  The program represents 2 parking garage lanes and a street as stacks with size = 10.\n" 
			<< "  All the information about arriving or departuring cars is processed from an input file.\n"
			<< "  The input file contains two fields separated by a blank:\n"
			<< "\t - code (A - arrival, D - departure)\n"
			<< "\t - license plate number (string)\n\n"
			<< "  An Arrival represents push operation, Departure - pop. \n\n";
			
		changeTextColor(02);	// green text color
		cout << setfill('*') << setw(90) << "*" << "\n\n\n";
		changeTextColor();	// light_gray text color (console default)
	}


	/*Postcondition: The different from console default color is applied to one element of output.
	In displayed sequence the current item has color defined as parameter for this function*/
	void highlight(const string& msg, int color = 07)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);				// specified text color 
		cout << msg;
		SetConsoleTextAttribute(hConsole, 07);					// light_gray text color (console default)
	}


	/*Postcondition: All the output after this function call has color defined as its parameter.*/
	void changeTextColor(int color = 07)
	{
		HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(hConsole, color);				// specified text color
	}

}; // end Shell
