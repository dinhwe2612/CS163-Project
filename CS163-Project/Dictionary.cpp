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
		
		int id = engEng_key.insert(key, def);
		bool add = engEng_def.add(def, id);
		if (add) {
			if (id >= engEng.size()) {
				engEng.emplace_back();
				engEng[id].key = key;
			}
			engEng[id].def.push_back(def);
		}
	}
	fin.close();

	fin.open("../Data/engVie/engVie_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		//engVie_key.insert(key, def);
		//engVie_def.add(key, def);
		int id = engVie_key.insert(key, def);
		bool add = engVie_def.add(def, id);
		if (add) {
			if (id >= engVie.size()) {
				engVie.emplace_back();
				engVie[id].key = key;
			}
			engVie[id].def.push_back(def);
		}
	}
	fin.close();

	fin.open("../Data/vieEng/vieEng_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		//vieEng_key.insert(key, def);
		//vieEng_def.add(key, def);
		int id = vieEng_key.insert(key, def);
		bool add = vieEng_def.add(def, id);
		if (add) {
			if (id >= vieEng.size()) {
				vieEng.emplace_back();
				vieEng[id].key = key;
			}
			vieEng[id].def.push_back(def);
		}
	}
	fin.close();

	fin.open("../Data/slang/slang_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		//slang_key.insert(key, def);
		//slang_def.add(key, def);
		int id = slang_key.insert(key, def);
		bool add = slang_def.add(def, id);
		if (add) {
			if (id >= slang.size()) {
				slang.emplace_back();
				slang[id].key = key;
			}
			slang[id].def.push_back(def);
		}
	}
	fin.close();

	fin.open("../Data/emotional/emotional_origin.txt");
	while (!fin.eof()) {
		string mix;
		getline(fin, mix);
		int index = mix.find("	");
		string key = mix.substr(0, index);
		string def = mix.substr(index + 1, mix.length());

		//emotional_key.insert(key, def);
		//emotional_def.add(key, def);
		int id = emotional_key.insert(key, def);
		bool add = emotional_def.add(def, id);
		if (add) {
			if (id >= emotional.size()) {
				emotional.emplace_back();
				emotional[id].key = key;
			}
			emotional[id].def.push_back(def);
		}
	}
	fin.close();
}

void Dictionary::build() {
	ifstream fin;
	//engEng
	fin.open("../Data/engEng/engEng_trie.txt");
	engEng_key.build(engEng_key.root, fin);
	fin.close();
	fin.open("../Data/engEng/engEng_hashTable.txt");
	engEng_def.build(fin);
	fin.close();
	fin.open("../Data/engEng/engEng.txt");
	int sz; fin >> sz;
	fin.ignore();
	engEng.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, engEng[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			engEng[i].def.push_back(tmp);
		}
	}
	fin.close();
	//engVie
	fin.open("../Data/engVie/engVie_trie.txt");
	engVie_key.build(engVie_key.root, fin);
	fin.close();
	fin.open("../Data/engVie/engVie_hashTable.txt");
	engVie_def.build(fin);
	fin.close();
	fin.open("../Data/engVie/engVie.txt");
	fin >> sz;
	fin.ignore();
	engVie.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, engVie[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			engVie[i].def.push_back(tmp);
		}
	}
	fin.close();
	//vieEng
	fin.open("../Data/vieEng/vieEng_trie.txt");
	vieEng_key.build(vieEng_key.root, fin);
	fin.close();
	fin.open("../Data/vieEng/vieEng_hashTable.txt");
	vieEng_def.build(fin);
	fin.close();
	fin.open("../Data/vieEng/vieEng.txt");
	fin >> sz;
	fin.ignore();
	vieEng.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, vieEng[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			vieEng[i].def.push_back(tmp);
		}
	}
	fin.close();
	//engVie
	fin.open("../Data/slang/slang_trie.txt");
	slang_key.build(slang_key.root, fin);
	fin.close();
	fin.open("../Data/slang/slang_hashTable.txt");
	slang_def.build(fin);
	fin.close();
	fin.open("../Data/slang/slang.txt");
	fin >> sz;
	fin.ignore();
	slang.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, slang[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			slang[i].def.push_back(tmp);
		}
	}
	fin.close();
	//slang
	fin.open("../Data/slang/slang_trie.txt");
	slang_key.build(slang_key.root, fin);
	fin.close();
	fin.open("../Data/slang/slang_hashTable.txt");
	slang_def.build(fin);
	fin.close();
	fin.open("../Data/slang/slang.txt");
	fin >> sz;
	fin.ignore();
	slang.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, slang[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			slang[i].def.push_back(tmp);
		}
	}
	fin.close();
	//emotional
	fin.open("../Data/emotional/emotional_trie.txt");
	emotional_key.build(emotional_key.root, fin);
	fin.close();
	fin.open("../Data/emotional/emotional_hashTable.txt");
	emotional_def.build(fin);
	fin.close();
	fin.open("../Data/emotional/emotional.txt");
	fin >> sz;
	fin.ignore();
	emotional.resize(sz);
	for (int i = 0; i < sz; ++i) {
		getline(fin, emotional[i].key);
		int sz2; fin >> sz2;
		fin.ignore();
		for (int j = 0; j < sz2; ++j) {
			string tmp; getline(fin, tmp);
			emotional[i].def.push_back(tmp);
		}
	}
	fin.close();
}

void Dictionary::save() {
	ofstream fout;
	//engEng
	fout.open("../Data/engEng/engEng_trie.txt");
	engEng_key.save(engEng_key.root, fout);
	fout.close();
	fout.open("../Data/engEng/engEng_hashTable.txt");
	engEng_def.save(fout);
	fout.close();
	fout.open("../Data/engEng/engEng.txt");
	fout << engEng.size() << '\n';
	for (int i = 0; i < engEng.size(); ++i) {
		fout << engEng[i].key << '\n';
		fout << engEng[i].def.size() << '\n';
		for (string &tmp : engEng[i].def) {
			fout << tmp << '\n';
		}
	}
	fout.close();
	//vieEng
	fout.open("../Data/vieEng/vieEng_trie.txt");
	vieEng_key.save(vieEng_key.root, fout);
	fout.close();
	fout.open("../Data/vieEng/vieEng_hashTable.txt");
	vieEng_def.save(fout);
	fout.close();
	fout.open("../Data/vieEng/vieEng.txt");
	fout << vieEng.size() << '\n';
	for (int i = 0; i < vieEng.size(); ++i) {
		fout << vieEng[i].key << '\n';
		fout << vieEng[i].def.size() << '\n';
		for (string& tmp : vieEng[i].def) {
			fout << tmp << '\n';
		}
	}
	fout.close();
	//engVie
	fout.open("../Data/engVie/engVie_trie.txt");
	engVie_key.save(engVie_key.root, fout);
	fout.close();
	fout.open("../Data/engVie/engVie_hashTable.txt");
	engVie_def.save(fout);
	fout.close();
	fout.open("../Data/engVie/engVie.txt");
	fout << engVie.size() << '\n';
	for (int i = 0; i < engVie.size(); ++i) {
		fout << engVie[i].key << '\n';
		fout << engVie[i].def.size() << '\n';
		for (string& tmp : engVie[i].def) {
			fout << tmp << '\n';
		}
	}
	fout.close();
	//slang
	fout.open("../Data/slang/slang_trie.txt");
	slang_key.save(slang_key.root, fout);
	fout.close();
	fout.open("../Data/slang/slang_hashTable.txt");
	slang_def.save(fout);
	fout.close();
	fout.open("../Data/slang/slang.txt");
	fout << slang.size() << '\n';
	for (int i = 0; i < slang.size(); ++i) {
		fout << slang[i].key << '\n';
		fout << slang[i].def.size() << '\n';
		for (string& tmp : slang[i].def) {
			fout << tmp << '\n';
		}
	}
	fout.close();
	//emotional
	fout.open("../Data/emotional/emotional_trie.txt");
	emotional_key.save(emotional_key.root, fout);
	fout.close();
	fout.open("../Data/emotional/emotional_hashTable.txt");
	emotional_def.save(fout);
	fout.close();
	fout.open("../Data/emotional/emotional.txt");
	fout << emotional.size() << '\n';
	for (int i = 0; i < emotional.size(); ++i) {
		fout << emotional[i].key << '\n';
		fout << emotional[i].def.size() << '\n';
		for (string& tmp : emotional[i].def) {
			fout << tmp << '\n';
		}
	}
	fout.close();
}

vector<string> Dictionary::searchKeyword(string key, int dicNum) {
	vector<string> found;
	//vector<string> tmp;
	int index;
	switch (dicNum) {
	case 1:
		//tmp = engEng_key.search(key);
		index = engEng_key.search(key);
		if (index != -1) {
			found.push_back(key);
			for(string &def : engEng[index].def) {
				found.push_back(def);
			}
		}
		break;
	case 2:
		//tmp = vieEng_key.search(key);
		index = vieEng_key.search(key);
		if (index != -1) {
			found.push_back(key);
			for(string &def : vieEng[index].def) {
				found.push_back(def);
			}
		}
		break;
	case 3:
		//tmp = engVie_key.search(key);
		index = engVie_key.search(key);
		if (index != -1) {
			found.push_back(key);
			for(string &def : engVie[index].def) {
				found.push_back(def);
			}
		}
		break;
	case 4:
		//tmp = slang_key.search(key);
		index = slang_key.search(key);
		if (index != -1) {
			found.push_back(key);
			for(string &def : slang[index].def) {
				found.push_back(def);
			}
		}
		break;
	case 5:
		//tmp = emotional_key.search(key);
		index = emotional_key.search(key);
		if (index != -1) {
			found.push_back(key);
			for(string &def : emotional[index].def) {
				found.push_back(def);
			}
		}
		break;
	}
	//if (!tmp.empty()) {
	//	found.push_back(key);
	//	for (int i = 0; i < tmp.size(); i++) {
	//		found.push_back(tmp[i]);
	//	}
	//}
	return found;
}

vector<string> Dictionary::predictKeyword(string key, int dicNum) {
	vector<int> found;
	vector<string> result;
	switch (dicNum) {
	case 1:
		found = engEng_key.predict(key);
		for (int& id : found) {
			result.push_back(engEng[id].key);
		}
		break;
	case 2:
		found = vieEng_key.predict(key);
		for (int& id : found) {
			result.push_back(vieEng[id].key);
		}
		break;
	case 3:
		found = engVie_key.predict(key);
		for (int& id : found) {
			result.push_back(engVie[id].key);
		}
		break;
	case 4:
		found = slang_key.predict(key);
		for (int& id : found) {
			result.push_back(slang[id].key);
		}
		break;
	case 5:
		found = emotional_key.predict(key);
		for (int& id : found) {
			result.push_back(emotional[id].key);
		}
		break;
	}
	return result;
}

vector<string> Dictionary::searchDefinition(string def, int dicNum) {
	vector<string> found;
	vector<int> index;
	switch (dicNum) {
	case 1:
		index = engEng_def.search(def);
		for(int &id : index) {
			for(string &tmp : engEng[id].def) {
				if (def == tmp) {
					found.push_back(engEng[id].key);
					break;
				}
			}
		}
		break;
	case 2:
		index = vieEng_def.search(def);
		for(int &id : index) {
			for(string &tmp : vieEng[id].def) {
				if (def == tmp) {
					found.push_back(vieEng[id].key);
					break;
				}
			}
		}
		break;
	case 3:
		index = engVie_def.search(def);
		for (int &id : index) {
			for (string &tmp : engVie[id].def) {
				if (def == tmp) {
					found.push_back(engVie[id].key);
					break;
				}
			}
		}
		break;
	case 4:
		index = slang_def.search(def);
		for(int &id : index) {
			for(string &tmp : slang[id].def) {
				if (def == tmp) {
					found.push_back(slang[id].key);
					break;
				}
			}
		}
		break;
	case 5:
		index = emotional_def.search(def);
		for(int &id : index) {
			for(string &tmp : emotional[id].def) {
				if (def == tmp) {
					found.push_back(emotional[id].key);
					break;
				}
			}
		}
		break;
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
	int id, add;
	switch (dictnum) {
	case 1:
		//if (!engEng_key.insert(key, def)) return false;
		//engEng_def.add(key, def);
		id = engEng_key.insert(key, def);
		add = engEng_def.add(def, id);
		if (add) {
			if (id >= engEng.size()) engEng.emplace_back();
			engEng[id].def.push_back(def);
		} else return false;
		break;
	case 2:
		//if (!vieEng_key.insert(key, def)) return false;
		//vieEng_def.add(key, def);
		id = vieEng_key.insert(key, def);
		add = vieEng_def.add(def, id);
		if (add) {
			if (id >= vieEng.size()) vieEng.emplace_back();
			vieEng[id].def.push_back(def);
		} else return false;
		break;
	case 3:
		//if (!engVie_key.insert(key, def)) return false;
		//engVie_def.add(key, def);
		id = engVie_key.insert(key, def);
		add = engVie_def.add(def, id);
		if (add) {
			if (id >= engVie.size()) engVie.emplace_back();
			engVie[id].def.push_back(def);
		} else return false;
		break;
	case 4:
		//if (!slang_key.insert(key, def)) return false;
		//slang_def.add(key, def);
		id = slang_key.insert(key, def);
		add = slang_def.add(def, id);
		if (add) {
			if (id >= slang.size()) slang.emplace_back();
			slang[id].def.push_back(def);
		} else return false;
		break;
	case 5:
		//if (!emotional_key.insert(key, def)) return false;
		//emotional_def.add(key, def);
		id = emotional_key.insert(key, def);
		add = emotional_def.add(def, id);
		if (add) {
			if (id >= emotional.size()) emotional.emplace_back();
			emotional[id].def.push_back(def);
		} else return false;
		break;
	}
	addWordToFile(dictnum, key, def);
	return true;
}

bool Dictionary::editDefinition(int dictNum, string key, string def, string newdef) {
	return false;
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