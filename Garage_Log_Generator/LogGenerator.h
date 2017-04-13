#pragma once
#include <ctime>
#include <string>
#include <cstdlib>
#include <fstream>
#include <iostream>
using namespace std;

class LogGenerator
{
public:
	const static int POOL_SIZE = 100;
	const static int PLATE_LETTERS = 3;
	const static int PLATE_NUMBERS = 4;
	LogGenerator();
	~LogGenerator();
	string plate_generator();
	string plateRecord(string status);
	string setPlate();
	int isRecord();
	void log();
	
private:
	string plates[10000];
	string carPool[POOL_SIZE];
	string plate;
};

