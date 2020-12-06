#define PART_ONE

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#ifdef PART_ONE

struct person {
	string byr;
	string iyr;
	string eyr;
	string hgt;
	string hcl;
	string ecl;
	string pid;
	string cid;

	string toString()
	{
		stringstream ss;
		ss << "Birth Year: " << byr << endl;
		ss << "Issue Year: " << iyr << endl;
		ss << "Expiry Year: " << eyr << endl;
		ss << "Height: " << hgt << endl;
		ss << "Eye Color: " << ecl << endl;
		ss << "Hair Color: " << hcl << endl;
		ss << "Passport ID: " << pid << endl;
		ss << "Country ID: " << cid << endl;
		return ss.str();
	}
};

int main()
{
	fstream f("input.txt", fstream::in);

	bool hasInput = true;
	person p = {};
	vector<person> people;
	while (hasInput)
	{
		string line;
		getline(f, line);

		if (line == "")
		{
			people.push_back(p);
			p = {};
			continue;
		}

		stringstream ss(line);
		while (!ss.eof())
		{
			string field;
			getline(ss, field, ':');

			if (field[0] == ' ')
			{
				field = field.substr(1);
			}

			if (field == "byr")
			{
				ss >> p.byr;
			}
			else if (field == "iyr")
			{
				ss >> p.iyr;
			}
			else if (field == "eyr")
			{
				ss >> p.eyr;
			}
			else if (field == "hgt")
			{
				ss >> p.hgt;
			}
			else if (field == "hcl")
			{
				ss >> p.hcl;
			}
			else if (field == "ecl")
			{
				ss >> p.ecl;
			}
			else if (field == "pid")
			{
				ss >> p.pid;
			}
			else if (field == "cid")
			{
				ss >> p.cid;
			}
		}

		if (f.eof())
		{
			people.push_back(p);
			hasInput = false;
		}
	}

	int correctPassports = 0;
	for (person p : people)
	{
		cout << p.toString() << endl;
		if (p.byr == "")
		{
			continue;
		}
		if (p.iyr == "")
		{
			continue;
		}
		if (p.eyr == "")
		{
			continue;
		}
		if (p.hgt == "")
		{
			continue;
		}
		if (p.hcl == "")
		{
			continue;
		}
		if (p.ecl == "")
		{
			continue;
		}
		if (p.pid == "")
		{
			continue;
		}

		correctPassports++;
	}

	cout << correctPassports << endl;

	return 0;
}

#endif // PART_ONE
