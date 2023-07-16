#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <iostream>
#include "Keyword.h"
#include "Definition.h"
#include "Favourite.h"
#include "History.h"
using namespace std;

struct Dictionary {
	Keyword engEng_key;
	Keyword vieEng_key;
	Keyword engVie_key;
	Keyword slang_key;
	Keyword emotional_key;

	Definition engEng_def;
	Definition vieEng_def;
	Definition engVie_def;
	Definition slang_def;
	Definition emotional_def;

	History history;
	Favourite favourite;

	void buildFromOrigin();
	void build();
	vector<string> searchKeyword(string key, int dicNum); // dicNum: No of dataset
	vector<string> searchDefinition(string def, int dicNum);
	void deleteDictionary();
};

void addWordToFile(int dictNum, string key, string def);
void addNewWord(TrieNode* root, string key, string def);
void addNewDefinition(hash_node** root, string key, string def);
#endif