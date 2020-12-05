#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

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