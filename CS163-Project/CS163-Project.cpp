/*******************************************************************************************
*
*   raylib [shapes] example - Draw raylib logo using basic shapes
*
*   Example originally created with raylib 1.0, last time updated with raylib 1.0
*
*   Example licensed under an unmodified zlib/libpng license, which is an OSI-certified,
*   BSD-like license that allows static linking with closed source software
*
*   Copyright (c) 2014-2023 Ramon Santamaria (@raysan5)
*
********************************************************************************************/

#include "System.h"
#include "Dictionary.h"

//bool compareKeyword(TrieNode* a, TrieNode* b) {
//    if (!a && !b) return true;
//    if (!a || !b) {
//        if (!a) cerr << "a is null\n";
//        if (!b) cerr << "b is null\n";
//        return false;
//    }
//    if (a->id != b->id) {
//        cerr << "diff " << a->id << ' ' << b->id << endl;
//        return false;
//    }
//    for (int i = 0; i < 128; i++) {
//        if (!compareKeyword(a->child[i], b->child[i])) {
//            return false;
//        }
//	}
//    return true;
//}
//
//bool compareDefinition(Definition* a, Definition* b) {
//	if (a->num != b->num) return false;
//    for (int i = 0; i < MAX; i++) {
//		if (a->words[i] != b->words[i]) return false;
//	}
//	return true;
//}
//
//bool compare(Dictionary* a, Dictionary* b) {
//	if (!compareKeyword(a->engEng_key.root, b->engEng_key.root)) return false;
//    cerr << "trie checked\n";
//	if (!compareDefinition(&a->engEng_def, &b->engEng_def)) return false;
//    cerr << "def checked\n";
//    if (a->engEng.size() != b->engEng.size()) return false;
//    for (int i = 0; i < a->engEng.size(); i++) {
//        if (a->engEng[i].key != b->engEng[i].key) return false;
//        if (a->engEng[i].def != b->engEng[i].def) return false;
//    }
//    cerr << "engEng is OK" << endl;
//    if (!compareKeyword(a->engVie_key.root, b->engVie_key.root)) return false;
//    cerr << "trie checked\n";
//    if (!compareDefinition(&a->engVie_def, &b->engVie_def)) return false;
//    cerr << "def checked\n";
//    if (a->engVie.size() != b->engVie.size()) return false;
//    for (int i = 0; i < a->engVie.size(); i++) {
//		if (a->engVie[i].key != b->engVie[i].key) return false;
//		if (a->engVie[i].def != b->engVie[i].def) return false;
//	}
//    cerr << "engVie is OK" << endl;
//    if (!compareKeyword(a->vieEng_key.root, b->vieEng_key.root)) return false;
//    cerr << "trie checked\n";
//	if (!compareDefinition(&a->vieEng_def, &b->vieEng_def)) return false;
//    cerr << "def checked\n";
//	if (a->vieEng.size() != b->vieEng.size()) return false;
//    for (int i = 0; i < a->vieEng.size(); i++) {
//		if (a->vieEng[i].key != b->vieEng[i].key) return false;
//		if (a->vieEng[i].def != b->vieEng[i].def) return false;
//	}
//    cerr << "vieEng is OK" << endl;
//	return true;
//}

int main(void)
{

    //System system;
    //system.Construct();
    //system.Draw();

    Dictionary d;
    //d.buildFromOrigin();
    d.build();
    //d.save();
 //   Dictionary d2;
 //   d2.build();
 //   if (compare(&d, &d2)) cerr << "OK" << endl;
	//else cerr << "NOT OK" << endl;
    //d.deleteDictionary();
    //d.engEng_key.save(d.engEng_key.root, fout);
 //   d.engEng_key.load(d.engEng_key.root, fin);
 //   vector<string> found = d2.searchKeyword("tu", 2);
 //   vector<string> found2 = d2.searchKeyword("tu", 2);
 //   if (found != found2) cerr << "NOT OK" << endl;
 //   if (found.empty()) {
	//	cout << "Not found" << endl;
	//}
 //   for (int i = 0; i < found.size(); i++) {
 //       cout << found[i] << endl;
 //   }
 //   d.deleteDictionary();
    return 0;
}