#include <iostream>
#include <fstream>
#include "Favourite.h"
#include "Trie.h"
using namespace std;

Definition def;

void Favourite::init(string dataset) {
	datasetName = dataset;
	// read the data from file
	ifstream fin;
	// check empty file
	fin.open("../Data/" + datasetName + "/" + datasetName + ".txt");
	fin.get();
	if (fin.eof()) {
		fin.close();
		return;
	}
	fin.close();
	// read data
	fin.open("../Data/" + datasetName + "/" + datasetName + ".txt");
	while (!fin.eof()) {
		string tmp;
		getline(fin, tmp);
		FavouriteQueue.enqueue(tmp);
	}
	fin.close();
}

void Favourite::insert(string key) {
	// add to LL
	FavouriteQueue.enqueue(key);

	// add key to file
	++limit;
	//int x = def.search(key);	// search in definition saved in memory

	ifstream fin;
	ofstream fout;
	fin.open("../Data/" + datasetName + "/" + datasetName + ".txt");
	fout.open("../Data/" + datasetName + "/" + datasetName + ".txt", ios::app);
	fin.get();
	if (!fin.eof()) fout << endl;
	//fout << x;
	fin.close();
	fout.close();

	// if it exceed limit
	if (limit == MAX_FAVOURITE) 
		FavouriteQueue.dequeue();
}