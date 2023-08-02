#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

//struct hash_node {
//	pair<string, string> data;// {keyword, definition}
//	hash_node* next;
//};
const int MAX = 1011;
int hashFunc(string def);
//void deleteHashlist(hash_node*& pHead);

struct Definition {
	int num = 0;// number of definition
	//hash_node** word = new hash_node*[30011];
	vector<int> words[MAX];
	
	//Definition() {
	//	fill(word, word + 30011, nullptr);
	//	num = 0;
	//}

	void build(ifstream &fin);
	void save(ofstream &fout);
	bool add(string &def, int id);// add a new definition, return true if success
	vector<int> search(string &def);// search a definition, return the index of the definition else return -1
	bool remove(string &def, int id);// remove a definition, return true if success
	void deleteDefinition();
};

#endif