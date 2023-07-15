#include "Definition.h"
using namespace std;

int hashFunc(string def, int size) {
	return def.length() % size;
}

void Definition::add(string key, string def) {
	int index = hashFunc(def, num);
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

// return keyword
string Definition::search(string def) {
    int index = hashFunc(def, num);
    if (word[index] == nullptr) return "\0";

    hash_node* cur = word[index];
    while (cur && cur->data.second != def) {
        cur = cur->next;
    }
    if (!cur) return "\0";
    return cur->data.first;
}

// remove both keyword and definition
void Definition::remove(string def) {
    int index = hashFunc(def, num);
    if (!word[index]) return;

    hash_node* cur = word[index];
    while (cur->next && cur->next->data.second != def)
        cur = cur->next;

    if (!cur->next) return;
    hash_node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}