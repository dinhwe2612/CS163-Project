#include "Definition.h"

using namespace std;

int hashFunc(string &def) {
    int hashDef = 0;
    for (int i = 0; i < (int)def.size(); ++i) {
        hashDef = (hashDef * 137 + def[i] + 1) % MAX;
    }
	return hashDef;
}

vector<int> Definition::getHashList(string& def) {
    vector<int> res;
    stringstream ss(def);
    string word;
    while (ss >> word) {
        if (res.empty()) {
            res.push_back(hashFunc(word));
        }
        else {
            res.push_back((1ll * res.back() * 137 + hashFunc(word)) % MOD);
        }
	}
    return res;
}

int Definition::POW(int n) {
    if (n == 0) return 1;
    if (n == 1) return 137;
    while (n >= (int)pw.size()) {
        pw.push_back(-1);
	}
    if (pw[n] != -1) return pw[n];
    int tmp = POW(n >> 1);
    return pw[n] = (n & 1 ? (1ll * tmp * tmp * 137) % MOD : (1ll * tmp * tmp) % MOD);
}

int Definition::getHash(vector<int> &hashDef, int l, int r) {
    if (l > r) {
        cerr << "getHash error\n";
        return 0;
    }
    return (hashDef[r] - 1ll * (l ? hashDef[l - 1] : 0) * POW(r - l + 1) + 1ll * MOD * MOD) % MOD;
}

int Definition::getHash(string &def) {
    stringstream ss(def);
    string word;
    int hashDef = 0;
	while (ss >> word) {
		hashDef = (1ll * hashDef * 137 + hashFunc(word)) % MOD;
	}
	return hashDef;
}

int Definition::getNumDef(string &def) {
    stringstream ss(def);
    int cnt = 0;
    while (ss >> def) {
        ++cnt;
    }
    return cnt;
}

vector<pair<int, int>> Definition::searchHash(string &def) {
    int hashDef = getHash(def);
    int szDef = getNumDef(def);
	vector<pair<int, int>> res;
	for (int id = 0; id < (int)hashList.size(); ++id) {
        int cnt = 0;
        for (vector<int> &listDef : hashList[id]) {
            bool ok = false;
            for (int l = 0, r = szDef - 1; r < (int)listDef.size(); ++l, ++r) {
                if (getHash(listDef, l, r) == hashDef) {
                    res.push_back({ id, cnt });
                    ok = true;
                    break;
                }
            }
            if (ok) break;
            ++cnt;
        }
	}
	return res;
}

bool Definition::add(string &def, int id) {
	int index = hashFunc(def);
    vector<int>::iterator it = find(words[index].begin(), words[index].end(), id);
    if (it == words[index].end()) {
		words[index].push_back(id);
        if (id >= (int)hashList.size()) {
            hashList.emplace_back();
        }
        hashList[id].push_back(getHashList(def));
        return true;
	}
    return false;
}

// return keyword
vector<int> Definition::search(string &def) {
    int index = hashFunc(def);
    return words[index];
}

// remove both keyword and definition
bool Definition::remove(string &def, int id) {
    int index = hashFunc(def);
    vector<int>::iterator it = find(words[index].begin(), words[index].end(), id);
    if (it == words[index].end()) return false;
    words[index].erase(it);
    hashList[id].clear();
    return true;
}

void Definition::deleteDefinition() {
    for (int i = 0; i < MAX; i++) {
        words[i].clear();
    }
    hashList.clear();
}

void Definition::build(ifstream& fin) {
    for (int i = 0; i < MAX; ++i) {
        int num; 
        fin.read((char*)&num, sizeof(int));
        for (int j = 0; j < num; ++j) {
            words[i].emplace_back();
            fin.read((char*)&words[i][j], sizeof(int));
		}
	}
    int szHashList;
	fin.read((char*)&szHashList, sizeof(int));
	for (int i = 0; i < szHashList; ++i) {
		int szListDef;
		fin.read((char*)&szListDef, sizeof(int));
		hashList.emplace_back();
		for (int j = 0; j < szListDef; ++j) {
			int szDef;
			fin.read((char*)&szDef, sizeof(int));
			hashList[i].emplace_back();
			for (int k = 0; k < szDef; ++k) {
				hashList[i][j].emplace_back();
				fin.read((char*)&hashList[i][j][k], sizeof(int));
			}
		}
	}
}

void Definition::save(ofstream& fout) {
    for (int i = 0; i < MAX; ++i) {
        int num = words[i].size();
        fout.write((char*)&num, sizeof(int));
        for(int &j : words[i]) {
            fout.write((char*)&j, sizeof(int));
		}
	}
    int szHashList = hashList.size();
    fout.write((char*)&szHashList, sizeof(int));
    for (int i = 0; i < szHashList; ++i) {
        int szListDef = hashList[i].size();
        fout.write((char*)&szListDef, sizeof(int));
        for (int j = 0; j < szListDef; ++j) {
            int szDef = hashList[i][j].size();
            fout.write((char*)&szDef, sizeof(int));
            for (int& k : hashList[i][j]) {
                fout.write((char*)&k, sizeof(int));
            }
        }
    }
}