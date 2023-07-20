#include <iostream>
#include <fstream>
#include <string>
#include "History.h"
using namespace std;

void History::init() {
	// read the data from file
	ifstream fin;
	// check empty file
	fin.open("../Data/history.txt");
	fin.get();
	if (fin.eof()) {
		fin.close();
		return;
	}
	fin.close();
	// read data
	fin.open("../Data/history.txt");
	while (!fin.eof()) {
		string tmp;
		getline(fin, tmp);
		history.push_back(tmp);
	}
	fin.close();
}

void History::insert(string key) {
	++limit;
	// add to LL
	history.push_back(key);

	// add key to file
	ifstream fin;
	ofstream fout;
	fin.open("../Data/history.txt");
	fout.open("../Data/history.txt", ios::app);
	fin.get();
	if (!fin.eof()) fout << endl;
	fout << key;
	fin.close();
	fout.close();

	// if it exceed limit
	if (limit == MAX_HISTORY)
		history.pop_back();
}

void deleteAKeyinHistory(vector<string> history, string key) {
	for (auto it = history.begin(); it != history.end(); ++it) {
		if (*it == key) {
			history.erase(it);
			return;
		}
	}
}

void outputHistory(vector<string> history, string fileName) {
	ofstream fout;
	fout.open(fileName);
	for (auto it = history.begin(); it != history.end(); ++it) {
		fout << *it;
		if (it + 1 != history.end()) fout << endl;
	}
}

void History::remove(string key) {
	deleteAKeyinHistory(history, key);
	string fileName = "../Data/history.txt";
	outputHistory(history, fileName);
}

void History::removeAll() {
	history.clear();
	ofstream fout;
	fout.open("../Data/history.txt");
	fout.close();
}