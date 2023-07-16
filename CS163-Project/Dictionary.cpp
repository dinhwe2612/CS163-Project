#include "Dictionary.h"
#include <fstream>
using namespace std;

void Dictionary::buildFromOrigin() {
	ifstream fin;
	fin.open("../Data/eng_eng/engEng_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());
		
		engEng_key.insert(key, def);
		engEng_def.add(key, def);
	}
	fin.close();

	fin.open("../Data/eng_vie/engVie_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		engVie_key.insert(key, def);
		engVie_def.add(key, def);
	}
	fin.close();

	fin.open("../Data/eng_eng/vieEng_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		vieEng_key.insert(key, def);
		vieEng_def.add(key, def);
	}
	fin.close();

	fin.open("../Data/slang/slang_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		slang_key.insert(key, def);
		slang_def.add(key, def);
	}
	fin.close();

	fin.open("../Data/emotional/emotional_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		emotional_key.insert(key, def);
		emotional_def.add(key, def);
	}
	fin.close();
}

vector<string> Dictionary::searchKeyword(string key, int dicNum) {
	vector<string> found;
	vector<string> tmp;
	switch (dicNum) {
	case 1:
		tmp = engEng_key.search(key);
		break;
	case 2:
		tmp = vieEng_key.search(key);
		break;
	case 3:
		tmp = engVie_key.search(key);
		break;
	case 4:
		tmp = slang_key.search(key);
		break;
	case 5:
		tmp = emotional_key.search(key);
		break;
	}
	if (!tmp.empty()) {
		found.push_back(key);
		for (int i = 0; i < tmp.size(); i++) {
			found.push_back(tmp[i]);
		}
	}
	return found;
}

vector<string> Dictionary::searchDefinition(string def, int dicNum) {
	vector<string> found;
	string key;
	switch (dicNum) {
	case 1:
		key = engEng_def.search(def);
		break;
	case 2:
		key = vieEng_def.search(def);
		break;
	case 3:
		key = engVie_def.search(def);
		break;
	case 4:
		key = slang_def.search(def);
		break;
	case 5:
		key = emotional_def.search(def);
		break;
	}
	if (key != "\0") {
		found.push_back(key);
		found.push_back(def);
	}
	return found;
}

void Dictionary::deleteDictionary() {
	engEng_def.deleteDefinition();
	vieEng_def.deleteDefinition();
	engVie_def.deleteDefinition();
	slang_def.deleteDefinition();
	emotional_def.deleteDefinition();
}