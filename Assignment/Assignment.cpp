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
		//cout << keyMaker(key) << '\t' << item << endl;
		stations.insert(key, item);
	}
	inf.close();
	return stations;
}
BST loadLine() {
	BST stations = BST();
	ifstream inf;
	inf.open("csv / Routes.csv");
	string key, item, line, temp;
	getline(inf, line);
	stringstream s(line);
	bool flag = true;
	while (getline(s, temp, ',')) {

	}
	inf.close();
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
		cout << stations.search(st)->item << endl;
	}

	//loadFares();
}