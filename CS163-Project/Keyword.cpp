#include "Keyword.h"
using namespace std;

void Keyword::insert(string key, string def) {
    if (!root) root = new TrieNode();
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!pCrawl->child[index])
            pCrawl->child[index] = new TrieNode();

        ++pCrawl->countWord;
        pCrawl = pCrawl->child[index];
    }

    // mark last node as leaf
    pCrawl->definition = def;
}

string Keyword::search(string key) {
    TrieNode* pCrawl = root;

    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i] - 'a';
        if (!pCrawl->child[index])
            return "\0";

        pCrawl = pCrawl->child[index];
    }

    return pCrawl->definition;
}

void Keyword::remove(string key) {

}