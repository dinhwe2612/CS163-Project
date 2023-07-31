#include "Dictionary.h"
#include <fstream>
using namespace std;

void Dictionary::buildFromOrigin() {
	ifstream fin;
	fin.open("../Data/engEng/engEng_origin.txt");
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

	fin.open("../Data/engVie/engVie_origin.txt");
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

	fin.open("../Data/vieEng/vieEng_origin.txt");
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

void save() {

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

vector<string> Dictionary::predictKeyword(string key, int dicNum) {
	switch (dicNum) {
	case 1:
		return engEng_key.predict(key);
		break;
	case 2:
		return vieEng_key.predict(key);
		break;
	case 3:
		return engVie_key.predict(key);
		break;
	case 4:
		return slang_key.predict(key);
		break;
	case 5:
		return emotional_key.predict(key);
		break;
	}
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

bool Dictionary::addNewWord(int dictnum, string key, string def)
{
	switch (dictnum) {
	case 1:
		if (!engEng_key.insert(key, def)) return false;
		engEng_def.add(key, def);
		break;
	case 2:
		if (!vieEng_key.insert(key, def)) return false;
		vieEng_def.add(key, def);
		break;
	case 3:
		if (!engVie_key.insert(key, def)) return false;
		engVie_def.add(key, def);
		break;
	case 4:
		if (!slang_key.insert(key, def)) return false;
		slang_def.add(key, def);
		break;
	case 5:
		if (!emotional_key.insert(key, def)) return false;
		emotional_def.add(key, def);
		break;
	}
	addWordToFile(dictnum, key, def);
	return true;
}

bool Dictionary::editDefinition(int dictNum, string key, string def, string newdef) {
	switch (dictNum) {
	case 1:
		if (!engEng_key.edit(key, def, newdef)) return false;
		engEng_key.edit(key, def, newdef);
		break;
	case 2:
		if (!vieEng_key.edit(key, def, newdef)) return false;
		vieEng_key.edit(key, def, newdef);
		break;
	case 3:
		if (!engVie_key.edit(key, def, newdef)) return false;
		engVie_key.edit(key, def, newdef);
		break;
	case 4:
		if (!slang_key.edit(key, def, newdef)) return false;
		slang_key.edit(key, def, newdef);
		break;
	case 5:
		if (!emotional_key.edit(key, def, newdef)) return false;
		emotional_key.edit(key, def, newdef);
		break;
	}
	return true;
}

string getSource(int dictNum) {
	switch (dictNum) {
	case 1:
		return "engEng";
	case 2:
		return "vieEng";
	case 3:
		return "engVie";
	case 4:
		return "slang";
	case 5:
		return "emotional";
	}
}

void copyDictionary(int dictNum)
{
	string source = getSource(dictNum);

	ifstream fin;
	fin.open("../Data/" + source + "/" + source + "_origin.txt", ios::binary | ios::ate);

	ofstream fout;
	fout.open("../Data/" + source + "/" + source + ".txt", ios::binary);

	int size = fin.tellg();
	char* memblock = new char[size];
	fin.seekg(0, ios::beg);
	fin.read(memblock, size);
	fout.write(memblock, size);

	delete[] memblock;
	fin.close();
	fout.close();
}

void addWordToFile(int dictNum, string key, string def)
{
	string filename = getSource(dictNum);

	ofstream fout;
	fout.open("../Data/" + filename + "/" + filename + ".txt", ios::app);
	fout << "\n" << key << "	" << def;
	fout.close();
}

void Dictionary::resetDictionary(int dictNum)
{
	copyDictionary(dictNum);
}

vector<string> Dictionary::viewFavourite(int dictNum) {
	string dataset = getSource(dictNum);
	favourite.init(dataset);
	return favourite.favourite;
}

void Dictionary::addFavourite(int dictNum, string key) {
	string dataset = getSource(dictNum);
	favourite.init(dataset);
	favourite.insert(key);
}

void Dictionary::removeAFavourite(int dictNum, string key) {
	string dataset = getSource(dictNum);
	favourite.init(dataset);
	favourite.remove(key);
}

vector<string> Dictionary::viewHistory() {
	history.init();
	return history.history;
}

void Dictionary::addHistory(string key) {
	history.init();
	history.insert(key);
}

void Dictionary::removeAHistory(string key) {
	history.init();
	history.remove(key);
}