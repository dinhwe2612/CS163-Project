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
	//int countWord;// count word have the same prefix
	vector<string> definition;// definition at the end of keyword

	TrieNode() {
		fill(child, child + ASCII_SIZE, nullptr);
	}
};

struct Keyword { // Trie
	TrieNode* root = nullptr;

	int limitSuggestions = 5;
	vector<string> predict(string keyword);// using bfs, return vector of suggestions

	bool insert(string key, string def);// return true if insert successfully
	bool edit(string key, string def, string newdef);// return true if edit successfully
	vector<string> search(string key);
	void remove(string key);
	void save(TrieNode* root, ofstream& fout);

private:
	void removeHelper(TrieNode* root, string key, int depth);
};

#endif