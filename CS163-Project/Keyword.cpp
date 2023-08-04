#include "Keyword.h"
#include <string>
#include <random>
using namespace std;

int Keyword::insert(string key, string &def) {
    if (!root) root = new TrieNode();
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = tolower(key[i]);
        if (index < 0) {
            cerr << "Error: " << key << endl;
            index = ' ';
        }
        if (!pCrawl->child[index]) {
            pCrawl->child[index] = new TrieNode();
            ++pCrawl->countChild;
        }
            
        
        pCrawl = pCrawl->child[index];
    }
    if (pCrawl->id == -1) return pCrawl->id = numOfWords++;
    return pCrawl->id;
}

int Keyword::search(string key) {
    TrieNode* pCrawl = root;
    for (int i = 0; i < key.length(); i++)
    {
        int index = tolower(key[i]);
        if (!pCrawl->child[index])
            return -1;

        pCrawl = pCrawl->child[index];
    }

    return pCrawl->id;
}

void Keyword::removeHelper(TrieNode* root, string key, int depth) {
    if (!root) return;

    if (depth == key.length()) {
        //remove the definition vector
        root->id = -1;
        delete root;
        root = nullptr;
        --numOfWords;
        return;
    }

    int index = static_cast<int>(key[depth]);
    removeHelper(root->child[index], key, depth + 1);
    --root->countChild;

    // remove if it has no definition and has no child nodes.
    if (root->countChild == 0) {
        delete root;
        root = nullptr;
    }
}

void Keyword::remove(string key) {
    removeHelper(root, key, 0);
}

vector<int> Keyword::predict(string keyword) {
    if (keyword.empty()) return vector<int>(0);
	TrieNode* pCrawl = root;
    for (int i = 0; i < keyword.length(); i++) {
		int index = tolower(keyword[i]);
		if (!pCrawl->child[index])
			return vector<int>(0);

		pCrawl = pCrawl->child[index];
	}

	vector<int> suggestions;
	queue<TrieNode*> q;
    q.push(pCrawl);
    while (!q.empty()) {
        TrieNode* temp = q.front();
		q.pop();
        if (temp->id != -1) {
            suggestions.push_back(temp->id);
            if (suggestions.size() == limitSuggestions) return suggestions;
		}
        for (int i = 0; i < ASCII_SIZE; i++) {
            if (temp->child[i]) {
                q.push(temp->child[i]);
			}
		}
	}
	return suggestions;
}

void Keyword::save(ofstream &fout) {
    fout.write((char*)&numOfWords, sizeof(int));
    queue<TrieNode*> q;
    q.push(root);
    while (!q.empty()) {
		TrieNode* temp = q.front();
		q.pop();
        fout.write((char*)&temp->id, sizeof(int));
        fout.write((char*)&temp->countChild, sizeof(int));
        for (int i = 0; i < ASCII_SIZE; ++i) {
            if (temp->child[i]) {
                fout.write((char*)&i, sizeof(int));
				q.push(temp->child[i]);
			}
		}
	}
}


void Keyword::build(ifstream& fin) {
    fin.read((char*)&numOfWords, sizeof(int));
    queue<TrieNode*> q;
    q.push(root);
    while (!q.empty()) {
        TrieNode* temp = q.front();
        q.pop();
        fin.read((char*)&temp->id, sizeof(int));
        fin.read((char*)&temp->countChild, sizeof(int));
        for (int i = 0; i < temp->countChild; ++i) {
			int c; 
            fin.read((char*)&c, sizeof(int));
			temp->child[c] = new TrieNode();
			q.push(temp->child[c]);
		}
    }
}