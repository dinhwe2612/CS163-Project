#ifndef TRIE_H
#define TRIE_H

#include <iostream>
using namespace std;

const int ASCII_SIZE = 128;

struct TrieNode {
	TrieNode *child[ASCII_SIZE];
	int countWord;// count word have the same prefix
	string definition;// definition at the end of keyword

	TrieNode() {
		fill(child, child + ASCII_SIZE, nullptr);
		countWord = 0;
		definition = '\0';
	}
};

struct Keyword { // Trie
	TrieNode* root = nullptr;

	void insert(string key, string def);
	string search(string key);// return id of word if found, else return -1
	void remove(string key);
};

#endif