#include "Definition.h"
using namespace std;

int hashFunc(string def) {
    int hashDef = 0;
    for (int i = 0; i < min(4, (int)def.size()); ++i) {
        hashDef = (hashDef * 137 + def[i] + 1) % MAX;
    }
	return hashDef;
}

//void deleteHashlist(hash_node*& pHead) {
//    while (pHead) {
//        hash_node* tmp = pHead;
//        pHead = pHead->next;
//        delete tmp;
//    }
//    pHead = nullptr;
//}

bool Definition::add(string &def, int id) {
	int index = hashFunc(def);
    //hash_node* pNew = new hash_node;
    //pNew->next = nullptr;
    //pNew->data.first = key;
    //pNew->data.second = def;

    //if (!word[index]) {
    //    word[index] = pNew;
    //    return;
    //}

    //hash_node* cur = word[index];
    //while (cur->next != nullptr)
    //    cur = cur->next;
    //cur->next = pNew;
    vector<int>::iterator it = find(words[index].begin(), words[index].end(), id);
    if (it == words[index].end()) {
		words[index].push_back(id);
        return true;
	}
    return false;
}

// return keyword
vector<int> Definition::search(string &def) {
    int index = hashFunc(def);
    //if (word[index] == nullptr) return "\0";

    //hash_node* cur = word[index];
    //while (cur && cur->data.second != def) {
    //    cur = cur->next;
    //}
    //if (!cur) return "\0";
    //return cur->data.first;
    return words[index];
}

// remove both keyword and definition
bool Definition::remove(string &def, int id) {
    int index = hashFunc(def);
    //if (!word[index]) return;

    //hash_node* cur = word[index];
    //while (cur->next && cur->next->data.second != def)
    //    cur = cur->next;

    //if (!cur->next) return;
    //hash_node* tmp = cur->next;
    //cur->next = tmp->next;
    //delete tmp;
    vector<int>::iterator it = find(words[index].begin(), words[index].end(), id);
    if (it == words[index].end()) return false;
    words[index].erase(it);
    return true;
}

void Definition::deleteDefinition() {
    for (int i = 0; i < MAX; i++) {
        //deleteHashlist(word[i]);
        //word[i] = nullptr;
        words[i].clear();
    }
    //delete[] word;
}

void Definition::build(ifstream& fin) {
    for (int i = 0; i < MAX; ++i) {
        int num; fin >> num;
        for (int j = 0; j < num; ++j) {
			int id; fin >> id;
			words[i].push_back(id);
		}
	}
}

void Definition::save(ofstream& fout) {
    for (int i = 0; i < MAX; ++i) {
        fout << words[i].size() << ' ';
        for(int &j : words[i]) {
			fout << j << ' ';
		}
        fout << '\n';
	}
}