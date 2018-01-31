#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>

using namespace std;

string getLowestVote(map <string, int> myMap)
{
	string lowest = "";
	int votes = 0;
	map<string, int>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second <= votes)
		{
			votes = it->second;
			lowest = it->first;
		}
	}

	return lowest;
}

int main()
{
	map <string, int> ballot;
	ballot["Michael Collins"] = 0;
	ballot["Wolfe Tone"] = 0;
	ballot["Brian Boru"] = 0;
	ballot["Charles Parnell"] = 0;

	int eliminated[3] = {0,0,0};
	vector<string> ballots;

	int count = 0;
	string line;
	ifstream myfile("votes.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			ballots.push_back(line);
			cout << line << "\n";
		}
		myfile.close();
		cin.ignore();
	}

	else
	{
		cout << "Unable to open file";
	}
	int pref = 1;
	while (pref <= 4)
	{
		
		for (int j = 0; j < ballots.size(); j++)
		{
			cout << "vote = " << ballots.at(j) << "\n";
			string vote = ballots.at(j);
			cout << "looking for: " << pref <<"\n";
			if ((int)vote.at(0) - 48 == pref)
			{
				ballot["Michael Collins"] = ballot["Michael Collins"] + 1;
			}
			else if ((int)vote.at(1) - 48 == pref)
			{
				ballot["Wolfe Tone"] = ballot["Wolfe Tone"] + 1;
			}
			else if ((int)vote.at(2) - 48 == pref)
			{
				ballot["Brian Boru"] = ballot["Brian Boru"] + 1;
			}
			else if ((int)vote.at(3) - 48 == pref)
			{
				ballot["Charles Parnell"] = ballot["Charles Parnell"] + 1;
			}

			count++;
		}
		cout << "----------- "<< pref << " -------------\n";
		cout << "Micael Collins - " << ballot["Michael Collins"] << "\n";
		cout << "Wolfe Tone - " << ballot["Wolfe Tone"] << "\n";
		cout << "Brian Boru - " << ballot["Brian Boru"] << "\n";
		cout << "Charles PArnell - " << ballot["Charles Parnell"] << "\n";
		cout << "Eliminated = " << getLowestVote(ballot) << "\n";
		pref++;
		cin.ignore();
	}
	cout << "---------------------------------\n";
	cout << "Micael Collins - " << ballot["Michael Collins"] <<"\n";
	cout << "Wolfe Tone - " << ballot["Wolfe Tone"] << "\n";
	cout << "Brian Boru - " << ballot["Brian Boru"] << "\n";
	cout << "Charles PArnell - "<< ballot["Charles Parnell"] << "\n";
	
	cin.ignore();
}