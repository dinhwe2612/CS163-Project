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
#include <chrono>

int main(void)
{
    //System system;
    //system.Construct();
    //system.Draw();


    Dictionary d;
    d.addFavourite(1, "1");
    d.addFavourite(1, "2");
    d.addFavourite(1, "3");
    d.addFavourite(1, "4");
    d.removeAFavourite(1, "2");

    //Dictionary d;
    //auto start = chrono::high_resolution_clock::now();
    //d.buildFromOrigin();
    //d.build();
    //auto stop = chrono::high_resolution_clock::now();
    //auto duration = chrono::duration_cast<chrono::milliseconds>(stop - start);
    //cout << "Time taken by loading data: " << duration.count() << " milliseconds" << endl;
    //cout << d.isFavourite("hello") << endl;
    //d.save();

    return 0;
}