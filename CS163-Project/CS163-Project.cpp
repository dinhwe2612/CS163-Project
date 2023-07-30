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
//#include <iostream>

int main(void)
{

    //System system;
    //system.Construct();
    //system.Draw();

    Dictionary d;
    d.buildFromOrigin();
    vector<string> found = d.searchKeyword("A Dong", 2);
    if (found.empty()) {
		cout << "Not found" << endl;
	}
    for (int i = 0; i < found.size(); i++) {
        cout << found[i] << endl;
    }
    d.deleteDictionary();
    return 0;
}