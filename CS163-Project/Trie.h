#pragma once
#include <string>
#include <iostream>
#include <vector>
using namespace std;

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
	void remove(string& key);
};

struct history {// singly linked list
	int limit = 10;
	string word;
	history *next;
	void insert(string& key);
	void remove(string& key);
	void removeAll();
};

struct Favourite {
	int limit = 10;
	int word;
	Favourite* next;
	void insert(string& key);
	void remove(string& key);
	void removeAll();
};