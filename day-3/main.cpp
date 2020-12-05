#define PART_ONE

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
