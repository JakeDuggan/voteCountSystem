#include "stdafx.h"
#include <fstream>
#include <string>
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

//Functions

string getLowestVote(map <string, int> myMap)
{
	string lowest = "No lowest found";
	int votes = myMap.begin()->second;
	map<string, int>::iterator it;
	for (it = myMap.begin(); it != myMap.end(); it++)
	{
		if (it->second <= votes)
		{
			votes = it->second;
			lowest = it->first;
		}
	}
	votes = myMap.begin()->second;
	return lowest;
}

bool containsCandidate(vector<string> v,string name)
{
	if (std::find(v.begin(), v.end(), name) != v.end())
	{
		return true;
	}
	return false;
}

//Main Class

int main()
{
	string candidates[] = {"Michael Collins","Wolfe Tone","Brian Boru","Charles Parnell" };
	map <string, int> ballot;
	ballot["Michael Collins"] = 0;
	ballot["Wolfe Tone"] = 0;
	ballot["Brian Boru"] = 0;
	ballot["Charles Parnell"] = 0;

	//collection of all votes
	vector<string> ballotCollection;
	

	//read in the file line by line
	string line;
	ifstream myfile("votes.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			ballotCollection.push_back(line);
		}
		myfile.close();
		cin.ignore();
	}

	else
	{
		cout << "Unable to open file";
	}
	//vector to hold the names of eliminated candidates 
	vector<string> eliminated;

	for (int j = 0; j < ballotCollection.size(); j++)
	{
		string vote = ballotCollection.at(j);

		if ((int)vote.at(0) - 48 == 1)
		{
			ballot["Michael Collins"] = ballot["Michael Collins"] + 1;
		}
		else if ((int)vote.at(1) - 48 == 1)
		{
			ballot["Wolfe Tone"] = ballot["Wolfe Tone"] + 1;
		}
		else if ((int)vote.at(2) - 48 == 1)
		{
			ballot["Brian Boru"] = ballot["Brian Boru"] + 1;
		}
		else if ((int)vote.at(3) - 48 == 1)
		{
			ballot["Charles Parnell"] = ballot["Charles Parnell"] + 1;
		}

	}

	cout << "Eliminated = " << getLowestVote(ballot) << "\n";


	int pref = 2;
	while (pref <= ballot.size()
		)
	{
		
		for (int j = 0; j < ballotCollection.size(); j++)
		{
			string vote = ballotCollection.at(j);

			if (containsCandidate(eliminated,candidates[0]) == true)
			{
				ballot["Michael Collins"] = ballot["Michael Collins"] + 1;
			}
			else if (containsCandidate(eliminated, candidates[1]) == true)
			{
				ballot["Wolfe Tone"] = ballot["Wolfe Tone"] + 1;
			}
			else if (containsCandidate(eliminated, candidates[2]) == true)
			{
				ballot["Brian Boru"] = ballot["Brian Boru"] + 1;
			}
			else if (containsCandidate(eliminated, candidates[3]) == true)
			{
				ballot["Charles Parnell"] = ballot["Charles Parnell"] + 1;
			}

		}
		cout << "----------- "<< pref << " -------------\n";
		cout << "Micael Collins - " << ballot["Michael Collins"] << "\n";
		cout << "Wolfe Tone - " << ballot["Wolfe Tone"] << "\n";
		cout << "Brian Boru - " << ballot["Brian Boru"] << "\n";
		cout << "Charles PArnell - " << ballot["Charles Parnell"] << "\n";
		cout << "Eliminated = " << getLowestVote(ballot) << "\n";
		eliminated.push_back(getLowestVote(ballot));
		cout << containsCandidate(eliminated, "Brian Boru");
		

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