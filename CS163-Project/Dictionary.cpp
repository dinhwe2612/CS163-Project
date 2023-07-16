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

void addWordToFile(int dictNum, string key, string def)
{
	//Open the source file
	string source;
	switch (dictNum){
	case 1:
		source = "engEng";
		break;
	case 2:
		source = "engVie";
		break;
	case 3:
		source = "engEng";
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
	if (!fin.is_open())
	{
		cout << "Unable to open source file!" << endl;
		return;
	}

	ofstream fout;
	fout.open("../Data/" + source + "/" + source + "_updated.txt", ios::binary | ios::app);
	if (!fout.is_open())
	{
		cout << "Unable to open destination file!" << endl;
		return;
	}

	int size = fin.tellg();
	char* memblock = new char[size];
	fin.seekg(0, ios::beg);
	fin.read(memblock, size);
	fout.write(memblock, size);

	//add new keyword and definiton into updated file
	fout << "\n" << key << "	" << def;

	delete[] memblock;
	fin.close();
	fout.close();
}

void addNewWord(TrieNode* root, string key, string def)
{
	if (!root) root = new TrieNode();
	TrieNode* pCrawl = root;

	for (int i = 0; i < key.length(); i++)
	{
		int index = key[i];
		if (!pCrawl->child[index])
			pCrawl->child[index] = new TrieNode();

		pCrawl = pCrawl->child[index];
	}

	// mark last node as leaf
	pCrawl->definition.push_back(def);
}

void addNewDefinition(hash_node** word, string key, string def)
{
	int index = hashFunc(def);
	hash_node* pNew = new hash_node;
	pNew->next = nullptr;
	pNew->data.first = key;
	pNew->data.second = def;

	if (!word[index]) {
		word[index] = pNew;
		return;
	}

	hash_node* cur = word[index];
	while (cur->next != nullptr)
		cur = cur->next;
	cur->next = pNew;
}