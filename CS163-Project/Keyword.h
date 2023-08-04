#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
#include <queue>
#include <fstream>
using namespace std;

const int ASCII_SIZE = 128;

struct TrieNode {
	TrieNode *child[ASCII_SIZE];
	int countChild = 0;
	//vector<string> definition;// definition at the end of keyword
	int id = -1;// id of keyword
	TrieNode() {
		fill(child, child + ASCII_SIZE, nullptr);
	}
};

struct Keyword { // Trie
	TrieNode* root = new TrieNode();
	int numOfWords = 0;

	int limitSuggestions = 5;
	vector<int> predict(string keyword);// using bfs, return vector of suggestions

	void build(ifstream &fin);// build Trie from edges
	int insert(string key, string &def);// return id of words if insert successfully else return -1
	bool edit(string key, string def, string newdef);// return true if edit successfully
	int search(string key);
	void remove(string key);
	void save(ofstream &fout);

private:
	void removeHelper(TrieNode* root, string key, int depth);
};

#endif