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

	vector<string> lines;

	bool hasInput = true;
	while (hasInput)
	{
		string line;
		f >> line;
		lines.push_back(line);

		if (f.eof())
		{
			hasInput = false;
		}
	}

	const int linesDown = 1;
	const int linesRight = 3;

	const char tree = '#';
	const char empty = '.';

	int numberOfTrees = 0;

	int column = 0;
	for (int row = 0; row < lines.size(); row++)
	{
		string line = lines[row];
		char cell = line[column];
		if (cell == tree)
		{
			numberOfTrees++;
		}

		column += linesRight;
		if (column >= line.size())
		{
			column %= line.size();
		}
	}


	f.close();

	cout << numberOfTrees << endl;
}

#endif // PART_ONE

#ifdef PART_TWO

int main()
{
	fstream f("input.txt", fstream::in);

	vector<string> lines;

	bool hasInput = true;
	while (hasInput)
	{
		string line;
		f >> line;
		lines.push_back(line);

		if (f.eof())
		{
			hasInput = false;
		}
	}

	f.close();

	const vector<int> linesDown  { 1, 1, 1, 1, 2 };
	const vector<int> linesRight { 1, 3, 5, 7, 1 };

	const char tree = '#';
	const char empty = '.';

	vector<int> numberOfTrees;

	for (int attempt = 0; attempt < linesDown.size(); attempt++)
	{
		int column = 0;
		int numberOfTreesInAttempt = 0;
		for (int row = 0; row < lines.size(); row += linesDown[attempt])
		{
			string line = lines[row];
			char cell = line[column];
			if (cell == tree)
			{
				numberOfTreesInAttempt++;
			}

			column += linesRight[attempt];
			if (column >= line.size())
			{
				column %= line.size();
			}
		}

		numberOfTrees.push_back(numberOfTreesInAttempt);
		cout << numberOfTreesInAttempt << endl;
	}

	int multiplied = 1;
	for (int number : numberOfTrees)
	{
		multiplied *= number;
	}

	cout << multiplied << endl;
}

#endif // PART_TWO