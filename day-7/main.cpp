#define _PART_ONE_

#ifdef _PART_ONE_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <sstream>

using namespace std;

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

		int count;
		ss >> count;

		if (count == 0) // "no"
		{
			bagRules[bagColor] = {};
			continue;
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
			continue;
		}

		ss >> count;
		ss >> bagColorOne >> bagColorTwo;

		ssCombine.str("");
		ssCombine << bagColorOne << " " << bagColorTwo;
		bagColorInside = ssCombine.str();

		bagRules[bagColor][bagColorInside] = count;
	}

	for (pair<string, map<string, int>> outerBag : bagRules)
	{
		cout << outerBag.first << ":" << endl;
		for (pair <string, int> innerBag : outerBag.second)
		{
			cout << "- " << innerBag.second << " " << innerBag.first << endl;
		}
	}

	return 0;
}

#endif // _PART_ONE_