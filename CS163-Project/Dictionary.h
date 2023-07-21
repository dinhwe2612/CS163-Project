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
	void addNewWord(int dictnum, string key, string def);
	void deleteDictionary();
	void resetDictionary(int dictNum);
	void editDefinition(int dictNum, string key, string def, string newdef);

	// favourite function
	vector<string> viewFavourite(int dictNum);
	void addFavourite(int dictNum, string key);
	void removeAFavourite(int dictNum, string key);

	// history function
	vector<string> viewHistory();
	void addHistory(string key);
	void removeAHistory(string key);
};

string getSource(int dictNum);
void copyDictionary(int dictNum);
void addWordToFile(int dictNum, string key, string def);

#endif