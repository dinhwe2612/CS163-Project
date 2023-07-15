#ifndef FAVOURITE_H
#define FAVOURITE_H

#include "Queue.h"
using namespace std;

const int MAX_FAVOURITE = 1000;

struct Favourite {
	string datasetName;
	MyQueue FavouriteQueue;
	int limit = MAX_FAVOURITE;

	void init(string dataset);
	void insert(string key);
	void remove(string key);
	void removeAll();
};

void outputLLToFile(Node* pHead, string fileName);

#endif