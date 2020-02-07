#include "pch.h"
#include <iostream>
#include <fstream>
#include <sstream>  
#include "BST.h"

using namespace std;

BST loadStations() {
	// BST store
	BST stations = BST();
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
		stations.insert(key, item);
	}
	return stations;
}

BST loadFares() {
	// BST store
	BST fares = BST();
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
		fares.insert(key, item);
	}
	return fares;
}

int main()
{
	while (true)
	{
		string st;
		BST stations = loadStations();
		BST fares = loadFares();
		cout << "Please enter the Station Code : ";
		getline(cin, st);
		if (stations.search(st) != NULL)
			cout << stations.search(st)->item << endl;
		else
			cout << "No Station found" << endl;
		
	}

	//loadFares();
}
