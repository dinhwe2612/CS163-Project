#include <iostream>
#include "Queue.h"
using namespace std;

#ifndef HISTORY_H
#define HISTORY_H

const int MAX_HISTORY = 100;
struct History {
	string datasetName;
	MyQueue HistoryQueue;
	int limit = MAX_HISTORY;

	void init(string dataset);
	void insert(string key);
	void remove(string key);
	void removeAll();
};

#endif