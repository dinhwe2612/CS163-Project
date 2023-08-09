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

	struct dic {
		string key;
		vector<string> def;
	};
	vector<dic> engEng;
	vector<dic> vieEng;
	vector<dic> engVie;
	vector<dic> slang;
	vector<dic> emotional;

	History history;
	Favourite favourite;

	void buildFromOrigin();
	void build();
	void save();
	vector<string> searchKeyword(string key, int dicNum); // dicNum: No of dataset
	vector<string> predictKeyword(string key, int dicNum);
	vector<string> searchDefinition(string def, int dicNum);
	bool addNewWord(int dictnum, string key, string def);
	//void deleteDictionary();
	void resetDictionary();
	bool editDefinition(int dictNum, string key, string def, string newdef);
	void removeAWord(int dictNum, string key);
	vector<string> randomAWord(int dictNum);

	// favourite function
	vector<string> viewFavourite(int dictNum);
	void addFavourite(int dictNum, string key);
	void removeAFavourite(int dictNum, string key);
	bool isFavourite(string key);

	// history function
	vector<his> viewHistory(int dictNum);
	void addHistory(int dictNum, string word, bool isKey);
	void removeAHistory(int dictNum, string word);

	// random
	void randomWord(int dictNum, pair<int, vector<string>>& result);
	void randomDef(int dictNum, pair<int, vector<string>> &result);
};
bool compareDef(vector<string> curDef, string newdef);
string getSource(int dictNum);
void copyDictionary(int dictNum);
void addWordToFile(int dictNum, string key, string def);

#endif