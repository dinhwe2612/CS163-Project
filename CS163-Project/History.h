#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include <vector>
using namespace std;

const int MAX_HISTORY = 100;
struct History {
	vector<string> history;
	int limit = MAX_HISTORY;

	void init();
	void insert(string key);
	void remove(string key);
	void removeAll();
};

void deleteAKeyinHistory(vector<string> history, string key);
void outputHistory(vector<string> history, string fileName);

#endif