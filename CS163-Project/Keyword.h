#ifndef TRIE_H
#define TRIE_H

#include <iostream>
#include <vector>
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

	void insert(string key, string def);
	vector<string> search(string key);// return id of word if found, else return -1
	void remove(string key);

private:
	void removeHelper(TrieNode* root, string key, int depth);
};

#endif