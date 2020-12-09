#define _PART_ONE_

#ifdef _PART_ONE_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

bool canContain(map<string, map<string, int>> bagRules, string toFind, string color)
{
	if (bagRules[color].empty())
	{
		return false;
	}
	
	bool found = bagRules[color].find(toFind) != bagRules[color].end();
	if (found)
	{
		return true;
	}

	for (pair<string, int> innerBag : bagRules[color])
	{
		string innerColor = innerBag.first;
		bool contains = canContain(bagRules, toFind, innerColor);
		if (contains)
		{
			return true;
		}
	}
	return false;
}

int main()
{
	fstream f("input.txt", fstream::in);
	bool hasInput = true;
	map<string, map<string, int>> bagRules;

	while (hasInput)
	{
		string rule;
		getline(f, rule);

		if (f.eof())
		{
			hasInput = false;
		}

		string bagColorOne;
		string bagColorTwo;
		stringstream ss(rule);
		ss >> bagColorOne >> bagColorTwo;

		stringstream ssCombine;
		ssCombine << bagColorOne << " " << bagColorTwo;
		string bagColor = ssCombine.str();

		string ignore;
		ss >> ignore >> ignore; // "bags", "contain"

		while (true)
		{
			int count;
			ss >> count;

			if (count == 0) // "no"
			{
				bagRules[bagColor] = {};
				break;
			}

			ss >> bagColorOne >> bagColorTwo; 

			ssCombine.str("");
			ssCombine << bagColorOne << " " << bagColorTwo;
			string bagColorInside = ssCombine.str();

			bagRules[bagColor][bagColorInside] = count;

			ss >> ignore; // "bags," or "bags."

			char delimiter = ignore[ignore.size() - 1];
			if (delimiter == '.')
			{
				break;
			}
		}
	}

	const string bagToFind = "shiny gold";
	int canContainCount = 0;
	for (pair<string, map<string, int>> rule : bagRules)
	{
		string color = rule.first;
		if (color == bagToFind)
		{
			continue;
		}
		bool colorCanContain = canContain(bagRules, bagToFind, color);

		if (colorCanContain)
		{
			canContainCount++;
		}
	}

	cout << canContainCount << endl;

	return 0;
}

#endif // _PART_ONE_