#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <algorithm>
using namespace std;

const int MAX = 1011;
int hashFunc(string &def);

struct Definition {
	int num = 0;// number of definition

	vector<int> words[MAX];

	const int MOD = 1e9 + 7;
	vector<int> pw;
	vector<vector<vector<int>>> hashList;
	
	int getNumDef(string &def);
	int POW(int n);
	vector<int> getHashList(string &def);
	int getHash(vector<int> &hashDef, int l, int r);
	int getHash(string& def);
	vector<pair<int, int>> searchHash(string &def);
	void build(ifstream &fin);
	void save(ofstream &fout);
	bool add(string &def, int id);// add a new definition, return true if success
	vector<int> search(string &def);// search a definition, return the index of the definition else return -1
	bool remove(string &def, int id);// remove a definition, return true if success
	void deleteDefinition();
};

#endif