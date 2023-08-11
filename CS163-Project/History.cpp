#include <iostream>
#include <fstream>
#include <string>
#include "History.h"
using namespace std;

void History::init(string dataset) {
	history.clear();
	datasetName = dataset;
	// read the data from file
	ifstream fin;
	// check empty file
	fin.open("../Data/" + datasetName + "/" + datasetName + "_history.txt");
	fin.get();
	if (fin.eof()) {
		fin.close();
		return;
	}
	fin.close();
	// read data
	fin.open("../Data/" + datasetName + "/" + datasetName + "_history.txt");
	while (!fin.eof()) {
		char* word = new char[1001];
		fin.get(word, 1001, '	');
		fin.ignore();
		his hisWord;
		hisWord.word = string(word);
		fin >> hisWord.isKey;
		fin.ignore();
		history.push_back(hisWord);
		delete[] word;
	}
	fin.close();
}

void History::insert(string word, bool isKey) {
	// add to LL
	his hisWord;
	hisWord.init(word, isKey);
	history.push_back(hisWord);

	// add key to file
	ifstream fin;
	ofstream fout;
	fin.open("../Data/" + datasetName + "/" + datasetName + "_history.txt");
	fout.open("../Data/" + datasetName + "/" + datasetName + "_history.txt", ios::app);
	fin.get();
	if (!fin.eof()) fout << endl;
	fout << word << "	" << isKey;
	fin.close();
	fout.close();

	// if it exceed limit
	if (history.size() == MAX_HISTORY)
		history.pop_back();
}

void deleteAKeyinHistory(vector<his>& history, string word) {
	for (auto it = history.begin(); it != history.end(); ++it) {
		if (it->word == word) {
			history.erase(it);
			return;
		}
	}
}

void outputHistory(vector<his> history, string fileName) {
	ofstream fout;
	fout.open(fileName);
	for (auto it = history.begin(); it != history.end(); ++it) {
		fout << it->word << "	" << it->isKey;
		if (it + 1 != history.end()) fout << endl;
	}
}

void History::remove(string word) {
	deleteAKeyinHistory(history, word);
	string fileName = "../Data/" + datasetName + "/" + datasetName + "_history.txt";
	outputHistory(history, fileName);
}

void History::removeAll() {
	history.clear();
	ofstream fout;
	/*for (int i = 1; i <= 5; i++) {
		string dataset;
		switch (i) {
		case 1:
			dataset = "engEng";
		case 2:
			dataset = "vieEng";
		case 3:
			dataset = "engVie";
		case 4:
			dataset = "slang";
		case 5:
			dataset = "emotional";
		}
		fout.open("../Data/" + dataset + "/" + dataset + "_history.txt");
		fout.close();
	}*/
}