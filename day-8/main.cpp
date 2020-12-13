#define _PART_TWO_

#ifdef _PART_ONE_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <sstream>

using namespace std;

int main()
{
	vector<string> instructions;
	fstream f("input.txt", fstream::in);
	while (true)
	{
		string line;
		getline(f, line);
		instructions.push_back(line);
		if (f.eof())
		{
			break;
		}
	}

	const string jump = "jmp";
	const string acc = "acc";
	const string noop = "nop";

	int accomulator = 0;
	vector<bool> hasVisited(instructions.size(), false);

	int index = 0;
	while (true)
	{
		stringstream ss(instructions[index]);
		
		string instruction;
		ss >> instruction;

		int argument;
		ss >> argument;

		if (hasVisited[index])
		{
			break;
		}
		hasVisited[index] = true;
		
		if (instruction == noop)
		{
			index++;
		}
		else if (instruction == acc)
		{
			accomulator += argument;
			index++;
		}
		else if (instruction == jump)
		{
			index += argument;
		}
	}

	cout << accomulator << endl;

	return 0;
}

#endif // _PART_ONE_

#ifdef _PART_TWO_

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <array>
#include <sstream>

using namespace std;

int main()
{
	vector<string> instructions;
	fstream f("input.txt", fstream::in);
	while (true)
	{
		string line;
		getline(f, line);
		instructions.push_back(line);
		if (f.eof())
		{
			break;
		}
	}

	const string jump = "jmp";
	const string acc = "acc";
	const string noop = "nop";

	int accomulator = 0;
	bool foundAnswer = false;
	int indexOfChangedLine = 0;
	while (!foundAnswer && indexOfChangedLine < instructions.size())
	{
		string instructionToChange = instructions[indexOfChangedLine].substr(0, 3);
		if (instructionToChange == acc)
		{
			indexOfChangedLine++;
			continue;
		}

		accomulator = 0;
		vector<bool> hasVisited(instructions.size(), false);

		int index = 0;
		while (true)
		{
			if (index == instructions.size())
			{
				foundAnswer = true;
				break;
			}

			stringstream ss(instructions[index]);

			string instruction;
			ss >> instruction;

			int argument;
			ss >> argument;

			if (index == indexOfChangedLine)
			{
				if (instruction == noop)
				{
					instruction = jump;
				}
				else if (instruction == jump)
				{
					instruction = noop;
				}
			}

			if (hasVisited[index])
			{
				indexOfChangedLine++;
				break;
			}
			hasVisited[index] = true;

			if (instruction == noop)
			{
				index++;
			}
			else if (instruction == acc)
			{
				accomulator += argument;
				index++;
			}
			else if (instruction == jump)
			{
				index += argument;
			}
		}
	}

	cout << accomulator << endl;

	return 0;
}

#endif // _PART_TWO_