#include "LogGenerator.h"

LogGenerator::LogGenerator()
{
	srand(time(NULL));
}


LogGenerator::~LogGenerator()
{
	
}


string LogGenerator::plate_generator()
{
	static const char alpha[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	static const char num[] = "0123456789";
	string strAlpha, strNum;

	for (int i = 0; i < PLATE_LETTERS; ++i)
		strAlpha += alpha[rand() % (sizeof(alpha)-1)];

	for (int i = 0; i < PLATE_NUMBERS; ++i)
		strNum += num[rand() % 10];

	return (strAlpha + '-' + strNum);
}

string LogGenerator::setPlate()
{
	plate = plate_generator();
	return plate;
}


string LogGenerator::plateRecord(string status)
{
	return (status + ' ' + plate);
}

int LogGenerator::isRecord()
{
	int counter = 0;
	for (int i = 0; i < sizeof(plates[i]); i++)
	{
		if (plate.compare(plates[i]) == 0)
		{
			counter++;
		}
	}
	return counter;
}


void LogGenerator::log()
{
	// generate car pool
	for (int i = 0; i < POOL_SIZE; i++)
	{
		carPool[i] = setPlate();
	}

	int i = 0;
	int tick = 0;
	int x = 0;
	int countA = 0;
	int countD = 0;

	ofstream myfile("MyGarage.txt");

	if (myfile.is_open())
	{
		
		cout << "\n\tEnter the number of lines: ";
			cin >> x;

		while (i < x)
		{
			// generator A
			if (tick % 2 == 0)				// even tick
			{
				tick = 1;
				plate = carPool[rand() % POOL_SIZE];
				if (isRecord() % 2 == 0)
				{
					plates[i++] = plate;
					myfile << "A " << plate << endl;
					countA++;
				}

			}
			else                       // odd tick
			{
				// generator D
				tick = 0;
				plate = carPool[rand() % POOL_SIZE];
				if (isRecord() % 2 != 0)
				{
					plates[i++] = plate;
					myfile << "D " << plate << endl;
					countD++;
				}
			}
		}

		myfile.close();
	}

	cout << "\n\n   A = " << countA << ", D = " << countD << ", Total = " << countA + countD << endl;
}