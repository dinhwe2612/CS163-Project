#ifndef FAVOURITE_H
#define FAVOURITE_H

#include <vector>
#include <string>
#include <iostream>
using namespace std;

const int MAX_FAVOURITE = 1000;

struct Favourite {
	string datasetName;
	vector<string> favourite;
	int limit = MAX_FAVOURITE;

	void init(string dataset);
	void insert(string key);
	void remove(string key);
	bool isFavourite(string key);
	void removeAll();
};

void deleteAKey(vector<string> favourite, string key);
void outputFavourite(vector<string> favourite, string fileName);

#endif