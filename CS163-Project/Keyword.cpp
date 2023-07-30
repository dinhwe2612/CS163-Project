#include "Keyword.h"
using namespace std;

void Keyword::insert(string key, string def) {
    if (!root) root = new TrieNode();
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = tolower(key[i]);
        if (!pCrawl->child[index])
            pCrawl->child[index] = new TrieNode();

        pCrawl = pCrawl->child[index];
    }

    // mark last node as leaf
    pCrawl->definition.push_back(def);
}

vector<string> Keyword::search(string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++)
        key[i] = tolower(key[i]);
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!pCrawl->child[index])
            return {};

        pCrawl = pCrawl->child[index];
    }

    return pCrawl->definition;
}

void Keyword::removeHelper(TrieNode* root, string key, int depth) {
    if (!root) return;

    if (depth == key.length()) {
        //remove the definition vector
        root->definition.clear();
        return;
    }

    int index = static_cast<int>(key[depth]);
    removeHelper(root->child[index], key, depth + 1);

    // remove if it has no definition and has no child nodes.
    if (root->definition.empty()) {
        for (int i = 0; i < ASCII_SIZE; ++i) {
            if (root->child[i]) {
                return;
            }
        }
        delete root;
        root = nullptr;
    }
}

void Keyword::remove(string key) {
    removeHelper(root, key, 0);
}