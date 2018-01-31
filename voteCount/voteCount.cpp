#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>

using namespace std;

int main()
{
	map <string, int> ballot;
	ballot["Michael Collins"] = 0;
	ballot["Wolfe Tone"] = 0;
	ballot["Brian Boru"] = 0;
	ballot["Charles Parnell"] = 0;

	int eliminated[3] = {0,0,0};

	int count = 0;
	string line;
	ifstream myfile("votes.txt");
	
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{

			if ((int)line.at(0) - 48 == 1)
			{
				ballot["Michael Collins"] = ballot["Michael Collins"] + 1;
			}
			if ((int)line.at(1) - 48 == 1)
			{
				ballot["Wolfe Tone"] = ballot["Wolfe Tone"] + 1;
			}
			if ((int)line.at(2) - 48 == 1)
			{
				ballot["Brian Boru"] = ballot["Brian Boru"] + 1;
			}
			if ((int)line.at(3) - 48 == 1)
			{
				ballot["Charles Parnell"] = ballot["Charles Parnell"] + 1;
			}
			
			count++;
		}
		cout << "---- " << count << " ballots counted ----\n";
		cout << "Micael Collins - " << ballot["Michael Collins"] << "\n";
		cout << "Wolfe Tone - " << ballot["Wolfe Tone"] << "\n";
		cout << "Brian Boru - " << ballot["Brian Boru"] << "\n";
		cout << "Charles Parnell - " << ballot["Charles Parnell"] << "\n";
		myfile.close();
		cin.ignore();
	}

	
	else 
		cout << "Unable to open file";

}