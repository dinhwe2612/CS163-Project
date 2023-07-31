#include "Keyword.h"
using namespace std;

bool Keyword::insert(string key, string def) {
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
    for(string &s : pCrawl->definition)
		if(s == def) return false;
    pCrawl->definition.push_back(def);
    return true;
}

bool Keyword::edit(string key, string def, string newdef) {
	TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
		int index = tolower(key[i]);
		if (!pCrawl->child[index])
			return false;

		pCrawl = pCrawl->child[index];
	}

    for (string& s : pCrawl->definition) {
        if (s == def) {
            s = newdef;
            return true;
        }
    }
	return false;
}

vector<string> Keyword::search(string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++)
        key[i] = tolower(key[i]);
    for (int i = 0; i < key.length(); i++)
    {
        int index = key[i];
        if (!pCrawl->child[index])
            return vector<string>(0);

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

vector<string> Keyword::predict(string keyword) {
    if (keyword.empty()) return vector<string>(0);
	TrieNode* pCrawl = root;
    for (int i = 0; i < keyword.length(); i++) {
		int index = tolower(keyword[i]);
		if (!pCrawl->child[index])
			return vector<string>(0);

		pCrawl = pCrawl->child[index];
	}

	vector<string> suggestions;
	queue<pair<TrieNode*, string>> q;
    q.push({ pCrawl, "" });
    while (!q.empty()) {
		TrieNode* temp = q.front().first;
        string word = q.front().second;
		q.pop();
        if (!temp->definition.empty()) {
            suggestions.push_back(keyword + word);
            if (suggestions.size() == limitSuggestions) return suggestions;
		}
        for (int i = 0; i < ASCII_SIZE; i++) {
            if (temp->child[i]) {
                q.push({ temp->child[i], word + (char)i });
			}
		}
	}
	return suggestions;
}

void save(TrieNode* root, ofstream& fout) {
    if (!root) return;
    for (int i = 0; i < ASCII_SIZE; i++) {
        if (root->child[i]) {
			fout << (char)i << ' ';
			save(root->child[i], fout);
		}
	}
    cout << -1 << ' ';
    cout << root->definition.size() << ' ';
    for (string& s : root->definition) {
		cout << s << ' ';
    }
}