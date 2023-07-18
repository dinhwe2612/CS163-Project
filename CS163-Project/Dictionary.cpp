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

	fin.open("../Data/engEng/vieEng_origin.txt");
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

void Dictionary::addNewWord(int dictnum, string key, string def)
{
	switch (dictnum) {
	case 1:
		engEng_key.insert(key, def);
		engEng_def.add(key, def);
		break;
	case 2:
		vieEng_key.insert(key, def);
		vieEng_def.add(key, def);
		break;
	case 3:
		engVie_key.insert(key, def);
		engVie_def.add(key, def);
		break;
	case 4:
		slang_key.insert(key, def);
		slang_def.add(key, def);
		break;
	case 5:
		emotional_key.insert(key, def);
		emotional_def.add(key, def);
		break;
	}
	addWordToFile(dictnum, key, def);
}

void copyDictionary(int dictNum)
{
	string source;
	switch (dictNum) {
	case 1:
		source = "engEng";
		break;
	case 2:
		source = "vieEng";
		break;
	case 3:
		source = "engVie";
		break;
	case 4:
		source = "slang";
		break;
	case 5:
		source = "emotional";
		break;
	}

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
	string filename;
	switch (dictNum) {
	case 1:
		filename = "engEng";
		break;
	case 2:
		filename = "vieEng";
		break;
	case 3:
		filename = "engVie";
		break;
	case 4:
		filename = "slang";
		break;
	case 5:
		filename = "emotional";
		break;
	}

	ofstream fout;
	fout.open("../Data/" + filename + "/" + filename + ".txt", ios::app);
	fout << "\n" << key << "	" << def;
	fout.close();
}

void Dictionary::resetDictionary(int dictNum)
{
	copyDictionary(dictNum);
}