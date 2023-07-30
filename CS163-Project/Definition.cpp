#include "Definition.h"
using namespace std;

int hashFunc(string def) {
	return def[0] * def.length() % 30011;
}

void deleteHashlist(hash_node*& pHead) {
    while (pHead) {
        hash_node* tmp = pHead;
        pHead = pHead->next;
        delete tmp;
    }
    pHead = nullptr;
}

void Definition::add(string key, string def) {
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

// return keyword
string Definition::search(string def) {
    int index = hashFunc(def);
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
    int index = hashFunc(def);
    if (!word[index]) return;

    hash_node* cur = word[index];
    while (cur->next && cur->next->data.second != def)
        cur = cur->next;

    if (!cur->next) return;
    hash_node* tmp = cur->next;
    cur->next = tmp->next;
    delete tmp;
}

void Definition::deleteDefinition() {
    for (int i = 0; i < 30011; i++) {
        deleteHashlist(word[i]);
        word[i] = nullptr;
    }
    delete[] word;
}