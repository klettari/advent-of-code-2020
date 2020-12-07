#define PART_TWO

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


#ifdef PART_TWO

struct person {
	int byr;
	int iyr;
	int eyr;
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

	const int minBirthYear = 1920;
	const int maxBirthYear = 2002;

	const int minIssueYear = 2010;
	const int maxIssueYear = 2020;

	const int minExpYear = 2020;
	const int maxExpYear = 2030;

	const string cm = "cm";
	const string in = "in";

	const int minHeightCm = 150;
	const int maxHeightCm = 193;

	const int minHeightIn = 59;
	const int maxHeightIn = 76;

	const char hairColorFirstDigit = '#';
	const int hairColorLength = 6;

	const int passportIdLength = 9;

	string eyeColors[] = { "amb", "blu", "brn", "gry", "grn", "hzl", "oth" };

	int correctPassports = 0;
	for (person p : people)
	{
		// birth year
		if (! (minBirthYear <= p.byr && p.byr <= maxBirthYear) )
		{
			continue;
		}

		// issue year
		if (! (minIssueYear <= p.iyr && p.iyr <= maxIssueYear) )
		{
			continue;
		}
		
		// expiry year
		if (! (minExpYear <= p.eyr && p.eyr <= maxExpYear) )
		{
			continue;
		}

		// height
		if (p.hgt.size() < 2)
		{
			continue;
		}

		int secondToLastPos = p.hgt.size() - 2;
		string measurment = p.hgt.substr(secondToLastPos, 2);
		string numberPart = p.hgt.substr(0, p.hgt.size() - 2);

		int value = 0;
		stringstream ss(numberPart);
		ss >> value;
		
		if (measurment == in)
		{
			if (! (minHeightIn <= value && value <= maxHeightIn) )
			{
				continue;
			}
		}
		else if (measurment == cm)
		{
			if (! (minHeightCm <= value && value <= maxHeightCm) )
			{
				continue;
			}
		}
		else
		{
			continue;
		}
		
		// hair color		
		if (p.hcl.size() < hairColorLength + 1)
		{
			continue;
		}
		if (p.hcl[0] != hairColorFirstDigit)
		{
			continue;
		}
		
		bool validHair = true;
		for (char digit : p.hcl.substr(1))
		{
			if (!isxdigit(digit))
			{
				validHair = false;
			}
		}
		if (!validHair)
		{
			continue;
		}

		// eye color
		bool validEyeColor = false;
		for (string option : eyeColors)
		{
			if (p.ecl == option)
			{
				validEyeColor = true;
			}
		}
		if (!validEyeColor)
		{
			continue;
		}
		
		// passport id
		if (p.pid.size() != passportIdLength)
		{
			continue;
		}

		bool validPassportId = true;
		for (char digit : p.pid)
		{
			if (!isdigit(digit))
			{
				validPassportId = false;
			}
		}
		if (!validPassportId)
		{
			continue;
		}

		correctPassports++;
	}

	cout << correctPassports << endl;

	return 0;
}

#endif // PART_TWO