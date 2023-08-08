#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
using namespace std;

const int MAX_HISTORY = 100;

// key	1
// def	0
struct his {
	string word;
	bool isKey;
	void init(string s, bool key) {
		word = s;
		isKey = key;
	}
};

struct History {
	string datasetName;
	vector<his> history;

	void init(string dataset);
	void insert(string word, bool isKey);
	void remove(string word);
	void removeAll();
};

void deleteAKeyinHistory(vector<his>& history, string word);
void outputHistory(vector<his> history, string fileName);

#endif