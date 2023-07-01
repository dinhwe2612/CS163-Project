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
	++limit;
	// add to LL
	FavouriteQueue.enqueue(key);

	// add key to file
	ifstream fin;
	ofstream fout;
	fin.open("../Data/" + datasetName + "/" + datasetName + ".txt");
	fout.open("../Data/" + datasetName + "/" + datasetName + ".txt", ios::app);
	fin.get();
	if (!fin.eof()) fout << endl;
	fout << key;
	fin.close();
	fout.close();

	// if it exceed limit
	if (limit == MAX_FAVOURITE) 
		FavouriteQueue.dequeue();
}

void outputLLToFile(Node* pHead, string fileName) {
	ofstream fout;
	fout.open(fileName);
	while (pHead) {
		fout << pHead->word << endl;
		pHead = pHead->next;
	}
	fout.close();
}

void Favourite::remove(string key) {
	removeANode(FavouriteQueue.head, key);
	string fileName = "../Data/" + datasetName + "/" + datasetName + ".txt";
	outputLLToFile(FavouriteQueue.head, fileName);
}

void Favourite::removeAll() {
	while (!FavouriteQueue.isEmpty()) {
		FavouriteQueue.dequeue();
	}
	ofstream fout;
	fout.open("../Data/" + datasetName + "/" + datasetName + ".txt");
	fout.close();
}