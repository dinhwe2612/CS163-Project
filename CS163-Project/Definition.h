#ifndef DEFINITION_H
#define DEFINITION_H

#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct hash_node {
	pair<string, string> data;// {keyword, definition}
	hash_node* next;
};

int hashFunc(string def);
void deleteHashlist(hash_node*& pHead);

struct Definition {
	int num;// number of definition
	hash_node** word = new hash_node*[30011];
	
	Definition() {
		fill(word, word + 30011, nullptr);
		num = 0;
	}

	void add(string key, string def);
	string search(string def);
	void remove(string def);
	void deleteDefinition();
};

#endif