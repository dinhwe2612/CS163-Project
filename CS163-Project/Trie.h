#include <string>
#include <iostream>
#include <vector>
using namespace std;

#ifndef TRIE_H
#define TRIE_H

const int ASCII_SIZE = 128;

struct TrieNode {
	TrieNode *child[ASCII_SIZE];
	TrieNode() {
		fill(child, child + ASCII_SIZE, nullptr);
	}
	int countWord;// count word have the same prefix
	int id = -1;// id of word if node is end of word
	void add(string& key);
	int find(string& key);// return id of word if found, else return -1
	void remove(string& key);
};

struct Definition {
	int num;// number of definition
	vector<pair<string, string>> word;// {keyword, definition}
	void add(string& key);
	string search(string def);
	void remove(string& key);
};

#endif