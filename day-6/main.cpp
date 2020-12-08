#define _PART_ONE_

#ifdef _PART_ONE_

#include <iostream>
#include <fstream>
#include <string>
#include <map>

using namespace std;

int main()
{
	fstream f("input.txt", fstream::in);
	bool hasInput = true;

	map<char, int> group;
	int sumOfScores = 0;

	while (hasInput)
	{
		string person;
		getline(f, person);

		for (char c : person)
		{
			group[c]++;
		}

		if (f.eof())
		{
			hasInput = false;
		}

		if (person == "" || f.eof())
		{
			int scoreOfGroup = group.size();
			sumOfScores += scoreOfGroup;
			group = {};
		}
	}

	cout << sumOfScores << endl;

	return 0;
}

#endif // _PART_ONE_