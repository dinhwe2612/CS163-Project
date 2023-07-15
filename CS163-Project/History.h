#ifndef HISTORY_H
#define HISTORY_H

#include <iostream>
#include "Queue.h"
using namespace std;

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