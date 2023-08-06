#include "Dictionary.h"
#include "UI/Other.h"
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
	cout << "Building..." << endl;
	ifstream fin;
	//engEng
	fin.open("../Data/engEng/engEng.txt", ios::binary);
	engEng_key.build(fin);
	engEng_def.build(fin);
	int sz; fin.read((char*)&sz, sizeof(int));
	engEng.resize(sz);
	for (int i = 0; i < sz; ++i) {
		int szKey; 
		fin.read((char*)&szKey, sizeof(int));
		engEng[i].key.resize(szKey);
		fin.read((char*)&engEng[i].key[0], szKey);
		int numDef; 
		fin.read((char*)&numDef, sizeof(int));
		for (int j = 0; j < numDef; ++j) {
			string tmp; 
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			tmp.resize(szDef);
			fin.read((char*)&tmp[0], szDef);
			engEng[i].def.push_back(tmp);
		}
	}
	fin.close();
	cout << "20% engEng done" << endl;
	//engVie
	fin.open("../Data/engVie/engVie.txt", ios::binary);
	engVie_key.build(fin);
	engVie_def.build(fin);
	fin.read((char*)&sz, sizeof(int));
	engVie.resize(sz);
	for (int i = 0; i < sz; ++i) {
		int szKey;
		fin.read((char*)&szKey, sizeof(int));
		engVie[i].key.resize(szKey);
		fin.read((char*)&engVie[i].key[0], szKey);
		int numDef;
		fin.read((char*)&numDef, sizeof(int));
		for (int j = 0; j < numDef; ++j) {
			string tmp;
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			tmp.resize(szDef);
			fin.read((char*)&tmp[0], szDef);
			engVie[i].def.push_back(tmp);
		}
	}
	fin.close();
	cout << "40% engVie done" << endl;
	//vieEng
	fin.open("../Data/vieEng/vieEng.txt", ios::binary);
	vieEng_key.build(fin);
	vieEng_def.build(fin);
	fin.read((char*)&sz, sizeof(int));
	vieEng.resize(sz);
	for (int i = 0; i < sz; ++i) {
		int szKey;
		fin.read((char*)&szKey, sizeof(int));
		vieEng[i].key.resize(szKey);
		fin.read((char*)&vieEng[i].key[0], szKey);
		int numDef;
		fin.read((char*)&numDef, sizeof(int));
		for (int j = 0; j < numDef; ++j) {
			string tmp;
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			tmp.resize(szDef);
			fin.read((char*)&tmp[0], szDef);
			vieEng[i].def.push_back(tmp);
		}
	}
	fin.close();
	cout << "60% vieEng done" << endl;
	//slang
	fin.open("../Data/slang/slang.txt", ios::binary);
	slang_key.build(fin);
	slang_def.build(fin);
	fin.read((char*)&sz, sizeof(int));
	slang.resize(sz);
	for (int i = 0; i < sz; ++i) {
		int szKey;
		fin.read((char*)&szKey, sizeof(int));
		slang[i].key.resize(szKey);
		fin.read((char*)&slang[i].key[0], szKey);
		int numDef;
		fin.read((char*)&numDef, sizeof(int));
		for (int j = 0; j < numDef; ++j) {
			string tmp;
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			tmp.resize(szDef);
			fin.read((char*)&tmp[0], szDef);
			slang[i].def.push_back(tmp);
		}
	}
	fin.close();
	cout << "80% slang done" << endl;
	//emotional
	fin.open("../Data/emotional/emotional.txt", ios::binary);
	emotional_key.build(fin);
	emotional_def.build(fin);
	fin.read((char*)&sz, sizeof(int));
	emotional.resize(sz);
	for (int i = 0; i < sz; ++i) {
		int szKey;
		fin.read((char*)&szKey, sizeof(int));
		emotional[i].key.resize(szKey);
		fin.read((char*)&emotional[i].key[0], szKey);
		int numDef;
		fin.read((char*)&numDef, sizeof(int));
		for (int j = 0; j < numDef; ++j) {
			string tmp;
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			tmp.resize(szDef);
			fin.read((char*)&tmp[0], szDef);
			emotional[i].def.push_back(tmp);
		}
	}
	fin.close();
	cout << "100% emotional done" << endl;
}

void Dictionary::save() {
	ofstream fout;
	int sz;
	//engEng
	fout.open("../Data/engEng/engEng.txt", ios::binary);
	engEng_key.save(fout);
	engEng_def.save(fout);
	sz = engEng.size();
	fout.write((char*)&sz, sizeof(int));
	for (int i = 0; i < engEng.size(); ++i) {
		int szKey = engEng[i].key.size();
		fout.write((char*)&szKey, sizeof(int));
		fout.write((char*)&engEng[i].key[0], sizeof(char) * szKey);
		int numDef = engEng[i].def.size();
		fout.write((char*)&numDef, sizeof(int));
		for (string &tmp : engEng[i].def) {
			int szDef = tmp.size();
			fout.write((char*)&szDef, sizeof(int));
			fout.write((char*)&tmp[0], sizeof(char) * szDef);
		}
	}
	fout.close();
	//vieEng
	fout.open("../Data/vieEng/vieEng.txt", ios::binary);
	vieEng_key.save(fout);
	vieEng_def.save(fout);
	sz = vieEng.size();
	fout.write((char*)&sz, sizeof(int));
	for (int i = 0; i < vieEng.size(); ++i) {
		int szKey = vieEng[i].key.size();
		fout.write((char*)&szKey, sizeof(int));
		fout.write((char*)&vieEng[i].key[0], sizeof(char) * szKey);
		int numDef = vieEng[i].def.size();
		fout.write((char*)&numDef, sizeof(int));
		for (string& tmp : vieEng[i].def) {
			int szDef = tmp.size();
			fout.write((char*)&szDef, sizeof(int));
			fout.write((char*)&tmp[0], sizeof(char) * szDef);
		}
	}
	fout.close();
	//engVie
	fout.open("../Data/engVie/engVie.txt", ios::binary);
	engVie_key.save(fout);
	engVie_def.save(fout);
	sz = engVie.size();
	fout.write((char*)&sz, sizeof(int));
	for (int i = 0; i < engVie.size(); ++i) {
		int szKey = engVie[i].key.size();
		fout.write((char*)&szKey, sizeof(int));
		fout.write((char*)&engVie[i].key[0], sizeof(char) * szKey);
		int numDef = engVie[i].def.size();
		fout.write((char*)&numDef, sizeof(int));
		for (string& tmp : engVie[i].def) {
			int szDef = tmp.size();
			fout.write((char*)&szDef, sizeof(int));
			fout.write((char*)&tmp[0], sizeof(char) * szDef);
		}
	}
	fout.close();
	//slang
	fout.open("../Data/slang/slang.txt", ios::binary);
	slang_key.save(fout);
	slang_def.save(fout);
	sz = slang.size();
	fout.write((char*)&sz, sizeof(int));
	for (int i = 0; i < slang.size(); ++i) {
		int szKey = slang[i].key.size();
		fout.write((char*)&szKey, sizeof(int));
		fout.write((char*)&slang[i].key[0], sizeof(char) * szKey);
		int numDef = slang[i].def.size();
		fout.write((char*)&numDef, sizeof(int));
		for (string& tmp : slang[i].def) {
			int szDef = tmp.size();
			fout.write((char*)&szDef, sizeof(int));
			fout.write((char*)&tmp[0], sizeof(char) * szDef);
		}
	}
	fout.close();
	//emotional
	fout.open("../Data/emotional/emotional.txt", ios::binary);
	emotional_key.save(fout);
	emotional_def.save(fout);
	sz = emotional.size();
	fout.write((char*)&sz, sizeof(int));
	for (int i = 0; i < emotional.size(); ++i) {
		int szKey = emotional[i].key.size();
		fout.write((char*)&szKey, sizeof(int));
		fout.write((char*)&emotional[i].key[0], sizeof(char) * szKey);
		int numDef = emotional[i].def.size();
		fout.write((char*)&numDef, sizeof(int));
		for (string& tmp : emotional[i].def) {
			int szDef = tmp.size();
			fout.write((char*)&szDef, sizeof(int));
			fout.write((char*)&tmp[0], sizeof(char) * szDef);
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
					for(string &tmp2 : engEng[id].def) {
						found.push_back(tmp2);
					}
					return found;
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
					for(string &tmp2 : vieEng[id].def) {
						found.push_back(tmp2);
					}
					return found;
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
					for (string &tmp2 : engVie[id].def) {
						found.push_back(tmp2);
					}
					return found;
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
					for(string &tmp2 : slang[id].def) {
						found.push_back(tmp2);
					}
					return found;
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
					for(string &tmp2 : emotional[id].def) {
						found.push_back(tmp2);
					}
					return found;
				}
			}
		}
		break;
	}
	return found;
}

vector<string> Dictionary::randomAWord(int dictNum)
{
	int id;
	srand(time(NULL));
	vector<string> word;
	switch (dictNum)
	{
	case 1:
		//id = rand() % (engEng.size() + 1);
		id = RandInt(0, engEng.size() - 1);
		word.push_back(engEng[id].key);
		for (int i = 0; i < engEng[id].def.size(); ++i)
			word.push_back(engEng[id].def[i]);
		break;
	case 2:
		//id = rand() % (vieEng.size() + 1);
		id = RandInt(0, vieEng.size() - 1);
		word.push_back(vieEng[id].key);
		for (int i = 0; i < vieEng[id].def.size(); ++i)
			word.push_back(vieEng[id].def[i]);
		break;
	case 3:
		//id = rand() % (engVie.size() + 1);
		id = RandInt(0, engVie.size() - 1);
		word.push_back(engVie[id].key);
		for (int i = 0; i < engVie[id].def.size(); ++i)
			word.push_back(engVie[id].def[i]);
		break;
	case 4:
		//id = rand() % (slang.size() + 1);
		id = RandInt(0, slang.size() - 1);
		word.push_back(slang[id].key);
		for (int i = 0; i < slang[id].def.size(); ++i)
			word.push_back(slang[id].def[i]);
		break;
	case 5:
		//id = rand() % (emotional.size() + 1);
		id = RandInt(0, emotional.size() - 1);
		word.push_back(emotional[id].key);
		for (int i = 0; i < emotional[id].def.size(); ++i)
			word.push_back(emotional[id].def[i]);
		break;
	}
	return word;
}

//void Dictionary::deleteDictionary() {
//	engEng_def.deleteDefinition();
//	vieEng_def.deleteDefinition();
//	engVie_def.deleteDefinition();
//	slang_def.deleteDefinition();
//	emotional_def.deleteDefinition();
//}

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
	return true;
}

bool compareDef(vector<string> curDef, string newdef)
{
	for (int i = 0; i < curDef.size(); ++i)
	{
		if (curDef[i] == newdef) return false;
	}
	//addWordToFile(dictnum, key, def);
	return true;
}

bool Dictionary::editDefinition(int dictNum, string key, string def, string newdef) {
	int id;
	vector<string> curDef;
	vector<string>::iterator it; 
	switch (dictNum)
	{
	case 1:
		id = engEng_key.search(key);
		curDef = engEng[id].def;
		if (!compareDef(curDef, newdef)) return false;
		it = find(curDef.begin(), curDef.end(), def);
		*it = newdef;
		break;
	case 2:
		id = vieEng_key.search(key);
		curDef = vieEng[id].def;
		if (!compareDef(curDef, newdef)) return false;
		it = find(curDef.begin(), curDef.end(), def);
		*it = newdef;
		break;
	case 3:
		id = engVie_key.search(key);
		curDef = engVie[id].def;
		if (!compareDef(curDef, newdef)) return false;
		it = find(curDef.begin(), curDef.end(), def);
		*it = newdef;
		break;
	case 4:
		id = slang_key.search(key);
		curDef = slang[id].def;
		if (!compareDef(curDef, newdef)) return false;
		it = find(curDef.begin(), curDef.end(), def);
		*it = newdef;
		break;
	case 5:
		id = emotional_key.search(key);
		curDef = emotional[id].def;
		if (!compareDef(curDef, newdef)) return false;
		it = find(curDef.begin(), curDef.end(), def);
		*it = newdef;
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

//void copyDictionary(int dictNum)
//{
//	string source = getSource(dictNum);
//
//	ifstream fin;
//	fin.open("../Data/" + source + "/" + source + "_origin.txt", ios::binary | ios::ate);
//
//	ofstream fout;
//	fout.open("../Data/" + source + "/" + source + ".txt", ios::binary);
//
//	int size = fin.tellg();
//	char* memblock = new char[size];
//	fin.seekg(0, ios::beg);
//	fin.read(memblock, size);
//	fout.write(memblock, size);
//
//	delete[] memblock;
//	fin.close();
//	fout.close();
//}

//void addWordToFile(int dictNum, string key, string def)
//{
//	string filename = getSource(dictNum);
//
//	ofstream fout;
//	fout.open("../Data/" + filename + "/" + filename + ".txt", ios::app);
//	fout << "\n" << key << "	" << def;
//	fout.close();
//}

void Dictionary::removeAWord(int dictNum, string key)
{
	int id;
	vector<dic>::iterator it;
	switch (dictNum)
	{
	case 1:
		id = engEng_key.search(key);
		for (int i = 0; i < engEng[id].def.size(); ++i)
			engEng_def.remove(engEng[id].def[i], id);
		it = engEng.begin() + id;
		engEng.erase(it);
		engEng_key.remove(key);
		break;
	case 2:
		id = vieEng_key.search(key);
		for (int i = 0; i < vieEng[id].def.size(); ++i)
			vieEng_def.remove(vieEng[id].def[i], id);
		it = vieEng.begin() + id;
		vieEng.erase(it);
		vieEng_key.remove(key);
		break;
	case 3:
		id = engVie_key.search(key);
		for (int i = 0; i < engVie[id].def.size(); ++i)
			engVie_def.remove(engVie[id].def[i], id);
		it = engVie.begin() + id;
		engVie.erase(it);
		engVie_key.remove(key);
		break;
	case 4:
		id = slang_key.search(key);
		for (int i = 0; i < slang[id].def.size(); ++i)
			slang_def.remove(slang[id].def[i], id);
		it = slang.begin() + id;
		slang.erase(it);
		slang_key.remove(key);
		break;
	case 5:
		id = emotional_key.search(key);
		for (int i = 0; i < emotional[id].def.size(); ++i)
			emotional_def.remove(emotional[id].def[i], id);
		it = emotional.begin() + id;
		emotional.erase(it);
		emotional_key.remove(key);
		break;
	}
}

void Dictionary::resetDictionary(int dictNum)
{
	// copyDictionary(dictNum);
	buildFromOrigin();
	favourite.removeAll();
	history.removeAll();
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

bool Dictionary::isFavourite(string key) {
	for (int i = 1; i <= 5; i++) {
		string dataset = getSource(i);
		favourite.init(dataset);
		if (favourite.isFavourite(key))
			return true;
	}
	return false;
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

void Dictionary::randomWord(int dictNum, pair<int, vector<string>> &result) {
	result.second.resize(5);
	switch (dictNum)
	{
	default:
		break;
	case 1: 
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, engEng.size() - 1);
			if (i == result.first) {
				result.second[0] = engEng[randIdKey].key;
			}
			int randIdDef = RandInt(0, engEng[randIdKey].def.size() - 1);
			result.second[i] = engEng[randIdKey].def[randIdDef];
		}
		return;
	case 2:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, vieEng.size() - 1);
			if (i == result.first) {
				result.second[0] = vieEng[randIdKey].key;
			}
			int randIdDef = RandInt(0, vieEng[randIdKey].def.size() - 1);
			result.second[i] = vieEng[randIdKey].def[randIdDef];
		}
		return;
	case 3:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, engVie.size() - 1);
			if (i == result.first) {
				result.second[0] = engVie[randIdKey].key;
			}
			int randIdDef = RandInt(0, engVie[randIdKey].def.size() - 1);
			result.second[i] = engVie[randIdKey].def[randIdDef];
		}
		return;
	case 4:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, slang.size() - 1);
			if (i == result.first) {
				result.second[0] = slang[randIdKey].key;
			}
			int randIdDef = RandInt(0, slang[randIdKey].def.size() - 1);
			result.second[i] = slang[randIdKey].def[randIdDef];
		}
		return;
	case 5:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, emotional.size() - 1);
			if (i == result.first) {
				result.second[0] = emotional[randIdKey].key;
			}
			int randIdDef = RandInt(0, emotional[randIdKey].def.size() - 1);
			result.second[i] = emotional[randIdKey].def[randIdDef];
		}
		return;
	}

}

void Dictionary::randomDef(int dictNum, pair<int, vector<string>> &result) {
	result.second.resize(5);
	switch (dictNum)
	{
	default:
		break;
	case 1:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, engEng.size() - 1);
			if (i == result.first) {
				int randIdDef = RandInt(0, engEng[randIdKey].def.size() - 1);
				result.second[0] = engEng[randIdKey].def[randIdDef];
			}
			result.second[i] = engEng[randIdKey].key;
		}
		return;
	case 2:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, vieEng.size() - 1);
			if (i == result.first) {
				int randIdDef = RandInt(0, vieEng[randIdKey].def.size() - 1);
				result.second[0] = vieEng[randIdKey].def[randIdDef];
			}
			result.second[i] = vieEng[randIdKey].key;
		}
		return;
	case 3:
		result.first = RandInt(0, engVie.size() - 1);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(1, 4);
			if (i == result.first) {
				int randIdDef = RandInt(0, engVie[randIdKey].def.size() - 1);
				result.second[0] = engVie[randIdKey].def[randIdDef];
			}
			result.second[i] = engVie[randIdKey].key;
		}
		return;
	case 4:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, slang.size() - 1);
			if (i == result.first) {
				int randIdDef = RandInt(0, slang[randIdKey].def.size() - 1);
				result.second[0] = slang[randIdKey].def[randIdDef];
			}
			result.second[i] = slang[randIdKey].key;
		}
		return;
	case 5:
		result.first = RandInt(1, 4);
		for (int i = 1; i <= 4; ++i) {
			int randIdKey = RandInt(0, emotional.size() - 1);
			if (i == result.first) {
				int randIdDef = RandInt(0, emotional[randIdKey].def.size() - 1);
				result.second[0] = emotional[randIdKey].def[randIdDef];
			}
			result.second[i] = emotional[randIdKey].key;
		}
		return;
	}
}