#define PART_TWO

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

#ifdef PART_ONE
int main()
{
	fstream f("input.txt", fstream::in);
	const int shouldSumTo = 2020;

	vector<int> numbers;
	int first = 0;
	int second = 0;

	bool getInput = true;

	while (getInput)
	{
		f >> first;

		if (f.eof())
		{
			getInput = false;
		}

		if (numbers.size() > 0)
		{
			for (int number : numbers)
			{
				if (first + number == shouldSumTo)
				{
					second = number;
					getInput = false;
				}
			}
		}
		numbers.push_back(first);
	}

	f.close();

	int multiplied = first * second;
	cout << multiplied << endl;

	return 0;
}
#endif // PART_ONE


#ifdef PART_TWO
int main()
{
	fstream f("input.txt", fstream::in);
	const int shouldSumTo = 2020;

	vector<int> numbers;
	int first = 0;
	int second = 0;
	int third = 0;

	bool getInput = true;

	while (getInput)
	{
		f >> first;

		if (f.eof())
		{
			getInput = false;
		}

		if (numbers.size() > 1)
		{
			for (int numberA : numbers)
			{
				for (int numberB : numbers)
				{
					if (first + numberA + numberB == shouldSumTo)
					{
						second = numberA;
						third = numberB;
						getInput = false;
					}
				}
			}
		}
		numbers.push_back(first);
	}

	f.close();

	cout << first << ", " << second << ", " << third << endl;

	int multiplied = first * second * third;
	cout << multiplied << endl;

	return 0;
}
#endif // PART_TWO