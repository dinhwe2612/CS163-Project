#include <iostream>
#include <fstream>
#include <string>
#include "Favourite.h"
using namespace std;

void Favourite::init(string dataset) {
	datasetName = dataset;
	// read the data from file
	ifstream fin;
	// check empty file
	fin.open("../Data/" + datasetName + "/" + datasetName + "_favourite.txt");
	fin.get();
	if (fin.eof()) {
		fin.close();
		return;
	}
	fin.close();
	// read data
	fin.open("../Data/" + datasetName + "/" + datasetName + "_favourite.txt");
	while (!fin.eof()) {
		string tmp;
		getline(fin, tmp);
		favourite.push_back(tmp);
	}
	fin.close();
}

void Favourite::insert(string key) {
	++limit;
	// add to LL
	favourite.push_back(key);

	// add key to file
	ifstream fin;
	ofstream fout;
	fin.open("../Data/" + datasetName + "/" + datasetName + "_favourite.txt");
	fout.open("../Data/" + datasetName + "/" + datasetName + "_favourite.txt", ios::app);
	fin.get();
	if (!fin.eof()) fout << endl;
	fout << key;
	fin.close();
	fout.close();

	// if it exceed limit
	if (limit == MAX_FAVOURITE)
		favourite.pop_back();
}

void deleteAKey(vector<string> favourite, string key) {
	for (auto it = favourite.begin(); it != favourite.end(); ++it) {
		if (*it == key) {
			favourite.erase(it);
			return;
		}
	}
}

void outputFavourite(vector<string> favourite, string fileName) {
	ofstream fout;
	fout.open(fileName);
	for (auto it = favourite.begin(); it != favourite.end(); ++it) {
		fout << *it;
		if (it + 1 != favourite.end()) fout << endl;
	}
}

void Favourite::remove(string key) {
	deleteAKey(favourite, key);
	string fileName = "../Data/" + datasetName + "/" + datasetName + "_favourite.txt";
	outputFavourite(favourite, fileName);
}

bool Favourite::isFavourite(string &key) {
	for (int i = 0; i < favourite.size(); i++) {
		if (key == favourite[i])
			return true;
	}
	return false;
}

void Favourite::removeAll() {
	favourite.clear();
	ofstream fout;
	fout.open("../Data/" + datasetName + "/" + datasetName + "_favourite.txt");
	fout.close();
}