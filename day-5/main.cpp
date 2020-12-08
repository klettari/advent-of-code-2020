#define _PART_TWO_

#ifdef _PART_ONE_

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const int rowPartLength = 7;
	const int colPartLength = 3;

	const char front = 'F';
	const char back = 'B';

	const char left = 'L';
	const char right = 'R';

	int highestSeat = 0;

	fstream f("input.txt", fstream::in);
	bool hasInput = true;
	while (hasInput)
	{
		string seat;
		f >> seat;

		string rowPart = seat.substr(0, rowPartLength);
		int rowLow = 0;
		int rowHigh = 127;

		for (char c : rowPart)
		{
			int difference = (rowHigh - rowLow) / 2 + 1;
			if (c == front)
			{
				rowHigh = rowHigh - difference;
			}
			else if (c == back)
			{
				rowLow = rowLow + difference;
			}
		}

		string colPart = seat.substr(rowPartLength, colPartLength);
		int colLow = 0;
		int colHigh = 7;

		for (char c : colPart)
		{
			int difference = (colHigh - colLow) / 2 + 1;
			if (c == left)
			{
				colHigh = colHigh - difference;
			}
			else if (c == right)
			{
				colLow = colLow + difference;
			}
		}

		int seatId = rowHigh * 8 + colHigh;
		if (seatId > highestSeat)
		{
			highestSeat = seatId;
		}

		if (f.eof())
		{
			hasInput = false;
		}
	}

	cout << highestSeat << endl;

	return 0;
}

#endif // _PART_ONE_

#ifdef _PART_TWO_

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	const int rowPartLength = 7;
	const int colPartLength = 3;

	const char front = 'F';
	const char back = 'B';

	const char left = 'L';
	const char right = 'R';

	bool seats[127 * 8] = { false };

	fstream f("input.txt", fstream::in);
	bool hasInput = true;
	while (hasInput)
	{
		string seat;
		f >> seat;

		string rowPart = seat.substr(0, rowPartLength);
		int rowLow = 0;
		int rowHigh = 127;

		for (char c : rowPart)
		{
			int difference = (rowHigh - rowLow) / 2 + 1;
			if (c == front)
			{
				rowHigh = rowHigh - difference;
			}
			else if (c == back)
			{
				rowLow = rowLow + difference;
			}
		}

		string colPart = seat.substr(rowPartLength, colPartLength);
		int colLow = 0;
		int colHigh = 7;

		for (char c : colPart)
		{
			int difference = (colHigh - colLow) / 2 + 1;
			if (c == left)
			{
				colHigh = colHigh - difference;
			}
			else if (c == right)
			{
				colLow = colLow + difference;
			}
		}

		int seatId = rowHigh * 8 + colHigh;
		seats[seatId] = true;

		if (f.eof())
		{
			hasInput = false;
		}
	}
	
	int yourSeat = 0;
	for (int i = 1; i < sizeof(seats) - 2; i++)
	{
		bool seatEmpty = !seats[i];
		bool previousOccupied = seats[i - 1];
		bool nextOccupied = seats[i + 1];

		if (seatEmpty && previousOccupied && nextOccupied)
		{
			yourSeat = i;
			break;
		}
	}

	cout << yourSeat << endl;

	return 0;
}

#endif // _PART_TWO_