#define PART_ONE

#include <fstream>
#include <iostream>
#include <string>

using namespace std;

#ifdef PART_ONE

int main()
{
	fstream f("input.txt", fstream::in);

	int validPasswords = 0;

	bool getInput = true;
	while (getInput)
	{
		unsigned int minTimes;
		f >> minTimes;

		char dash;
		f >> dash;

		unsigned int maxTimes;
		f >> maxTimes;

		char letter;
		f >> letter;

		char colon;
		f >> colon;

		string password;
		f >> password;

		if (f.eof())
		{
			getInput = false;
		}

		int letterCount = 0;
		for (char symbol : password)
		{
			if (symbol == letter)
			{
				letterCount++;
			}
		}

		if (minTimes <= letterCount && letterCount <= maxTimes)
		{
			validPasswords++;
		}
	}

	f.close();

	cout << validPasswords << endl;

	return 0;
}

#endif // PART_ONE
