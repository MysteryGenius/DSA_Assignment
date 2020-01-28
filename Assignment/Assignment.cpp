#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>  
#include "BST.h"

using namespace std;

void loadStations() {
	// BST store
	ifstream inf;
	inf.open("csv/Stations.csv");
	string key, item, line, temp;
	while (inf)
	{
		getline(inf, line);
		stringstream s(line);
		bool flag = true;
		while (getline(s, temp, ','))
		{
			if (flag) { 
				key = temp;
				flag = false;
			}
			else item = temp;
		}
		cout << key << '\t' << item << endl;
	}
}

void loadFares() {
	// BST store
	ifstream inf;
	inf.open("csv/Fares.csv");
	string key, item, line, temp;
	while (inf)
	{
		getline(inf, line);
		stringstream s(line);
		bool flag = true;
		while (getline(s, temp, ','))
		{
			if (flag) {
				key = temp;
				flag = false;
			}
			else item = temp;
		}
		cout << key << '\t' << item << endl;
	}
}

int main()
{
	//loadStations();
	loadFares();
}
