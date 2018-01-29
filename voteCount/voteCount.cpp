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
	string line;
	ifstream myfile("votes.txt");
	if (myfile.is_open())
	{
		while (getline(myfile, line))
		{
			cout << line << '\n';
			ballot["Michael Collins"] = ballot["Michael Collins"] + line.at(0);
			ballot["Wolfe Tone"] = ballot["Wolfe Tone"] + line.at(1);
			ballot["Brian Boru"] = ballot["Brian Boru"] + line.at(3);
			ballot["Charles Parnell"] = ballot["Charles Parnell"] + line.at(4);
			
		}
		cout << "Micael Collins - " << ballot["Michael Collins"];
		cout << "Wolfe Tone - " << ballot["Wolfe Tone"];
		cout << "Brian Boru - " << ballot["Brian Boru"];
		cout << "Charles Parnell - " << ballot["Charles Parnell"];
		myfile.close();
		cin.ignore();
	}

	
	else 
		cout << "Unable to open file";

}

